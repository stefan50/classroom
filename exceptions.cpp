#include <iostream>
#define STACK_SIZE 10
using namespace std;

class StackError 
{
	char sterror_[20];
public:
	StackError(char error[20])
	{
		sterror_ = error;
	}
	char get_msg()[20]
	{
		return sterror_;
	}
};

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
			throw StackError("Stack is full.");
		}
		data_[top_++] = val;
	}
	int pop()
	{
		if(empty()) 
		{
			cout << "Fill me, Daddy" << endl;
			throw StackError("Stack is empty.");
		}
		return data_[--top_];
	}
};

int main()
{
	Stack myst;
	try
	{
		myst.push(0);
		cout << myst.empty() << endl;		
		cout << myst.full() << endl;
		
		for(int i=1; i<11; ++i)
		{
			myst.push(i);
		}
		
	} catch(StackError ex) {
		cout << ex.get_msg() << endl;
	}	
	while(!myst.empty())
	{
		cout << "pop: " << myst.pop() << endl;
	}
	return 0;
}
