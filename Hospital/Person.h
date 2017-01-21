#pragma once
#include <string>

using namespace std;

class Person
{
public:
	Person(int id, string firstName, string lastName);
	~Person();

	void SetFirstName(string firstName);
	void SetLastName(string lastName);

	int getId();
	string getFirstName();
	string getLastName();

private:
	int id;
	string firstName;
	string lastName;



};

