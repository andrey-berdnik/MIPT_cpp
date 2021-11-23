#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void Print(const vector<int> &A)
{
   for (const auto& c : A)
      cout << c << ' ';
}

int main(int argc, const char *argv[])
{
   int N;
   cin >> N;
   
   vector<int> A(N);
   for (int &n : A)
      {cin >> n;}

   sort(begin(A), end(A), [](int a, int b)
        {
      if (abs(a) < abs(b))
         {return true;}
      else
         {return false;} });

   Print(A);
   return 0;
}