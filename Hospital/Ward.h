#pragma once
#include <string>
#include <iostream>

using namespace std;

class Ward
{
public:
	Ward(int id, string name);
	~Ward();

	string GetName();
	int GetId();

private:
	int id;
	string name;
};

