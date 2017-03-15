/////////////////////////////////////
//File Name: FileHelper.cpp
//Purpose: source file for file read
//Author: Bo Liang
//Date:03/13/2017
/////////////////////////////////////

#include "FileHelper.h"


void FileHelper::ReadFile(string filePath, DataHolder & dataHolder)
{
	//string filePath = argv[1];
	std::ifstream  file;
	file.open("test.txt", std::ifstream::in);
	if (!file.is_open())
	{
		cout << "\n File not opened";
		return;
	}
	string temp;
	string line;
	bool isKey = true;

	//DataHolder myDataHolder;

	while (getline(file,line))
	{
		dataHolder.SaveData(line);
	}

	file.close();

}
