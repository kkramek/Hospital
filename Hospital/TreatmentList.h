#pragma once
#include "Service.h"
#include <vector>

using namespace std;

class TreatmentList
{
public:
	TreatmentList();
	~TreatmentList();

	static TreatmentList* GetInstance();

	void AddExampleTreatment();
	void ShowTreatmentList();
	bool TreatmentExists(int id);

private:
	static TreatmentList *instance;
	vector < Service* > treatmentList;
};

