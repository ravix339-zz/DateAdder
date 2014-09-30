/*
 * Enter American Style Date and add a number of days to reach a new date.
 * By: Ravi Sinha and Amulya Musipatla
 * September 29th-30th, 2014
 */

#include <iostream>
#include <string>

using namespace std;

class DateSeparate
{
private:
	string original; //original date
	string day; //extracted day from date
	string month; //extracted month from date
	string year; //extracted year from date
	int numofdays; //number of days needed to be added
	int newset[3]; //new date {day, month, year}
	int numday; //original day in numeric form
	int nummon; //original month in numeric form
	int numye; //original year in numberic form
public:
	DateSeparate(string,int); //constructor
	void separator(); //parse original string to separate date elements
	int monthconverter(string); //convert string month to numeric form
	int daysinmonth(int); // returns number of days in a month taking into account leap years
	void adddate(); //adds the number of days to the date
	void convertbacktonormal(); //converts the date to American Style
};

DateSeparate::DateSeparate(string x, int y)
{
	numofdays = y;
	original = x;
}

void DateSeparate::separator()
{
	int first = original.find_first_of(' ');
	int last = original.find_last_of(' ');
	month = original.substr(0, first);
	day = original.substr(first+1, last-first-2);
	year = original.substr(last+1, 4); 
	nummon = monthconverter(month);
	numday = atoi(day.c_str());
	numye = atoi(year.c_str());
	newset[0] = numday;
	newset[1] = nummon;
	newset[2] = numye;
}

int DateSeparate::monthconverter(string mon)
{
	if (mon == "january")
		return 1;
	else if (mon == "february")
		return 2;
	else if (mon == "march")
		return 3;
	else if (mon == "april")
		return 4;
	else if (mon == "may")
		return 5;
	else if (mon == "june")
		return 6;
	else if (mon == "july")
		return 7;
	else if (mon == "august")
		return 8;
	else if (mon == "september")
		return 9;
	else if (mon == "october")
		return 10;
	else if (mon == "november")
		return 11;
	else if (mon == "december")
		return 12;

}
int DateSeparate::daysinmonth(int x)
{
	if (x == 1||x==3||x==5||x==7||x==8||x==10||x==12)
		return 31;
	else if (x == 2)
	{
		if (!(newset[2] % 400 != 0&&newset[2] %100==0)&& newset[2] % 4 == 0) // check if leap year
						//(divisible by 4 except when divisible by 100 but not 400)
			return 29;
		else
			return 28;
	}
	else
		return 30;
}
void DateSeparate::adddate()
{
	int numofdayscopy = numofdays;
	separator();
	while (numofdayscopy != 0)
	{
		if (newset[0] == daysinmonth(newset[1])) //if days meets max in the month
		{
			newset[0] = 1; //reset day
			if (newset[1] == 12) //if month is max
			{
				newset[1] = 1; //reset month
				newset[2] += 1;//increment year
			}
			else
				newset[1] += 1; //increment month
		}
		else
			newset[0] += 1; //increment day
		numofdayscopy -= 1;
	}
	convertbacktonormal();
}

void DateSeparate::convertbacktonormal()
{
	cout << "Original date: " << original <<endl;
	cout << "After " << numofdays << " days, the new date is: ";
	if (newset[1] == 1)
		cout << "january ";
	else if (newset[1] == 2)
		cout << "february ";
	else if (newset[1] == 3)
		cout << "march ";
	else if (newset[1] == 4)
		cout << "april ";
	else if (newset[1] == 5)
		cout << "may ";
	else if (newset[1] == 6)
		cout << "june ";
	else if (newset[1] == 7)
		cout << "july ";
	else if (newset[1] == 8)
		cout << "august ";
	else if (newset[1] == 9)
		cout << "september ";
	else if (newset[1] == 10)
		cout << "october ";
	else if (newset[1] == 11)
		cout << "november ";
	else if (newset[1] == 12)
		cout << "december ";
	cout << newset[0] << ", " << newset[2] << endl << endl;

}
void main()
{
	int numberofdays;
	string original;
	cout << "Enter the date (ie. march 3, 2014): ";
	getline(cin, original);
	cout << "Enter the number of days in the future (ie. 365): ";
	cin >> numberofdays;
	DateSeparate x(original,numberofdays);
	x.adddate();
	system("PAUSE");
	return;
}
