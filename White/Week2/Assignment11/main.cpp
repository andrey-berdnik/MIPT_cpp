#include <iostream>
#include <map>
using namespace std;

inline void about_size_0(string &string_1)
{
    cin >> string_1;
    cout << "Country " << string_1 << " doesn't exist" << endl;
}

void change_capital_size_0(string &string_1, string &string_2, map<string, string> &dict)
{
    dict[string_1] = string_2;
    cout << "Introduce new country " << string_1 << " with capital " << string_2 << endl;
}

inline void rename_size_0(string &string_1, string &string_2)
{
    cin >> string_1 >> string_2;
    cout << "Incorrect rename, skip" << endl;
}

inline void dump_size_0()
{
    cout << "There are no countries in the world" << endl;
}

void about(string &string_1, map<string, string> &dict)
{
    bool counter_country = 0;

    counter_country = dict.count(string_1);

    if (counter_country == false)
        cout << "Country " << string_1 << " doesn't exist" << endl; // Если такой страны не существует
    else
    {
        cout << "Country " << string_1 << " has capital " << dict[string_1] << endl; //Если существует
    }
}

void change_capital(string &string_1, string &string_2, map<string, string> &dict)
{
    bool counter_country = 0;

    counter_country = dict.count(string_1); //Проверка того, что есть ли уже такая страна

    if (counter_country == false)
    {
        cout << "Introduce new country " << string_1 << " with capital " << string_2 << endl;
        dict[string_1] = string_2;
    }
    else
    {
        if (dict[string_1] == string_2)
        {
            cout << "Country " << string_1 << " hasn't changed its capital" << endl;
        }
        else
        {
            cout << "Country " << string_1 << " has changed its capital from " << dict[string_1] << " to " << string_2 << endl;
            dict[string_1] = string_2;
        }
    }
}

void RENAME(string &string_1, string &string_2, map<string, string> &dict)
{
    bool counter_old_country = 0;
    bool counter_new_country = 0;

    counter_old_country = dict.count(string_1);
    counter_new_country = dict.count(string_2);

    if (counter_old_country == false || counter_new_country == true || string_1 == string_2)
    {
        cout << "Incorrect rename, skip" << endl;
    }
    else
    {
        string capital;
        for (auto i : dict)
        {
            if (i.first == string_1)
            {
                capital = i.second;
            }
        }
        dict.erase(string_1);
        dict[string_2] = capital;
        cout << "Country " << string_1 << " with capital " << capital << " has been renamed to " << string_2 << endl;
    }
}

void dump(map<string, string> dict)
{
    for (auto i : dict)
    {
        cout << i.first << "/" << i.second << " ";
    }
}

int main(int argc, const char *argv[])
{
    int Q = 0;
    cin >> Q;
    map<string, string> dict;              // <country, capital>
    string request, string_1, string_2;  
    for (int j = 0; j < Q; j++)
    {
        cin >> request;
        if (dict.size() == 0)
        {
            if (request == "ABOUT")
            {
                about_size_0(string_1);
            }
            else
            {
                if (request == "CHANGE_CAPITAL")
                {
                    cin >> string_1 >> string_2;
                    change_capital_size_0(string_1, string_2, dict);
                }
                if (request == "RENAME")
                {
                    rename_size_0(string_1, string_2);
                }
                if (request == "DUMP")
                {
                    dump_size_0();
                }
            }
        }
        else
        {
            if (request == "ABOUT")
            {
                cin >> string_1;
                about(string_1, dict);
            }
            else
            {
                if (request == "CHANGE_CAPITAL")
                {
                    cin >> string_1 >> string_2;
                    change_capital(string_1, string_2, dict);
                }
                if (request == "RENAME")
                {
                    cin >> string_1 >> string_2;
                    RENAME(string_1, string_2, dict);
                }
                if (request == "DUMP")
                {
                    dump(dict);
                }
            }
        }
    }
    return 0;
}