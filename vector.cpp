#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vi;
	vector<double> vec(100); //100 elements

	vi.push_back(-1); //new element at the end of the vector
	for(int i = 0;i < 10; i++)
	{
		vi.push_back(i);
	}
	vi.pop_back();
	//cout << "size = " << vi.size() << endl << "cap = " << vi.capacity() << endl << "empty  = " << vi.empty() << endl;

	for(int i = 0;i < vi.size(); i++)
	{
		cout << vi[i] << endl;
	}

	cout << vi.at(42) << endl; //throws exception

	for(vector<int>::iterator it = vi.begin(); it!=vi.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}
