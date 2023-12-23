#pragma once
#include "Specialties.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <string>


using namespace std;

class EducationalInstitution
{
protected:
	int _id; //ID
	string _title; //��������
	string _category; //��������� �������� ���������
	vector <string> _formTraining; //��� �������� (������� ����������)
	vector <string> _formEducation; //����� ��������
	static inline int _staticID;
	int _idSpec{};
	vector <Specialties> _specialties; //������������
	int _position;

	string _training[3]{ "��������","������","������� ���������" };
	string _education[3]{ "�������","���������","�������" };
	int NextIdSpec()
	{
		return _idSpec++;
	}
	static int NextID()
	{
		return _staticID++;
	}
	void CreateArayy(vector <string> vectorForm , string arrayDate[])
	{
		string text;
		for (int i = 0; i < 2; i++)
		{
			srand(time(0));
			if (i == 0)
			{
				vectorForm.push_back(arrayDate[0]);
			}
			else if (750 > GetRandomInt(0,1000))
			{
				vectorForm.push_back(arrayDate[i + 1]);
			}
		}
	}

public:
	EducationalInstitution()
	{

	}
	
	EducationalInstitution(string title, string category)
	{
		_title = title;
		_category = category;
		_id = NextID();
		CreateArayy(_formTraining, _training);
		CreateArayy(_formEducation, _education);
	}
	bool SearchSpec(int id)
	{
		for (Specialties spec : _specialties)
		{
			if (id = spec.GetId())
			{
				_position = id;
			}
		}
	}
	int GetRandomInt(int min, int max)
	{
		static random_device rd;
		static mt19937 generator(rd());
		uniform_int_distribution<int> distribution(min, max);

		int randomValue;

		randomValue = distribution(generator);

		return randomValue;
	}
	void CreateSpecialties(string specialties, string formEducation, string direction, int salary)
	{
		_specialties.push_back(*new Specialties(specialties, formEducation, direction, salary, NextIdSpec()));
	}
	string GeTitle()
	{
		return _title;
	}
	string GetCategory()
	{
		return _category;
	}
	void PrintTitle()
	{
		cout << _id << setw(50) << _title << endl;
	}
	void PrintSpec()
	{
		cout << setw(30) << "������������" << setw(20) << "����� ��������" << setw(30) << "����������� ��������" << setw(10) << "���������" << endl;
		for (Specialties spec : _specialties)
		{
			spec.Print();
		}
	}
	void SetPosition(int id)
	{
		_position = id;
	}
	int GetID()
	{
		return _id;
	}
};
