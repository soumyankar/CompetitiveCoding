#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long int D;
    cin >> D;
    long long int oc, of, od;
    cin >> oc >> of >> od;
    long long int cs, cb, cm, cd;
    cin >> cs >> cb >> cm >> cd;

    // Online taxi Costs
    long long int online_taxi = 0;
    if(of > D)
        online_taxi = oc;
    else
    {
        long long int extra_distance_cost = od*(D - of);
        online_taxi = oc + extra_distance_cost;
    }

    long long int travel_time = D/cs;
    long long int classic_taxi = cb + travel_time*cm + D*cd;

    // cout << online_taxi << endl;
    // cout << classic_taxi << endl;
    if(online_taxi<classic_taxi)
        cout << "Online Taxi" << "\n";
    if(classic_taxi<online_taxi)
        cout << "Classic Taxi" << "\n";
    if(online_taxi == classic_taxi)
        cout << "Online Taxi" << "\n";
}