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
		string education[]{ "�������", "��������", "�������" };
		CreateModelsUniversity("������", "��������", "230�");
		CreateModelsUniversity("���������������", "��������", "230�");
		CreateModelsUniversity("�������������", "��������", "230�");
		CreateModelsUniversity("���������������", "��������", "230�");
		CreateModelsUniversity("��������", "��������", "230�");

		CreateModelCollege("���������� ����������", "������");
		CreateModelCollege("����������������", "������");
		CreateModelCollege("�����������", "������");
		CreateModelCollege("���������������� ����������", "������");
		CreateModelCollege("�������� ��������������", "������");

		for (University& univers : _universitys)
		{
			univers.CreateSpecialties("���", education[univers.GetRandomInt(0, 2)], "�������������", univers.GetRandomInt(50000, 500000));
			univers.CreateSpecialties("���������", education[univers.GetRandomInt(0, 2)], "�������", univers.GetRandomInt(50000, 500000));
			univers.CreateSpecialties("���������� � ����������", education[univers.GetRandomInt(0, 2)], "��������� ���������� ����", univers.GetRandomInt(50000, 500000));

		}
		for (College& col : _colleges)
		{
			col.CreateSpecialties("�������", education[col.GetRandomInt(0, 2)], "���������", col.GetRandomInt(30000, 200000));
			col.CreateSpecialties("�������������", education[col.GetRandomInt(0, 2)], "�����", col.GetRandomInt(30000, 200000));
			col.CreateSpecialties("�������������� �������������", education[col.GetRandomInt(0, 2)], "�������������� �������", col.GetRandomInt(30000, 200000));
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
	void PrintAll()
	{
		//cout << "ID" << setw(50) << "�������� �������� ���������" << endl << endl;
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
				_university->SetPosition(-1);
			}
			else
			{
				_college->SetPosition(-1);
			}
			result = false;
			cout << "������ ��������" << endl;
		}
		else
		{
			cout << "����� ����!" << endl;
		}
			system("pause");

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
		char choise;
		if (result)
		{
			cout << "� ������ ��������� ������ ����, �������? y/n: ";
			cin >> choise;
			if (choise == 'y')
			{
				result = false;
			}
		}
		while (result == false)
		{
			cout << "ID" << setw(50) << "�������� �������� ���������" << endl << endl;
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
			ChoseInstitution();
		}
	}
	void ChoseInstitution()
	{
		bool result;
		string textID;
		int id;
		cout << "ID �������� ���������" << endl;
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
		cout << "������� ������������? y/n: ";
		cin >> choise;
		if (choise == 'y')
		{
			cout << "�������� ID: ";
			cin >> position;

			if (model.SearchSpec(position))
			{
				result = true;
				model.SetPosition(position);
			}
			else
			{
				system("cls");
				cout << "�������� ID" << endl;
				result = false;
			}
		}
		else
		{
			system("cls");
			cout << "�������� �����" << endl;
			result = false;
		}
	}
	void PrintSpecialties(University& model)
	{
		model.PrintSpec();
		_univers = true;
		char choise;
		int position;
		cout << "������� ������������? y/n: ";
		cin >> choise;
		if (choise == 'y')
		{
			cout << "�������� ID: ";

			cin >> position;

			if (model.SearchSpec(position))
			{
				model.SetPosition(position);
				result = true;
			}
			else
			{
				system("cls");
				cout << "�������� ID" << endl;
				result = false;
			}
		}
		else
		{
			system("cls");
			cout << "�������� �����" << endl;
			result = false;
		}
	}
	//int ChoiceIdSpecialties()

};

