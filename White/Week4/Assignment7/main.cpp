#include <iostream>
#include <vector>

using namespace std;

struct Student
{
	string first_name;
	string last_name;
	int day;
	int month;
	int year;
};

int main()
{
	int n;

	cin >> n;
	vector<Student> students(n);
	for (int i = 0; i < n; i++)
	{
		cin >> students[i].first_name >> students[i].last_name >> students[i].day >> students[i].month >> students[i].year;
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string request;
		int sid;
		cin >> request >> sid;
		if (sid < 1 || sid > students.size() || (request != "name" && request != "date"))
			cout << "bad request" << endl;
		else
		{
			sid--;
			if (request == "name")
			{
				cout << students[sid].first_name << " " << students[sid].last_name << endl;
			}
			else
			{
				cout << students[sid].day << "." << students[sid].month << "." << students[sid].year << endl;
			}
		}
	}
	return 0;
}