// Solution for below link
// http://www.geeksforgeeks.org/implement-two-stacks-in-an-array/

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Stacks2
{
public:
	Stacks2(int szStack);

public:
	enum class STACKIDX {STACK1, STACK2};

public:
	void PushInStack(int num, STACKIDX stackidx);
	int PopFromStack(STACKIDX stackidx);

private:
	typedef pair<int, int> StackData;

private:
	vector<StackData> vcStack;
	queue<int> quNextIdx;
	int idxTopStack1;
	int idxTopStack2;
};

Stacks2::Stacks2(int szStack)
: vcStack(szStack)
, quNextIdx()
, idxTopStack1(-1)
, idxTopStack2(-1)
{
for(int i = 0; i < szStack; ++i)
	quNextIdx.push(i);
}

void Stacks2::PushInStack(int num, Stacks2::STACKIDX stackidx)
{
if(quNextIdx.empty())
	return;

if(stackidx == STACKIDX::STACK1)
	{
	StackData stackdata(num, idxTopStack1);
	idxTopStack1 = quNextIdx.front();
	vcStack[idxTopStack1] = stackdata;
	quNextIdx.pop();
	}
else if(stackidx == STACKIDX::STACK2)
	{
	StackData stackdata(num, idxTopStack2);
	idxTopStack2 = quNextIdx.front();
	vcStack[idxTopStack2] = stackdata;
	quNextIdx.pop();
	}

}

int Stacks2::PopFromStack(Stacks2::STACKIDX stackidx)
{
int val = INT_MIN;
if(stackidx == STACKIDX::STACK1 && idxTopStack1 != -1)
	{
	StackData stackdata = vcStack[idxTopStack1];
	val = stackdata.first;
	quNextIdx.push(idxTopStack1);
	idxTopStack1 = stackdata.second;
	}
else if(stackidx == STACKIDX::STACK2 && idxTopStack2 != -1)
	{
	StackData stackdata = vcStack[idxTopStack2];
	val = stackdata.first;
	quNextIdx.push(idxTopStack2);
	idxTopStack2 = stackdata.second;
	}

return val;
}

int main(int __argc, char *argv[])
{
Stacks2 stacks2(5);

stacks2.PushInStack(11, Stacks2::STACKIDX::STACK1);
stacks2.PushInStack(21, Stacks2::STACKIDX::STACK2);
stacks2.PushInStack(12, Stacks2::STACKIDX::STACK1);
stacks2.PushInStack(22, Stacks2::STACKIDX::STACK2);

int val2 = stacks2.PopFromStack(Stacks2::STACKIDX::STACK2);
int val1 = stacks2.PopFromStack(Stacks2::STACKIDX::STACK1);

return 0;
}