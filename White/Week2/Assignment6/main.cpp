#include <iostream>
#include <vector>
using namespace std;


void Reverse(vector<int> &v)
{
    int tmp = 0;
    for (int i = 0; i < v.size() / 2; i++)
    {
        tmp =  v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i]  = tmp;
    }
}

int main()
{

}