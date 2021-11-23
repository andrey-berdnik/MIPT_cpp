#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
    int N;
    cin >> N;
    vector<int> temperature_in(N);

    for (int &i : temperature_in)
    {
        cin >> i;
    }

    int temp_sum = 0;
    for (int i : temperature_in)
    {
        temp_sum += i;
    }
    int average_temp = 0;
    average_temp = temp_sum / N;

    int number_of_days = 0;
    for (int i : temperature_in)
    {
        if (i > average_temp)
        {
            number_of_days++;
        }
    }
    cout << number_of_days << endl;

    for (int i = 0; i < temperature_in.size(); i++)
    {
        if (temperature_in[i] > average_temp)
            cout << i << ' ';
    }
    return 0;
}