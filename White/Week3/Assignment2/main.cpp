#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string to_lower(const string &input_str)
{
   string out;
   for (auto c : input_str)
   {
      out += tolower(c);
   }
   return out;
}

void Print(const vector<string> &input_str)
{
   for (auto c : input_str)
      cout << c << ' ';
}

int main(int argc, const char *argv[])
{
   int N;
   cin >> N;

   vector<string> input_str(N);
   for (auto &n : input_str)
   {
      cin >> n;
   }

   sort(begin(input_str), end(input_str), [](string a, string b)
        { return to_lower(a) < to_lower(b); });
        
   Print(input_str);
   return 0;
}