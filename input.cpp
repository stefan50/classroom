#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string token;
	
	while(true)
	{
		cin >> token;
		if(!cin.good())
		{
			break;
		}
		cout << token << endl;
		double val;
		istringstream in(token);
		in >> val;
		if(!in.fail() && in.eof()) 
		{		
			cout << "success: val= " << val << endl;
		} 
		else 
		{
			cout << "Ne moje " << token << endl; 
		}		
		/*if(!in.fail())
		{
			cout << "SUCCESS: val = " << val << endl;
			if(!in.eof())
			{				
				string tmp;
				in >> tmp;
				cout << "TAIL FROM STREAM: " << tmp << endl;
			}
		}
		else
		{
			cout << "Sori motori:" << token << endl; 
		}*/
	}

	return 0;
}
