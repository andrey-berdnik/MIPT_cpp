#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
   vector<int> bin;
   int dec;
   cin >> dec;

   if (dec == 1)
      cout << dec << endl;
   else
   {
      do
      {

         bin.push_back(dec % 2);
         dec /= 2;

      } while (dec >= 2);

      bin.push_back(dec);
      for (int i = bin.size() - 1; i >= 0; i--)
         cout << bin[i];
   }

   return 0;
}