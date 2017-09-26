#include <iostream>
using namespace std;

class Point
{
//private
	double x_; //naming convention
	double y_;
public:
	Point() //no arguments = default constructor
	{
		x_ = 6;
		y_ = 6;
	}
	Point(double x, double y) 
	{
		x_ = x;
		y_ = y;	
	}
	double get_x()
	{
		return x_;
	}
	double get_y()
	{
		return y_;
	}
};

class Rectangle 
{
	Point m_;
	Point n_;
public:
	
};
int main()
{
	Point mypo(2,3), yopo; //yopo = 0, 0 (default)	
	//cout << "I have " << mypo.get_x() << ", " << mypo.get_y() << endl;
	//cout << "You have " << yopo.get_x() << ", " << yopo.get_y() << endl;	
	Rectangle myrec;
	cout << myrec.get_x() <<" " << myrec.get_y() << endl;			
	return 0;
}
