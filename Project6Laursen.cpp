using namespace std;
#include <string>
#include <iomanip>
#include <iostream>


struct Payroll
{
	int empId;
	string empName;
	float payRate;
	int employeeType;	
};

struct Timecard
{
	float grossPay;
	float tax;
	float netPay;
};

void inputEmployee(Payroll[], Timecard[]);
float payrollReport(Payroll[], Timecard[]);

int main()
{
	Payroll employee[4];
	Timecard paystub[4];
	double hours;
	
	inputEmployee(employee, paystub);
	payrollReport(employee, paystub);
	
	return 0;
	
}

void inputEmployee(Payroll employee[], Timecard paystub[])
{
	int empId;
	string empName;
	float payRate;
	int employeeType;
	for (int i = 0; i < 4; i++ )
	{
		cout << "Enter information for employee "<<i+1<<endl;
		cout << "Employee id: ";
		cin >> empId;
		while(empId < 0)
		{
			cout << "Employee id must be a positive number." << endl;
			cout << "Employee id: ";
			cin >> empId;
		}
		
		cin.ignore();
		cout << "Employee name: ";
		getline(cin, empName);
		cout << "Pay rate: ";
		cin >> payRate;
		
		while(payRate < 0)
		{
			cout << "Pay rate must be a positive number." << endl;
			cout << "Pay rate: ";
			cin >> payRate;
		}
		cout << "Employee type ";
		cin >>employeeType;
		while(employeeType != 0 && employeeType !=1)
		{
			cout << "Employee type must be 0 or 1." << endl;
			cout << "Employee type ";
			cin >> employeeType;
		}
		
		employee[i].empId = empId;
		employee[i].payRate =payRate;
		employee[i].empName = empName;
		employee[i].employeeType = employeeType;
	}
	
		
	//----timesheet----------------------------------------------
	float hours;
	for (int i = 0; i < 4; i++ )
	{
		cout << "Hours worked for " << employee[i].empName << " :";
		cin >> hours;
		while(hours < 0)
		{
			cout << "Employee's hours cannot be less than 0'." << endl;
            cout << "Hours worked for " << employee[i].empName << " :";
            cin >> hours;
		}
		if(hours > 40)
		{
			paystub[i].grossPay = employee[i].payRate * 40;
			paystub[i].grossPay += (hours - 40) * (1.5 * employee[i].payRate);
			cout << paystub[i].grossPay;
		}
		else
		{
			paystub[i].grossPay = employee[i].payRate * hours;
		}
		cout << "gross pay is " << paystub[i].grossPay << endl;
		paystub[i].tax = (paystub[i].grossPay * 0.15); 
		cout << "tax is " << paystub[i].tax << endl;
		paystub[i].netPay = paystub[i].grossPay - paystub[i].tax;
		cout << "net pay " << paystub[i].netPay << endl;
	}
	
	
}

float payrollReport(Payroll employee[], Timecard paystub[])
{
	cout << left <<setw(4) <<"ID"<<setw(27)<<"Name" <<right << setw(9) << "Gross Pay" << setw(9)  << "Tax" << setw(9) << "Net Pay" << endl;

	float totalGross = 0;
	float totalNet = 0;
	
	for (int i = 0; i < 4; i++ )
	{
		cout << left <<setw(4) <<employee[i].empId<<setw(27)
		<<employee[i].empName  <<right << setw(9) <<paystub[i].grossPay << setw(9) << paystub[i].tax << setw(9) << paystub[i].netPay << endl;
		totalGross += paystub[i].grossPay;
		totalNet += paystub[i].netPay;
	}
	cout << "Total Gross Pay: $" <<totalGross<< endl;
	cout << "Total Net Pay: $" <<totalNet<< endl;

}


