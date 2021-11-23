#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
    int N = 0;
    cin >> N;
    set<string> word;
    for (int j = 0; j < N; j++)
    {
        string word_tmp;
        cin >> word_tmp;
        word.insert(word_tmp);
    }
    cout << word.size() << endl;
    return 0;
}