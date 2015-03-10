// Solution for below link
// http://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/

#include <iostream>
#include <cmath>
using namespace std;

void Swap(int &a, int &b)
{
a = a^b;
b = a^b;
a = a^b;
}

void ReverseArray(int Array[], size_t szArray, size_t idxStart, size_t idxEnd)
{
if(idxStart >= idxEnd || idxEnd >= szArray)
	return;

while(idxStart < idxEnd)
	{
	Swap(Array[idxStart], Array[idxEnd]);
	idxStart++;
	idxEnd--;
	}
}

void RotateArray(int Array[], size_t szArray, int Value)
{
if(szArray <= 1)
	return;

if(Value > 0)
	{
	Value = abs(Value) % szArray;
	size_t idxStart1 = 0;
	size_t idxEnd1 = szArray - 1 - Value;
	size_t idxStart2 = idxEnd1 + 1;
	size_t idxEnd2 = szArray - 1;

	ReverseArray(Array, szArray, idxStart1, idxEnd1);
	ReverseArray(Array, szArray, idxStart2, idxEnd2);
	ReverseArray(Array, szArray, 0, szArray - 1);
	}
else if(Value < 0)
	{
	Value = abs(Value) % szArray;
	size_t idxStart1 = 0;
	size_t idxEnd1 = Value - 1;
	size_t idxStart2 = idxEnd1 + 1;
	size_t idxEnd2 = szArray - 1;

	ReverseArray(Array, szArray, idxStart1, idxEnd1);
	ReverseArray(Array, szArray, idxStart2, idxEnd2);
	ReverseArray(Array, szArray, 0, szArray - 1);
	}
}

int main(int argc, char* argv[])
{
int Array[5] = {1, 2, 3, 4, 5};

RotateArray(Array, sizeof(Array)/sizeof(int), -2);

return 0;
}