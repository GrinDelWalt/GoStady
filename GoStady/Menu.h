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
			cout << "--------------------------------------------------" << endl;

			cout << "a) Choosing an educational institution" << endl; //выбор учебного заведения
			cout << "b) Print all" << endl;
			cout << "d) Revers vector" << endl;
			cout << "c) Print all title vector reverse" << endl;
			cout << "e) Get last version all program" << endl;
			cout << "f) Paste 500 elements in center vector" << endl;
			cout << "g) Clear vectro" << endl;
			cout << "q) exet" << endl;

			cout << "Write programm : ";

			cin >> choice;
			cout << endl;
			switch (choice)
			{
			case'a':
				_models->PrintInstitution();

				break;
			case 'b':

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

