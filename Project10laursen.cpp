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
    string name;        // employee name
    double hourlyPay;   // pay per hour
    int numDeps;        // number of dependents
    int type;           // employee type
    
  public:
  	//public class declarations
    Employee( int initId=0, string initName="", 
              double initHourlyPay=0.0, 
              int initNumDeps=0, int initType=0 );  // Constructor

	int getID(){return id;}	
	string getName(){return name;}
	int getHours(){return hourlyPay;}	
	int getRate(){return hourlyPay;}											///add other get functions	

    bool set(int newId, string newName, double newHourlyPay,
             int newNumDeps, int newType);
             
};

class TimeCard 
{
	private:
    	int id;            
    	float hours;
    	
    public:
    TimeCard()
	{id =0; hours=0;}
	
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
Employee::Employee( int initId, string initName, 
              		double initHourlyPay, 
              		int initNumDeps, int initType )
	{
	//initiate variable status
  	bool status = set( initId, initName, initHourlyPay, 
                     initNumDeps, initType );
	//set all file inputs to 0 if status is false
  	if ( !status )
  	{
    	id = 0;
    	name = "";
    	hourlyPay = 0.0;
    	numDeps = 0;
    	type = 0;    
  	}
	}

//call set function of class employee
bool Employee::set( int newId, string newName, double newHourlyPay,
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
    id = newId;
    name = newName;
    hourlyPay = newHourlyPay;
    numDeps = newNumDeps;
    type = newType;
  }
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
	
	bool flag = true;
	
	for (int i = 0; i < size; i++ )
		{
		int id = emp[i].getID();
		int hours = tc[i].getHours();
		if(id = 0)
		{
			flag = false;
		}
		else if (hours <= 0.0)
		{
			flag = false;
		}
		else if(flag = true)
		{
			float grossPay = calcPay(emp[i], tc, size);
			float tax = .15 * grossPay;
			int insurance = 30;
			float netPay = grossPay - tax - insurance;
			cout << left <<setw(4) <<emp[i].getID()<<setw(27)
			<< emp[i].getName()  <<right << setw(9) <<grossPay << setw(9) << tax << setw(12) << insurance << setw(9)<< netPay << endl;
			totalGross += grossPay;
			totalNet += netPay;
		}
	}
	cout << endl;
	cout << "Total Gross Pay: $" <<totalGross<< endl;
	cout << "Total Net Pay: $" <<totalNet<< endl;

}


int popEmployees(ifstream& employeeFile, Employee emp[], int size)
{
	//declares variables
	int empId;
	string empName;
	float payRate;
	int dependents;
	int employeeType;
	int counter=0;
	string name;
	//gets variables from employeeFile doc

		for(int i=0; i < size; i++)
		{
		employeeFile >> empId;
		employeeFile.ignore();
		getline(employeeFile, name, '#');
		employeeFile.clear();
		employeeFile >> payRate;
		employeeFile >> dependents;
		employeeFile >> employeeType;
			
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
	int size = 6;
	Employee emp[size];
	TimeCard tc[size];
	ifstream transFile;
	int recNum;
	
	transFile.open("trans9.txt");
	employeeFile.open("master9.txt");								
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
	
	employeeFile.close();
	transFile.close();
	
	return 0;

}
