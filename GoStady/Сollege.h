#pragma once
#include <iostream>
#include "EducationalInstitution.h"


using namespace std;

class College : public EducationalInstitution
{
private:
	string arrayFeatures[5]{ "�������������� ���������� � ���",
		"�������� � �������� �������������",
		"�������� �� �������� ������� �������",
		"��������������� �� ������ ����� ������ �������",
		"������������� � �������� ������ ������ �� �������� ��������������" };
	string arrayEntrance[5]{ "�������",
		"���������� ��������",
		"���������, �������������� �������������� ����������",
		"�������� � ����������, �������������� ������ ����� �� ����������",
		"������� � ������� ��������" };

public:
	College() {}
	College(string title, string category)
		:EducationalInstitution(title, category)
	{
		CreateModels(_entrance, arrayEntrance, sizeof(arrayEntrance) / sizeof(arrayEntrance[0]));
		CreateModels(_features, arrayFeatures, sizeof(arrayFeatures) / sizeof(arrayFeatures[0]));
	}
};

