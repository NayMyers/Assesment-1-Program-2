#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include<vector>

using namespace std;

#define ORGANISATIONRECORD "organisation.txt"
#define HRRECORD "hrRecord.txt"
#define PAYROLLRECORD "payroll.txt"
#define TOPENDSALARY 50000.00

class EmployeeNumber
{
private:

public:
	string employeeNumber;
};
class OrganisationRecord : public EmployeeNumber
{
private:

public:
	string name;
	string occupation;
	string department;

};
class HRRecord : public EmployeeNumber
{
private:

public:
	string address;
	string phoneumber;
	string ninumber;
};
class PayrollRecord : public EmployeeNumber
{
private:

public:
	string ninumber;
	double salary;
};
class PayrollProcessing
{
private:
	ifstream inputfile;
	ofstream outputfile;
	vector<OrganisationRecord> OrganisationRecords;
	vector<HRRecord> HRRecords;
	vector<PayrollRecord> PayrollRecords;
public:
	void loadOrganisationRecords(string filename);
	void loadHRRecords(string filename);
	void loadPayrollRecords(string filename);
	void displayEmployeeOfSalaryGTE(double salary);
	//GTE = Greater Than or Equal to 
};
//class FileCheck
//{
//private:
//	ofstream checkFile;
//	
//public:
//	void checkFiles(void);
//};
//void FileCheck::checkFiles(void)
//{
//	checkFile.open("hello.txt");
//
//}
void PayrollProcessing::loadOrganisationRecords(string filename)
{
	inputfile.open(filename); // *****O
	OrganisationRecord organisationProcessing;
	while (inputfile)
	{
		getline(inputfile, organisationProcessing.employeeNumber);
		getline(inputfile, organisationProcessing.name);
		getline(inputfile, organisationProcessing.occupation);
		getline(inputfile, organisationProcessing.department);
		OrganisationRecords.push_back(organisationProcessing);
	}
	inputfile.close(); //*****C
}
void PayrollProcessing::loadHRRecords(string filename)
{
	inputfile.open(filename); //*****O
	HRRecord HRProcessing;
	while (inputfile)
	{
		getline(inputfile, HRProcessing.employeeNumber);
		getline(inputfile, HRProcessing.address);
		getline(inputfile, HRProcessing.phoneumber);
		getline(inputfile, HRProcessing.ninumber);
		HRRecords.push_back(HRProcessing);
	}
	inputfile.close(); //*****C
}
void PayrollProcessing::loadPayrollRecords(string filename)
{
	inputfile.open(filename); //*****O
	PayrollRecord PayrollProcessing;
	while (inputfile)
	{
		inputfile >> PayrollProcessing.employeeNumber >> PayrollProcessing.ninumber >> PayrollProcessing.salary;
		PayrollRecords.push_back(PayrollProcessing);
	}
	inputfile.close(); //*****C
}
void PayrollProcessing::displayEmployeeOfSalaryGTE(double salary)
{
	cout << "========================================================" << endl;
	cout << "EMPLOYEES EARNING OVER £" << salary << "\n--------------------" << endl;
	for (int x = 0; x<int(PayrollRecords.size() - 1); x++)
	{
		if (PayrollRecords[x].salary > salary)
		{
			cout << "Name: " << OrganisationRecords[x].name << "\nAddress: " << HRRecords[x].address << endl;
			cout << "Department: " << OrganisationRecords[x].department << "\nSalary: " << PayrollRecords[x].salary << endl;
			cout << "--------------------------------------" << endl;
		}
	}
}

int main(void)
{
	PayrollProcessing payrollProcess;
	payrollProcess.loadOrganisationRecords(ORGANISATIONRECORD);
	payrollProcess.loadHRRecords(HRRECORD);
	payrollProcess.loadPayrollRecords(PAYROLLRECORD);
	payrollProcess.displayEmployeeOfSalaryGTE(TOPENDSALARY);
	return 0;
}