#pragma once
#include "Ward.h"
#include <vector>

using namespace std;

class WardList
{
public:
	WardList();
	~WardList();

	static WardList* GetInstance();

	void AddExampleWards();
	void ShowWardList();
	bool WardExists(int id);

private:
	static WardList *instance;
	vector < Ward* > wardList;
};

