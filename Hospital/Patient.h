#include "Person.h"
#include "Service.h"
#include <string>
#include <vector>

using namespace std;

using namespace std;

class Patient
	: public Person
{
public:
	Patient(int id, string firstName, string lastName, int doctorId, int wardId, string admissionDate) ;
	~Patient();

	void ShowPatient();

	void SetAdmissionDate(string admissionDate);
	void SetDoctorId(int doctorId);
	void SetWardId(int wardId);

	string getAdmissionDate();
	int GetWardId();

private:
	int doctorId;
	int wardId;
	string admissionDate;

	vector < Service* > drugList;
	vector < Service* > treatmentList;
};

