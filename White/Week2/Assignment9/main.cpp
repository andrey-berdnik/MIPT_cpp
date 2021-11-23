#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printDay(int n, vector<vector<string>> &tasks)
{
    cout << tasks[n - 1].size() << ' ';
    for (auto c : tasks[n - 1])
        cout << c << ' ';
    cout << endl;
}

int main(int argc, const char *argv[])
{
    int Q;
    string command;
    vector<int> size_of_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> days_tasks(31);
    int current_month = 0;

    cin >> Q;
    for (int j = 0; j < Q; j++)
    {
        cin >> command;
        int n = 0;
        if (command == "ADD")
        {
            string task;
            cin >> n >> task;
            days_tasks[n - 1].push_back(task);
        }
        if (command == "DUMP")
        {
            cin >> n;
            printDay(n, days_tasks);
        }
        if (command == "NEXT")
        {
            current_month++;

            if (current_month > 11)
            {
                current_month = 0;
            }
            if (size_of_months[current_month] > days_tasks.size())
            {
                days_tasks.resize(size_of_months[current_month]);
            }
            else
            {
                for (int j = size_of_months[current_month]; j < days_tasks.size(); j++)
                {
                    days_tasks[size_of_months[current_month] - 1].insert(end(days_tasks[size_of_months[current_month] - 1]), begin(days_tasks[j]), end(days_tasks[j]));
                }
            }
            days_tasks.resize(size_of_months[current_month]);
        }
    }
    return 0;
}
