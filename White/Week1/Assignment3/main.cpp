#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, d, x1, x2;
    cin >> a >> b >> c;


    if (a == 0 && b == 0 ) // ax2 + Вх + С = 0
    {
        return 0;
    }


    if (a == 0) // Вх + С = 0
    {
        cout << -1*c / b ;
        return 0;
    }


    d = b * b - 4 * a * c;
    if (d > 0)
    {
        x1 = ((-b) + sqrt(d)) / (2 * a);
        x2 = ((-b) - sqrt(d)) / (2 * a);
        cout << x1 << " " << x2;
    }
    if (d == 0)
    {
        x1 = -(b / (2 * a));
        cout << x1;
    }
    if (d < 0)
        {//cout << "";
        }
    return 0;
}
