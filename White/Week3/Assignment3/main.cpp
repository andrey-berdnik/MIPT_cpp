#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class SortedStrings
{
public:
   void AddString(const string &s)
   {
      list_of_strings.push_back(s);
      sort(begin(list_of_strings), end(list_of_strings));
   }
   vector<string> GetSortedStrings()
   {
      return list_of_strings;
   }

private:
   vector<string> list_of_strings;
};

void PrintSortedStrings(SortedStrings &strings)
{
   for (const string &s : strings.GetSortedStrings())
   {
      cout << s << " ";
   }
   cout << endl;
}

int main()
{
   SortedStrings strings;

   strings.AddString("first");
   strings.AddString("third");
   strings.AddString("second");
   PrintSortedStrings(strings);

   strings.AddString("second");
   PrintSortedStrings(strings);

   return 0;
}