#pragma once
#include "PatientList.h"
#include "DoctorList.h"
#include "WardList.h"
#include "DrugList.h"
#include "TreatmentList.h"

class Menu
{
public:
	Menu();
	~Menu();

	void ShowMenu();
	void ShowPatientListByWard();
	void ShowPatientListByDate();
	void ShowDrugs();
	void ShowTreatment();

	void AddPatient();
	Patient* SearchPatient();
	void EditPatient();
	void DeletePatient();
};

