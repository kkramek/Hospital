#include "stdafx.h"
#include "DoctorList.h"
#include <iostream>

using namespace std;

DoctorList* DoctorList::instance = NULL;

DoctorList::DoctorList()
{
}


DoctorList::~DoctorList()
{
}

DoctorList * DoctorList::GetInstance() {

	if (!instance) {
		instance = new DoctorList();
	};

	return instance;
};

void DoctorList::AddExampleDoctors()
{

	Doctor *doctor1 = new Doctor(1, "Wladyslaw", "Tarnawski", "Pediatria");
	Doctor *doctor2 = new Doctor(2, "Monika", "Czartoryska", "Neurologia");
	Doctor *doctor3 = new Doctor(3, "Stanislaw", "Niezlomny", "Chirurgia");

	this->doctorList.push_back(doctor1);
	this->doctorList.push_back(doctor2);
	this->doctorList.push_back(doctor3);


	cout << "[INFO] Dodano przykladowych lekarzy!" << endl << endl;

};

void DoctorList::ShowDoctorList()
{
	vector < Doctor* >::iterator iter, end;

	cout << endl << "***************Lista lekarzy***************" << endl;

	for (iter = this->doctorList.begin(), end = this->doctorList.end(); iter != end; ++iter) {

		cout << (*iter)->getId() << " " << (*iter)->getFirstName() << " " << (*iter)->getLastName() << " " << (*iter)->GetSpecialization() << endl;
	}

	cout << "*********************************************" << endl << endl;
};

bool DoctorList::DoctorExists(int id)
{
	vector < Doctor* >::iterator iter, end;

	for (iter = this->doctorList.begin(), end = this->doctorList.end(); iter != end; ++iter) {

		if ((*iter)->getId() == id) {
			return true;
		}
	}

	return false;
}