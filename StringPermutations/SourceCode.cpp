#include <fstream>
#include <map>
using namespace std;

void Swap(string &strin, unsigned int idxFirst, unsigned int idxSecond)
{
char temp = strin[idxFirst];
strin[idxFirst] = strin[idxSecond];
strin[idxSecond] = temp;
}

string Permute(string &strin, unsigned int idxStart, fstream &fileio)
{
if(strin.length() <= 0 || idxStart >= strin.length())
	return strin;

if(idxStart == strin.length() - 1)
	{
	fileio << strin.c_str() << endl;
	return strin;
	}

Permute(strin, idxStart + 1, fileio);
for(unsigned int idx = idxStart+1; idx < strin.length(); ++idx)
	{
	if(strin[idx] == strin[idxStart])
		continue;

	Swap(strin, idxStart, idx);
	Permute(strin, idxStart + 1, fileio);
	Swap(strin, idx, idxStart);
	}

return strin;
}

int main(int argc, char *argv)
{
fstream fileio;
fileio.open("output.txt", fstream::out);

string strin = "ABA";
Permute(strin, 0, fileio);

fileio.close();
return 0;
}