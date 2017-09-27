//******************************************************************
// Template Program
// Programmer: Scooby Doo
// Completed : Sept 01, 2015
// Status    : Complete
//
// This program will be used to start my project
//******************************************************************

#include <iostream>				// for cin, cout, endl
using namespace std;

int main()						
{ 
	int x;
	char grade;
	
    cout << "Please enter a number: ";
    cin >> x;

	//run if statement
	if(x > 100 || x < 0)
		cout << "That is not a valid grade" << endl;
	else
	{

		if (x >= 90) 
			grade = 'A';
		else if(x >= 80)
			grade = 'B';
		else if(x >= 70 )
			grade = 'C';
		else if(x >= 60 )
			 grade = 'D';
		else
			grade = 'F';
			
		cout << "Your grade is: " << grade << endl; 	
	}	
	
	return 0;
}                               // end of main function

