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
	void ShowPatientDue();

	void AddPatient();
	Patient* SearchPatient();
	void EditPatientMenu();
	void EditPatient(Patient *foundPatient);
	void EditPatientAdDrug(Patient *foundPatient);
	void EditPatientAdTreatment(Patient *foundPatient);
	void DeletePatient();
};

