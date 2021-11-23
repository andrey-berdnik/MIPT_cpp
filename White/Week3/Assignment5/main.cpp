#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Person
{
public:
   void ChangeFirstName(int year, const string &first_name)
   {
      name[year] = first_name;
   }

   void ChangeLastName(int year, const string &last_name)
   {
      surname[year] = last_name;
   }

   string GetFullName(int year)
   {
      string result;
      int year_with_name = previous_year(year, name);
      int year_with_surname = previous_year(year, surname);

      if (year_with_name == 0 && year_with_surname == 0)
         result = "Incognito";
      else
      {
         if (year_with_name == 0)
         {
            result = surname[year_with_surname] + " with unknown first name";
         }
         else
         {
            if (year_with_surname == 0)
            {
               result = name[year_with_name] + " with unknown last name";
            }
            else
            {
               result = name[year_with_name] + " " + surname[year_with_surname];
            }
         }
      }
      return result;
   }

   string GetFullNameWithHistory(int year)
   {
      string out;
      int year_with_name = previous_year(year, name);
      int year_with_surname = previous_year(year, surname);

      vector<string> history_names = history(year_with_name, name);
      vector<string> history_surnames = history(year_with_surname, surname);

      auto last_name = unique(history_names.begin(), history_names.end());
      history_names.erase(last_name, history_names.end());

      auto last_surname = unique(history_surnames.begin(), history_surnames.end());
      history_surnames.erase(last_surname, history_surnames.end());

      if (year_with_name == 0 && year_with_surname == 0)
         out = "Incognito";
      else
      {
         if (year_with_name == 0)
         {
            out = Print(history_surnames) + " with unknown first name";
         }
         else
         {
            if (year_with_surname == 0)
            {
               out = Print(history_names) + " with unknown last name";
            }
            else
            {
               out = Print(history_names) + " " + Print(history_surnames);
            }
         }
      }
      return out;
   }

private:
   int previous_year(int year, const map<int, string> &m)
   {
      int i = 0;
      for (auto item : m)
      {
         if (item.first <= year)
         {
            i = item.first;
         }
         else
         {
            break;
         }
      }
      return i;
   }

   vector<string> history(int year, map<int, string> &m)
   {
      vector<string> v;
      for (auto item : m)
      {
         if (item.first <= year)
         {
            v.push_back(item.second);
         }
         else
         {
            break;
         }
      }
      return v;
   }

   string Print(const vector<string> &s)
   {
      string out;
      string brakes;

      if (s.size() == 1)
      {
         out = s[0];
      }
      else
      {
         if (s.size() == 2)
         {
            out = s[1] + " (" + s[0] + ")";
         }
         else
         {
            out = s[s.size() - 1];
            brakes = s[s.size() - 2];
            for (long j = s.size() - 3; j >= 0; j--)
            {
               brakes += (", " + s[j]);
            }
            out += " (" + brakes + ")";
         }
      }
      return out;
   }

   map<int, string> name;
   map<int, string> surname;
};

int main(int argc, const char *argv[])
{

   return 0;
}
