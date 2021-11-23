#include <iostream>
using namespace std;

int Factorial(int n)
{
   int f = 1;
   if (n <= 0)
   {
      return f;
   }
   else
   {

      for (int i = n; i > 0; i--)
      {
         f *= i;
      }
      return f;
      }
}

int main()
{
   return 0;
}