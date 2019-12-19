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

struct real_vector3d
{
	float I, J, K;

	void Update(LPCSTR pName)
	{
		printf("[%s, %.8f %.8f %.8f]\n", pName, I, J, K);
		printf("[%s, Enter new values]: ", pName);
		if (scanf("%f %f %f", &I, &J, &K))
		{
			printf("[%s, %.8f %.8f %.8f]\n", pName, I, J, K);
		}
	}
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

	if (Commands.find("EditTag") != std::string::npos || Commands.find("edit_tag") != std::string::npos)
	{
		bool showHelp = true;
		if (Commands.find("Scenario") != std::string::npos)
		{
			showHelp = false;
			auto scenarioDatumHandle = ITagInterface::GetGlobalHandle('scnr');
			auto scenarioName = ITagList::GetName(scenarioDatumHandle);

			auto pScenarioDefinition = ITagInterface::GetDefinition<char *>(scenarioName);

			if (Commands.find("MapID") != std::string::npos)
			{
				printf("[map_id, %u]\n", *reinterpret_cast<UINT32 *>(&pScenarioDefinition[0xC]));
			}

			return;
		}

		if (Commands.find("Weap") != std::string::npos || Commands.find("weap") != std::string::npos)
		{
			std::vector<DefinitionUnion> definitions;
			definitions[0]._real_vector3d = { "first_person_weapon_offset", 0x4CC };

			for (auto& cmd : SplitString(Commands.c_str(), " "))
			{
				if (cmd.find(".weapon") != std::string::npos)
				{
					showHelp = false;

					WeaponDefinition &rWeaponDefinition = ITagInterface::GetDefinition<WeaponDefinition>(cmd.c_str());
					if (!rWeaponDefinition.IsNull())
					{
						printf("%s> ", cmd.c_str());
						char input_cmd[1024] = {};
						char input_arg[1024] = {};
						if (scanf("%s %s", &input_cmd, &input_arg) != 0 && (strcmp(input_cmd, "edit") == 0 && input_arg[0] != 0))
						{
							for (auto &definition : definitions)
							{
								if (!definition._real_vector3d.IsNull())
								{
									if (strcmp(input_arg, definition._real_vector3d.m_Name.c_str()) == 0)
									{
										rWeaponDefinition.Get<decltype(definition._real_vector3d.m_Type)>(definition._real_vector3d.m_Offset).Update(definition._real_vector3d.m_Name.c_str());
									}
								}
							}
						}
					}
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
		"EditTag"
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
