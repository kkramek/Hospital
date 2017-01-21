#include "stdafx.h"
#include "Service.h"


Service::Service(int id, string name, double price)
{
	this->id = id;
	this->name = name;
	this->price = price;
}


Service::~Service()
{
}

int Service::GetId()
{
	return this->id;
}

string Service::GetName()
{
	return this->name;
}

double Service::GetPrice()
{
	return this->price;
}
