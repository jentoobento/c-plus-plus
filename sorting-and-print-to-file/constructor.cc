#include "Employee.h"

Employee::Employee(string fname, string lname, char emCode, int id, int jobC, int yrs, int edC){
	first = fname;
	last = lname;
	if (emCode != 'S' && emCode != 'O'&&emCode != 'M'){
		empCode = 'X';
	}else{
		empCode = emCode;
	}
	idNum = id;
	if (jobC<1 || jobC>3){
		jobClassCode = 0;
	}else{
		jobClassCode = jobC;
	}
	if (yrs < 0 || yrs>50){
		years = -1;
	}else{
		years = yrs;
	}
	if (edC<1 || edC>4){
		edCode = 0;
	}else{
		edCode = edC;
	}
	calcGross();
}

Employee::Employee(){
	first = "None";
	last = "None";
	empCode = 'X';
	idNum = 0;
	jobClassCode = 0;
	years = -1;
	edCode = 0;
	gross = 0.0; 
}

void Employee::setFirstName(string newFirst){
	first = newFirst;
}
void Employee::setLastName(string newLast){
	last = newLast;
}
void Employee::setEmployeeCode(char newEmpCode){
	if (newEmpCode != 'S'&&newEmpCode != 'O'&&newEmpCode != 'M'){
		cout << "Error with employee code. No changes have been made.\n";
	}else{
		empCode = newEmpCode;
	}
}
void Employee::setIdentificationNumber(int newIdNum){
	idNum = newIdNum;
}
void Employee::setJobClassificationCode(int newJobClassCode){
	if (newJobClassCode<1 || newJobClassCode>3){
		cout << "Error with job classification code. No changes have been made.\n";
	}else{
		jobClassCode = newJobClassCode;
	}
}
void Employee::setYearsOfService(int newYears){
	if (newYears < 0 || newYears>50){
		cout << "Error with number of years worked. No changes have been made.\n";
	}else{
		years = newYears;
	}
}
void Employee::setEducationCode(int newEdCode){
	if (newEdCode<1 || newEdCode>4){
		cout << "Error with education code. No changes have been made.\n";
	}else{
		edCode = newEdCode;
	}
}

string Employee::getFirstName() const
{
	return first;
}
string Employee::getLastName() const
{
	return last;
}
string Employee::getFullName() const
{
	return first + ' ' + last;
}
char Employee::getEmpCode() const
{
	return empCode;
}
int Employee::getID() const
{
	return idNum;
}
int Employee::getJobClassCode() const
{
	return jobClassCode;
}
int Employee::getYears() const
{
	return years;
}
int Employee::getEdCode() const
{
	return edCode;
}
double Employee::getGross() const
{
	return gross;
}

void Employee::print() const
{
	cout << setw(20) << left
		<< "Name" << setw(20) << left
		<< "ID#" << setw(20) << left << "Employee Code"
		<< setw(20) << left << "Gross Salary";
	cout << "---------------------------------------------------";
	
	if (gross != 0.00){
		string empCodeName;
		if (empCode == 'S')
			empCodeName = "Factory";
		if (empCode == 'O')
			empCodeName = "Office";
		if (empCode == 'M')
			empCodeName = "Management";

		cout << setw(20) << left << getFullName() << setw(20) << left
			<< idNum << setw(20) << left << empCodeName << setprecision(2)
			<< fixed << "$" << setw(20) << left << gross;
	}else{
		cout << getFullName() << " ";
		if (empCode != 'S' && empCode != 'O'&&empCode != 'M')
			cout << "Error with Employee Code";
		if (jobClassCode < 1 || jobClassCode>3)
			cout << "Error with Job Classification Code";
		if (years < 0 || years>50)
			cout << "Error with number of years.";
		if (edCode < 1 || edCode>4)
			cout << "Error with Education Code.";
	}
		cout << "\n\n";
}

void Employee::print(ofstream& outputFile) const
{
	if (gross != 0.00){
		string empCodeName;
		if (empCode == 'S')
			empCodeName = "Factory";
		if (empCode == 'O')
			empCodeName = "Office";
		if (empCode == 'M')
			empCodeName = "Management";

		outputFile << setw(20) << left << getFullName() << setw(20) << left
			<< idNum << setw(20) << left << empCodeName << setprecision(2)
			<< fixed << "$" << setw(20) << left << gross;
	}else{
		outputFile << getFullName() << " ";
		if (empCode != 'S' && empCode != 'O'&&empCode != 'M')
			outputFile << "Error with Employee Code.";
		if (jobClassCode<1 || jobClassCode>3)
			outputFile << "Error with Job Classification Code.";
		if (years < 0 || years > 50)
			outputFile << "Error with number of years.";
		if (edCode<1 || edCode>4)
			outputFile << "Error with Education Code.";
	}
}

void Employee::getInstance(Employee& E1){
	cout << "Enter the employee's first name:\n";
	cin >> E1.first;
	cout << "Enter the employee's last name:\n";
	cin >> E1.last;
	cout << "Enter the employee's Employee Code:\n";
	cin >> E1.empCode;
	cout << "Enter the employee's ID#:\n";
	cin >> E1.idNum;
	cout << "Enter the employee's Job Classification Code:\n";
	cin >> E1.jobClassCode;
	cout << "Enter the number of years the employee has worked:\n";
	cin >> E1.years;
	cout << "Enter the employee's Education Code:\n";
	cin >> E1.edCode;
	E1.calcGross(); 
}

void Employee::getInstance(ifstream& inputFile, Employee& E1){
	string first; 
	string last; 
	char empCode; 
	int idNum; 
	int jobClassCode; 
	int years; 
	int edCode; 
	double gross; 
	string empCodeName;
	inputFile >> first >> last >> empCode >> idNum >> jobClassCode >> years >> edCode;
	E1 = Employee(first, last, empCode, idNum, jobClassCode, years, edCode); //call employee function
}

void Employee::calcGross(){
	if (years < 0){
		gross = 0.0;
		return;
	}
	double base = 0.0;
	double jobClassBonus = 0.0;
	double yearsBonus = 0.0;
	double edCodeBonus = 0.0;
	if (empCode == 'S')
		base = 800.0;
	if (empCode == 'O')
		base = 1000.0;
	if (empCode == 'M')
		base = 1500.0;
	if (jobClassCode == 1)
		jobClassBonus = 0.05*base;
	if (jobClassCode == 2)
		jobClassBonus = 0.1*base;
	if (jobClassCode == 3)
		jobClassBonus = 0.2*base;
	if (years > 0 && years <= 10)
		yearsBonus = 0.05*base;
	if (years > 10 && years <= 50)
		yearsBonus = (0.05 + (years - 10)*0.01)*base;
	if (edCode == 2)
		edCodeBonus = 0.05*base;
	if (edCode == 3)
		edCodeBonus = 0.12*base;
	if (edCode == 4)
		edCodeBonus = 0.2*base;
	this->gross = base + jobClassBonus + yearsBonus + edCodeBonus;
}
