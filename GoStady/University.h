#pragma once
#include <iostream>
#include <iomanip>
#include "EducationalInstitution.h"


using namespace std;
class University : public EducationalInstitution
{
private:
	string arrayFeatures[5]{ "Преподаватели из других стран",
		"Обучение по обмену",
		"Практика на реальных рабочих задачах",
		"Трудоустройство на работу после защиты диплома",
		"Преподователи с реальным опытом работы по основным специальностям" };
	string arrayEntrance[6]{ "ЕГЭ",
		"Диплом о среднем специальном оброзовании",
		"Медицинска коммисия",
		"документы, подтверждающие индивидуальные достижения",
		"сведения о документах, подтверждающих особые права на зачисление",
		"договор о целевом обучении" };
	string _admissionRequirement; //требование для поступление

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

		CreateModels(_entrance, arrayEntrance, sizeof(arrayEntrance) / sizeof(arrayEntrance[0]));
		CreateModels(_features, arrayFeatures, sizeof(arrayFeatures) / sizeof(arrayFeatures[0]));
	}
	void Print()
	{
		cout << "Название: " << _title << endl;
		cout << "Виды обучения: " << _specialties[_position].GetFormEducation() << endl;
		cout << "Специальность: " << _specialties[_position].GetSpecialties() << endl;
		cout << "Стоимость: " << _specialties[_position].GetSalary() << endl;
		cout << "Мимимальный бал за ЕГЭ: " << _admissionRequirement << endl;
		PrintEntrance();
		PrintFeatures();
	}
};

