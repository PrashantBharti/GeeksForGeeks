// Solution for below link
// http://www.geeksforgeeks.org/how-to-print-maximum-number-of-a-using-given-four-keys/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void CalculateNbAs(vector<int> &nbAs, int nbMaxStrokes)
{
nbAs[0] = 0;
nbAs[1] = 1;
nbAs[2] = 2;
nbAs[3] = 3;

if(nbMaxStrokes >= 4)
	{
	int nbMaxAs = nbMaxStrokes;
	int power = 2;
	for(int nbStrokes = nbMaxStrokes - 3; nbStrokes >= 1; --nbStrokes)
		{
		if(nbAs[nbStrokes] == 0)
			CalculateNbAs(nbAs, nbStrokes);

		nbMaxAs = max(nbMaxAs, power*nbAs[nbStrokes]);

		power++;
		}

	nbAs[nbMaxStrokes] = nbMaxAs;
	}
}

int main(int argc, char* argv[])
{
int nbMaxStrokes = 0;
cin >> nbMaxStrokes;

vector<int> nbAs(nbMaxStrokes+1);
CalculateNbAs(nbAs, nbMaxStrokes);

cout << nbAs[nbMaxStrokes];
return 0;
}