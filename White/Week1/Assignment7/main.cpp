#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
   string in;
   int index = -2; 
   int i = 0;
   cin >> in;

   for (auto c : in)
   {
      if (c == 'f')
         {
         if (index == -2) {
            index = -1;
         } else

         if (index  == -1) {
            index = i;
         }
         }  
      i++;
   }
   cout << index;
   return 0;
}
