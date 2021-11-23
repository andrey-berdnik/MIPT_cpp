#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double price, level1, level2, discount1, discount2, newPrice;

    cin >> price >> level1 >> level2 >> discount1 >> discount2;

    newPrice = price;

    if (price > level1)
    {
       newPrice = price - (price  * discount1 / 100);
    }
   
    if (price > level2)
    {
       newPrice = price - (price  * discount2 / 100);
    }

    cout << newPrice;
    return 0;
}
