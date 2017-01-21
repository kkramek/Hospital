#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "stdafx.h"
#include "Patient.h"

using namespace std;

class PatientList
{
public:
	PatientList();
	~PatientList();

	static PatientList* GetInstance();

	void ShowPatientList();
	void ShowPatientListByWard(int wardId);
	void ShowPatientListByDate(string date);
	void AddPatient(Patient *patient);
	void AddExamplePatients();
	void DeletePatient(Patient *patient);

	int GetNewId();
	Patient* SearchPatient(Patient *patient);
	bool PatientCompare(Patient *firstPatient, Patient *secondPatient);

private:
	static PatientList *instance;
	vector < Patient* > patientList;
};

