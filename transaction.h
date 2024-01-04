#pragma once
#include <iostream>
#include <fstream>
#include "customer.h"
#include"vehicle.h"
using namespace std;
struct transaction
{
	int transaction_amount;
	int transaction_id;
	customer object;
	vehicle obj;
};
void populate_arrays_transaction(transaction v3[], int size);
void menu_transaction(transaction v3[], int size, vehicle v1[], int vehiclesize, customer v2[], int csize);
void add_transaction(transaction v3[], int size,vehicle v1[],customer v2[]);
void view_transaction(transaction v3[], int size);
void search_transaction(transaction v3[], int size);
void update_transaction(transaction v3[], int size);
void delete_transaction(transaction v3[], int size);
void populate_arrays_transaction(transaction v3[], int size)
{ifstream fin;
	fin.open("transactions.txt");
	if (!fin.fail())
	{
		int count = 0;
		while (fin >> v3[count].transaction_amount >> v3[count].transaction_id >> v3[count].obj.name >> v3[count].object.customer_name)
		{			count++;		}
		fin.close();	}
	else
	{		cout << "Error: Unable to open file." << endl;	}}
void menu_transaction(transaction v3[], int size, vehicle v1[], int vsize,customer v2[],int csize)
{
	int option;
	char sure = 'n';
	do
	{
		cout << "\n1-Add transaction in Record\n2-View transaction from record\n3-Search Transaction\n4-Update Transactionn\n5-Delete Transaction \n6-Exit the program" << endl ;
		cin >> option;
		switch (option)
		{
		case 1:	cout << "\nAdd transaction in Record" << endl;         add_transaction(v3, size, v1,v2);	break;
		case 2:	cout << "\nView transactions" << endl;	view_transaction(v3, size);	break;
		case 3:	cout << "\nSearch transactions" << endl;	search_transaction(v3, size);	break;
		case 4:	cout << "\nUpdate transactions" << endl;update_transaction(v3, size);	break;
		case 5:	cout << "\nDelete transactions" << endl;	delete_transaction(v3, size);	break;
		case 6:	cout << "\nAre you sure to exit (Y for Yes || N for No) : ";	cin >> sure;	cout << "\n*program terminates*" << endl;	break;
		default:	cout << "\nGOOD BYE";	break;	}} while (sure == 'N' || sure == 'n');}
void add_transaction(transaction v3[], int size, vehicle v1[],customer v2[]) {
    char check = 'y';
    ofstream fout;
    string vname, cname;
    fout.open("transactions.txt", ios::app);
    do 
    {
        cout << "\nEnter Car Name (against which transaction to be made) : ";
        cin >> vname;
        cout << "\nEnter Customer ID (against which transaction to be made) : ";
        cin >> cname; 
        bool exists = false;
		for (int count = 0; count < size; count++)
		{
			if (v1[count].name == vname && v2[count].customer_name == cname)
			{
				exists = true;
				cout << "\nEnter Transaction Amount : ";
				cin >> v3[count].transaction_amount;
				cout << "\nEnter Transaction ID : ";
				cin >> v3[count].transaction_id;
				fout << "\n" << v3[count].transaction_amount << "\t" << v3[count].transaction_id << "\t" << v1[count].name << "\t" << v2[count].customer_name;
				cout << "\nEnter 'y' to add another record (or enter any other character to exit add function) : ";
				cin >> check;
				cout << endl;
				break;  // Break the loop once the record is found
			}
			else {
				exists = false;
			}
		}
				if(!exists){
					cout << "\nRecord Not found for the given customer and vehicle combination." << endl;
			}
    } while (check == 'y' || check == 'Y');
    fout.close();
}
void view_transaction(transaction v3[], int size)
{
	ofstream fout;
	string vname, cname;
	fout.open("transactions.txt", ios::app);
	for (int count = 0; count < size; count++)
	{
		if (!(v3[count].obj.name.empty()))
		{
			cout << "\n-------------------------------";
			cout << "\nTransaction Amount : " << v3[count].transaction_amount;
				cout << "\nTransaction ID : " << v3[count].transaction_id;
				cout << "\nVehicle Name : " << v3[count].obj.name;
				cout << "\nCustomer name : " << v3[count].object.customer_name ;
				cout << "\n------------------------------";
		}
	}
	fout.close();
}
void search_transaction(transaction v3[], int size)
{
	bool find = false;
	char check;
	int id_to_search;
	int count;
	do
	{
		cout << "\nEnter Transaction ID to Search : ";
		cin >> id_to_search;
		for (count = 0; count < size; count++)
		{
			if (id_to_search == v3[count].transaction_id)
			{
				cout << "\nTransactio Amount : " << v3[count].transaction_amount;
				cout << "\nTransaction ID : " << v3[count].transaction_id;
				cout << "\nVehicle Name : " << v3[count].obj.name;
				cout << "\nCustomer Name : " << v3[count].object.customer_name << endl << endl;
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
void update_transaction(transaction v3[], int size) {
	bool found = false;
	int id_to_update;
	cout << "\nEnter Transaction ID to Search  : ";
	cin >> id_to_update;
	for (int count = 0; count < size; count++)
	{	if (v3[count].transaction_id == id_to_update)
		{
			cout << "\nEnter New Transaction Amount: ";
			cin >> v3[count].transaction_amount;
			cout << "\nEnter New Transaction ID : ";
			cin >> v3[count].transaction_id;
			cout << "\nEnter New Customer Name : ";
			cin >> v3[count].object.customer_name;
			cout << "\nEnter New Vehicle Name : ";
			cin >> v3[count].obj.name;
			found = true;	}}
	if (found)
	{	cout << "\nThe record with the id " << id_to_update << " has been updated if it existed" << endl;}
	else
	{	cout << "\nThe record with the id " << id_to_update << " was not found" << endl;}
}
void delete_transaction(transaction v3[], int size) {
	bool found = false;
	int id_to_delete;
	cout << "\nEnter Transaction ID to Delete  : ";
	cin >> id_to_delete;
	for (int count = 0; count < size; count++)
	{	if (v3[count].transaction_id == id_to_delete)
		{
			for (int i = count; i < size - 1; i++)
			{		v3[i] = v3[i + 1];		}
			found = true;
			size--;
			break;		}
	if (found)
	{	cout << "\nThe record with the id " << id_to_delete << " has been updated if it existed" << endl;	}
	else
	{		cout << "\nThe record with the id " << id_to_delete << " was not found" << endl;	}
}