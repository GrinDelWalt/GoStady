#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "�ollege.h"
#include "University.h"


using namespace std;

class Models
{
protected:
	

private:
	void TestModels()
	{
		CreateModelsUniversity("������", "��������", "230�");
		CreateModelsUniversity("���������������", "��������", "230�");
		CreateModelsUniversity("�������������", "��������", "230�");
		CreateModelsUniversity("���������������", "��������", "230�");
		CreateModelsUniversity("���������������", "��������", "230�");
		CreateModelsUniversity("��������", "��������", "230�");

		CreateModelCollege("���������� ����������", "������");
		CreateModelCollege("����������������", "������");
		CreateModelCollege("�����������", "������");
		CreateModelCollege("���������������� ����������", "������");
		CreateModelCollege("�������� ��������������", "������");
		CreateModelCollege("�������������������� � ����������������", "������");
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
		cout << "ID" << setw(30) << "�������� �������� ���������" << endl;
		cout << setw(30) << "���������" << endl << endl;

		for (University univers : _universitys)
		{
			univers.PrintTitle();
		}
		cout << setw(30) << "�������" << endl << endl;

		for (College col : _colleges)
		{
			col.PrintTitle();
		}
	}
	void ChoseInstitution()
	{
		string textID;
		int id;
		cout << "ID �������� ���������" << endl;
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

