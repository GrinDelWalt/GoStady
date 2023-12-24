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
	string _averageScore;
public:
	College() {}
	College(string title, string category, string averageScore)
		:EducationalInstitution(title, category)
	{
		_averageScore = averageScore;
		CreateModels(_entrance, arrayEntrance, sizeof(arrayEntrance) / sizeof(arrayEntrance[0]));
		CreateModels(_features, arrayFeatures, sizeof(arrayFeatures) / sizeof(arrayFeatures[0]));
	}
	void Print()
	{
		cout << "��������: " << _title << endl;
		cout << "���� ��������: " << _specialties[_position].GetFormEducation() << endl;
		cout << "�������������: " << _specialties[_position].GetSpecialties() << endl;
		cout << "���������: " << _specialties[_position].GetSalary() << endl;
		cout << "����������� ������� ��� : " << _averageScore << endl;
		PrintEntrance();
		PrintFeatures();
	}
};

