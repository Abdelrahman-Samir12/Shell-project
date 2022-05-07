#include "Shell.h"
#include<bits/stdc++.h>
using namespace std;
void Shell::prompt()
{
	while (true)
	{
		
		cout << currentDirictory << ">";
		string Command;
		getline(cin, Command);
		stringstream data(Command);
		string cmd;
		data >> cmd;
		if (cmd.empty())continue;
		if (cmd == "cd")
		{
			string paramters;
			for (int i = 3; i < Command.size(); i++)
				paramters += Command[i];
			vector<string>pramter;
			pramter.push_back(paramters);
			(this->*functionsWithparm[cmd])(pramter);
			cout << "\n";
			continue;
		}
		vector<string>paramters;
		string temp;
		while (data >> temp)paramters.push_back(temp);
		if (commands.find(cmd) == commands.end())
		{
			cout << '\'' << cmd << "\' is  not recognized.\n";
		}
		else
		{
			if (functions.find(cmd) != functions.end())
			{
				(this->*functions[cmd])();
			}
			else if (functionsWithparm.find(cmd) != functionsWithparm.end())
			{
				(this->*functionsWithparm[cmd])(paramters);
			}
			else
			{
				cout << "Invalid input";
			}
			cout << "\n";
		}
	}

}
void Shell::getCommands(map<string, string>& commands)
{
	commands.clear();
	commands["clr"] = "Clear the screen.";
	commands["help"] = "Provides Help information for commands.";
	commands["exit"] = "Quit the shell.";
	commands["dir"] = "List the contents of directory.";
	commands["mkdir"] = "Creats a directory.";
	commands["rd"] = "Removes a directory.";
	commands["cd"] = "Changes the current directory";
}
void Shell::buildFunctions(map<string, void(Shell::*) (void)>& mp)
{
	mp.clear();
	mp["exit"] = &Shell::Exit;
	mp["clr"] = &Shell::Clear;
	mp["dir"] = &Shell::dir;
}
void Shell::buildFunctionsWithparm(map<string, void(Shell::*) (vector<string>)>& mp)
{
	mp.clear();
	mp["help"] = &Shell::Help;
	mp["mkdir"] = &Shell::mkdir;
	mp["rd"] = &Shell::rmdir;
	mp["cd"] = &Shell::cd;
}
void Shell::Exit()
{
	exit(0);
}
void Shell::Help(vector<string>paramters)
{
	if (paramters.empty())
	{
		for (auto it : commands)
		{
			cout << "     " << it.first << setw(10 - it.first.size()) << " -> " << it.second << "\n";
		}
	}
	else if (commands.find(paramters[0]) != commands.end())
	{
		cout << commands[paramters[0]] << "\n";
	}
	else
		cout << "This command is not supported by the help command\n";
}
void Shell::Clear()
{
	system("cls");
}
void Shell::dir()
{
	system("dir");
}
void Shell::mkdir(vector<string>parameters)
{
	if (parameters[0].empty())
	{
		cout << "The syntax of the command is incorrect\n";
		return;
	}
	string dirictoryName = parameters[0];
	char* char_arr;
	char_arr = &dirictoryName[0];
	if (!~_mkdir(char_arr))
		cout << "Failed to create dirictory\n";

}
void Shell::rmdir(vector<string>parameters)
{
	if (parameters.empty())
	{
		cout << "The syntax of the command is incorrect\n";
		return;
	}
	for (string cur : parameters)
	{
		char* char_arr;
		char_arr = &cur[0];
		if (!~_rmdir(char_arr))
		{
			cout << cur << " :The system cannot find the file specifed.\n";
		}
	}
}
void Shell::cd(vector<string>parameters)
{
	if (parameters.empty())
	{
		cout << currentDirictory << "\n";
		return;
	}
	char* char_arr;
	char_arr = &parameters[0][0];
	if (!~_chdir(char_arr))
	{
		cout << "The system couldn't find the dirictory specifed.\n";
	}
	char buff[FILENAME_MAX];
	currentDirictory = string(_getcwd(buff, FILENAME_MAX));
}