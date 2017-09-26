#include <iostream>
using namespace std;

#define STACK_SIZE 10
class Stack
{
	int data_[STACK_SIZE];
	int top_;
public:
	Stack()
	{
		top_ = 0;
	}

	bool empty()
	{
		return top_ == 0;
	}	

	bool full()
	{
		return top_ == STACK_SIZE;
	}
	void push(int val)
	{
		if(full())
		{
			cout << "OOPS! I'm full" << endl;
			return;
		}
		data_[top_++] = val;
	}
	int pop()
	{
		if(empty()) 
		{
			cout << "Fill me, Daddy" << endl;
			return -1;
		}
		return data_[--top_];
	}
};

int main()
{
	Stack myst;
	myst.push(0);
	cout << myst.pop() << endl;
	return 0;
}
