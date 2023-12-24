#pragma once
#include <iostream>
#include <vector>
#include "Сollege.h"
#include "University.h"
#include "Specialties.h"
#include <fstream>
using namespace std;

class WritingFile
{
public:
	void WriteResult(University univers)
	{
		vector <string> texts;
		ofstream tofile("result.txt");

		tofile << "Название: " << univers.GeTitle() << endl;
		tofile << "Виды обучения: " << univers.GetSpecialties(univers.GetPosition()).GetFormEducation() << endl;
		tofile << "Специальность: " << univers.GetSpecialties(univers.GetPosition()).GetSpecialties() << endl;
		tofile << "Стоимость: " << univers.GetSpecialties(univers.GetPosition()).GetSalary() << endl;
		tofile << "Мимимальный бал за ЕГЭ: " << univers.GetAdmissionRequirement() << endl;
		tofile << endl;
		tofile << "Особености обучения" << endl << endl;
		texts = univers.GetFeatures();
		for (int i = 0; i < texts.size(); i++)
		{
			tofile << texts[i] << endl;
		}
		texts = univers.GetEntrance();
		tofile << endl;
		tofile << "Требования для поступления" << endl << endl;
		for (int i = 0; i < texts.size(); i++)
		{
			tofile << texts[i] << endl;
		}
		tofile.close();
	}
	void WriteUniversity(vector <University> universitys)
	{
		vector <string> texts;
		ofstream tofile("colleges.txt");

		for (University univ : universitys)
		{
			tofile << "ID: " << univ.GetID() << endl;
			tofile << "Название: " << univ.GeTitle() << endl;
			tofile << "Мимимальный бал за ЕГЭ: " << univ.GetAdmissionRequirement() << endl;
			tofile << "Виды обучения: ";
			
			texts = univ.GetFormTraining();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << " " << texts[i];
				if (i != texts.size() - 1)
				{
					tofile << ",";
				}
			}
			tofile << "\nФорма обучения: ";

			texts = univ.GetFormEducation();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << " " << texts[i];
				if (i != texts.size() - 1)
				{
					tofile << ",";
				}
			}
			tofile << endl;
			tofile << "Требования для поступления" << endl << endl;

			texts = univ.GetEntrance();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << texts[i] << endl;
			}
			tofile << endl;
			tofile << "Особености обучения" << endl << endl;

			texts = univ.GetFeatures();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << texts[i] << endl;
			}
			tofile << setw(30) << "Спецальность" << setw(20) << "Форма обучения" << setw(30) << "Направление обучения" << setw(10) << "Стоимость" << endl;

			vector <Specialties> specVector = univ.GetSpecialtiesVector();

			for (Specialties spec : specVector)
			{
				tofile << spec.GetId() << setw(30) << spec.GetSpecialties() << setw(20) << spec.GetFormEducation() << setw(30) << spec.GetDirection() << setw(10) << spec.GetSalary() << endl;
			}
			tofile << endl << endl << endl << endl;
		}
			tofile.close();
	}
	void WriteColleg(vector <College> colleges)
	{
		vector <string> texts;
		ofstream tofile("colleges.txt");

		for (College col : colleges)
		{
			tofile << "ID: " << col.GetID() << endl;
			tofile << "Название: " << col.GeTitle() << endl;
			tofile << "Мимимальный среднйи бал: " << col.GetAverageScore() << endl;
			tofile << "Виды обучения: ";

			texts = col.GetFormTraining();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << " " << texts[i];
				if (i != texts.size() - 1)
				{
					tofile << ",";
				}
			}
			tofile << "\nФорма обучения: ";

			texts = col.GetFormEducation();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << " " << texts[i];
				if (i != texts.size() - 1)
				{
					tofile << ",";
				}
			}
			tofile << endl;
			tofile << "Требования для поступления" << endl << endl;

			texts = col.GetEntrance();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << texts[i] << endl;
			}
			tofile << endl;
			tofile << "Особености обучения" << endl << endl;

			texts = col.GetFeatures();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << texts[i] << endl;
			}
			tofile << setw(30) << "Спецальность" << setw(20) << "Форма обучения" << setw(30) << "Направление обучения" << setw(10) << "Стоимость" << endl;

			vector <Specialties> specVector = col.GetSpecialtiesVector();

			for (Specialties spec : specVector)
			{
				tofile << spec.GetId() << setw(30) << spec.GetSpecialties() << setw(20) << spec.GetFormEducation() << setw(30) << spec.GetDirection() << setw(10) << spec.GetSalary() << endl;
			}
			tofile << endl << endl << endl << endl;
		}
			tofile.close();
	}
};


