#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct customer
{
	string customer_name;
	int customer_id;
	string customer_contact;
	int amount_paid;
};
void populate_arrays_customer(customer v2[], int size);
void menu_customer(customer v2[], int size, int& count);
void add_customer(customer v2[], int size);
void view_customer(customer v2[], int size);
void search_customer(customer v2[], int size);
void update_customer(customer v2[], int size);
void remove_customer(customer v2[], int size);
void populate_arrays_customer(customer v2[], int size)
{
	ifstream fin;
	fin.open("customers.txt");
	if (!fin.fail())
	{
		int count = 0;
		while (fin >> v2[count].customer_name >> v2[count].customer_id >> v2[count].customer_contact >> v2[count].amount_paid)
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
void menu_customer(customer v2[], int size, int& count)
{
	int option;
	char sure = 'n';
	do
	{
		cout << "\n1 - Add customer in Record\n2 - View customer from record\n3 - Search customer from record\n4 - Update customer Record\n5 - Delete customer from Record\n6 - Exit the program" << endl << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "\nAdd customer in Record" << endl;
			add_customer(v2, size);
			break;
		case 2:
			cout << "\nView customers in Record" << endl;
			view_customer(v2, size);
			break;
		case 3:
			cout << "\nSearch a customer in Record" << endl;
			search_customer(v2, size);
			break;
		case 4:
			cout << "\nUpdate a customer in Record" << endl;
			update_customer(v2, size);
			break;
		case 5:
			cout << "\nRemove a customer from Record" << endl;
			remove_customer(v2, size);
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
void add_customer(customer v2[], int size) {
	char check;
	ofstream fout;
	fout.open("customers.txt", ios::app);
	int count = 0;
	do
	{
		cout << "\nEnter Customer Name : ";
		cin >> v2[count].customer_name;
		cout << "\nEnter Customer ID : ";
		cin >> v2[count].customer_id;
		cout << "\nEnter Car ID : ";
		cin >> v2[count].customer_contact;
		cout << "\nEnter Amount Paid : ";
		cin >> v2[count].amount_paid;
		fout << "\t" << v2[count].customer_name << "\t" << v2[count].customer_id << "\t" << v2[count].customer_contact << "\t" << v2[count].amount_paid << endl;
		count++;
		cout << "\nEnter 'y' to add another record (or enter any other character to exit add function) : ";
		cin >> check;
		cout << endl;
	} while (check == 'y' || check == 'Y');
	fout.close();
}
void view_customer(customer v2[], int size)
{
	
	for (int count = 0; count < size; count++)
	{
		
		if (!(v2[count].customer_name.empty()))
		{   cout << "\n-------------------------------";
			cout << "\nCustomer Name : " << v2[count].customer_name;
			cout << "\nCustomer ID : " << v2[count].customer_id;
			cout << "\nCustomer Contact :  " << v2[count].customer_contact;
			cout << "\nAmount Paid : " << v2[count].amount_paid; 
			cout << "\n-------------------------------";
		}
	}
}
void search_customer(customer v2[], int size)
{
	bool find = false;
	char check;
	string name_to_search;
	int count;
	do
	{
		cout << "\nEnter name of  Customer to Search : ";
		cin >> name_to_search;
		for (count = 0; count < size; count++)
		{
			if (name_to_search == v2[count].customer_name)
			{
				cout << "\nCustomer Name : " << v2[count].customer_name;
				cout << "\nCustomer ID : " << v2[count].customer_id;
				cout << "\nCustomer Contact : " << v2[count].customer_contact;
				cout << "\nAmount Paid : " << v2[count].amount_paid<< endl << endl;
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
void update_customer(customer v2[], int size) {
	bool found = false;
	string name_to_update;
	cout << "\nEnter the name of customer you want to update : ";
	cin >> name_to_update;
	for (int count = 0; count < size; count++)
	{	if (v2[count].customer_name == name_to_update)	{
			cout << "\nEnter New name : ";
			cin >> v2[count].customer_name;
			cout << "\nEnter New ID : ";
			cin >> v2[count].customer_id;
			cout << "\nEnter New Contact : ";
			cin >> v2[count].customer_contact;
			cout << "\nEnter New Amount Paid : ";
			cin >> v2[count].amount_paid;
			found = true;	}	}
	if (found)	{	cout << "\nThe record with the name " << name_to_update << " has been updated if it existed" << endl;	}
	else	{		cout << "\nThe record with the name " << name_to_update << " was not found" << endl;	}}
void remove_customer(customer v2[], int size)
{bool found = false;
	string name_to_delete;
	cout << "\nEnter the name of customer you want to delete: ";
	cin >> name_to_delete;
	for (int count = 0; count < size; count++){
		if (v2[count].customer_name == name_to_delete)	{
			for (int i = count; i < size - 1; i++)	{
				v2[i] = v2[i + 1];	}
			found = true;		size--;
			break;	}}
	if (found)	{	cout << "\nThe record with the name " << name_to_delete << " has been deleted if it existed" << endl;	}
	else{	cout << "\nThe record with the name " << name_to_delete << " was not found" << endl;}
}