#pragma once
#include "Models.h"
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;
class Menu
{
	Models* _models;
public:
	Menu()
	{
		_models = new Models();
	}
	void StartMenu()
	{
		setlocale(LC_ALL, "Russian");
		char choice;
		do
		{
			system("cls");
			cout << "--------------------------------------------------" << endl;

			cout << "a) Просмотр направлений и учебных заведений" << endl;
			cout << "b) Выбор учебного заведения" << endl; //выбор учебного заведения
			cout << "d) Очистить выбор" << endl;
			cout << "d) Просмотр условий" << endl;
			cout << "c) Просмотр особенностей" << endl;
			cout << "q) exet" << endl;

			cout << "Write programm : ";

			cin >> choice;
			cout << endl;
			switch (choice)
			{
			case'a':
				_models->PrintAll();
				break;
			case'b':
				_models->PrintInstitution();
				break;
			case 'd':
				_models->ClearResult();
				break;
			default:
				break;
			}
		} while (choice != 'q');
	}
	void InstitutionMenu()
	{

	}
	void ChoosingInstitution() //выбор учебного заведния
	{
		cout << setw(20) << "Title" << setw(30) << "type of study assignment" << endl;
	}
};

