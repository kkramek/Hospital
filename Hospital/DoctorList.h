#pragma once
#include "Doctor.h"
#include <vector>

using namespace std;

class DoctorList
{
public:
	DoctorList();
	~DoctorList();

	static DoctorList* GetInstance();

	void AddExampleDoctors();
	void ShowDoctorList();
	bool DoctorExists(int id);

private:
	static DoctorList *instance;
	vector < Doctor* > doctorList;
};

