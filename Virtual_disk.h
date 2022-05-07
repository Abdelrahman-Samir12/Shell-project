#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Virtual_disk
{
public:
	Virtual_disk()
	{
		initalize();
	}
	void write_Block(vector<char>, int index);
	vector<char> read_Block(int index);
private:
	void initalize();

};

