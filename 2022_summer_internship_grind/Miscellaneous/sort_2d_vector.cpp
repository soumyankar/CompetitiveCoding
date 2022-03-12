#include <iostream>
// #include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    void minMeetingRooms(vector<vector<int> >& intervals) {
        vector<int> meeting_rooms;
        int i,j;
        for(i=0;i<intervals.size()-1;i++)
        {
            for(j=0;j<intervals.size()-i-1;j++)
            {
                vector<int> now=intervals[j];
                vector<int> next=intervals[j+1];
                cout<<"now[0] "<<now[0]<<endl;
                cout<<"next[0] "<<next[0]<<endl;
                if(next[0]<now[0])
                {
                    intervals[j+1]=intervals[j];
                    intervals[j]=next;
                }
            } // Now we have a sorted vector in terms of starting time
        }
        for(i=0;i<intervals.size();i++)
        {
            for(j=0;j<intervals[i].size();j++)
                cout<<intervals[i][j]<<" ";
            cout<<"\n";
        }
        int need_new_room;
        for(i=0;i<intervals.size();i++)
        {
            vector<int> curr=intervals[i];
            if(meeting_rooms.empty()==true)
            {
                meeting_rooms.push_back(curr[1]);
                continue;
            }
            need_new_room=1;
            for(j=0;j<meeting_rooms.size();j++)
            {
                if(meeting_rooms[j]<=curr[0])
                {
                    meeting_rooms[j]=curr[1];
                    need_new_room=0;
                    break;
                }
            }
            if(need_new_room==1)
                meeting_rooms.push_back(curr[1]);
        }

        for(i=0;i<meeting_rooms.size();i++)
            cout<<meeting_rooms[i]<<" ";
        // return meeting_rooms.size();
    }
};

int main()
{
    vector<vector<int> > vect {{20,45},{12,13},{2,50},{14,20},{3,5}};
    sort(vect.begin(),vect.end(), sortcol());
    // Solution my_sol;
    // my_sol.minMeetingRooms(vect);
    int i,j;
    for(i=0;i<vect.size();i++)
    {
        for(j=0;j<vect[i].size();j++)
            cout<<vect[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}