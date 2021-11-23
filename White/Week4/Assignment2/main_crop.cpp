#include <iostream>
#include <vector>
#include <algorithm>

class FunctionPart
{
public:
	FunctionPart(char newOperation, double newValue)
	{
		operation = newOperation;
		value = newValue;
	}
	double Apply(double sourceValue) const
	{
		if (operation == '+')
		{
			return sourceValue + value;
		}
		else
		{
			return sourceValue - value;
		}
	}

	void Invert()
	{
		if (operation == '+')
		{
			operation = '-';
		}
		else
		{
			operation = '+';
		}
	}

private:
	char operation;
	double value;
};

class Function
{
public:
	void AddPart(char operation, double value)
	{
		parts.push_back({operation, value});
	}
	double Apply(double value) const
	{
		for (FunctionPart const &part : parts)
		{
			value = part.Apply(value);
		}
		return value;
	}
	void Invert()
	{
		for (FunctionPart &part : parts)
		{
			part.Invert();
		}
		reverse(begin(parts), end(parts));
	}

private:
	vector<FunctionPart> parts;
};
