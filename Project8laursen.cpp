 using namespace std;
#include <string>

#include <iostream>
#include <fstream>
#include <iomanip>



class Employee 
{
  //private class declarations
  private:
    int id;             // employee ID
    char name [21];        // employee name
    double hourlyPay;   // pay per hour
    int numDeps;        // number of dependents
    int type;           // employee type
    //float rate;			// payrate
    char gender;
    
  public:
  	//public class declarations
    Employee( int initId, char initName[], 
              double initHourlyPay, 
              int initNumDeps, int initType );  // Constructor

	int getID(){return id;}	
	char* getName(){return name;}
	int getHours(){return hourlyPay;}	
	int getRate(){return hourlyPay;}											///add other get functions
	
	//called later with employee variables passed in
    bool set(int newId, char newName[], double newHourlyPay,
             int newNumDeps, int newType);
             
};

class TimeCard 
{
	private:
    	int id;            
    	float hours;
    	
    public:
    TimeCard(){id =0; hours=0;}
	TimeCard(int initId, float initHours);
	
	int getID(){return id;}
	float getHours(){return hours;}
	
	bool set(int initId, float initHours);
};
bool TimeCard::set(int initId, float initHours)
{
	if(initHours < 0)
	{
		id =0;
		hours=0;
		return false;
	}
	else
	{
		id =initId;
		hours=initHours;
		return true;
	}
}
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
    	name[0] = '\0';
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


float calcPay(Employee emp, TimeCard tc[], int size)
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
				grossPay += (hours - 40) * (1.5 * emp.getRate());
			}
			else
			{
				grossPay = emp.getRate() * hours;
			}
		}
	}
	return grossPay;
}

float payrollReport(Employee emp[], TimeCard tc[], int size)					/// finish struct -> class translation
{
	cout << left <<setw(4) <<"ID"<<setw(27)<<"Name" <<right << setw(9) << "Gross Pay" << setw(9)  << "Tax" << setw(12) << "Insurance" << setw(9) << "Net Pay" << endl;

	float totalGross = 0;
	float totalNet = 0;
	
	for (int i = 0; i < size; i++ )
	{
		float grossPay = calcPay(emp[i], tc, size);
		float tax = .15 * grossPay;
		int insurance = 30;
		float netPay = grossPay - tax - insurance;
		cout << left <<setw(4) <<emp[i].getID()<<setw(27)
		<<emp[i].getName()  <<right << setw(9) <<grossPay << setw(9) << tax << setw(12) << insurance << setw(9)<< netPay << endl;
		totalGross += grossPay;
		totalNet += netPay;
	}
	cout << endl;
	cout << "Total Gross Pay: $" <<totalGross<< endl;
	cout << "Total Net Pay: $" <<totalNet<< endl;

}


int popEmployees(ifstream& employeeFile, Employee emp[], int size)
{
	//declares variables
	int empId;
	char empName [21];
	float payRate;
	int dependents;
	int employeeType;
	char gender;
	int counter=0;
	//gets variables from employeeFile doc
	//employeeFile >> empId;
	for (int i = 0; i < size && employeeFile >> empId; i++ )  
	{
		
		employeeFile.get(empName, 20, '\n');
		// clear right hand spaces and add \0
		employeeFile >> payRate;
		employeeFile >> dependents;
		employeeFile >> employeeType;
		employeeFile >> gender;
		
		//passes empId, empName, payRate, dependents, employeeType from the file to set function
		emp[i].set(empId, empName, payRate, dependents, employeeType);
		
		//employeeFile >> empId;
		counter++;
	}
	return counter;
}

void popTimeCard(ifstream& transFile, TimeCard tc [], int size)
{
	//declares variables
	int empId;
	float hours;
	for (int i = 0; i < size && transFile >> empId; i++ )  
	{
		transFile >> hours;
		//passes empId, empName, payRate, dependents, employeeType from the file to set function
		tc[i].set(empId, hours);
	}
}


int main()
{
	ifstream employeeFile;
	int size = 20;
	Employee emp[size];
	TimeCard tc[size];
	ifstream transFile;
	int recNum;
	
	transFile.open("trans10.txt");
	employeeFile.open("master10.txt");								
	if (!employeeFile)
	{
		cout << "Cannot open file" << endl;
		return 1;
	}
	else
	{
		recNum = popEmployees(employeeFile, emp, size);
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
	payrollReport(emp, tc, recNum);
	
	return 0;

}
