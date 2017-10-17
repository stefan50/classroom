#include <iostream>
using namespace std;

class Point
{
	double x_, y_;
	double cx_, cy_;
public:	
	static const double DEFAULT_CX_ = 0, DEFAULT_CY_ = 0;
	Point(double x, double y, double cx, double cy) //default stoynosti oburkva Emo
	: x_(x), y_(y), cx_(cx), cy_(cy) {}
	/*{	
		x_ = x;
		y_ = y;
		cx_ = cx;
		cy_ = cy;
	}*/
	Point(double x, double y) 
	: x_(x), y_(y), cx_(DEFAULT_CX_), cy_(DEFAULT_CY_) {}
	/*{
		x_ = x;
		y_ = y;
		cx_ = DEFAULT_CX_;
		cy_ = DEFAULT_CY_;
	}*/

	static Point get_default_beginning()
	{
		//code doesn't compile if we use class members in static function!		
		return Point(DEFAULT_CX_, DEFAULT_CY_);
	}
	
	double get_x()
	{
		return x_;
	}
	double get_y()
	{
		return y_;
	}
	double get_cx()
	{
		return cx_;
	}
	void set_x(double x)
	{
		x_ = x;
	}
	void set_y(double y)
	{
		y_ = y;
	}
	void print()
	{
		cout << "(" << x_ << "," << y_ << ")" << " in "
			 << "(" << cx_ << "," << cy_ << ")" << endl; 
	}
	Point transform_in_default()
	{
		return transform_in(DEFAULT_CX_, DEFAULT_CY_);
	}
	Point transform_in(double new_cx, double new_cy)
	{
		return Point(x_ + cx_ - new_cx, y_ + cy_ - new_cy, new_cx, new_cy);
	}
};
	
int main()
{
	Point mypo(-3,-1,5,3);	
	cout << "Default coord system is ";
	Point::get_default_beginning().print();
	cout << "My point is ";	
	mypo.print();
	cout << "My point is ";
	mypo.transform_in_default().print();
	cout << "My point is ";	
	mypo.transform_in(1,1).print();	
	return 0;
}
