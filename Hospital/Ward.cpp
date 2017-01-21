#include "stdafx.h"
#include "Ward.h"


Ward::Ward(int id, string name)
{
	this->id = id;
	this->name = name;
}


Ward::~Ward()
{
}

string Ward::GetName()
{
	return this->name;
}

int Ward::GetId()
{
	return this->id;
}
