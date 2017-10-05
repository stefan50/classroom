#include <iostream>
using namespace std;

#define STACK_SIZE 10
class StackError
{
};

template<typename Used> class Stack
{
	Used data_[STACK_SIZE];
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

	void push(Used val)
	{
		if(full())
		{
			throw StackError();
			return;
		}
		data_[top_++] = val;
	}

	Used pop()
	{
		if(empty()) 
		{
			throw StackError();
		}
		return data_[--top_];
	}
};

int main()
{
	Stack<int> myst;
	//Stack<Stack<int> > st;
	try
	{
		myst.push(2);
		cout << myst.pop() << endl;
	} catch(...) {
		cout << "Error" << endl;
	}
	return 0;
}
