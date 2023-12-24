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
	string _title; //название
	string _category; //котегория учебного заведения
	vector <Specialties> _specialties; //спецальность
	vector <string> _formTraining; //вид обучения (платный бесплатный)
	vector <string> _formEducation; //форма обучения
	vector <string> _entrance;//требования
	vector <string> _features;//особенности
	int _idSpec{};
	int _position;

	static inline int _staticID;

	string _training[3]{ "Контракт","Бюджет","Целевое обучеение" };
	string _education[3]{ "Дневная","Вечернаяя","Заочная" };
	int NextIdSpec()
	{
		return _idSpec++;
	}
	static int NextID()
	{
		return _staticID++;
	}
	void CreateArayy(vector <string> &vectorForm , string arrayDate[])
	{
			srand(time(0));
		string text;
		for (int i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				vectorForm.push_back(arrayDate[0]);
			}
			if (750 > GetRandomInt(0,1000))
			{
				vectorForm.push_back(arrayDate[i + 1]);
			}
		}
	}
	void CreateModels(vector <string> &array, string arrayData[], int count)
	{
		srand(time(0));
		string text;
		for (int i = 0; i < count-1; i++)
		{
			if (i == 0)
			{
				array.push_back(arrayData[0]);
			}
			if (500 > GetRandomInt(0, 1000))
			{
				array.push_back(arrayData[i + 1]);
			}
		}
	}

public:
	EducationalInstitution() {}
	
	
	EducationalInstitution(string title, string category)
	{
		_title = title;
		_category = category;
		_id = NextID();
		CreateArayy(_formTraining, _training);
		CreateArayy(_formEducation, _education);
		_position = -1;
	}
	bool SearchSpec(int id)
	{
		for (Specialties spec : _specialties)
		{
			if (id == spec.GetId())
			{
				_position = id;
				return true;
			}
		}
		return false;
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
	void PrintAll()
	{
		cout << "Название: " << _title << endl;
		cout << "Виды обучения: ";
		for (int i = 0; i < _formTraining.size(); i++)
		{
			cout << " " << _formTraining[i];
			if (i != _formTraining.size()-1)
			{
				cout << ",";
			}
		}
		cout << "\nФорма обучения: ";
		for (int i = 0; i < _formEducation.size(); i++)
		{
			cout << " " << _formEducation[i];
			if (i != _formTraining.size() - 1)
			{
				cout << ",";
			}
		}
		cout << "\nИнформация о направлениях" << endl;
		PrintSpec();
		cout << endl << endl;
	}
	void PrintSpec()
	{
		cout << setw(30) << "Спецальность" << setw(20) << "Форма обучения" << setw(30) << "Направление обучения" << setw(10) << "Стоимость" << endl;
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
	void PrintEntrance() //печать требований для поступления
	{
		cout << endl;
		cout << "Требования для поступления" << endl << endl;
		for (string text : _entrance)
		{
			cout << text << endl;
		}
	}
	void PrintFeatures()
	{
		cout << endl;
		cout << "Особености обучения" << endl << endl;
		for (string text : _features)
		{
			cout << text << endl;
		}
	}
};
