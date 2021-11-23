#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, const char *argv[])
{
    map<string, set<string>> synonym;
    int Q = 0;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        string request;
        cin >> request;

        if (request == "CHECK")
        {
            string word1, word2;
            cin >> word1 >> word2;
            if (synonym[word1].count(word2) != 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

        if (request == "COUNT")
        {
            string word;
            cin >> word;
            cout << synonym[word].size() << endl;
        }

        if (request == "ADD")
        {
            string word1, word2;
            cin >> word1 >> word2;
            synonym[word1].insert(word2);
            synonym[word2].insert(word1);
        }
    }
    return 0;
}