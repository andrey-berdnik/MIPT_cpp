
#include <iostream>
using namespace std;

int main()
{
    string a, b, c, res;
    cin >> a >> b >> c;

    if (a <= b && a <= c)
    {
        res = a;
    }

    if (b <= a && b <= c)
    {
        res = b;
    }

    if (c <= b && c <= a)
    {
        res = c;
    }

    cout << res;
    return 0;
}
