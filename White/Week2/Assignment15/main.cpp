#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

set<string> BuildMapValuesSet(map<int, string> s)
{
    set<string> out;
    for (auto x:s) {
        out.insert(x.second);
    }

    return out;
}

/*
int main(int argc, const char *argv[])
{

    set<string> values = BuildMapValuesSet({{1, "odd"},
                                            {2, "even"},
                                            {3, "odd"},
                                            {4, "even"},
                                            {5, "odd"}});

    for (const string &value : values)
    {
        cout << value << endl;
    }
}
*/