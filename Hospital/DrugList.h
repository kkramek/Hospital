#pragma once
#include "Service.h"
#include <vector>

using namespace std;

class DrugList
{
public:
	DrugList();
	~DrugList();


	static DrugList* GetInstance();

	void AddExampleDrug();
	void ShowDrugList();
	bool DrugExists(int id);
	Service* GetDrug(int id);

private:
	static DrugList *instance;
	vector < Service* > drugList;
};

