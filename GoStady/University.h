#pragma once
#include <iostream>
#include <iomanip>
#include "EducationalInstitution.h"


using namespace std;
class University : public EducationalInstitution
{
private:
	string araayFeatures[5] { "������������� �� ������ �����",
		"�������� �� ������",
		"�������� �� �������� ������� �������", 
		"��������������� �� ������ ����� ������ �������", 
		"������������� � �������� ������ ������ �� �������� ��������������"};
	string araayEntrance[6]{ "���", 
		"������ � ������� ����������� �����������",
		"���������� ��������",
		"���������, �������������� �������������� ����������",
		"�������� � ����������, �������������� ������ ����� �� ����������",
		"������� � ������� ��������" };
	string _admissionRequirement; //���������� ��� �����������
	vector <string> _entrance;
	vector <string> _features;
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
	}
	
};

