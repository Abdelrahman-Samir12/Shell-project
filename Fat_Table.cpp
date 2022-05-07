#include "Fat_Table.h"
#include<bits/stdc++.h>

using namespace std;

Fat_Table::Fat_Table()
{
	Fat_array = new int[1024];
	memset(Fat_array, 0, sizeof Fat_array);
	for (int i = 0; i < 5; i++)
	{
		Fat_array[i] = -1;
	}
}
int Fat_Table::avalible_blocks()
{
	int count = 0;
	for (int i = 0; i < 1024; i++)
	{
		if (Fat_array[i] == 0)
			count++;
	}
	return count;
}
void Fat_Table::Write_FAT_Table()
{
	fstream CurrentFile;
	CurrentFile.open("File.txt");
	CurrentFile.seekg(1024, ios::beg);
	for (int i = 0; i < 1024; i++)
	{
		CurrentFile.write((char*)&Fat_array[i], sizeof(Fat_array[i]));
	}
	CurrentFile.close();
}
void Fat_Table::Print_FAT_Table()
{
	get_FAT_Table();
	for (int i = 0; i < 1024; i++)
	{
		cout << Fat_array[i] << " ";
	}
	cout << endl;
}
void Fat_Table::get_FAT_Table()
{
	fstream CurrentFile;
	CurrentFile.open("File.txt");
	CurrentFile.seekg(1024, ios::beg);
	for (int i = 0; i < 1024; i++)
	{
		CurrentFile.read((char*)&Fat_array[i], sizeof(Fat_array[i]));
	}
	CurrentFile.close();
}
int Fat_Table::getValue(int index)
{
	return Fat_array[index];
}
void Fat_Table::setValue(int index, int value)
{
	Fat_array[index] = value;
}
int Fat_Table::Get_Avalible_Block()
{
	
	for (int i = 0; i < 1024; i++)
	{
		if (Fat_array[i] == 0)
		{
			return i;
		}
	}
	return -1;
}
