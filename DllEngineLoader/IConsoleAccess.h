#pragma once

class IConsoleAccess
{
public:
	IConsoleAccess();
	~IConsoleAccess();

	static bool SetGameInterface(IGameInterface &);

	static void Write(std::string, ...);
	static void WriteLine(std::string, ...);

private:
	static HANDLE          s_threadHandle;
	static IGameInterface *s_pGameInterface;

	static void Thread();
	static void Commands(std::string);
};

HANDLE          IConsoleAccess::s_threadHandle   = 0;
IGameInterface *IConsoleAccess::s_pGameInterface = 0;

IConsoleAccess::IConsoleAccess()
{
	if (!s_threadHandle)
	{
		s_threadHandle = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&Thread, NULL, 0, NULL);
	}
}

IConsoleAccess::~IConsoleAccess()
{
}

bool IConsoleAccess::SetGameInterface(IGameInterface &rGameInterface)
{

	if (&rGameInterface && !s_pGameInterface)
	{
		s_pGameInterface = &rGameInterface;
		return true;
	}
	return false;
}

void IConsoleAccess::Write(std::string pFormat, ...)
{
	va_list args;
	va_start(args, pFormat);
	vprintf(pFormat.c_str(), args);
}

void IConsoleAccess::WriteLine(std::string pFormat, ...)
{
	pFormat += "\n";

	va_list args;
	va_start(args, pFormat);
	vprintf(pFormat.c_str(), args);
}

void IConsoleAccess::Thread()
{
	auto pGameInterface = s_pGameInterface;
	while (pGameInterface)
	{
		static std::string input = "";
		if (std::getline(std::cin, input, '\n'))
		{
			if (input.find_first_of(":") == 0)
			{
				Commands(input);
			}
		}
	}
}

template<typename T>
struct vector3d
{
	T I, J, K;
};

// TODO: Support lowercase
void IConsoleAccess::Commands(std::string Commands)
{
	auto pGameInterface = s_pGameInterface;
	if (Commands.find("cls") != std::string::npos)
	{
		std::system("CLS");

		return;
	}

	if (Commands.find("LaunchTitle") != std::string::npos)
	{
		bool showHelp = true;
		if (showHelp)
		{
			WriteLine("enum LaunchTitle\n{");
			WriteLine("\tHaloReach");
			WriteLine("};");
		}

		return;
	}

	if (Commands.find("EngineState") != std::string::npos)
	{
		if (pGameInterface->GetEngine() == nullptr)
		{
			WriteLine("No engine loaded");
			return;
		}

		bool showHelp = true;
		auto engineStateCount = static_cast<size_t>(EngineState::kCount);
		for (size_t i = 0; i < engineStateCount; i++)
		{
			auto engineState = static_cast<EngineState>(i);
			auto engineStateStr = EngineStateFromID(engineState);
			if (Commands.find(engineStateStr) != std::string::npos)
			{
				showHelp = false;
				pGameInterface->GetEngine()->UpdateEngineState(engineState);
				WriteLine("EngineState [%s]", engineStateStr);

				break;
			}
		}
		if (showHelp)
		{
			WriteLine("enum EngineState\n{");
			for (size_t i = 0; i < engineStateCount; i++)
			{
				auto engineState = static_cast<EngineState>(i);
				auto engineStateStr = EngineStateFromID(engineState);
				WriteLine((i == engineStateCount - 1 ? "\t%s" : "\t%s,"), engineStateStr);
			}
			WriteLine("};");
		}

		return;
	}

	if (Commands.find("TagGet") != std::string::npos)
	{
		bool showHelp = true;
		if (Commands.find("Scenario") != std::string::npos)
		{
			showHelp = false;
			auto scenarioDatumHandle = CacheGlobalTagGet('scnr');
			printf("[scnr, 0x%08X]\n", scenarioDatumHandle.m_Index);

			auto pScenarioDefinition = TagGetDefinition<char *>('scnr', scenarioDatumHandle);

			if (Commands.find("MapID") != std::string::npos)
			{
				printf("[map_id, %u]\n", *reinterpret_cast<UINT32 *>(&pScenarioDefinition[0xC]));
			}
			CacheGlobalTagPrint('scnr');

			return;
		}
		if (Commands.find("weap") != std::string::npos)
		{
			auto weapon_edit_fp_offset = [](LPCSTR pName)
			{
				char *pWeaponDefinition = TagGetDefinition<char *>(pName);

				if (*reinterpret_cast<UINT32 *>(pWeaponDefinition) != 0xFFFFFFFF)
				{
					auto &FirstPersonWeaponOffset = *reinterpret_cast<vector3d<float> *>(pWeaponDefinition + 0x4CC);

					printf("[First Person Weapon Offset, %.8f %.8f %.8f]\n", FirstPersonWeaponOffset.I, FirstPersonWeaponOffset.J, FirstPersonWeaponOffset.K);

					printf("[First Person Weapon Offset, Enter new values]:\n");
					if (scanf("%f %f %f", &FirstPersonWeaponOffset.I, &FirstPersonWeaponOffset.J, &FirstPersonWeaponOffset.K))
					{
						printf("[First Person Weapon Offset, %.8f %.8f %.8f]\n", FirstPersonWeaponOffset.I, FirstPersonWeaponOffset.J, FirstPersonWeaponOffset.K);
					}
				}
			};

			for (auto& cmd : SplitString(Commands.c_str(), " "))
			{
				if (cmd.find(".weapon") != std::string::npos)
				{
					showHelp = false;

					weapon_edit_fp_offset(cmd.c_str());
				}
			}

			if (showHelp)
			{
				WriteLine("enum Weapon\n{");

				for (auto& tagInfo : ITagList::Get())
				{
					if (tagInfo.Name[0] && strstr(tagInfo.Name, ".weapon") != 0)
					{
						WriteLine("\t%s", tagInfo.Name);
					}
				}

				WriteLine("};");
			}

			return;
		}


		if (showHelp)
		{
			WriteLine("enum TagGroup\n{");

			WriteLine("\t%s", ".scnr");
			WriteLine("\t%s", ".weap");

			WriteLine("};");
		}

		return;
	}

	enum class Commands : int
	{
		LaunchTitle,
		EngineState,
		TagGet,

		kCount
	};
	LPCSTR commands[static_cast<int>(Commands::kCount)] =
	{
		"LaunchTitle",
		"EngineState",
		"TagGet"
	};
	auto commandCount = static_cast<size_t>(Commands::kCount);

	WriteLine("enum Command\n{");
	for (size_t i = 0; i < commandCount; i++)
	{
		auto command = static_cast<int>(i);
		auto commandStr = commands[command];
		WriteLine((i == commandCount - 1 ? "\t%s" : "\t%s,"), commandStr);
	}
	WriteLine("};");
}
