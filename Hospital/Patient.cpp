#include "stdafx.h"
#include "Patient.h"
#include <iostream>


Patient::Patient(int id, string firstName, string lastName, int doctorId, int wardId, string admissionDate)
: Person(id, firstName, lastName)
{
	this->doctorId = doctorId;
	this->wardId = wardId;
	this->admissionDate = admissionDate;
}


Patient::~Patient()
{
}

string Patient::getAdmissionDate()
{
	return this->admissionDate;
}

int Patient::GetWardId()
{
	return this->wardId;
}


void Patient::ShowPatient()
{
	cout << endl << "***************Pacjent***************" << endl;
	cout << this->getId() << " " << this->getFirstName() << " " << this->getLastName() << " " << this->getAdmissionDate() << endl;
	cout << "*********************************************" << endl << endl;
}

void Patient::SetAdmissionDate(string admissionDate)
{
	this->admissionDate = admissionDate;
}

void Patient::SetDoctorId(int doctorId)
{
	this->doctorId = doctorId;
}

void Patient::SetWardId(int wardId)
{
	this->wardId = wardId;
}