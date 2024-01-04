#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct vehicle
{
	string name;
	int price;
	int model;
	string registration_number;
};
void populate_arrays_vehicle(vehicle v1[], int size);
void menu_vehicle(vehicle v1[], int size, int& count);
void add_vehicle(vehicle v1[], int size);
void view_vehicle(vehicle v1[], int size);
void search_vehicle(vehicle v1[], int size);
void update_vehicle(vehicle v1[], int size);
void remove_vehicle(vehicle v1[], int size);
void populate_arrays_vehicle(vehicle v1[], int size)
{
	ifstream fin;
	fin.open("vehicle.txt");
	if (!fin.fail())
	{
		int count = 0;
		while (fin >> v1[count].name >> v1[count].price >> v1[count].model >> v1[count].registration_number)
		{
			count++;
		}
		fin.close();
	}
	else
	{
		cout << "Error: Unable to open file." << endl;
	}
}
void menu_vehicle(vehicle v1[], int size, int& count)
{
	int option;
	char sure = 'n';
	do
	{
		cout << "\n1 - Add Vehicle in Record\n2 - View Vehicle from record\n3 - Search Vehicle from record\n4 - Update Vehicle Record\n5 - Delete Vehicle from Record\n6 - Exit the program" << endl << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "\nAdd Vehicle in Record" << endl;
			add_vehicle(v1, size);
			break;
		case 2:
			cout << "\nView Vehicles in Record" << endl;
			view_vehicle(v1, size);
			break;
		case 3:
			cout << "\nSearch a Vehicle in Record" << endl;
			search_vehicle(v1, size);
			break;
		case 4:
			cout << "\nUpdate a Vehicle in Record" << endl;
			update_vehicle(v1, size);
			break;
		case 5:
			cout << "\nRemove a Vehicle from Record" << endl;
			remove_vehicle(v1, size);
			break;
		case 6:
			cout << "\nAre you sure to exit (Y for Yes || N for No) : ";
			cin >> sure;
			cout << "\n*program terminates*" << endl;
			exit(0);
			break;
		default:
			cout << "\nGOOD BYE";
			break;
		}
	} while (sure == 'N' || sure == 'n');
}
void add_vehicle(vehicle v1[], int size) 
{
	char check;
	ofstream fout;
	fout.open("vehicle.txt", ios::app);
	int count = 0;
	do
	{
		cout << "\nEnter car name : ";
		cin>> v1[count].name;
		cout << "\nEnter the price : ";
		cin >> v1[count].price;
		cout << "\nEnter the model : ";
		cin >> v1[count].model;
		cout << "\nEnter the registration number : ";
		cin >> v1[count].registration_number;
		fout << "\n" << v1[count].name << "\t" << v1[count].price << "\t" << v1[count].model << "\t" << v1[count].registration_number;
		count++;
		cout << "\nEnter 'y' to add another record (or enter any other character to exit add function) : ";
		cin >> check;
		cout << endl;
	} while (check == 'y' || check == 'Y');
	fout.close();
}
void view_vehicle(vehicle v1[], int size)
{
	for (int count = 0; count < size; count++)
	{
		
		if (!(v1[count].name.empty()))
		{
			cout << "\n-------------------------------";
			cout << "\nCar Name : " << v1[count].name;
			cout << "\nPRICE : " << v1[count].price;
			cout << "\nModel : " << v1[count].model;
			cout << "\nReg no. : " << v1[count].registration_number;
			cout << "\n-------------------------------";
		}
	}
}
void search_vehicle(vehicle v1[], int size)
{
	bool find = false;
	char check;
	string name_to_search;
	int count;
	do
	{
		cout << "\nEnter name of Vehicle to Search : ";
		cin >> name_to_search;
		for (count = 0; count < size; count++)
		{
			if (name_to_search == v1[count].name)
			{
				cout << "\nCAR NAME : " << v1[count].name;
				cout << "\nPRICE : " << v1[count].price;
				cout << "\nMODEL : " << v1[count].model;
				cout << "\nREGISTRATION NUMBER : " << v1[count].registration_number << endl << endl;
				find = true;
				break;
			}
			else
			{
				find = false;
			}
		}
		if (!find)
		{
			cout << "RECORD NOT FOUND" << endl;
		}

		cout << "\nWant to Search Again Press 'y' or 'Y otherwise program will be terminated'";
		cin >> check;
	} while (check == 'y' || check == 'Y');
}
void update_vehicle(vehicle v1[], int size) {
	bool found = false;
	string name_to_update;
	cout << "\nEnter the name of vehicle you want to update : ";
	cin >> name_to_update;
	for (int count = 0; count < size; count++) 
	{
		if (v1[count].name == name_to_update)
		{
			cout << "\nEnter New name : ";
			cin >> v1[count].name;
			cout << "\nEnter New price : ";
			cin >> v1[count].price;
			cout << "\nEnter New model : ";
			cin >> v1[count].model;
			cout << "\nEnter New registration number : ";
			cin >> v1[count].registration_number;
			found = true;
		}
	}
			if (found)
			{
				cout << "\nThe record with the name " << name_to_update << " has been updated if it existed" << endl;
			}
			else
			{
				cout << "\nThe record with the name " << name_to_update << " was not found" << endl;
			}
}
void remove_vehicle(vehicle v1[], int size)
{
		bool found = false;
		string name_to_delete;
		cout << "\nEnter the name of vehicle you want to delete: ";
		cin >> name_to_delete;
		for (int count = 0; count < size; count++)
		{
			if (v1[count].name == name_to_delete)
			{
				for (int i = count; i < size - 1; i++) 
				{
					v1[i] = v1[i + 1];
				}
				found = true;
				size--;
				break;
			}
		}

		if (found)
		{
			cout << "\nThe record with the name " << name_to_delete << " has been deleted if it existed" << endl;
		}
		else
		{
			cout << "\nThe record with the name " << name_to_delete << " was not found" << endl;
		}
}
