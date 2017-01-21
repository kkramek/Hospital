#include "stdafx.h"
#include "DrugList.h"
#include <iostream>

DrugList* DrugList::instance = NULL;

DrugList::DrugList()
{
}


DrugList::~DrugList()
{
}

DrugList * DrugList::GetInstance() {

	if (!instance) {
		instance = new DrugList();
	};

	return instance;
};

void DrugList::AddExampleDrug()
{

	Service *service1 = new Service(1, "Apap", 9.99);
	Service *service2 = new Service(2, "Morfina", 19.99);
	Service *service3 = new Service(3, "Amisulpryd", 25.50);
	Service *service4 = new Service(4, "Chlorpromazyna", 5.29);
	Service *service5 = new Service(5, "Fentanyl", 13.90);
	Service *service6 = new Service(6, "Oxycodon", 49.99);
	Service *service7 = new Service(7, "Methadone", 32.15);
	Service *service8 = new Service(8, "Ketamina", 21.13);
	Service *service9 = new Service(9, "Oxazepam", 41.20);
	Service *service10 = new Service(10, "Ephedryna", 39.29);


	this->drugList.push_back(service1);
	this->drugList.push_back(service2);
	this->drugList.push_back(service3);
	this->drugList.push_back(service4);
	this->drugList.push_back(service5);
	this->drugList.push_back(service6);
	this->drugList.push_back(service7);
	this->drugList.push_back(service8);
	this->drugList.push_back(service9);
	this->drugList.push_back(service10);


	cout << "[INFO] Dodano przykladowe leki!" << endl << endl;

};

void DrugList::ShowDrugList()
{
	vector < Service* >::iterator iter, end;

	cout << endl << "***************Lista lekow***************" << endl;

	for (iter = this->drugList.begin(), end = this->drugList.end(); iter != end; ++iter) {

		cout << (*iter)->GetId() << " " << (*iter)->GetName() << " " << (*iter)->GetPrice() << endl;
	}

	cout << "*********************************************" << endl << endl;
};

bool DrugList::DrugExists(int id)
{
	vector < Service* >::iterator iter, end;

	for (iter = this->drugList.begin(), end = this->drugList.end(); iter != end; ++iter) {

		if ((*iter)->GetId() == id) {
			return true;
		}
	}

	return false;
};