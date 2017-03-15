/////////////////////////////////////
//File Name: FileHlper.h
//Purpose: header file for file read
//Author: Bo Liang
//Date:03/13/2017
/////////////////////////////////////

#include<iostream>
#include<string>
#include<fstream>
#include "DataHolder.h"
using namespace std;

class FileHelper{
public:
	void ReadFile(string filePath, DataHolder & dataHolder);
};