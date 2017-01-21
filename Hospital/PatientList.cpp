#include "stdafx.h"
#include "PatientList.h"
#include <string>

PatientList* PatientList::instance = NULL;

PatientList::PatientList()
{
}


PatientList::~PatientList()
{
}

PatientList * PatientList::GetInstance() {

	if (!instance) {
		instance = new PatientList();
	};

	return instance;
};

void PatientList::AddPatient(Patient *patient)
{
	this->patientList.push_back(patient);
};

void PatientList::ShowPatientList()
{
	vector < Patient* >::iterator iter, end;

	cout << endl << "***************Lista pacjentow***************" << endl;

	for (iter = this->patientList.begin(), end = this->patientList.end(); iter != end; ++iter) {

		cout << (*iter)->getFirstName() << " " << (*iter)->getLastName() << " " << (*iter)->getAdmissionDate() << endl;
	}

	cout << "*********************************************" << endl << endl;
};

int PatientList::GetNewId()
{
	return this->patientList.size();
}

Patient* PatientList::SearchPatient(Patient *patient)
{
	vector < Patient* >::iterator iter, end;

	for (iter = this->patientList.begin(), end = this->patientList.end(); iter != end; ++iter) {

		if (this->PatientCompare(patient, (*iter))) {
			return (*iter);
		}
	}

	return nullptr;
}

void PatientList::DeletePatient(Patient *patient)
{
	vector < Patient* >::iterator iter, end;

	for (iter = this->patientList.begin(), end = this->patientList.end(); iter != end; ++iter) {

		if (this->PatientCompare(patient, (*iter))) {
			this->patientList.erase(iter);
			break;
		}
	}
}

bool PatientList::PatientCompare(Patient *firstPatient, Patient *secondPatient)
{
	bool result = true;

	if (firstPatient->getId() != 0 && firstPatient->getId() == secondPatient->getId()) {
		result = true;
	}
	else {
		result = false;
	}

	if (firstPatient->getFirstName() != "" && firstPatient->getFirstName().compare(secondPatient->getFirstName()) == 0) {
		result = true;
	}
	else {
		result = false;
	}

	if (firstPatient->getFirstName() != "" && firstPatient->getFirstName().compare(secondPatient->getFirstName()) == 0) {
		result = true;
	}
	else {
		result = false;
	}

	return result;
}

void PatientList::AddExamplePatients()
{

	Patient *patient1 = new Patient(1, "Jan", "Kowalski", 1, 1, "20.01.2017");
	Patient *patient2 = new Patient(2, "Pawel", "Nowak", 2, 1, "01.01.2017");
	Patient *patient3 = new Patient(3, "Adam", "Drygala", 3, 1, "04.01.2017");
	Patient *patient4 = new Patient(4, "Mateusz", "Wosz", 1, 1, "07.01.2017");
	Patient *patient5 = new Patient(5, "Marcin", "Mikolaszek", 2, 1, "09.01.2017");
	Patient *patient6 = new Patient(6, "Michal", "Hasa", 3, 1, "12.01.2017");
	Patient *patient7 = new Patient(7, "Radoslaw", "Kopek", 1, 1, "15.01.2017");
	Patient *patient8 = new Patient(8, "Przemyslaw", "Mlonka", 2, 1, "16.01.2017");
	Patient *patient9 = new Patient(9, "Antoni", "Kaczmarczyk", 3, 1, "17.01.2017");
	Patient *patient10 = new Patient(10, "Lukasz", "Kolodzej", 1, 1, "20.01.2017");

	this->patientList.push_back(patient1);
	this->patientList.push_back(patient2);
	this->patientList.push_back(patient3);
	this->patientList.push_back(patient4);
	this->patientList.push_back(patient5);
	this->patientList.push_back(patient6);
	this->patientList.push_back(patient7);
	this->patientList.push_back(patient8);
	this->patientList.push_back(patient9);
	this->patientList.push_back(patient10);

	cout << "[INFO] Dodano prykladowych pacjentow!" << endl << endl;

};