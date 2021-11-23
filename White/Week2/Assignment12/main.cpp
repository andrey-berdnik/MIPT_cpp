#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> Buses_with_stop(string &stop, map<string, vector<string>> &dict)
{
    vector<string> buses_with_stop;
    for (auto j : dict)
    {
        for (string item : j.second)
        {
            if (item == stop)
            {
                buses_with_stop.push_back(j.first);
            }
        }
    }
    return buses_with_stop;
}

vector<string> Buses_in_order(vector<string> &new_bus, vector<string> &buses_with_stop)
{
    vector<string> buses_in_order;
    for (string item_1 : new_bus)
    {
        for (string item_2 : buses_with_stop)
        {
            if (item_1 == item_2)
            {
                buses_in_order.push_back(item_1);
            }
        }
    }
    return buses_in_order;
}

void Print_vector(vector<string> buses, string &request)
{
    if (buses.size() == 0)
    {
        if (request == "BUSES_FOR_STOP")
        {
            cout << "No stop" << endl;
        }
        else
        {
            if (request == "STOPS_FOR_BUS")
            {
                cout << "no interchange" << endl;
            }
        }
    }
    else
    {
        for (string item : buses)
        {
            cout << item << " ";
        }
        cout << endl;
    }
}

void all_busses(map<string, vector<string>> &dict)
{
    if (dict.size() == 0)
    {
        cout << "No buses" << endl;
    }
    else
    {
        for (auto j : dict)
        {
            cout << "Bus " << j.first << ": ";
            for (string item : j.second)
            {
                cout << item << " ";
            }
            cout << endl;
        }
    }
}

int find_position(vector<string> &vector_with_buses, string &needed_bus)
{
    int p = 0;
    for (int k = 0; k < vector_with_buses.size(); k++)
    {
        if (vector_with_buses[k] == needed_bus)
        {
            p = k;
        }
    }
    return p;
}

int main(int argc, const char *argv[])
{
    string request;
    int Q;
    cin >> Q;
    map<string, vector<string>> dict;
    vector<string> new_bus;
    for (int i = 0; i < Q; i++)
    {
        cin >> request;

        if (request == "NEW_BUS")
        {
            string bus_name;
            string route_name;
            int stop_count = 0;
            cin >> bus_name >> stop_count;
            new_bus.push_back(bus_name);
            vector<string> route(stop_count);
            for (int j = 0; j < route.size(); j++)
            {
                cin >> route_name;
                route[j] = route_name;
            }
            dict[bus_name] = route;
        }

        if (request == "BUSES_FOR_STOP")
        {
            string stop;
            cin >> stop;
            vector<string> buses_with_stop;
            buses_with_stop = Buses_with_stop(stop, dict);
            vector<string> buses_in_order = Buses_in_order(new_bus, buses_with_stop);
            Print_vector(buses_in_order, request);
        }

        if (request == "ALL_BUSES")
        {
            all_busses(dict);
        }

        if (request == "STOPS_FOR_BUS")
        {
            string bus;
            cin >> bus;
            vector<string> buses_with_stop;
            if (dict.count(bus) == 0)
            {
                cout << "No bus" << endl;
            }
            else
            {
                for (string item : dict[bus])
                {
                    buses_with_stop = Buses_with_stop(item, dict);
                    int Position = find_position(buses_with_stop, bus);
                    buses_with_stop.erase(buses_with_stop.begin() + Position);

                    cout << "Stop " << item << ": ";
                    vector<string> buses_in_order = Buses_in_order(new_bus, buses_with_stop);
                    Print_vector(buses_in_order, request);
                }
            }
        }
    }
    return 0;
}
