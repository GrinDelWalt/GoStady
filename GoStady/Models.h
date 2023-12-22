#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
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
	vector <University> _universitys;
	vector <�ollege> _colleges;
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
		_colleges.push_back(*new �ollege(title, category));
	}
	void PrintInstitution()
	{
		cout << "ID" << setw(30) << "�������� �������� ���������" << endl;

		for (University univers : _universitys)
		{
			univers.PrintTitle();
		}
	}
};

