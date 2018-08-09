#ifndef EMPLOYEEHELPERCLASS_H
#define EMPLOYEEHELPERCLASS_H
#include "Employee.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class EmployeeHelperClass{
public:
	static const int MAX = 30;
	static size_t FillArray(ifstream& inputFile, Employee employeeArray[]);
	static size_t FillArray(Employee employeeArray[]);
	static void print(Employee employeeArray[], size_t length); 
	static void print(ofstream& outputFile, Employee employeeArray[], size_t  length);
	static void searchID(ifstream& inputFile, Employee employeeArray[], size_t length, int idNumSearch);
	static void searchLastName(ifstream& inputFile, Employee employeeArray[], size_t length, string lastNameSearch);
	void calcGross(Employee employeeArray[], size_t length);
	static void bubbleSort(Employee employeeArray[], size_t length, size_t flag);
};
#endif
