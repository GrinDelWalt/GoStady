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
		CreateModelsUniversity("Горный", "Институт", "230б");
		CreateModelsUniversity("Железнодорожный", "Институт", "230б");
		CreateModelsUniversity("Архитектурный", "Институт", "230б");
		CreateModelsUniversity("Телекомуникаций", "Институт", "230б");
		CreateModelsUniversity("Полетехнический", "Институт", "230б");
		CreateModelsUniversity("Аграрный", "Институт", "230б");

		CreateModelCollege("Отраслевых технологий", "Коледж");
		CreateModelCollege("Фармацевтический", "Коледж");
		CreateModelCollege("Медицинский", "Коледж");
		CreateModelCollege("Железнодорожного транспорта", "Коледж");
		CreateModelCollege("Академия машиностроения", "Коледж");
		CreateModelCollege("Энергомашиностроения и металлообработки", "Коледж");
	}
public:
	College* _college;
	University* _university;
	vector <University> _universitys;
	vector <College> _colleges;
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
	}
	void ChoseInstitution()
	{
		string textID;
		int id;
		cout << "ID Учебного заведения" << endl;
		cin >> textID;
		id = stoi(textID); 
		for (University univers : _universitys)
		{
			if (univers.GetID() == id)
			{
			}
		}
		for (College col : _colleges)
		{
			_college = new College(col);
		}
	}

};

