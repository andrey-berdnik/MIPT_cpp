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
			throw invalid_argument("Invalid argument");
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

bool operator==(const Rational &r_1, const Rational &r_2)
{
	if ((r_1.Numerator() == r_2.Numerator()) && (r_1.Denominator() == r_2.Denominator()))
		return true;
	else
		return false;
}

Rational operator+(const Rational &r_1, const Rational &r_2)
{
	int Numerator = 0;
	int Denominator = 0;
	Denominator = r_1.Denominator() * r_2.Denominator();
	Numerator = r_1.Numerator() * r_2.Denominator() + r_2.Numerator() * r_1.Denominator();
	return Rational(Numerator, Denominator);
}

Rational operator-(const Rational &r_1, const Rational &r_2)
{
	int Numerator = 0;
	int Denominator = 0;
	Denominator = r_1.Denominator() * r_2.Denominator();
	Numerator = r_1.Numerator() * r_2.Denominator() - r_2.Numerator() * r_1.Denominator();
	return Rational(Numerator, Denominator);
}

Rational operator/(const Rational &r_1, const Rational &r_2)
{
	int Numerator = 0;
	int Denominator = 0;
	if (r_2.Numerator() == 0)
	{
		throw domain_error("Division by zero");
	}
	Denominator = r_1.Denominator() * r_2.Numerator();
	Numerator = r_1.Numerator() * r_2.Denominator();

	return Rational(Numerator, Denominator);
}

Rational operator*(const Rational &r_1, const Rational &r_2)
{
	int Numerator = 0;
	int Denominator = 0;
	Denominator = r_1.Denominator() * r_2.Denominator();
	Numerator = r_1.Numerator() * r_2.Numerator();
	return Rational(Numerator, Denominator);
}

ostream &operator<<(ostream &stream, const Rational &r)
{
	stream << r.Numerator() << "/" << r.Denominator();
	return stream;
}

istream &operator>>(istream &stream, Rational &r)
{
	char delenie;
	int a, b;
	stream >> a >> delenie >> b;
	if (stream && delenie == '/')
	{
		r = Rational(a, b);
	}
	return stream;
}

bool operator>(Rational a, Rational b)
{
	return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}
bool operator<(Rational a, Rational b)
{
	return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}

int main(int argc, char const *argv[])
{
	Rational rat1, rat2, rat_out;
	char cmd;

	try
	{
		cin >> rat1;
		cin >> cmd;
		cin >> rat2;

		

		try
		{
			if (cmd == '+')
			{
				rat_out = rat1 + rat2;
			}
			else if (cmd == '-')
			{
				rat_out = rat1 - rat2;
			}
			else if (cmd == '*')
			{
				rat_out = rat1 * rat2;
			}
			else
			{
				rat_out = rat1 / rat2;
			}
			cout << rat_out << endl;
		}
		catch (domain_error &err2)
		{
			cout << err2.what() << endl;
		}
	}
	catch (invalid_argument &err1)
	{
		cout << err1.what() << endl;
	}

	return 0;
}