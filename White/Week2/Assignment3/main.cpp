#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(string w)
{

    bool result = true;
    for (int i = 0; i < w.size() / 2; i++)
    {
        if (w[i] != w[w.size() - 1 - i])
        {
            result = false;
            break;
        }
    }
    return result;
}

vector<string> PalindromFilter(vector<string> words, int minLength)
{
    vector<string> output;
    for (auto word : words)
    {

        if (word.size() >= minLength && IsPalindrom(word) == true)
        {
            output.push_back(word);
        }
    }
    return output;
}

int main()
{

    return 0;
}