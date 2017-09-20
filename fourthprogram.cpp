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

int xyz(int &numb);

int main(){ 
    int num = 25;
    int alibaba = xyz(num);
    cout << alibaba << endl;
}                               // end of main function

int xyz(int &numb){
	int x1 = numb;
	numb = num * 99;
	return x1 * 2;
}

