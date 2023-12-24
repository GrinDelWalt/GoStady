#pragma once
#include <iostream>
#include <vector>
#include "�ollege.h"
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

		tofile << "��������: " << univers.GeTitle() << endl;
		tofile << "���� ��������: " << univers.GetSpecialties(univers.GetPosition()).GetFormEducation() << endl;
		tofile << "�������������: " << univers.GetSpecialties(univers.GetPosition()).GetSpecialties() << endl;
		tofile << "���������: " << univers.GetSpecialties(univers.GetPosition()).GetSalary() << endl;
		tofile << "����������� ��� �� ���: " << univers.GetAdmissionRequirement() << endl;
		tofile << endl;
		tofile << "���������� ��������" << endl << endl;
		texts = univers.GetFeatures();
		for (int i = 0; i < texts.size(); i++)
		{
			tofile << texts[i] << endl;
		}
		texts = univers.GetEntrance();
		tofile << endl;
		tofile << "���������� ��� �����������" << endl << endl;
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
			tofile << "��������: " << univ.GeTitle() << endl;
			tofile << "����������� ��� �� ���: " << univ.GetAdmissionRequirement() << endl;
			tofile << "���� ��������: ";
			
			texts = univ.GetFormTraining();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << " " << texts[i];
				if (i != texts.size() - 1)
				{
					tofile << ",";
				}
			}
			tofile << "\n����� ��������: ";

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
			tofile << "���������� ��� �����������" << endl << endl;

			texts = univ.GetEntrance();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << texts[i] << endl;
			}
			tofile << endl;
			tofile << "���������� ��������" << endl << endl;

			texts = univ.GetFeatures();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << texts[i] << endl;
			}
			tofile << setw(30) << "������������" << setw(20) << "����� ��������" << setw(30) << "����������� ��������" << setw(10) << "���������" << endl;

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
			tofile << "��������: " << col.GeTitle() << endl;
			tofile << "����������� ������� ���: " << col.GetAverageScore() << endl;
			tofile << "���� ��������: ";

			texts = col.GetFormTraining();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << " " << texts[i];
				if (i != texts.size() - 1)
				{
					tofile << ",";
				}
			}
			tofile << "\n����� ��������: ";

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
			tofile << "���������� ��� �����������" << endl << endl;

			texts = col.GetEntrance();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << texts[i] << endl;
			}
			tofile << endl;
			tofile << "���������� ��������" << endl << endl;

			texts = col.GetFeatures();

			for (int i = 0; i < texts.size(); i++)
			{
				tofile << texts[i] << endl;
			}
			tofile << setw(30) << "������������" << setw(20) << "����� ��������" << setw(30) << "����������� ��������" << setw(10) << "���������" << endl;

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


