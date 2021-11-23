#include <iostream>
#include <string>
#include <vector>
#include <map>

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

   map<int, string> name;
   map<int, string> surname;
};

int main(int argc, const char *argv[])
{
   return 0;
}