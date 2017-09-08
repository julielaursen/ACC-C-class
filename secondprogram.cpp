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
    int x = 0; //initialize integer x and set to 5
    int y = 0; //initialize integer y and set to 15

    
    
    cout << "Enter the first integer:  ";
    cin >> x;
    cout << "Enter the second integer:  ";
    cin >> y;
    
    int sum = x + y; //calculate the sum of x and y and set it to variable of sum
    int difference = x - y;

	//  Print sum
    cout << "The sum is:  " << sum << endl; 
    //print difference
    cout << "The difference is:  " << difference << endl;

    return 0;
	           

}                               // end of main function

