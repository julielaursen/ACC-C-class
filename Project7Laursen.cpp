using namespace std;
#include <string>
#include <iomanip>
#include <iostream>


struct Student
{
//	int score;
	int test1;
	int test2;
	int test3;
	string name;	
};

void inputStudent(Student*, int&);
double avgScore(Student*, int);
void sortArray(Student* , int);
void outputTable(Student*, int, double);
int getScore(string prompt, int max, int min);

int main()
{
	Student* arrayOfStudents;
	int numStudents;
	double average;
	

	
	cout << "Please enter the number of students to be processed: ";
	cin >> numStudents;
	
	arrayOfStudents = new Student[numStudents];
	
	inputStudent(arrayOfStudents, numStudents);
    sortArray(arrayOfStudents, numStudents);
	average = avgScore(arrayOfStudents, numStudents);
	outputTable(arrayOfStudents, numStudents, average);
	
	return 0;
}

int getScore(string prompt, int max, int min)
{
	int score;
	cout << endl << prompt;
	cin >> score;
	
	while(score > max || score < min)
	{
		cout << "Student's score cannot be less than " << min << " or greater than " << max << endl;
        cout << endl << prompt;
        cin >> score;
	}
	return score;
}

//function to input student name/score
void inputStudent(Student* arrayOfStudents, int& numStudents)
{
	for (int i= 0; i < numStudents; i++)
	{
		cout << endl << "Enter the name of student " << i + 1 << ":";
		cin.ignore();
		getline(cin, arrayOfStudents[i].name);
		arrayOfStudents[i].test1 = getScore("Enter the student's test 1 score: ", 105,0);
		arrayOfStudents[i].test2 = getScore("Enter the student's test 2 score: ", 105,0);
		arrayOfStudents[i].test3 = getScore("Enter the student's test 3 score: ", 105,0);
	}
}

void sortArray(Student* arrayOfStudents, int numStudents)
{
        Student Temp;   //holds a student struct object
        bool swap;      //swap is initialized to false at the start of each loop. If it is still false at end of loop we know there is nothing else to sort
        do
        {
            swap = false;
            for (int i = 0; i < numStudents-1; i++)
            {
                if (arrayOfStudents[i].test1 > arrayOfStudents[i + 1].test1)
                {
                    Temp = arrayOfStudents[i];
                    arrayOfStudents[i] = arrayOfStudents[i + 1];
                    arrayOfStudents[i + 1] = Temp;
                    swap = true;
                }
            }
        } while (swap);
}

//function that calculates average scores
double avgScore(Student* arrayOfStudents, int numStudents)
{
	int sum;
	double average;
	sum = 0;
	
	for(int i=0; i < numStudents; i++)
	{
		//sum = (arrayOfStudents + i)->test1;
		sum = arrayOfStudents[i].test1 + arrayOfStudents[i].test2 + arrayOfStudents[i].test3;
		cout << "Sum : " << sum << endl;
		average = sum / 3;
	}
	cout << "Average :" << average << endl;
	return average;
}

//function to output table
void outputTable(Student* arrayOfStudents, int numStudents, double average)
{   
    cout << endl << setw(31) << left << "Name" << setw(6) << right << "Score" << right << setw(5) << "Letter Grade" << endl;
    cout << "-------------------------------------" << endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << setw(31) << left << arrayOfStudents[i].name << setw(5) << right << arrayOfStudents[i].test1 << "," << arrayOfStudents[i].test2 
		<< "," << arrayOfStudents[i].test3 <<  endl;
    }
    cout << "-------------------------------------" << endl;
    cout << setw(31) << left << "Average: " << setw(6) << right << average << endl;
}
