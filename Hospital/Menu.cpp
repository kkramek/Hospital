#include "stdafx.h"
#include "Menu.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::ShowMenu()
{
	int choice;

	do {

		cout << endl << "***************MENU***************" << endl;
		cout << "1.Wyswietl liste pacjentow." << endl;
		cout << "2.Wyswietl liste pacjentow na oddziale." << endl;
		cout << "3.Wyswietl liste pacjentow przyjetych w dniu." << endl;

		cout << "4.Dodaj Pacjenta" << endl;
		cout << "5.Szukaj Pacjenta" << endl;
		cout << "6.Edytuj Pacjenta" << endl;
		cout << "7.Usun Pacjenta" << endl;

		cout << "8.Wyswietl lekarzy" << endl;
		cout << "9.Wyswietl oddzialy" << endl;
		cout << "10.Wyswietl leki" << endl;
		cout << "11.Wyswietl zabiegi" << endl;

		cout << "12.Dodaj przykladowe dane" << endl;

		cout << "**********************************" << endl;

		cout << "Wybierz: ";
		if (!(cin >> choice)) {
			cerr << "[ERROR] Bledny wybor!";
			exit(0);
		}

		switch (choice)
		{
		case 1:
			PatientList::GetInstance()->ShowPatientList();
			break;
		case 2:
			this->ShowPatientListByWard();
			break;
		case 3:
			this->ShowPatientListByDate();
			break;
		case 4:
			this->AddPatient();
			break;
		case 5:
			this->SearchPatient();
			break;
		case 6:
			this->EditPatient();
			break;
		case 7:
			this->DeletePatient();
			break;
		case 8:
			DoctorList::GetInstance()->ShowDoctorList();
			break;
		case 9:
			WardList::GetInstance()->ShowWardList();
			break;
		case 10:
			DrugList::GetInstance()->ShowDrugList();
			break;
		case 11:
			TreatmentList::GetInstance()->ShowTreatmentList();
			break;
		case 12:
			PatientList::GetInstance()->AddExamplePatients();
			DoctorList::GetInstance()->AddExampleDoctors();
			WardList::GetInstance()->AddExampleWards();
			DrugList::GetInstance()->AddExampleDrug();
			TreatmentList::GetInstance()->AddExampleTreatment();
			break;
		default:
			cout << "[ERROR] Niepoprawny wybor!";
			break;
		}

	} while (true == true);
}

void Menu::ShowPatientListByWard()
{
	int wardId;
	bool wardExist;

	WardList::GetInstance()->ShowWardList();

	cout << endl << "***************Wyswietl pacjentow na oddziale***************" << endl;

	cout << "Podaj id oddzialu: ";
	cin >> wardId;

	wardExist = WardList::GetInstance()->WardExists(wardId);

	if (wardExist) {
		PatientList::GetInstance()->ShowPatientListByWard(wardId);
	}
	else {
		cout << "[ERROR]  Oddzial o podanym id nie istnieje!";
	}
}

void Menu::ShowPatientListByDate()
{
	string data;

	cout << endl << "***************Wyswietl przyjetych w dniu***************" << endl;
	cout << "Podaj date (dd.mm.RRRR): ";
	cin >> data;

	PatientList::GetInstance()->ShowPatientListByDate(data);
}

void Menu::AddPatient()
{
	Patient *patient;
	PatientList *patientList;
	string firstName;
	string lastName;
	string admissionDate;
	int doctorId;
	int wardId;
	bool doctorExist;
	bool wardExist;



	cout << endl << "***************Dodawanie pacjenta***************" << endl;
	cout << "Imie: ";
	cin >> firstName;
	cout << "Nazwisko: ";
	cin >> lastName;
	cout << "Data przyjecia: ";
	cin >> admissionDate;
	cout << "Id lekarza: ";
	cin >> doctorId;
	cout << "Id oddzialu: ";
	cin >> wardId;

	doctorExist = DoctorList::GetInstance()->DoctorExists(doctorId);
	wardExist = WardList::GetInstance()->WardExists(wardId);

	if (doctorExist && wardExist) {

		patientList = PatientList::GetInstance();

		patient = new Patient(patientList->GetNewId(), firstName, lastName, doctorId, wardId, admissionDate);

		patientList->AddPatient(patient);

		cout << "[INFO] Dodano pacjenta" << endl;
	
	}
	else {
		if (!doctorExist) {
			cout << "[ERROR]  Lekarz o podanym id nie istnieje!";
		}

		if (!wardExist) {
			cout << "[ERROR]  oddzial o podanym id nie istnieje!";
		}
	}

}

void Menu::EditPatient()
{
	Patient *foundPatient;
	string firstName;
	string lastName;
	string admissionDate;
	int doctorId;
	int wardId;
	bool doctorExist;
	bool wardExist;

	foundPatient = this->SearchPatient();

	cout << endl << "***************Edytowanie pacjenta***************" << endl;
	cout << "Imie: ";
	cin >> firstName;
	cout << "Nazwisko: ";
	cin >> lastName;
	cout << "Data przyjecia: ";
	cin >> admissionDate;
	cout << "Id lekarza: ";
	cin >> doctorId;
	cout << "Id oddzialu: ";
	cin >> wardId;

	doctorExist = (doctorId != 0) ? DoctorList::GetInstance()->DoctorExists(doctorId) : false;
	wardExist = (wardId != 0) ? WardList::GetInstance()->WardExists(wardId) : false;

	if (firstName != "")
		foundPatient->SetFirstName(firstName);

	if (lastName != "")
		foundPatient->SetLastName(lastName);

	if (admissionDate != "")
		foundPatient->SetAdmissionDate(admissionDate);

	if (doctorExist) {
		foundPatient->SetDoctorId(doctorId);
	}
	else if (doctorId != 0) {
		cout << "[ERROR]  Wprowadzono bledne id lekarza!" << endl;
	}

	if (wardExist) {
		foundPatient->SetWardId(wardId);
	}
	else if (wardId != 0) {
		cout << "[ERROR]  Wprowadzono bledne id oddzialu!" << endl;
	}
}

void Menu::DeletePatient()
{
	Patient *foundPatient;
	PatientList *patientList;

	foundPatient = this->SearchPatient();

	if (foundPatient != nullptr) {
		patientList = PatientList::GetInstance();
		patientList->DeletePatient(foundPatient);
		cout << "Pacjent zostal usuniety";
	}
	else{
		cout << "[ERROR]  Nie udalo sie usunac pacjenta!" << endl;
	}
}

Patient* Menu::SearchPatient()
{
	string firstName;
	string lastName;
	Patient *searchedPatient;
	Patient *foundPatient;
	PatientList *patientList;

	cout << endl << "***************Szukanie pacjenta***************" << endl;
	cout << "Imie: ";
	cin >> firstName;
	cout << "Nazwisko: ";
	cin >> lastName;

	patientList = PatientList::GetInstance();

	searchedPatient = new Patient(0, firstName, lastName, 0, 0, "");

	foundPatient = patientList->SearchPatient(searchedPatient);

	if (foundPatient != nullptr) {
		cout << "[INFO] Znaleziono pacjenta" << endl;
		foundPatient->ShowPatient();
		return foundPatient;
	}
	else {
		cout << "[INFO] Nie znaleziono pacjenta!" << endl;
		return foundPatient;
	}
}