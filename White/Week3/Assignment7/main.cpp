#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
//#include <cctype>

using namespace std;

class Person
{
public:
   Person(const string &first_name, const string &last_name, const int &year)
   {
      name[year] = first_name;
      surname[year] = last_name;
      birth = year;
   }

   string GetFullNameWithHistory(int year) const
   {
      string result;
      int nearest_year_name = neareest_year(year, name);
      int nearest_year_surname = neareest_year(year, surname);

      vector<string> history_of_names = history(nearest_year_name, name);
      vector<string> history_of_surnames = history(nearest_year_surname, surname);

      auto last_name = unique(history_of_names.begin(), history_of_names.end());
      history_of_names.erase(last_name, history_of_names.end());

      auto last_surname = unique(history_of_surnames.begin(), history_of_surnames.end());
      history_of_surnames.erase(last_surname, history_of_surnames.end());

      if (year < birth)
      {
         result = "No person";
      }
      else
      {
         if (nearest_year_name == 0 && nearest_year_surname == 0)
            result = "Incognito";
         else
         {
            if (nearest_year_name == 0)
            {
               result = Print(history_of_surnames) + " with unknown first name";
            }
            else
            {
               if (nearest_year_surname == 0)
               {
                  result = Print(history_of_names) + " with unknown last name";
               }
               else
               {
                  result = Print(history_of_names) + " " + Print(history_of_surnames);
               }
            }
         }
      }
      return result;
   }

   string GetFullName(int year) const
   {

      string result;
      int nearest_year_name = neareest_year(year, name);
      int nearest_year_surname = neareest_year(year, surname);
      if (year < birth)
      {
         result = "No person";
      }
      else
      {
         if (nearest_year_name == 0 && nearest_year_surname == 0)
            result = "Incognito";
         else
         {
            if (nearest_year_name == 0)
            {
               result = surname.at(nearest_year_surname) + " with unknown first name";
            }
            else
            {
               if (nearest_year_surname == 0)
               {
                  result = name.at(nearest_year_name) + " with unknown last name";
               }
               else
               {
                  result = name.at(nearest_year_name) + " " + surname.at(nearest_year_surname);
               }
            }
         }
      }
      return result;
   }

   void ChangeFirstName(int year, const string &first_name)
   {
      if (year >= birth)
      {
         name[year] = first_name;
      }
   }

   void ChangeLastName(int year, const string &last_name)
   {
      if (year >= birth)
      {
         surname[year] = last_name;
      }
   }

private:
   int neareest_year(int year, const map<int, string> &m) const
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

   vector<string> history(int year, const map<
                                        int, string> &m) const
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

   string Print(const vector<string> &s) const
   {
      string result;
      string brakes;
      // bool flag = false;
      if (s.size() == 1)
      {
         result = s[0];
      }
      else
      {
         if (s.size() == 2)
         {
            result = s[1] + " (" + s[0] + ")";
         }
         else
         {
            result = s[s.size() - 1];
            brakes = s[s.size() - 2];
            for (long j = s.size() - 3; j >= 0; j--)
            {
               brakes += (", " + s[j]);
            }
            result += " (" + brakes + ")";
         }
      }
      return result;
   }

   map<int, string> name;
   map<int, string> surname;
   int birth;
};

int main(int argc, const char *argv[])
{
   return 0;
}