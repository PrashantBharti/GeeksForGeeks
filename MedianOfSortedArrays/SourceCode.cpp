// Solution for below link
// http://www.geeksforgeeks.org/median-of-two-sorted-arrays/

#include <iostream>
using namespace std;

double GetMedian(int arr1[], size_t arr1IdxStart, size_t arr1IdxEnd, int arr2[], size_t arr2IdxStart, size_t arr2IdxEnd)
{
size_t szArr1 = arr1IdxEnd - arr1IdxStart + 1;
size_t szArr2 = arr2IdxEnd - arr2IdxStart + 1;

if(szArr1 == 1 && szArr2 == 1)
	return (arr1[arr1IdxStart] + arr2[arr2IdxStart]) / 2.0;

int arr1IdxMid = (arr1IdxEnd - arr1IdxStart) / 2 + arr1IdxStart;
int arr2IdxMid = (arr2IdxEnd - arr2IdxStart) / 2 + arr2IdxStart;

double median1 = 0;
if(szArr1 % 2 == 0)
	median1 = (arr1[arr1IdxMid] + arr1[arr1IdxMid + 1]) / 2.0;
else
	median1 = arr1[arr1IdxMid];

double median2 = 0;
if(szArr2 % 2 == 0)
	median2 = (arr2[arr2IdxMid] + arr2[arr2IdxMid + 1]) / 2.0;
else
	median2 = arr2[arr2IdxMid];

if(median1 < median2)
	{
	if(szArr1 % 2 == 0)
		arr1IdxStart = arr1IdxMid + 1;
	else
		arr1IdxStart = arr1IdxMid;

	arr2IdxEnd = arr2IdxMid;
	return GetMedian(arr1, arr1IdxStart, arr1IdxEnd, arr2, arr2IdxStart, arr2IdxEnd);
	}
else if(median1 > median2)
	{
	if(szArr2 % 2 == 0)
		arr2IdxStart = arr2IdxMid + 1;
	else
		arr2IdxStart = arr2IdxMid;

	arr1IdxEnd = arr1IdxMid;
	return GetMedian(arr1, arr1IdxStart, arr1IdxEnd, arr2, arr2IdxStart, arr2IdxEnd);
	}
else
	return median1;
}

int main(int argc, char* argv[])
{
int arr1[6] = {3, 6, 9, 10, 11, 19};
int arr2[6] = {1, 2, 4, 9, 14, 19};

double median = GetMedian(arr1, 0, 5, arr2, 0, 5);

return 0;
}