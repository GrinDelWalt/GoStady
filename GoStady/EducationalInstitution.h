#pragma once
#include "Specialties.h"
#include <iostream>
#include <vector>
#include <random>
#include <string>


using namespace std;

class EducationalInstitution
{
protected:
	int _id; //ID
	string _title; //название
	string _category; //котегория учебного заведения
	vector <string> _formTraining; //вид обучения (платный бесплатный)
	vector <string> _formEducation; //форма обучения
	static inline int _staticID;
	vector <Specialties> _specialties; //спецальность

	string _training[3]{ "Контракт","Бюджет","Целевое обучеенеи" };
	string _education[3]{ "Дневная","Вечернаяя","Заочная" };

	static int NextID()
	{
		return _staticID++;
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
	EducationalInstitution(string title, string category)
	{
		_title = title;
		_category = category;
		_id = NextID();
		CreateArayy(_formTraining, _training);
		CreateArayy(_formEducation, _education);
	}
	void CreateSpecialties(string specialties, string formEducation, string direction, int salary)
	{
		_specialties.push_back(*new Specialties(specialties, formEducation, direction, salary));
	}
	string GeTitle()
	{
		return _title;
	}
	string GetCategory()
	{
		return _category;
	}
};
