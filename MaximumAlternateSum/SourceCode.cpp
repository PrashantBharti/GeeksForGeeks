// Solution for below link
// http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> PAIR;
typedef vector<PAIR> ARRAY;

int main(int argc, char *argv[])
{
size_t nbNumbers = 0;
cin >> nbNumbers;

ARRAY array(nbNumbers);
for(size_t i = 0; i < nbNumbers; ++i)
	{
	int num = 0;
	cin >> num;

	array[i].first = num;
	
	if(i == 0)
		array[i].second = num;
	else if(i == 1)
		array[i].second = max(array[0].second, num);
	else
		array[i].second = max(array[i-2].second + num, array[i-1].second);
	}

cout << "Maximum value is: " << array[nbNumbers - 1].second << endl;

return 0;
}