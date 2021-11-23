#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, const char *argv[])
{
	int N = 0;
	int M = 0;
	int data = 0;
	ifstream textfile("input.txt");

	if (textfile)
	{
		textfile >> N >> M;
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			textfile >> data;
			textfile.ignore(1);
			if (j == M - 1)
				cout << setw(10) << data;
			else
				cout << setw(10) << data << " ";
		}
		cout << endl;
	}
	return 0;
}