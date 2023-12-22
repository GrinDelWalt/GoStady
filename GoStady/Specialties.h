#pragma once

#include <iostream>

using namespace std;

class Specialties
{
private:
	string _specialties; //������������
	string _formEducation; //����� ��������
	string _direction; //�����������
	int _salary;

public:
	Specialties(string specialties, string formEducation, string direction, int salary)
	{
		_specialties = specialties;
		_formEducation = formEducation;
		_direction = direction;
		_salary = salary;
	}
	Specialties()
	{

	}
	string GetDirection()
	{
		return _direction;
	}
	string GetSpecialties()
	{
		return _specialties;
	}
	int GetSalary()
	{
		return _salary;
	}
	string GetFormEducation()
	{
		return _formEducation;
	}

};

