// Solution for below link
// http://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

#include <iostream>
#include <vector>
using namespace std;

void Swap(int &a, int &b)
{
a = a^b;
b = a^b;
a = a^b;
}

int main(int argc, char *argv[])
{
size_t nbItems = 0;
cin >> nbItems;

vector<int> vcNumbers(nbItems);
for(size_t i = 0; i < nbItems; ++i)
	cin >> vcNumbers[i];

int idx0 = -1;
int idx2 = nbItems;
int idxUnknown = idx0 + 1;

while(idxUnknown < idx2)
	{
	if(vcNumbers[idxUnknown] == 0)
		{
		Swap(vcNumbers[++idx0], vcNumbers[idxUnknown]);
		idxUnknown++;
		}
	else if(vcNumbers[idxUnknown] == 1)
		idxUnknown++;
	else
		Swap(vcNumbers[--idx2], vcNumbers[idxUnknown]);
	}

for(size_t i = 0; i < nbItems; ++i)
	cout << vcNumbers[i];

return 0;
}