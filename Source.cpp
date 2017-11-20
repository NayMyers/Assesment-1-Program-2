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
	vector<OrganisationRecord> passOrgRecs(void);
	vector<HRRecord> passHRRecs(void);
	vector<PayrollRecord> passPayrollRecs(void);
	//GTE = Greater Than or Equal to 
};
vector<OrganisationRecord> PayrollProcessing::passOrgRecs(void)
{
	return OrganisationRecords;
}
vector<HRRecord> PayrollProcessing::passHRRecs(void)
{
	return HRRecords;
}
vector<PayrollRecord> PayrollProcessing::passPayrollRecs(void)
{
	return PayrollRecords;
}
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
	cout << "EMPLOYEES EARNING OVER " << salary << "\n--------------------" << endl;
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
class Menu
{
private:
	void displayOrgRecs(vector<OrganisationRecord>);
	void displayHRRecs(vector<HRRecord>);
	void displayPayRecs(vector<PayrollRecord>);
	int choice = 0;
	double employeeTopEndSalary = 0;
	bool menuYorN = true;
public:
	void displayMenu(void);
};
void Menu::displayOrgRecs(vector<OrganisationRecord> OrganisationRecords)
{
	cout << "===================================================================" << endl;
	cout << "ORGANISATION RECORDS\n-----------------------------------------" << endl;
	for (int x = 0; x< int(OrganisationRecords.size() - 1); x++)
	{
		cout << OrganisationRecords[x].employeeNumber << " " << OrganisationRecords[x].name << " " << OrganisationRecords[x].department << " " << OrganisationRecords[x].occupation << endl;
	}
	cout << "====================================================" << endl;
}
void Menu::displayHRRecs(vector<HRRecord> HRRecords)
{
	cout << "============================================================" << endl;
	cout << "HR RECORDS" << "\n-------------------" << endl;
	for (int x = 0; x< int(HRRecords.size() - 1); x++)
	{

		cout << HRRecords[x].employeeNumber << " " << HRRecords[x].address << " " << HRRecords[x].phoneumber << " " << HRRecords[x].ninumber << endl;
	}
	cout << "====================================================" << endl;
}
void Menu::displayPayRecs(vector<PayrollRecord> PayrollRecords)
{
	cout << "====================================================" << endl;
	cout << "PAYROLL RECORDS" << "\n-------------------" << endl;
	for (int x = 0; x< int(PayrollRecords.size() - 1); x++)
	{
		cout << PayrollRecords[x].employeeNumber << " " << PayrollRecords[x].ninumber << " " << PayrollRecords[x].salary << endl;
	}
	cout << "====================================================" << endl;
}
void Menu::displayMenu(void)
{
	PayrollProcessing payrollProcess;
	payrollProcess.loadOrganisationRecords(ORGANISATIONRECORD);
	payrollProcess.loadHRRecords(HRRECORD);
	payrollProcess.loadPayrollRecords(PAYROLLRECORD);

	while (choice != 6)
	{
		if(menuYorN)
		{
			cout << "1: Display Organisation Records." << endl;
			cout << "2: Display HR Records." << endl;
			cout << "3: Display Payroll Records." << endl;
			cout << "4: Display Employees earning over " << "????" << "." << endl;
			cout << "5: Toggle visible options on/off" << endl;
			cout << "6: Exit the program." << endl;
		}
		cout << "Enter choice --> ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1: displayOrgRecs(payrollProcess.passOrgRecs()); break;
		case 2: displayHRRecs(payrollProcess.passHRRecs()); break;
		case 3: displayPayRecs(payrollProcess.passPayrollRecs()); break;
		case 4:
			cout << "Enter top end salary --> ";
			cin >> employeeTopEndSalary;
			cout << endl;
			payrollProcess.displayEmployeeOfSalaryGTE(employeeTopEndSalary); break;
		case 5:
			menuYorN = !menuYorN;
			break;
		case 6:
			cout << "EXITING" << endl;
			break;
		default:
			cout << "OOPS try again!" << endl;
			break;
		}
	}
}
int main(void)
{
	Menu menu;
	menu.displayMenu();
	return 0;
}