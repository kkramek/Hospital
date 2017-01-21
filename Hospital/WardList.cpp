#include "stdafx.h"
#include "WardList.h"


WardList* WardList::instance = NULL;

WardList::WardList()
{
}


WardList::~WardList()
{
}

WardList * WardList::GetInstance() {

	if (!instance) {
		instance = new WardList();
	};

	return instance;
};

void WardList::AddExampleWards()
{

	Ward *ward1 = new Ward(1, "Intensywna Terapia");
	Ward *ward2 = new Ward(2, "Izba Przyjec");
	Ward *ward3 = new Ward(3, "Kostnica");

	this->wardList.push_back(ward1);
	this->wardList.push_back(ward2);
	this->wardList.push_back(ward3);


	cout << "[INFO] Dodano przykladowe oddzialy!" << endl << endl;

};

void WardList::ShowWardList()
{
	vector < Ward* >::iterator iter, end;

	cout << endl << "***************Lista oddzialow***************" << endl;

	for (iter = this->wardList.begin(), end = this->wardList.end(); iter != end; ++iter) {

		cout << (*iter)->GetId() << " " << (*iter)->GetName() << endl;
	}

	cout << "*********************************************" << endl << endl;
};

bool WardList::WardExists(int id)
{
	vector < Ward* >::iterator iter, end;

	for (iter = this->wardList.begin(), end = this->wardList.end(); iter != end; ++iter) {

		if ((*iter)->GetId() == id) {
			return true;
		}
	}

	return false;
}