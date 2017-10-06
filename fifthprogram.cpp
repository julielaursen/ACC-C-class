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

int add(int &numb);
int subtract(int &numb);
int multiply(int &numb);
int divide(int &numb);

int main(){ 
    int num = 24;
    int addNum = add(num);
    int subtractNum = subtract(num);
    int multiplyNum = multiply(num);
    int divideNum = divide(num);
    cout << addNum << endl;
    cout << subtractNum << endl;
    cout << multiplyNum << endl;
    cout << divideNum << endl;
}                               // end of main function

int add(int &numb){
	int a;
	a = numb;
	return a + 2;
}

int subtract(int &numb){
	int a;
	a = numb;
	return a - 2;
}

int multiply(int &numb){
	int a;
	a = numb;
	return a * 2;
}

int divide(int &numb){
	int a;
	a = numb;
	return a / 2;
}
