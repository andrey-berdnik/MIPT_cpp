#include <iostream>
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

bool operator==(const Rational &r_1, const Rational &r_2)
{
	if ((r_1.Numerator() == r_2.Numerator()) && (r_1.Denominator() == r_2.Denominator()))
		return true;
	else
		return false;
}

Rational operator*(const Rational &r_1, const Rational &r_2)
{
	int Numerator = 0;
	int Denominator = 0;
	Denominator = r_1.Denominator() * r_2.Denominator();
	Numerator = r_1.Numerator() * r_2.Numerator();
	return Rational(Numerator, Denominator);
}

Rational operator/(const Rational &r_1, const Rational &r_2)
{
	int Numerator = 0;
	int Denominator = 0;
	Denominator = r_1.Denominator() * r_2.Numerator();
	Numerator = r_1.Numerator() * r_2.Denominator();
	return Rational(Numerator, Denominator);
}

int main()
{
	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal)
		{
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal)
		{
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}

	cout << "OK" << endl;
	return 0;
}