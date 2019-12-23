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

	if (Commands.find("EngineState") != std::string::npos ||
		Commands.find("enginestate") != std::string::npos ||
		Commands.find("engine_state") != std::string::npos)
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

	if (Commands.find("EditTag") != std::string::npos ||
		Commands.find("edittag") != std::string::npos ||
		Commands.find("edit_tag") != std::string::npos)
	{
		std::set<std::pair<std::string, std::string>> tagGroups;
		for (auto &tagInfo : ITagList::Get())
		{
			tagGroups.emplace(std::make_pair(tagInfo.Group, tagInfo.GroupName));
		}

		auto list_tag_groups = [tagGroups]()
		{
			WriteLine("enum TagGroup\n{");

			for (auto &group : tagGroups)
			{
				if (strcmp(group.first.c_str(), (*tagGroups.rbegin()).first.c_str()) == 0)
				{
					WriteLine("\t{ %s, %s }", group.first.c_str(), group.second.c_str());
				}
				else
				{
					WriteLine("\t{ %s, %s },", group.first.c_str(), group.second.c_str());
				}
			}

			WriteLine("};");
		};

		auto list_tags_in_group = [tagGroups](LPCSTR pGroup)
		{
			bool valid = false;
			for (auto &group : tagGroups)
			{
				if (strcmp(group.first.c_str(), pGroup) == 0 || strcmp(group.second.c_str(), pGroup) == 0)
				{
					valid = true;
				}
			}
			if (valid)
			{
				WriteLine("enum %s\n{", pGroup);
			}

			for (auto &tagInfo : ITagList::Get())
			{
				if (valid)
				{
					if (strcmp(tagInfo.Group, pGroup) == 0 || strcmp(tagInfo.GroupName, pGroup) == 0)
					{
						if (strcmp(tagInfo.Group, (*ITagList::Get().rbegin()).Group) == 0 || strcmp(tagInfo.GroupName, (*ITagList::Get().rbegin()).GroupName) == 0)
						{
							WriteLine("\t%s.%s", tagInfo.Name, tagInfo.GroupName);
						}
						else
						{
							WriteLine("\t%s.%s,", tagInfo.Name, tagInfo.GroupName);
						}
					}
				}
			}

			if (valid)
			{
				WriteLine("};");
			}
		};

		bool showHelp = true;
		for (auto &cmd : SplitString(Commands.c_str(), " "))
		{
			if (cmd.find(".scenario") != std::string::npos)
			{
				showHelp = ITagInterface::GetDefinition<c_scenario_definition>(cmd.c_str()).run_access_loop(cmd.c_str());
			}
			if (cmd.find(".weapon") != std::string::npos)
			{
				showHelp = ITagInterface::GetDefinition<c_weapon_definition>(cmd.c_str()).run_access_loop(cmd.c_str());
			}
			if (showHelp)
			{
				for (auto &group : tagGroups)
				{
					if (strcmp(group.first.c_str(), cmd.c_str()) == 0 || strcmp(group.second.c_str(), cmd.c_str()) == 0)
					{
						showHelp = false;

						list_tags_in_group(group.first.c_str());
					}
				}
			}
		}

		if (showHelp)
		{
			list_tag_groups();
		}

		return;
	}

	enum class Commands : int
	{
		LaunchTitle,
		EngineState,
		EditGet,

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
