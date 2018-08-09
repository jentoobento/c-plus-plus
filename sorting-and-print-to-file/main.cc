#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Employee.h"
#include "EmployeeHelperClass.h"

const int MAX = 30;

void print(const Employee& E1);

int main(){
	Employee employeeArray[MAX];
	int length = 0;
	bool done = false;

	string inputFileName;
	cout << "Enter full path to file you wish to read from: ";
	cin.sync();
	getline(cin, inputFileName);
	ifstream inputFile(inputFileName); //Open the input file
	
	string outputFileName;
	cout << "Enter full path to file you wish to write to: ";
	cin.sync();
	getline(cin, outputFileName);
	ofstream outputFile(outputFileName); //Open the output file

	if (!inputFile.is_open() || !outputFile.is_open()){
		cout << "Cannot open file." << endl;
		inputFile.close();
		outputFile.close();
		exit(0);
	}

	length = EmployeeHelperClass::FillArray(inputFile, employeeArray);
	if (length == 0){
		cout << "This file is empty.\n\n";
		done = true;
	}
	if (length >= MAX){
		cout << "The number of records exceeded program capacity.\n";
		cout << "Only the first 30 records will be read.\n\n";
	}

	outputFile << "\t\t\Whoop whoop Awesome Company Employee Information\n"
  << "-------------------------------------------------------------------------\n\n";
	outputFile << "Default List\n\n";
	EmployeeHelperClass::print(outputFile, employeeArray, length); 
	outputFile << "\n\nSorted by ID#\n\n";
	EmployeeHelperClass::bubbleSort(employeeArray, length, 1); 
	EmployeeHelperClass::print(outputFile, employeeArray, length); 

	outputFile << "\n\nSorted by Last Name\n\n";
	EmployeeHelperClass::bubbleSort(employeeArray, length, 2);
	EmployeeHelperClass::print(outputFile, employeeArray, length);

	outputFile << "\n\nSorted by Gross Salary\n\n";
	EmployeeHelperClass::bubbleSort(employeeArray, length, 3);
	EmployeeHelperClass::print(outputFile, employeeArray, length);

	while (!done){
		cout << "Awesome Employee Information Menu\n"
			<< "----------------------------------------------------\n"
			<< "1. Search for employees based on ID#.\n"
			<< "2. Search for employee based on last name.\n"
			<< "3. Exit\n";

		int choice;
		cout << "Please enter menu choice:\n";
		cin >> choice;
		while (choice < 1 || choice>3) {
			cout << "Invalid choice. Please enter menu choice:\n";
			cin >> choice;
		}
		if (choice == 3){
			cout << "Goodbye!\n\n";
			done = true;
		}
		if (choice == 1){
			cout << "Enter the ID# you are looking for:\n";
			int idNumSearch = 0;
			cin >> idNumSearch;
			EmployeeHelperClass::searchID(inputFile, employeeArray, length, idNumSearch);
		}
		else if (choice == 2){
			cout << "Enter the last name you are looking for:\n";
			string lastNameSearch;
			cin >> lastNameSearch;
			EmployeeHelperClass::searchLastName(inputFile, employeeArray, length, lastNameSearch);
		}
	}
	return 0;
}
