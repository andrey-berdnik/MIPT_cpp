#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

int main(int argc, const char *argv[])
{
    map<set<string>, unsigned long> dict;
    unsigned long dict_size = dict.size();
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int N = 0;
        cin >> N;
        set<string> stops;
        for (int j = 0; j < N; j++)
        { 
            string stop;
            cin >> stop;
            stops.insert(stop);
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
