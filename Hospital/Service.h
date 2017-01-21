#pragma once
#include <string>

using namespace std;

class Service
{
public:
	Service(int id, string name, double price);
	~Service();

	int GetId();
	string GetName();
	double GetPrice();

private:
	int id;
	string name;
	double price;


};

