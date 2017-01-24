#include "stdafx.h"
#include "TreatmentList.h"
#include <iostream>

TreatmentList* TreatmentList::instance = NULL;


TreatmentList::TreatmentList()
{
}


TreatmentList::~TreatmentList()
{
}

TreatmentList * TreatmentList::GetInstance() {

	if (!instance) {
		instance = new TreatmentList();
	};

	return instance;
};

void TreatmentList::AddExampleTreatment()
{

	Service *service1 = new Service(1, "Aspirowanie", 9.99);
	Service *service2 = new Service(2, "Irygacja", 19.99);
	Service *service3 = new Service(3, "Jonoforeza", 25.50);
	Service *service4 = new Service(4, "Krioablacja", 5.29);
	Service *service5 = new Service(5, "Kriokoagulacja", 13.90);
	Service *service6 = new Service(6, "Kroplowka", 49.99);
	Service *service7 = new Service(7, "Skaryfikacja", 32.15);
	Service *service8 = new Service(8, "Termoablacja", 21.13);
	Service *service9 = new Service(9, "Wenopunkcja", 41.20);
	Service *service10 = new Service(10, "Zastrzyk domiesniowy", 39.29);
	Service *service11 = new Service(10, "Zastrzyk dozylny", 39.29);
	Service *service12 = new Service(10, "Zastrzyk podskorny", 39.29);


	this->treatmentList.push_back(service1);
	this->treatmentList.push_back(service2);
	this->treatmentList.push_back(service3);
	this->treatmentList.push_back(service4);
	this->treatmentList.push_back(service5);
	this->treatmentList.push_back(service6);
	this->treatmentList.push_back(service7);
	this->treatmentList.push_back(service8);
	this->treatmentList.push_back(service9);
	this->treatmentList.push_back(service10);
	this->treatmentList.push_back(service11);


	cout << "[INFO] Dodano przykladowe zabiegi!" << endl << endl;

};

void TreatmentList::ShowTreatmentList()
{
	vector < Service* >::iterator iter, end;

	cout << endl << "***************Lista zabiegow***************" << endl;

	for (iter = this->treatmentList.begin(), end = this->treatmentList.end(); iter != end; ++iter) {

		cout << (*iter)->GetId() << " " << (*iter)->GetName() << " " << (*iter)->GetPrice() << endl;
	}

	cout << "*********************************************" << endl << endl;
};

bool TreatmentList::TreatmentExists(int id)
{
	vector < Service* >::iterator iter, end;

	for (iter = this->treatmentList.begin(), end = this->treatmentList.end(); iter != end; ++iter) {

		if ((*iter)->GetId() == id) {
			return true;
		}
	}

	return false;
};