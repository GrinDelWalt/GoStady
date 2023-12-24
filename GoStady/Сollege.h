#pragma once
#include <iostream>
#include "EducationalInstitution.h"


using namespace std;

class College : public EducationalInstitution
{
private:
	string arrayFeatures[5]{ "Автоматическое зачисление в ВУЗ",
		"Практика у реальных работадателей",
		"Практика на реальных рабочих задачах",
		"Трудоустройство на работу после защиты диплома",
		"Преподователи с реальным опытом работы по основным специальностям" };
	string arrayEntrance[5]{ "Атестат",
		"Медицинска коммисия",
		"документы, подтверждающие индивидуальные достижения",
		"сведения о документах, подтверждающих особые права на зачисление",
		"договор о целевом обучении" };
	string _averageScore;
public:
	College() {}
	College(string title, string category, string averageScore)
		:EducationalInstitution(title, category)
	{
		_averageScore = averageScore;
		CreateModels(_entrance, arrayEntrance, sizeof(arrayEntrance) / sizeof(arrayEntrance[0]));
		CreateModels(_features, arrayFeatures, sizeof(arrayFeatures) / sizeof(arrayFeatures[0]));
	}
	void Print()
	{
		cout << "Название: " << _title << endl;
		cout << "Виды обучения: " << _specialties[_position].GetFormEducation() << endl;
		cout << "Специальность: " << _specialties[_position].GetSpecialties() << endl;
		cout << "Стоимость: " << _specialties[_position].GetSalary() << endl;
		cout << "Мимимальный среднйи бал : " << _averageScore << endl;
		PrintEntrance();
		PrintFeatures();
	}
};

