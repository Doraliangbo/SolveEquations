/////////////////////////////////////
//File Name: source.cpp
//Purpose: source file for main
//Author: Bo Liang
//Date:03/13/2017
/////////////////////////////////////
#include "FileHelper.h"
int main(int argc, char** argv)
{
	//read the command line and do validation check
	if (argc != 2)
	{
	cout << "\nThe input is invalid. \nPlease enter the valid params!";
	return 0;
	}
	//parse the file path
	string filePath = argv[1];
	FileHelper myFileHelper;
	DataHolder myDataHolder;
	//read lines from file
	myFileHelper.ReadFile(filePath, myDataHolder);
	//Calculate the equations
	myDataHolder.DataCooker();
	//Print the result out
	myDataHolder.PrintOut();
	return 0;
}