#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream input("input.txt");
	string line;
	ofstream output("output.txt");
	while (getline(input, line))
	{
		cout << line << "\n";
	}
	return 0;
}