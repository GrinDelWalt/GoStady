#pragma once
#include <iomanip>
#include <iostream>

using namespace std;

class Specialties
{
private:
	int _id;
	string _specialties; //спецальность
	string _formEducation; //форма обучение
	string _direction; //Ќаправление
	int _salary;
	

public:
	Specialties(string specialties, string formEducation, string direction, int salary, int id)
	{
		_id = id;
		_specialties = specialties;
		_formEducation = formEducation;
		_direction = direction;
		_salary = salary;
	}
	Specialties()
	{

	}

	void Print()
	{
		cout << _id <<setw(30) << _specialties << setw(20) << _formEducation << setw(30) << _direction << setw(10) << _salary << endl;
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
	int GetId()
	{
		return _id;
	}
	string GetFormEducation()
	{
		return _formEducation;
	}

};

