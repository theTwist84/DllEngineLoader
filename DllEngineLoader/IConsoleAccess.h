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
	static void Commands(LPCSTR, LPCSTR);
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
		printf("tags> ");
		char input_cmd[1024] = {}, input_arg[1024] = {};
		if (scanf("%s %s", &input_cmd, &input_arg) != 0 && input_cmd[0] == ':' && input_arg[0] != 0)
		{
			for (size_t i = 1; i < 1024; i++)
				input_cmd[i - 1] = input_cmd[i];
			Commands(input_cmd, input_arg);
		}
	}
}

// TODO: Support lowercase
void IConsoleAccess::Commands(LPCSTR pInputCommand, LPCSTR pInputArgument)
{
	auto pGameInterface = s_pGameInterface;
	if (strcmp(pInputCommand, "ClearScreen") == 0 || strcmp(pInputCommand, "clearscreen") == 0 || strcmp(pInputCommand, "clear_screen") == 0 || strcmp(pInputCommand, "cls") == 0)
	{
		std::system("CLS");

		return;
	}

	if (strcmp(pInputCommand, "LaunchTitle") == 0 || strcmp(pInputCommand, "launchtitle") == 0 || strcmp(pInputCommand, "launch_title") == 0)
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

	if (strcmp(pInputCommand, "EngineState") == 0 || strcmp(pInputCommand, "enginestate") == 0 || strcmp(pInputCommand, "engine_state") == 0)
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
			if (strcmp(pInputArgument, engineStateStr) == 0)
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

	if (strcmp(pInputCommand, "EditTag") == 0 ||strcmp(pInputCommand, "edittag") == 0 ||strcmp(pInputCommand, "edit_tag") == 0)
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
		if (strstr(pInputArgument, ".scenario") != 0)
		{
			showHelp = ITagInterface::GetDefinition<c_scenario_definition>(pInputArgument).apply().edit(pInputArgument);
		}
		if (strstr(pInputArgument, ".weapon") != 0)
		{
			showHelp = ITagInterface::GetDefinition<c_weapon_definition>(pInputArgument).apply().edit(pInputArgument);
		}
		if (strstr(pInputArgument, ".user_interface_shared_globals_definition") != 0)
		{
			showHelp = ITagInterface::GetDefinition<c_user_interface_shared_globals_definition>(pInputArgument).apply().edit(pInputArgument);
		}
		if (showHelp)
		{
			for (auto &group : tagGroups)
			{
				if (strcmp(group.first.c_str(), pInputArgument) == 0 || strcmp(group.second.c_str(), pInputArgument) == 0)
				{
					showHelp = false;

					list_tags_in_group(group.first.c_str());
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
