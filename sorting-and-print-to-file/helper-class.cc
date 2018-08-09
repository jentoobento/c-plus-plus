#include "EmployeeHelperClass.h"

size_t EmployeeHelperClass::FillArray(ifstream& inputFile, Employee employeeArray[]){
	size_t i = 0;
	while (i < MAX && inputFile.peek() != EOF){
		Employee::getInstance(inputFile, employeeArray[i]);
		i++;
	}
	return i;
}

void EmployeeHelperClass::print(Employee employeeArray[], size_t length){
	for (size_t i = 0; i < length; i++){
		employeeArray[i].print();
		cout << endl;
	}
}

void EmployeeHelperClass::print(ofstream& outputFile, Employee employeeArray[], size_t  length){
	outputFile << setw(20) << left
		<< "Name" << setw(20) << left
		<< "ID#" << setw(20) << left << "Employee Code"
		<< setw(20) << left << "Gross Salary\n"
		<< "--------------------------------------------------------------------------------\n";
	for (size_t i = 0; i < length; i++){
		employeeArray[i].print(outputFile);
		outputFile << endl;
	}
}

void EmployeeHelperClass::bubbleSort(Employee employeeArray[], size_t length, size_t flag){
	for (size_t i = 0; i < length; i++){
		for (size_t j = 0; j < length - i - 1; j++){
			if (flag == 1) {
				int tempNum;
				if (employeeArray[j].getID() > employeeArray[j + 1].getID()){
					Employee tempNum = employeeArray[j];
					employeeArray[j] = employeeArray[j + 1];
					employeeArray[j + 1] = tempNum;
				}
			}
			if (flag == 2) {
				string tempName;
				if (employeeArray[j].getLastName() > employeeArray[j + 1].getLastName()){
					Employee tempName = employeeArray[j];
					employeeArray[j] = employeeArray[j + 1];
					employeeArray[j + 1] = tempName;
				}
			}
			if (flag == 3){
				double grossTemp;
				if (employeeArray[j].getGross() > employeeArray[j + 1].getGross()){
					Employee grossTemp = employeeArray[j];
					employeeArray[j] = employeeArray[j + 1];
					employeeArray[j + 1] = grossTemp;
				}
			}
		}
	}
}

void EmployeeHelperClass::searchID(ifstream& inputFile, Employee employeeArray[], size_t length, int idNumSearch){
	bool found = false;
	for (size_t i = 0; i < length; i++){
		if (idNumSearch == employeeArray[i].getID(){
			employeeArray[i].print();
			found = true;
		}
	}
	if (!found){
		cout << "Sorry. No matches were found.\n\n";
	}
}

void EmployeeHelperClass::searchLastName(ifstream& inputFile, Employee employeeArray[], size_t length, string lastNameSearch){
	bool found = false;
	for (size_t i = 0; i < length; i++){
		if (lastNameSearch == employeeArray[i].getLastName()){
			employeeArray[i].print();
			found = true;
		}
	}
	if (!found){
		cout << "Sorry. No matches were found.\n\n";
	}
}
