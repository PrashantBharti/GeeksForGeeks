// Solution for below link
// http://www.geeksforgeeks.org/find-number-of-days-between-two-given-dates/

#include <iostream>
#include <vector>
using namespace std;

vector<int> NumberOfDaysInMonth(13);
vector<int> TotalDaysTillMonth(13);

void FillIntialDetails(void)
{
NumberOfDaysInMonth[0] = 0;
NumberOfDaysInMonth[1] = 31;
NumberOfDaysInMonth[2] = 28;
NumberOfDaysInMonth[3] = 31;
NumberOfDaysInMonth[4] = 30;
NumberOfDaysInMonth[5] = 31;
NumberOfDaysInMonth[6] = 30;
NumberOfDaysInMonth[7] = 31;
NumberOfDaysInMonth[8] = 31;
NumberOfDaysInMonth[9] = 30;
NumberOfDaysInMonth[10] = 31;
NumberOfDaysInMonth[11] = 30;
NumberOfDaysInMonth[12] = 31;

for(size_t i = 1; i < TotalDaysTillMonth.size(); ++i)
	TotalDaysTillMonth[i] = TotalDaysTillMonth[i - 1] + NumberOfDaysInMonth[i];
}

bool IsLeapYear(int Year)
{
if(Year % 4 != 0)
	return false;
else if(Year % 100 == 0 && Year % 400 == 0)
	return true;
else if(Year % 100 == 0 && Year % 400 != 0)
	return false;
else
	return true;
}

int DaysPassedInMonth(int Day, int Month, int Year)
{
return Day;
}

int DaysLeftInMonth(int Day, int Month, int Year)
{
if(Month != 2)
	return NumberOfDaysInMonth[Month] - Day;
else if(Month == 2 && IsLeapYear(Year))
	return NumberOfDaysInMonth[Month] + 1 - Day;
else
	return NumberOfDaysInMonth[Month] - Day;
}

int DaysPassedInYear(int Day, int Month, int Year)
{
int DaysPassed = TotalDaysTillMonth[Month - 1] + ((IsLeapYear(Year) && Month - 1 >= 2) ? 1 : 0);
DaysPassed += DaysPassedInMonth(Day, Month, Year);
return DaysPassed;
}

int DaysLeftInYear(int Day, int Month, int Year)
{
int DaysPassed = 0;
if(Month < 2)
	DaysPassed = TotalDaysTillMonth[Month];
else
	DaysPassed = TotalDaysTillMonth[Month] + (IsLeapYear(Year) ? 1 : 0);

int DaysLeft = (IsLeapYear(Year) ? 366 : 365) - DaysPassed;
DaysLeft += DaysLeftInMonth(Day, Month, Year);
return DaysLeft;
}

int TotalLeapYearsBetweenYears(int Year1, int Year2)
{
int NumberOfYears = Year2 - Year1 + 1;
return (NumberOfYears / 4) + (Year2 / 4) - (Year1 / 4);
}

int TotalDaysBetweenYears(int Year1, int Year2)
{
int NumberOfYears = Year2 - Year1 + 1;
int NumberOfLeapYears = TotalLeapYearsBetweenYears(Year1, Year2);

return NumberOfYears*365 + NumberOfLeapYears;
}

int main(int argc, char *argv[])
{
FillIntialDetails();

int Day1 = 10, Month1 = 2, Year1 = 2014;
int Day2 = 10, Month2 = 2, Year2 = 2015;

int NumberOfDays = TotalDaysBetweenYears(Year1, Year2) - DaysPassedInYear(Day1, Month1, Year1) - DaysLeftInYear(Day2, Month2, Year2);

return 0;
}