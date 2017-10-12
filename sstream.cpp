#include <iostream> //SHTO E TO STRING?
#include <string>
#include <sstream>

using namespace std;

int main()
{

	string s1 = "3.14 42";
	istringstream in(s1);
	double pi;
	int answer;
	in >> pi;
	in >> answer;

	cout << pi << endl << answer << endl;

	if(in.good())
	{
		cout << "Good!" << endl;
	} 
	else 
	{
		cout << "Bad" << endl;
	}
	if(in.eof())
	{
		cout << "eof" << endl;
	}
	if(!in.fail())
	{
		cout << "success" << endl;
	}
		
	return 0;
}
