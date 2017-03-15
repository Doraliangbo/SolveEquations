/////////////////////////////////////
//File Name: DataHolder.h
//Purpose: header file for database and data processor
//Author: Bo Liang
//Date:03/13/2017
/////////////////////////////////////


#ifndef DataHolder_HEADER
#define DataHolder_HEADER
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
using std::string;
using std::vector;

class DataHolder
{
public:
	//constructor
	DataHolder(){
		myMap = unordered_map<string, vector<string>>();
	}
	//destructor
	~DataHolder(){
		myMap.clear();
	}
	//to parse line by line into my database
	void SaveData(string str);
	//to check if one map item is done with calculation or not
	bool isResolved(string str);
	//to check if all the items in map are done with calculation or not
	bool isAllResolved();
	//main function to do calculation
	void DataCooker();
	//print out the result
	void PrintOut();
private:
	//hashmap to store all the data
	unordered_map<string, vector<string>> myMap;
	//left side of the equation
	string findLeft(string str);
	//right side of the equations
	vector<string> findRight(string str);
	//helper function: remove all the spaces in a string
	void removeSpaces(string &str);
	//helper function: check if a string is integer
	bool isNum(string str);
};
#endif