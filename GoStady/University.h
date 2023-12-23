#pragma once
#include <iostream>
#include <iomanip>
#include "EducationalInstitution.h"


using namespace std;
class University : public EducationalInstitution
{
private:
	string araayFeatures[5] { "Преподаватели из других стран",
		"Обучение по обмену",
		"Практика на реальных рабочих задачах", 
		"Трудоустройство на работу после защиты диплома", 
		"Преподователи с реальным опытом работы по основным специальностям"};
	string araayEntrance[6]{ "ЕГЭ", 
		"Диплом о среднем специальном оброзовании",
		"Медицинска коммисия",
		"документы, подтверждающие индивидуальные достижения",
		"сведения о документах, подтверждающих особые права на зачисление",
		"договор о целевом обучении" };
	string _admissionRequirement; //требование для поступление
	vector <string> _entrance;
	vector <string> _features;
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
	}
	
};

