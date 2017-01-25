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
		cout << "6.Podlicz Pacjenta" << endl;
		cout << "7.Edytuj Pacjenta" << endl;
		cout << "8.Usun Pacjenta" << endl;

		cout << "9.Wyswietl lekarzy" << endl;
		cout << "10.Wyswietl oddzialy" << endl;
		cout << "11.Wyswietl leki" << endl;
		cout << "12.Wyswietl zabiegi" << endl;

		cout << "13.Dodaj przykladowe dane" << endl;

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
			this->ShowPatientDue();
			break;
		case 7:
			this->EditPatientMenu();
			break;
		case 8:
			this->DeletePatient();
			break;
		case 9:
			DoctorList::GetInstance()->ShowDoctorList();
			break;
		case 10:
			WardList::GetInstance()->ShowWardList();
			break;
		case 11:
			DrugList::GetInstance()->ShowDrugList();
			break;
		case 12:
			TreatmentList::GetInstance()->ShowTreatmentList();
			break;
		case 13:
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

void Menu::ShowPatientDue()
{

	int choice;
	Patient *foundPatient;

	foundPatient = this->SearchPatient();

	if (foundPatient != nullptr) {
		cout << endl << "***************NALEZNOSC PACJENTA***************" << endl;
		cout << "Pacjent powienien zaplacic: " << foundPatient->GetDue() << endl << endl;
	}
}

void Menu::EditPatientMenu()
{
	int choice;
	Patient *foundPatient;

	foundPatient = this->SearchPatient();

	if (foundPatient != nullptr) {
		
		cout << endl << "***************EDYCJA PACJENTA***************" << endl;
		cout << "1.Edytuj Dane pacjenta." << endl;
		cout << "2.Dodaj lek." << endl;
		cout << "3.Dodaj zabieg." << endl;

		cout << "Wybierz: ";
		if (!(cin >> choice)) {
			cerr << "[ERROR] Bledny wybor!";
			exit(0);
		}

		switch (choice) {

		case 1:
			this->EditPatient(foundPatient);
			break;
		case 2:
			this->EditPatientAdDrug(foundPatient);
			break;
		case 3:
			this->EditPatientAdTreatment(foundPatient);
			cout << "[ERROR] Niepoprawny wybor!";
		default:
			cout << "[ERROR] Niepoprawny wybor!";
			break;
		}
	}

}

void Menu::EditPatientAdDrug(Patient *foundPatient)
{
	int drugId;
	bool result;

	DrugList::GetInstance()->ShowDrugList();

	cout << "Dodaj lek o id: ";
	cin >> drugId;

	result = foundPatient->AddDrug(drugId);

	if (result) {
		cout << "[INFO] Dodano lek" << endl;
	}
	else {
		cout << "[ERROR] Dodawanie lek nie powiodlo sie" << endl;
	}
}

void Menu::EditPatientAdTreatment(Patient *foundPatient)
{
	int treatmentId;
	bool result;

	TreatmentList::GetInstance()->ShowTreatmentList();

	cout << "Dodaj zabieg o id: ";
	cin >> treatmentId;

	result = foundPatient->AddTreatment(treatmentId);

	if (result) {
		cout << "[INFO] Dodano zabieg" << endl;
	}
	else {
		cout << "[ERROR] Dodawanie zabiegu nie powiodlo sie" << endl;
	}
}

void Menu::EditPatient(Patient *foundPatient)
{
	int wardId;
	int doctorId;
	bool doctorExist;
	bool wardExist;
	string firstName;
	string lastName;
	string admissionDate;

	cout << endl << "***************Edytowanie danych***************" << endl;


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
	PatientList *patientList;
	Patient *foundPatient;

	foundPatient = this->SearchPatient();

	if (foundPatient != nullptr) {
		patientList = PatientList::GetInstance();
		patientList->DeletePatient(foundPatient);
		cout << "[INFO] Pacjent zostal usuniety";
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