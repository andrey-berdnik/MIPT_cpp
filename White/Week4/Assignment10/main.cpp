#include <iostream>
#include <exception>
using namespace std;

class Rational
{
public:
	Rational()
	{
		_numerator = 0;
		_denominator = 1;
	}

	Rational(int numerator, int denominator)
	{
		_numerator = numerator / (nod(numerator, denominator));
		_denominator = denominator / (nod(numerator, denominator));
		normalization(_numerator, _denominator);
		if (_denominator == 0)
		{
			throw invalid_argument("invalid_argument");
		}
	}

	int Numerator() const
	{  
		return _numerator;
	}

	int Denominator() const
	{  
		return _denominator;
	}

private:
	void normalization(int &a, int &b)
	{
		if ((a > 0 && b < 0) || (a < 0 && b < 0))
		{
			a = -a;
			b = -b;
		}
	}
	int nod(int a, int b)
	{
		return b == 0 ? a : nod(b, a % b);
	}
 
	int _numerator; 
	int _denominator; 
};


Rational operator/(const Rational &r_1, const Rational &r_2)
{
	int Numerator = 0;
	int Denominator = 0;
	if (r_2.Numerator() == 0)
	{
		throw domain_error("domain_error");
	}
	Denominator = r_1.Denominator() * r_2.Numerator();
	Numerator = r_1.Numerator() * r_2.Denominator();

	return Rational(Numerator, Denominator);
}

int main()
{
	try
	{
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument &)
	{
	}

	try
	{
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error &)
	{
	}

	cout << "OK" << endl;
	return 0;
}