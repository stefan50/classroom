#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	char c;
	ostringstream out;	
	out << 3.14 << ", " << 42 << endl << "<3";

	string s = out.str();
	
	cout << "s = " << s << endl;
	return 0;
}
