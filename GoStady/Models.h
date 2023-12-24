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
		CreateModelsUniversity("Горный", "Институт", "260б");
		CreateModelsUniversity("Железнодорожный", "Институт", "210б");
		CreateModelsUniversity("Архитектурный", "Институт", "230б");
		CreateModelsUniversity("Полетехнический", "Институт", "270б");
		CreateModelsUniversity("Аграрный", "Институт", "220б");

		CreateModelCollege("Отраслевых технологий", "Коледж", "4.8");
		CreateModelCollege("Фармацевтический", "Коледж", "4.5");
		CreateModelCollege("Медицинский", "Коледж", "4.2");
		CreateModelCollege("Железнодорожного транспорта", "Коледж", "4.0");
		CreateModelCollege("Академия машиностроения", "Коледж", "4.1");

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
	bool result;
public:
	College* _college;
	University* _university;
	Models()
	{
		result = false;
		TestModels();
	}
	void PrintEntrance()
	{
		if (_univers)
		{
			_university->PrintEntrance();
		}
		else
		{
			_college->PrintEntrance();
		}
	}
	void PrintFeatures()
	{
		if (_univers)
		{
			_university->PrintFeatures();
		}
		else
		{
			_college->PrintFeatures();
		}
	}
	bool GetResult()
	{
		return result;
	}

	void PrintAll()
	{
		//cout << "ID" << setw(50) << "Название учебного заведения" << endl << endl;
		for (College col : _colleges)
		{
			col.PrintAll();
		}
		for (University univ : _universitys)
		{
			univ.PrintAll();
		}
		system("pause");

	}
	void ClearResult()
	{
		if (result)
		{
			if (_univers)
			{
				delete _university;
			}
			else
			{
				delete _college;
			}
			result = false;
			cout << "Данные очищенны" << endl;
		}
		else
		{
			cout << "Буфер пуст!" << endl;
		}
		system("pause");

	}
	void CreateModelsUniversity(string title, string category, string admissionRequirement)
	{
		_universitys.push_back(*new University(title, category, admissionRequirement));
	}
	void CreateModelCollege(string title, string category, string averageScore)
	{
		_colleges.push_back(*new College(title, category, averageScore));
	}
	void PrintInstitution()
	{
		char choise;
		if (result)
		{
			cout << "В буфере храняться данные вуза, удалить? y/n: ";
			cin >> choise;
			if (choise == 'y')
			{
				result = false;
			}
		}
		while (result == false)
		{
			cout << "ID" << setw(50) << "Название учебного заведения" << endl << endl;
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
			ChoseInstitution();
		}
	}
	void ChoseInstitution()
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
				PrintSpecialties(*_university);
			}
		}
		for (College col : _colleges)
		{
			if (col.GetID() == id)
			{
				_college = new College(col);
				PrintSpecialties(*_college);
			}
		}
	}
	void PrintSpecialties(College model)
	{
		model.PrintSpec();
		_univers = false;
		char choise;
		int position;
		cout << "Выбрать спецальность? y/n: ";
		cin >> choise;
		if (choise == 'y')
		{
			cout << "Выберете ID: ";
			cin >> position;

			if (model.SearchSpec(position))
			{
				result = true;
				model.SetPosition(position);
			}
			else
			{
				system("cls");
				cout << "Неверный ID" << endl;
				result = false;
			}
		}
		else
		{
			system("cls");
			cout << "неверный выбор" << endl;
			result = false;
		}
	}
	void PrintSpecialties(University& model)
	{
		model.PrintSpec();
		_univers = true;
		char choise;
		int position;
		cout << "Выбрать спецальность? y/n: ";
		cin >> choise;
		if (choise == 'y')
		{
			cout << "Выберете ID: ";

			cin >> position;

			if (model.SearchSpec(position))
			{
				model.SetPosition(position);
				result = true;
			}
			else
			{
				system("cls");
				cout << "Неверный ID" << endl;
				result = false;
			}
		}
		else
		{
			system("cls");
			cout << "неверный выбор" << endl;
			result = false;
		}
	}
	void Result()
	{
		if (result)
		{

			if (_univers)
			{
				_university->Print();
			}
			else
			{
				_college->Print();
			}
		}
		else
		{
			cout << "Нечего не выбрано!" << endl;
		}
	}
};

