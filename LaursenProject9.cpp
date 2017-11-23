#include <iostream>
#include <string>
using namespace std;

class Date
{
	private:
		int day;
		int month;
		int year;
		string getMonthName();

		
	public:
		//constructor
	    Date(int initMonth, int initDay, int initYear);
	    void printDate();

	    
//	int getDay(){return day;}	
//	int getMonth(){return month;}
//	int getYear(){return year;}
//	int getMonthName(){return monthName;}
	
	bool set(int newMonth, int newDay, int newYear);
};

Date::Date(int initMonth=0, int initDay=0, int initYear=0 )
	{
  	bool status = set(initMonth, initDay, initYear);
	//set all file inputs to 0 if status is false
  	if ( !status )
  	{
    	day = 0;
    	month = 0;
		year = 0;  
	}
}
  
bool Date::set(int newMonth, int newDay, int newYear)
{
	
  bool status = false;
  if ( newMonth > 0 && newMonth < 12 && newDay > 0 && newDay < 32 && newYear > 1949 && newYear < 2021)
  {
    status = true;
    month = newMonth;
    day = newDay;
    year = newYear;
  }
  return status;
}
 
int main()
{
	int month = 1;
	int day = 1;
	int year = 2020;
	
	Date date1;
	
	date1.set(month, day, year);
	date1.printDate();
	
	return 0;
   
}

void Date::printDate()
{
	cout << month << "/" << day << "/" << year << endl;
	cout << getMonthName() << " " << day << "," << " " << year << endl;
	cout << day << " " << getMonthName() << " " << year << endl;
}

string Date::getMonthName()
{
 
    int month1 = 1;
    int month2 = 2;
    int month3 = 3;
    int month4 = 4;
    int month5 = 5;
    int month6 = 6;
    int month7 = 7;
    int month8 = 8;
    int month9 = 9;
    int month10 = 10;
    int month11 = 11;
    int month12 = 12;
    string monthName;

     if(month == month1)
    {   monthName = "January";}
     else if(month == month2)
    {   monthName = "Febuary";}
     else if (month == month3)
    {   monthName = "March";}
     else if (month == month4)
    {   monthName = "April";}
	 else if (month == month5)
    {   monthName = "May";}
     else if (month == month6)
    {   monthName = "June";}
     else if (month == month7)
    {   monthName = "July";}
     else if (month == month8)
    {   monthName = "August";}
     else if (month == month9)
    {   monthName = "September";}
     else if (month == month10)
    {   monthName = "October";}
     else if (month == month11)
    {   monthName = "November";}
     else if (month == month12)
    {   monthName = "December";}

	return monthName;
}

