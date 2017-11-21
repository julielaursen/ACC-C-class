 using namespace std;
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>




class Employee 
{
  //private class declarations
  private:
    int id;             // employee ID
    char name [21];        // employee name
    double hourlyPay;   // pay per hour
    int numDeps;        // number of dependents
    int type;           // employee type
    float rate;			// payrate
    
  public:
  	//public class declarations
    Employee( int initId=0, char initName[]='\0', 
              double initHourlyPay=0.0, 
              int initNumDeps=0, int initType=0 );  // Constructor

	int getID(){return id;}	
	int getHours(){return hourlyPay;}	
	int getRate(){return rate;}											///add other get functions
	
	//called later with employee variables passed in
    bool set(int newId, string newName, double newHourlyPay,
             int newNumDeps, int newType)
             {
			  id = newId;
              name = newName;
              hours = newHourlyPay;
			  numDeps = newNumDeps;
              type = newType;
			  }
};

class Timecard {
	 private:
    	int id;             // employee ID
    	float hours;
};

//call employee function using class employee
Employee::Employee( int initId=0, char initName[]='\0', 
              		double initHourlyPay=0.0, 
              		int initNumDeps=0, int initType=0 )
	{
	//initiate variable status
  	bool status = set( initId, initName, initHourlyPay, 
                     initNumDeps, initType );
	//set all file inputs to 0 if status is false
  	if ( !status )
  	{
    	id = 0;
    	name = '\0';
    	hourlyPay = 0.0;
    	numDeps = 0;
    	type = 0;    
  	}
	}

//call set function of class employee
bool Employee::set( int newId, char newName[], double newHourlyPay,
                                 int newNumDeps, int newType )
  {	
  //initialize status to false																				/// check error checking
  bool status = false;
  //error check that all file inputs are true
  if ( newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 && 
       newType >= 0 && newType <= 1 )
  {
  	//set status to true
    status = true;
    //set id to new id
    id = newId;
    //for loop, while name is null value, stop
    for(int i=0; i<21; i++)
    {
		name[i] = newName[i];
		if(newName[i] == '\0')
			break;
	}
	hourlyPay = newHourlyPay;
    numDeps = newNumDeps;
    type = newType;
  }
  //return status as true or false
  return status;
}

float payrollReport(Employee emp[], Timecard tc[], int size)					/// finish struct -> class translation
{
	cout << left <<setw(4) <<"ID"<<setw(27)<<"Name" <<right << setw(9) << "Gross Pay" << setw(9)  << "Tax" << setw(9) << "Net Pay" << endl;

	float totalGross = 0;
	float totalNet = 0;
	
	for (int i = 0; i < 4; i++ )
	{
		float grossPay = calcPay(employee[i], paystub, size);
		//calc tax and net pay off of grossPay
		cout << left <<setw(4) <<employee[i].empId<<setw(27)
		<<employee[i].empName  <<right << setw(9) <<paystub[i].grossPay << setw(9) << paystub[i].tax << setw(9) << paystub[i].netPay << endl;
		totalGross += tc[i].grossPay;
		totalNet += tc[i].netPay;
	}
	cout << "Total Gross Pay: $" <<totalGross<< endl;
	cout << "Total Net Pay: $" <<totalNet<< endl;

}

float Employee::calcPay(Employee emp, TimeCard tc[], int size)
{
	float grossPay=0;
	for(int i=0; i<size && grossPay == 0; i++)
	{
		if(emp.getID() == tc[i].getID())
		{
			float hours = tc[i].getHours();
			if(hours > 40)														/// finish struct -> class translation
			{
				grossPay = emp.getRate() * 40;
				grossPay += (hours - 40) * (1.5 * employee[i].payRate);
				cout << paystub[i].grossPay;
			}
			else
			{
				paystub[i].grossPay = employee[i].payRate * hours;
			}
		}
	}
	return grossPay;
}

void popEmployees(employeeFile, emp, size)
{
	//declares variables
	int empId;
	char empName [21];
	float payRate;
	int dependents;
	int employeeType;
	//gets variables from employeeFile doc
	employeeFile >> empId;
	for (int i = 0; i < size && empId == '\n'; i++ )  
	{
		
		employeeFile.get(empName, 20, '\n');
		// clear right hand spaces and add \0
		employeeFile >> payRate;
		employeeFile >> dependents;
		employeeFile >> employeeType;
		
		//passes empId, empName, payRate, dependents, employeeType from the file to set function
		emps[i].set(empId, empName, payRate, dependents, employeeType);
	}
}

void popTimeCard(transFile, tc, size)
{
	//declares variables
	int empId;
	float payRate;
	transFile >> empId;
	for (int i = 0; i < size && empId == '\n'; i++ )  
	{
		transFile >> hours;
		//passes empId, empName, payRate, dependents, employeeType from the file to set function
		tc[i].getID(empId);
		tc[i].getHours(hours);
	}
}


int main()
{
	ifstream employeeFile;
	int size = 20;
	Employee emp[size];
	Timecard tc[size];
	ifstream transFile;
	
	transFile.open("trans10.txt");
	employeeFile.open("master10.txt");								// play with file not found logic
	if (!employeeFile || !transFile)
	{
		cout << "Cannot open file" << endl;
		return 1;
	}
	else
	{
		popEmployees(employeeFile, emps, size);
	}
		
	
	if (!transFile)
	{
		cout << "Cannot open transaction input file" << endl;
		return 1;
	}
	else
	{
		popTimeCard(transFile, tc, size);
	}
	payrollReport(emps, tc, size);
	

}
