#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

void printAnagrams(string arr[], int size)
{
    unordered_map<string, vector<string> > map;
    //Now we loop through all the words we got.
    int i,j,len;

    for(i=0;i<size;i++)
    {
        string word = arr[i];
        len=word.size()+1;
        char letters[len];
        strcpy(letters, word.c_str());
        sort(letters, letters+len);
        string newWord="";
        for(j=0;j<len;j++)
            newWord+=letters[j];

        //Find hashcode of string
        if(map.find(newWord)!=map.end()) //This would mean that the word is in the map already.
            map[newWord].push_back(word);
        else
        {
            vector<string> words;
            words.push_back(word);
            map[newWord] = words;
        }
    }

    unordered_map<string,vector<string> >::iterator it;
    for(it=map.begin();it!=map.end();it++)
    {
        vector<string> values=map[it->first];
        cout <<"[";
        for(i=0;i<values.size()-1;i++)
            cout<<values[i]<<", ";
        cout<<values[values.size()-1];
        cout<<"]"<<"\n";
    }
}

int main()
{
    string arr[] = {"hel","zyx","bat"};
    int size = sizeof(arr) / sizeof(arr[0]);
    printAnagrams(arr, size);
    return 0;
}