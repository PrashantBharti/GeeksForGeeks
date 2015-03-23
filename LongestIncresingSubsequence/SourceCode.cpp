// Solution for below link
// http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

typedef vector<int> SEQUENCE;
typedef list<SEQUENCE> LISTSEQUENCE;

void PrepareSequence(int value, LISTSEQUENCE &lssequence)
{
if(lssequence.size())
	{
	LISTSEQUENCE::iterator itrSequence = lssequence.end();
	itrSequence--;
	while(itrSequence != lssequence.begin())
		{
		if(itrSequence->back() > value)
			itrSequence--;
		else
			{
			SEQUENCE sequence(itrSequence->begin(), itrSequence->end());
			sequence.push_back(value);

			itrSequence++;
			if(itrSequence == lssequence.end())
				lssequence.push_back(sequence);
			else if(itrSequence->size() == sequence.size())
				{
				itrSequence->clear();
				*itrSequence = sequence;
				}
			else
				lssequence.insert(itrSequence, sequence);

			return;
			}
		}

	if(itrSequence->back() > value)
		{
		SEQUENCE sequence;
		sequence.push_back(value);
		itrSequence->clear();
		*itrSequence = sequence;
		}
	else
		{
		SEQUENCE sequence(itrSequence->begin(), itrSequence->end());
		sequence.push_back(value);

		itrSequence++;
		if(itrSequence == lssequence.end())
			lssequence.push_back(sequence);
		else if(itrSequence->size() == sequence.size())
			{
			itrSequence->clear();
			*itrSequence = sequence;
			}
		else
			lssequence.insert(itrSequence, sequence);
		}
	}
else
	{
	SEQUENCE sequence;
	sequence.push_back(value);
	lssequence.push_back(sequence);
	}
}

int main(int argc, char *argv[])
{
int szArr = 0;
cin >> szArr;

SEQUENCE sequenceMain(szArr);
for(int i = 0; i < szArr; ++i)
	cin >> sequenceMain[i];

LISTSEQUENCE lssequence;
for(int i = 0; i < szArr; ++i)
	PrepareSequence(sequenceMain[i], lssequence);

SEQUENCE &sequenceLongest = lssequence.back();
for(size_t i = 0; i < sequenceLongest.size(); ++i)
	cout << sequenceLongest[i] << " ";
cout << endl;

return 0;
}