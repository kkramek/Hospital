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

bool Patient::AddDrug(int drugId)
{
	Service* drug;

	drug = DrugList::GetInstance()->GetDrug(drugId);

	if (drug != nullptr) {
		this->drugList.push_back(drug);
		return true;
	} 

	return false;
}

bool Patient::AddTreatment(int treatmentId)
{
	Service* treatment;

	treatment = TreatmentList::GetInstance()->GetTreatment(treatmentId);

	if (treatment != nullptr) {
		this->treatmentList.push_back(treatment);
		return true;
	}

	return false;
}

double Patient::GetDue()
{
	double due = 0;
	vector < Service* >::iterator iter, end;

	for (iter = this->drugList.begin(), end = this->drugList.end(); iter != end; ++iter) {
		due += (*iter)->GetPrice();
	}

	for (iter = this->treatmentList.begin(), end = this->treatmentList.end(); iter != end; ++iter) {
		due += (*iter)->GetPrice();
	}

	return due;
}