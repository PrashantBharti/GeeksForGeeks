// Solution of below link
// http://www.geeksforgeeks.org/dynamic-programming-set-14-maximum-sum-increasing-subsequence/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
int szArr;
cin >> szArr;

vector<int> vcArr;
for(int i = 0; i < szArr; ++i)
	{
	int num  = 0;
	cin >> num;
	vcArr.push_back(num);
	}

vector<int> vcBestSum;

int iBestSumEver = INT_MIN;
for(int i = 0; i < szArr; ++i)
	{
	int iBestSum = vcArr[i];
	for(int j = 0; j < i; ++j)
		{
		if(vcArr[j] > vcArr[i])
			continue;
		else
			iBestSum = iBestSum > vcBestSum[j] + vcArr[i] ? iBestSum : vcBestSum[j] + vcArr[i];
		}

	vcBestSum.push_back(iBestSum);
	if(iBestSumEver < iBestSum)
		iBestSumEver = iBestSum;
	}

return 0;
}