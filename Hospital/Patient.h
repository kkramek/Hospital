#include "Person.h"
#include "Service.h"
#include "DoctorList.h"
#include "WardList.h"
#include "DrugList.h"
#include "TreatmentList.h"
#include <string>
#include <vector>

using namespace std;

class Patient
	: public Person
{
public:
	Patient(int id, string firstName, string lastName, int doctorId, int wardId, string admissionDate) ;
	~Patient();

	void ShowPatient();
	void EditPatient();

	void SetAdmissionDate(string admissionDate);
	void SetDoctorId(int doctorId);
	void SetWardId(int wardId);

	string getAdmissionDate();
	int GetWardId();
	double GetDue();

	bool AddDrug(int drugId);
	bool AddTreatment(int treatmentId);

private:
	int doctorId;
	int wardId;
	string admissionDate;

	vector < Service* > drugList;
	vector < Service* > treatmentList;
};

