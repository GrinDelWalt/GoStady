#pragma once
#include "Models.h"
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;
class Menu
{
private:
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
			cout << "c) Очистить выбор" << endl;
			cout << "d) Просмотр условий" << endl;
			cout << "e) Просмотр особенностей" << endl;
			cout << "f) Итог" << endl;
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
			case 'c':
				_models->ClearResult();
				break;
			case 'd':
				if (_models->GetResult())
				{
					_models->PrintEntrance();
				}
				else
				{
					cout << "Не выбранно учереждение" << endl;
				}
				cout << endl;
				system("pause");
				break;
			case 'e':
				if (_models->GetResult())
				{
					_models->PrintFeatures();
				}
				else
				{
					cout << "Не выбранно учереждение" << endl;
				}
				cout << endl;
				system("pause");
				break;
			case 'f':
				_models->Result();
				system("pause");
				break;
			default:
				break;
			}
		} while (choice != 'q');
	}
	void ChoosingInstitution() //выбор учебного заведния
	{
		cout << setw(20) << "Title" << setw(30) << "type of study assignment" << endl;
	}
};

