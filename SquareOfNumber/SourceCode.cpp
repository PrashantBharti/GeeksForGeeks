#include <iostream>
#include <cmath>
using namespace std;

unsigned int Square(int num)
{
if(num == 0)
	return 0;

int halfnum = num >> 1;
unsigned int sqrnum = 0;
if(num % 2 == 0)
	sqrnum = (Square(halfnum) << 2);
else
	sqrnum = (Square(halfnum) << 2) + (halfnum << 2) + 1;

return sqrnum;
}

int main(int argc, char* argv[])
{
int num = 0;
cout << "Enter the number to be squared: ";
cin >> num;

unsigned int sqrnum = Square(abs(num));
cout << "Square is: " << sqrnum << endl;

return 0;
}