#include "stdafx.h"
#include "Person.h"


Person::Person(int id, string firstName, string lastName)
{
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
}


Person::~Person()
{
}

int Person::getId()
{
	return this->id;
}

string Person::getFirstName()
{
	return this->firstName;
}

string Person::getLastName()
{
	return this->lastName;
}

void Person::SetFirstName(string firstName)
{
	this->firstName = firstName;
}

void Person::SetLastName(string lastName)
{
	this->lastName = lastName;
}