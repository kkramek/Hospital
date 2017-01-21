#include "stdafx.h"
#include "Doctor.h"


Doctor::Doctor(int id, string firstName, string lastName, string specialization)
: Person(id, firstName, lastName)
{
	this->specialization = specialization;
}


Doctor::~Doctor()
{
}

string Doctor::GetSpecialization()
{
	return this->specialization;
}
