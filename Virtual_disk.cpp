#include "Virtual_disk.h"
#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
using namespace std;

void Virtual_disk::initalize()
{
	ofstream file;
	file.open("File.txt");
	for (int i = 0; i < 1024; i++)
	{
		file << '0';
	}
	for (int i = 0; i < 1024; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			file << '*';
		}

	}
	for (int i = 0; i < 1024 * 1019; i++)
	{
		file << '#';
	}
	file.close();
}
void Virtual_disk::write_Block(vector<char>data, int index)
{
	while (data.size() < 1024)
		data.push_back('0');
	fstream file;
	file.open("file.txt");
	file.seekg(index * 1024, ios::beg);
	for (int i = 0; i < 1024; i++)
	{
		file.write((char*)&data[i], sizeof(data[i]));
	}
}
vector<char> Virtual_disk::read_Block(int index)
{
	vector<char>data(1024);
	fstream file;
	file.open("file.txt");
	file.seekg(index * 1024, ios::beg);
	for (int i = 0; i < 1024; i++)
	{
		file.read((char*)&data[i], sizeof(data[i]));
	}
	return data;
}