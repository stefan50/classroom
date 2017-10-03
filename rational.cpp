#include <iostream>
using namespace std;

int gcd(int n1, int n2)
{
	int gcd = n1 < n2 ? n1 : n2;
	while (gcd != 1)
	{
		if(n1%gcd == 0 && n2%gcd == 0)
			return gcd;
		gcd--;
	}
	return gcd;
}

class Rational
{
	int numerator_;
	int denominator_;
public:
	Rational(int numerator, int denominator)
	{
		int gcds = gcd(numerator, denominator);		
		numerator_ = numerator/gcds;
		denominator_ = denominator/gcds;	
			
	}
	int get_numerator()
	{
		return numerator_;
	}
	
	void set_numerator(int numerator)
	{
		numerator_ = numerator;
	}

	int get_denominator()
	{
		return denominator_;
	}
	
	void set_denominator(int denominator)
	{
		denominator_ = denominator;
	}
	
	void print()
	{
		cout << numerator_ << "/" << denominator_ << endl;
	}

	bool is_equal(Rational num)
	{
		return numerator_ == num.numerator_ && denominator_ == num.denominator_;
	}
	
};

int main()
{
	Rational mynum(2,4), yonum(10,20);
	mynum.print();
	cout << mynum.is_equal(yonum) << endl;	
	return 0;	
}
