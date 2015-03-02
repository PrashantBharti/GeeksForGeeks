// Solution for
// http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
size_t szInput = 0;
cout << "Enter the size of input: ";
cin >> szInput;

vector<int> vcInput(szInput);
cout << "Enter the array elemnts: ";
for(size_t i = 0; i < szInput; ++i)
	cin >> vcInput[i];

int iSumForTest = 0;
cout << "Enter the sum value to test: ";
cin >> iSumForTest;

map<int, size_t> hashmap;
size_t idx = 0;
for(int num : vcInput)
	{
	int iDiff = iSumForTest - num;
	if(hashmap[iDiff] != 0)
		cout << "Found pair " << num << " and " << iDiff << endl;
	else
		hashmap[num] = ++idx;
	}

return 0;
}