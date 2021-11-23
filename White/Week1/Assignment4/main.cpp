#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;
    if (b == 0)
    {
        cout << "Impossible";
    }
    else
    {
        cout << a / b;
    }
    return 0;
}
