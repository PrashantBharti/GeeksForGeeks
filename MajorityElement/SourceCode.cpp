#include <iostream>
using namespace std;

int TestForMajority(int arrInput[], size_t szInput)
{
if(arrInput == NULL || szInput == 0)
	return 0;

int count = 1;
int majoritynominee = arrInput[0];
for(size_t i = 1; i < szInput; ++i)
	{
	if(count == 0)
		{
		count++;
		majoritynominee = arrInput[i];
		}
	else if(arrInput[i] != arrInput[i-1])
		{
		count--;
		if(count == 0)
			{
			count++;
			majoritynominee = arrInput[i];
			}
		}
	else
		count++;
	}

return majoritynominee;
}

bool TestForEven(int arrInput[], size_t szInput, int *ptrOutput, int *ptrOutputPrev)
{
if(arrInput == NULL || ptrOutput == NULL)
	return false;

int majoritynominee = TestForMajority(arrInput, szInput);

if(majoritynominee == *ptrOutputPrev)
	{
	*ptrOutput = majoritynominee;
	return true;
	}

return false;
}

bool TestForOdd(int arrInput[], size_t szInput, int *ptrOutput)
{
if(arrInput == NULL || ptrOutput == NULL)
	return false;

if(szInput == 1)
	{
	*ptrOutput = arrInput[0];
	return true;
	}

int majoritynominee = TestForMajority(arrInput, szInput);

if(majoritynominee != arrInput[szInput - 1])
	{
	*ptrOutput = majoritynominee;
	return true;
	}

return TestForEven(arrInput, szInput - 1, ptrOutput, &majoritynominee);
}

bool TestForOdd(int arrInput[], size_t szInput, int *ptrOutput, int *ptrOutputPrev)
{
if(arrInput == NULL || ptrOutput == NULL)
	return false;

if(szInput == 1)
	{
	*ptrOutput = arrInput[0];
	return true;
	}

int majoritynominee = TestForMajority(arrInput, szInput);

if(majoritynominee == *ptrOutputPrev)
	{
	*ptrOutput = majoritynominee;
	return true;
	}

return TestForEven(arrInput, szInput - 1, ptrOutput, &majoritynominee);
}

bool TestForEven(int arrInput[], size_t szInput, int *ptrOutput)
{
if(arrInput == NULL || ptrOutput == NULL)
	return false;

int majoritynominee = TestForMajority(arrInput, szInput);

if(majoritynominee != arrInput[szInput - 1])
	{
	*ptrOutput = majoritynominee;
	return true;
	}

return TestForOdd(arrInput, szInput - 1, ptrOutput, &majoritynominee);
}

int main(int argc, char* argv[])
{
size_t szInput;
cout << "Enter the size of input: ";
cin >> szInput;

int *arrInput = new int[szInput];
memset(arrInput, 0, sizeof(int)*szInput);

cout << "Enter the input array: ";
for(size_t i = 0; i < szInput; ++i)
	cin >> arrInput[i];

int majorityelement = 0;
bool bhasmajority = false;
if(szInput % 2 != 0)
	bhasmajority = TestForOdd(arrInput, szInput, &majorityelement);
else
	bhasmajority = TestForEven(arrInput, szInput, &majorityelement);

if(bhasmajority)
	cout << "Majority element is " << majorityelement << endl;
else
	cout << "No majority element" << endl;

delete[] arrInput;
return 0;
}