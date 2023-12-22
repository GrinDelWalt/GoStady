#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
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
	vector <University> _universitys;
	vector <Сollege> _colleges;
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
		_colleges.push_back(*new Сollege(title, category));
	}
	void PrintInstitution()
	{
		cout << "ID" << setw(30) << "Название учебного заведения" << endl;

		for (University univers : _universitys)
		{
			univers.PrintTitle();
		}
	}
};

