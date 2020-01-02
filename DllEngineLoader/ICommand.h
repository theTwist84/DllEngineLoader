#pragma once

class ICommand
{
public:
	ICommand(std::initializer_list<std::string> names) : Names(names)
	{
	}

	bool Match(std::string Command)
	{
		for (const std::string &name : Names)
			if (strcmp(Command.c_str(), name.c_str()) == 0)
				return true;
		return false;
	}

private:
	std::initializer_list<std::string> Names;
};