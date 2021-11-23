#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <exception>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Date
{
public:
    int GetYear() const
    {
        return year;
    };
    int GetMonth() const
    {
        return month;
    };
    int GetDay() const
    {
        return day;
    };

    Date(string &istr)
    {
        stringstream a;
        char d1, d2;
        string d3;
        a << istr;

        a >> year;
        a >> d1;
        a >> month;
        a >> d2;
        a >> day;
        a >> d3;

        if (day == -1000 || month == -1000 || day == -1000 || d1 != '-' || d2 != '-' || d3 != "" )
        {
            throw invalid_argument("Wrong date format: " + istr);
        }

        if (month > 12 || month < 1)
        {
            throw invalid_argument((string)("Month value is invalid: " + to_string(month)));
        }

        if (day > 31 || day < 1)
        {
            throw invalid_argument((string)("Day value is invalid: " + to_string(day)));
        }
    }

private:
    int year = -1000;
    int month = -1000;
    int day = -1000;
};

bool operator<(const Date &lhs, const Date &rhs)
{
    if (lhs.GetYear() < rhs.GetYear())
    {
        return true;
    }
    else if (lhs.GetYear() > rhs.GetYear())
    {
        return false;
    }
    else if (lhs.GetMonth() < rhs.GetMonth())
    {
        return true;
    }
    else if (lhs.GetMonth() > rhs.GetMonth())
    {
        return false;
    }
    else if (lhs.GetDay() < rhs.GetDay())
    {
        return true;
    }
    else
    {
        return false;
    }
};

bool operator==(const Date &lhs, const Date &rhs)
{
    if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() == rhs.GetDay())
    {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &outs, const Date &date)
{
    return outs << setfill('0') << setw(4) << date.GetYear() << "-" << setw(2) << date.GetMonth() << "-" << setw(2) << date.GetDay();
}

class Event
{
public:
    Date date;
    string event;
};

bool operator==(const Event &lhs, const Event &rhs)
{
    if (lhs.date == rhs.date && lhs.event == rhs.event)
    {
        return true;
    }
    return false;
}

class Database
{
public:
    void AddEvent(const Date &date, const string &s_event)
    {
        Event e = {date, s_event};

        if (Find(date, s_event).size() < 1)
        {
            database.push_back(e);
        }

        sort(begin(database), end(database), [](Event a, Event b)
             {
            if (a.date == b.date)
            {
                if (a.event < b.event)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            } else if (a.date < b.date) {
                return true;
            } else {
                return false;
            } });
    }

    bool DeleteEvent(const Date &date, const string &s_event)
    {
        Event e = {date, s_event};
        int size = database.size();
        database.erase(remove(database.begin(), database.end(), e), database.end());
        return size != database.size();
    }

    int DeleteDate(const Date &date)
    {
        /*
        int count = 0;
        for (vector<Event>::iterator iter = database.begin(); iter != database.end(); ++iter)
        {
            if ((*iter).date == date)
            {
                database.erase(iter);
                count++;
            }
        }
        */
        int count = database.size();

        database.erase(remove_if(
                           database.begin(), database.end(),
                           [date](const Event &x)
                           {
                               return x.date == date;
                           }),
                       database.end());

        return (count - database.size());
    }

    int Erase()
    {
        int size = database.size();
        database.clear();
        return size;
    }

    vector<Event> Find(const Date &date) const
    {
        vector<Event> out;
        for (auto iter = database.begin(); iter != database.end(); ++iter)
        {
            if ((*iter).date == date)
            {
                out.push_back((*iter));
            }
        }

        sort(begin(out), end(out), [](Event a, Event b)
             { return a.event < b.event; });

        return out;
    };

    vector<Event> Find(const Date &date, const string &action) const
    {
        vector<Event> out;
        for (auto iter = database.begin(); iter != database.end(); ++iter)
        {
            if ((*iter).date == date && (*iter).event == action)
            {
                out.push_back((*iter));
            }
        }

        sort(begin(out), end(out), [](Event a, Event b)
             { return a.event < b.event; });

        return out;
    };

    void Print(vector<Event> din) const
    {
        for (auto iter = din.begin(); iter != din.end(); ++iter)
        {
            cout << (*iter).date << " " << (*iter).event << endl;
        }
    }

    void Print() const
    {
        Print(database);
    }

private:
    vector<Event> database;
};

int main()
{
    Database db;

    string command;
    while (getline(cin, command))
    {
        stringstream ss;
        ss << command;
        ss >> command;
        try
        {
            if (command == "Add")
            {
                string sdate = "";
                string action = "";
                ss >> sdate >> action;
                // cout << "Add recognized";
                // cout << "date to parse " << sdate << " action " << action << endl;
                Date date(sdate);
                db.AddEvent(date, action);
                continue;
            }

            else if (command == "Del")
            {
                string sdate = "";
                string action = "";
                ss >> sdate >> action;
                if (sdate == "")
                {
                    cout << "Deleted " << db.Erase() << " events" << endl;
                }
                else
                {
                    Date date(sdate);
                    if (action != "")
                    {
                        bool result = db.DeleteEvent(date, action);
                        if (result)
                        {
                            cout << "Deleted successfully" << endl;
                        }
                        else
                        {
                            cout << "Event not found" << endl;
                        }
                    }
                    else
                    {
                        int count = db.DeleteDate(date);
                        cout << "Deleted " << count << " events" << endl;
                    }
                    // cout << "Del  recognized";
                    continue;
                }
            }

            else if (command == "Find")
            {
                string sdate = "";
                ss >> sdate;
                // cout << "Find  recognized";
                Date date(sdate);

                vector<Event> a = db.Find(date);
                for (auto iter = a.begin(); iter != a.end(); ++iter)
                {
                    cout << (*iter).event << endl;
                }
                continue;
            }

            else if (command == "Print")
            {
                // Pcout << "Print  recognized";
                db.Print();
                continue;
            }
            else if (command != "")
            {
                cout << "Unknown command: " << command << endl;
            }
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
            return 0;
        }
    }

    return 0;
}