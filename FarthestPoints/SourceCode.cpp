// Solution for below link
// http://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
int nbNumbers = 0;
cin >> nbNumbers;

vector<int> vcNumbers(nbNumbers);
vector<int> vcLeftMin(nbNumbers);
vector<int> vcRightMax(nbNumbers);

for(int i = 0; i < nbNumbers; ++i)
	cin >> vcNumbers[i];

int minimum = INT_MAX;
for(int i = 0; i < nbNumbers; ++i)
	{
	if(minimum < vcNumbers[i])
		vcLeftMin[i] = minimum;
	else
		{
		vcLeftMin[i] = vcNumbers[i];
		minimum = vcNumbers[i];
		}
	}

int maximum = INT_MIN;
for(int i = nbNumbers - 1; i >= 0; --i)
	{
	if(maximum > vcNumbers[i])
		vcRightMax[i] = maximum;
	else
		{
		vcRightMax[i] = vcNumbers[i];
		maximum = vcNumbers[i];
		}
	}

int idxLeftMin = 0;
int idxRightMax = 0;
int diffIdx = 0;
int diffIdxTemp = 0;
while(idxLeftMin < nbNumbers)
	{
	while(vcRightMax[idxRightMax] > vcLeftMin[idxLeftMin])
		++idxRightMax;

	diffIdxTemp = idxRightMax - 1 - idxLeftMin;
	if(diffIdxTemp > diffIdx)
		diffIdx = diffIdxTemp;

	idxLeftMin++;
	}

cout << diffIdx;
return 0;
}