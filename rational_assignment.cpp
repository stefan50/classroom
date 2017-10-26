#include <iostream>

using namespace std;

int gcd(long a, long b)
{
	int gcd_n = a < b ? a : b;
	while (gcd_n != 1)
	{
		if(a % gcd_n == 0 && b % gcd_n == 0)
		{
			return gcd_n;
		}
		gcd_n--;
	}
	return gcd_n;
}

class Rational
{
	long num_;
	long den_;
public:
	Rational(long num, long den)
	{
		num_ = num;
		den_ = den;
	}
	long const get_numerator()
	{
		return num_;
	}
	long const get_denominator()
	{
		return den_;
	}
	Rational& normalise()
	{
		int gcd_n = gcd(num_,den_);
		num_ /= gcd_n;
		den_ /= gcd_n;
		return *this;
	}
	Rational& add(const Rational& r)
	{
		this->num_ += r.num_;
		this->normalise();
		return *this;
	}
	Rational& sub(const Rational& r)
	{
	}
};

int main()
{
	Rational number(2,5),num2(2,4);
	Rational sum(0,0);
	number.normalise();
	num2.normalise();
	number.add(num2);
	cout << number.get_numerator() << "/" << number.get_denominator() << endl;
}
