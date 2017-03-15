
/////////////////////////////////////
//File Name: DataHolder.cpp
//Purpose: source file for database and data processor
//Author: Bo Liang
//Date:03/13/2017
/////////////////////////////////////


#include "DataHolder.h"
#include <algorithm>
#include <iostream>
bool DataHolder::isResolved(string str)
{
	if (str=="")
	{
		return false;
	}
		
	auto iter = myMap.find(str);
	if ( iter!= myMap.end() && iter->second.size() == 1 && isNum(iter->second.at(0)) )
	{
		return true;
	}

	return false;

}


bool DataHolder::isAllResolved()
{
	for (auto iter = myMap.begin(); iter != myMap.end(); iter++)
	{
		if (!isNum(iter->second.at(0)))
		{
			return false;
		}
	}
	return true;
}

void DataHolder::SaveData(string str)
{
	removeSpaces(str);
	string leftS = findLeft(str);
	vector<string> rightS = findRight(str);
	int num = 0;
	auto iter = myMap.find(leftS);
	//we already have one in our map
	if (iter != myMap.end())
	{
		vector<string> myMapVectEle = iter->second;
		string temp = myMapVectEle[myMapVectEle.size()-1];
		num = atoi(temp.c_str());
		myMapVectEle.pop_back();
		for (auto i : rightS)
		{
			if (isNum(i))
			{
				num = num + atoi(i.c_str());
			}
			else
			{
				myMapVectEle.push_back(i);
			}
		}
		myMapVectEle.push_back(to_string(num));
		return;
	}

	//we donot have one in out map
	vector<string> vectorEle;
	for (auto i : rightS)
	{
		if (isNum(i))
		{
			num = num + atoi(i.c_str());
		}
		else
		{
			vectorEle.push_back(i);
		}
	}
	vectorEle.push_back(to_string(num));
	std::pair<string, vector<string>> myMapEle(leftS, vectorEle);
	myMap.insert(myMapEle);
	return;
}

string DataHolder::findLeft(string str)
{
	return str.substr(0, str.find_first_of("="));
}
vector<string> DataHolder::findRight(string str)
{
	vector<string> temp;
	int length = str.length();
	int index = str.find_first_of("=");
	int num = 0;
	str = str.substr(index+1, length);
	index = str.find_first_of("+");
	if (index == -1)
	{
		if (isNum(str))
		{
			num = atoi(str.c_str()) + num;
		}
		else
		{
			temp.push_back(str);
		}
	}
	else{
		while (index != -1 && index < length)
		{
			string tempStr = str.substr(0, index);

			if (isNum(tempStr))
			{
				num = atoi(tempStr.c_str()) + num;
			}
			else
			{
				temp.push_back(tempStr);
			}
			str = str.substr(index + 1, length);
			index = str.find_first_of("+");

			if (index == -1)
			{
				tempStr = str;
				if (isNum(tempStr))
				{
					num = atoi(tempStr.c_str()) + num;
				}
				else
				{
					temp.push_back(tempStr);
				}
				break;
			}

			length = str.length();

		}
	}
	temp.push_back(to_string(num));

	return temp;
}

bool DataHolder::isNum(string str)
{
	return isdigit(str[0])? true:false;
}

void DataHolder::removeSpaces(string &str)
{
	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
}

void DataHolder::DataCooker()
{
	if (myMap.size()==0)
	{
		return;
	}

	unordered_map<string, vector<string>>::iterator iter;
	while (!isAllResolved())
	{
		for (iter = myMap.begin(); iter != myMap.end(); iter++)
		{
			if (!isResolved(iter->first))
			{
				for (size_t t = iter->second.size()- 2; t >=0; t--)
				{
					bool isCurrentInt = isNum(iter->second.at(t));
					int temp = atoi(iter->second.back().c_str());
					iter->second.pop_back();
					if (!isCurrentInt)
					{
						auto it_pos = myMap.find(iter->second.at(t));
						if (it_pos != myMap.end())
						{
							if (isResolved(it_pos->first))
							{
								temp = temp + atoi(it_pos->second.at(0).c_str());
								iter->second.pop_back();
								iter->second.push_back(to_string(temp));
							}
							else
							{
								break;
							}
						}
					}

					if (isResolved(iter->first))
					{
						break;
					}
				}

			}

		}

	}

}

void DataHolder::PrintOut()
{
	for (auto iter = myMap.begin(); iter != myMap.end(); iter++)
	{
		std::cout << iter->first << " = " << iter->second.at(0) << "\n";
	}
}