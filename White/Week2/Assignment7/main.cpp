#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int> &v)
{
    vector<int> cv = v;
    int tmp = 0;
    for (int i = 0; i < cv.size() / 2; i++)
    {
        tmp = cv[i];
        cv[i] = cv[cv.size() - 1 - i];
        cv[cv.size() - 1 - i] = tmp;
    }
    return cv;
}

int main()
{

}