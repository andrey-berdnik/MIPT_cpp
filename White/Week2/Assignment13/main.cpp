#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, const char *argv[])
{
    map<vector<string>, unsigned long> dict;
    unsigned long dict_size = dict.size();
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int N = 0;
        cin >> N;
        vector<string> stops(N);
        for (int j = 0; j < stops.size(); j++)
        {   string stop;
            cin >> stop;
            stops[j] = stop;
        }
        if (dict.count(stops) == 0)
        {
            dict_size++;
            dict[stops] = dict_size;
            cout << "New bus " << dict_size << endl;
        }
        else
        {
            cout << "Already exists for " << dict[stops] << endl;
        }
    }
    return 0;
}