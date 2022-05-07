#pragma once
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include<direct.h>
#include <vector>
using namespace std;
class Shell
{
public:
	Shell() 
	{
		char buff[FILENAME_MAX];
		currentDirictory = string(_getcwd(buff, FILENAME_MAX));
		getCommands(commands);
		buildFunctions(functions);
		buildFunctionsWithparm(functionsWithparm);
	}
	void prompt();
private:
	string currentDirictory;
	map<string, void(Shell::*) (void)>functions;
	map<string, void(Shell::*) (vector<string>)>functionsWithparm;
	map<string, string>commands;
	void getCommands(map<string, string>& commands);
	void buildFunctions(map<string, void(Shell::*) (void)>& mp);
	void buildFunctionsWithparm(map<string, void(Shell::*) (vector<string>)>& mp);
	void Exit();
	void Help(vector<string>);
	void Clear();
	void mkdir(vector<string>);
	void dir();
	void rmdir(vector<string>);
	void cd(vector<string>);
};

