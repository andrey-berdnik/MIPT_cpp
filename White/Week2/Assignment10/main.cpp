#include <iostream>
#include <map>
#include <string>

using namespace std;
map<char, int> BuildCharCounters(const string &s)
{
    map<char, int> out;
    for (auto item : s)
    {
        ++out[item];
    }
    return out;
}

int main(int argc, const char *argv[])
{
    int N;
    map<char, int> dict_one, dict_two;
    string word_1, word_2;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> word_1 >> word_2;
        dict_one = BuildCharCounters(word_1);
        dict_two = BuildCharCounters(word_2);

        if (dict_one == dict_two)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}