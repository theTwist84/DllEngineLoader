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
	static bool Commands(LPCSTR, LPCSTR);
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
	static char input_buffer[1024] = {};
	while (true)
	{
		printf("command> ");

		memset(input_buffer, 0, 1024);
		fgets(input_buffer, 1024, stdin);

		char *newline = strchr(input_buffer, '\n');
		if (newline) *newline = '\0';

		if (strlen(input_buffer) == 0)
			continue;

		std::vector<std::string> inputs = SplitString(input_buffer, " ");
		LPCSTR pInputCommand = inputs.size() >= 1 ? inputs[0].c_str() : "\0";
		LPCSTR pInputArgument = inputs.size() >= 2 ? inputs[1].c_str() : "\0";

		if (ICommand({ "Exit", "exit" }).Match(pInputCommand))
			exit(0);

		Commands(pInputCommand, pInputArgument);
	}
}

// TODO: Support lowercase
bool IConsoleAccess::Commands(LPCSTR pInputCommand, LPCSTR pInputArgument)
{
	IGameInterface *pGameInterface = s_pGameInterface;

	if (ICommand({ "ClearScreen", "clearscreen", "clear_screen", "cls" }).Match(pInputCommand))
	{
		std::system("CLS");
		return true;
	}

	if (ICommand({ "LaunchTitle", "launchtitle", "launch_title" }).Match(pInputCommand))
	{
		bool showHelp = true;
		if (showHelp)
		{
			WriteLine("enum LaunchTitle\n{");
			WriteLine("\tHaloReach");
			WriteLine("};");
		}
		return false;
	}

	if (ICommand({ "EngineState", "enginestate", "engine_state" }).Match(pInputCommand))
	{
		if (pGameInterface->GetEngine() == nullptr)
		{
			WriteLine("No engine loaded");
			return false;
		}

		bool showHelp = true;
		size_t engineStateCount = static_cast<size_t>(EngineState::kCount);
		for (size_t i = 0; i < engineStateCount; i++)
		{
			EngineState engineState = static_cast<EngineState>(i);
			LPCSTR engineStateStr = EngineStateFromID(engineState);
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
				EngineState engineState = static_cast<EngineState>(i);
				LPCSTR engineStateStr = EngineStateFromID(engineState);
				WriteLine((i == engineStateCount - 1 ? "\t%s" : "\t%s,"), engineStateStr);
			}
			WriteLine("};");
		}
		return true;
	}

	if (ICommand({ "EditTag", "edittag", "edit_tag" }).Match(pInputCommand))
		return EditTag(pInputArgument);

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
	size_t commandCount = static_cast<size_t>(Commands::kCount);

	WriteLine("enum Command\n{");
	for (size_t i = 0; i < commandCount; i++)
	{
		WriteLine((i == commandCount - 1 ? "\t%s" : "\t%s,"), commands[i]);
	}
	WriteLine("};");

	return false;
}
