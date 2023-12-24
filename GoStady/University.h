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
	void Print()
	{
		cout << "��������: " << _title << endl;
		cout << "���� ��������: " << _specialties[_position].GetFormEducation() << endl;
		cout << "�������������: " << _specialties[_position].GetSpecialties() << endl;
		cout << "���������: " << _specialties[_position].GetSalary() << endl;
		cout << "����������� ��� �� ���: " << _admissionRequirement << endl;
		PrintEntrance();
		PrintFeatures();
	}
};

