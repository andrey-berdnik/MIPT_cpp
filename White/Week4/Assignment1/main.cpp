#include <iostream>

using namespace std;

struct Specialization
{
	string value;
	explicit Specialization(string const &str)
	{
		value = str;
	}
};

struct Course
{
	string value;
	explicit Course(string const &str)
	{
		value = str;
	}
};

struct Week
{
	string value;
	explicit Week(string const &str)
	{
		value = str;
	}
};

struct LectureTitle
{
	string specialization;
	string course;
	string week;

	explicit LectureTitle(Specialization const &s, Course const &c, Week const &w)
	{
		specialization = s.value;
		course = c.value;
		week = w.value;
	}
};

int main()
{
	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th"));
}