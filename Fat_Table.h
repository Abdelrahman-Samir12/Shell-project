#pragma once
#include<bits/stdc++.h>
using namespace std;

class Fat_Table
{
public:
	int* Fat_array;
	Fat_Table();
	void Write_FAT_Table();
	void Print_FAT_Table();
	int avalible_blocks();
	int Get_Avalible_Block();
	void get_FAT_Table();
	int getValue(int);
	void setValue(int, int);

};

