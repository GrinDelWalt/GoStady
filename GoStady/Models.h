#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "Сollege.h"
#include "University.h"


using namespace std;

class Models
{
protected:


private:
	void TestModels()
	{
		string education[]{ "Дневная", "Вечерняя", "Заочная" };
		CreateModelsUniversity("Горный", "Институт", "230б");
		CreateModelsUniversity("Железнодорожный", "Институт", "230б");
		CreateModelsUniversity("Архитектурный", "Институт", "230б");
		CreateModelsUniversity("Полетехнический", "Институт", "230б");
		CreateModelsUniversity("Аграрный", "Институт", "230б");

		CreateModelCollege("Отраслевых технологий", "Коледж");
		CreateModelCollege("Фармацевтический", "Коледж");
		CreateModelCollege("Медицинский", "Коледж");
		CreateModelCollege("Железнодорожного транспорта", "Коледж");
		CreateModelCollege("Академия машиностроения", "Коледж");

		for (University& univers : _universitys)
		{
			univers.CreateSpecialties("ПГС", education[univers.GetRandomInt(0, 2)], "Строительство", univers.GetRandomInt(50000, 500000));
			univers.CreateSpecialties("Экономист", education[univers.GetRandomInt(0, 2)], "Эконика", univers.GetRandomInt(50000, 500000));
			univers.CreateSpecialties("Управление и менеджмент", education[univers.GetRandomInt(0, 2)], "Факультет социальных наук", univers.GetRandomInt(50000, 500000));

		}
		for (College& col : _colleges)
		{
			col.CreateSpecialties("Финансы", education[col.GetRandomInt(0, 2)], "Экономика", col.GetRandomInt(30000, 200000));
			col.CreateSpecialties("Юриспруденция", education[col.GetRandomInt(0, 2)], "Право", col.GetRandomInt(30000, 200000));
			col.CreateSpecialties("Информационное моделирование", education[col.GetRandomInt(0, 2)], "Вычислительная техника", col.GetRandomInt(30000, 200000));
		}
	}
	vector <University> _universitys;
	vector <College> _colleges;
	bool _univers;
public:
	College* _college;
	University* _university;
	Models()
	{
		TestModels();
	}
	void CreateModelsUniversity(string title, string category, string admissionRequirement)
	{
		_universitys.push_back(*new University(title, category, admissionRequirement));
	}
	void CreateModelCollege(string title, string category)
	{
		_colleges.push_back(*new College(title, category));
	}
	void PrintInstitution()
	{
		do
		{
			cout << "ID" << setw(30) << "Название учебного заведения" << endl;
			cout << setw(30) << "Институты" << endl << endl;

			for (University univers : _universitys)
			{
				univers.PrintTitle();
			}
			cout << setw(30) << "Коледжи" << endl << endl;

			for (College col : _colleges)
			{
				col.PrintTitle();
			}
		} while (ChoseInstitution());
	}
	bool ChoseInstitution()
	{
		bool result;
		string textID;
		int id;
		cout << "ID Учебного заведения" << endl;
		cin >> textID;
		id = stoi(textID);
		for (University univers : _universitys)
		{
			if (univers.GetID() == id)
			{
				_university = new University(univers);
				PrintSpecialties(univers);
			}
		}
		for (College col : _colleges)
		{
			if (col.GetID() == id)
			{
				_college = new College(col);
				PrintSpecialties(col);
			}
		}
	}
	bool PrintSpecialties(College model)
	{
		model.PrintSpec();
		_univers = false;
	}
	bool PrintSpecialties(University model)
	{
		model.PrintSpec();
		_univers = true;

	}
	int ChoiceSpecialties()
	{
		char choise;
		int position;
		cout << "Выбрать спецальность? y/n: ";
		cin >> choise;
		if (choise == 'y')
		{
			cin >> position;
		}
	}
};

