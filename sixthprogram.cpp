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
    cout << "Please enter a number: " << endl;
    cin >> x;

	//run if statement
	if(x % 5 == 0){
		//  Print whether x is divisble by 5
		cout << "x is divisible by 5" << endl; 
	}
	
	cout << "Great job" << endl;
    return 0; 
}                               // end of main function

