#include <bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> &input)
{
	stack<int> tmpStack;

	while (!input.empty())
	{
		int tmp = input.top();
		input.pop();

		while (!tmpStack.empty() && tmpStack.top() < tmp)
		{
			input.push(tmpStack.top());
			tmpStack.pop();
		}
		tmpStack.push(tmp);
	}

	return tmpStack;
}

int main()
{
	stack<int> input;
	input.push(7);
	input.push(2);
	input.push(3);
	input.push(8);
	input.push(5);
	input.push(6);

	stack<int> tmpStack = sortStack(input);
	cout << "Sorted numbers are:\n";

	while (!tmpStack.empty())
	{
		cout << tmpStack.top()<< " ";
		tmpStack.pop();
	}

    return 0;
}
