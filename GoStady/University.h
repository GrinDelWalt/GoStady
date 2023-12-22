#pragma once
#include <iostream>
#include <iomanip>
#include "EducationalInstitution.h"


using namespace std;
class University : EducationalInstitution
{
private:
	string _admissionRequirement; //требование для поступление
public:

	University(string title, string category, string admissionRequirement)
		:EducationalInstitution(title, category)
	{
		_title = title;
		_category = category;
		_admissionRequirement = admissionRequirement;
	}
	void PrintTitle()
	{
		cout << _id << setw(30) << _title << endl;
	}
};

