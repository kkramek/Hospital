#pragma once
#include "Person.h"

class Doctor
	: public Person
{
public:
	Doctor(int id, string firstName, string lastName, string specialization);
	~Doctor();

	string GetSpecialization();

private:
	string specialization;
};

