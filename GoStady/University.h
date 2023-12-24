#pragma once
#include <iostream>
#include <iomanip>
#include "EducationalInstitution.h"


using namespace std;
class University : public EducationalInstitution
{
private:
	string arrayFeatures[5]{ "������������� �� ������ �����",
		"�������� �� ������",
		"�������� �� �������� ������� �������",
		"��������������� �� ������ ����� ������ �������",
		"������������� � �������� ������ ������ �� �������� ��������������" };
	string arrayEntrance[6]{ "���",
		"������ � ������� ����������� �����������",
		"���������� ��������",
		"���������, �������������� �������������� ����������",
		"�������� � ����������, �������������� ������ ����� �� ����������",
		"������� � ������� ��������" };
	string _admissionRequirement; //���������� ��� �����������

public:
	University()
	{

	}
	University(string title, string category, string admissionRequirement)
		:EducationalInstitution(title, category)
	{
		_title = title;
		_category = category;
		_admissionRequirement = admissionRequirement;

		CreateModels(_entrance, arrayEntrance, sizeof(arrayEntrance) / sizeof(arrayEntrance[0]));
		CreateModels(_features, arrayFeatures, sizeof(arrayFeatures) / sizeof(arrayFeatures[0]));
	}
};

