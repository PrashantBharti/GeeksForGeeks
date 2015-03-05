// Solution for below link
// http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

#include <iostream>
#include <vector>
using namespace std;

size_t ImprovedBinarySearch(vector<int> vcInput, size_t idxStart, size_t idxEnd, int iValue)
{
size_t idxMid = idxStart + (idxEnd - idxStart + 1) / 2;

if(vcInput[idxMid] == iValue)
	return idxMid;
else if(idxEnd - idxStart + 1 == 1)
	return UINT_MAX;
else if(vcInput[idxMid] > iValue)
	{
	if(idxMid == idxStart)
		return ImprovedBinarySearch(vcInput, idxMid + 1, idxEnd, iValue);
	else if(idxMid == idxEnd)
		return ImprovedBinarySearch(vcInput, idxStart, idxMid - 1, iValue);
	else
		{
		if(vcInput[idxMid - 1] < vcInput[idxMid] && vcInput[idxMid] < vcInput[idxMid + 1])
			return ImprovedBinarySearch(vcInput, idxStart, idxMid - 1, iValue);
		else if(vcInput[idxMid - 1] > vcInput[idxMid] && vcInput[idxMid] > vcInput[idxMid + 1])
			return ImprovedBinarySearch(vcInput, idxMid + 1, idxEnd, iValue);
		else
			{
			size_t idxLeft = ImprovedBinarySearch(vcInput, idxStart, idxMid - 1, iValue);
			size_t idxRight = ImprovedBinarySearch(vcInput, idxMid + 1, idxEnd, iValue);
			
			if(idxLeft < UINT_MAX)
				return idxLeft;
			else
				return idxRight;
			}
		}
	}
else
	{
	if(idxMid == idxStart)
		return ImprovedBinarySearch(vcInput, idxMid + 1, idxEnd, iValue);
	else if(idxMid == idxEnd)
		return ImprovedBinarySearch(vcInput, idxStart, idxMid - 1, iValue);
	else
		{
		if(vcInput[idxMid - 1] < vcInput[idxMid] && vcInput[idxMid] < vcInput[idxMid + 1])
			return ImprovedBinarySearch(vcInput, idxMid + 1, idxEnd, iValue);
		else if(vcInput[idxMid - 1] > vcInput[idxMid] && vcInput[idxMid] > vcInput[idxMid + 1])
			return ImprovedBinarySearch(vcInput, idxStart, idxMid - 1, iValue);
		else
			{
			size_t idxLeft = ImprovedBinarySearch(vcInput, idxStart, idxMid - 1, iValue);
			size_t idxRight = ImprovedBinarySearch(vcInput, idxMid + 1, idxEnd, iValue);
			
			if(idxLeft < UINT_MAX)
				return idxLeft;
			else
				return idxRight;
			}
		}
	}
}

int main(void)
{
vector<int> vcInput;
// 1 2 3 4 5
vcInput.push_back(5);
vcInput.push_back(1);
vcInput.push_back(2);
vcInput.push_back(3);
vcInput.push_back(4);

size_t idx = ImprovedBinarySearch(vcInput, 0, vcInput.size()-1, 4);

return 0;
}