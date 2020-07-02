#include<bits/stdc++.h>
using namespace std;

int main()
{
        unordered_map<string,int> M;

        //Insert the elements in unordered_map
        M.insert(make_pair("girija",1));
        M["atharva"]=2;
        M["gita"]=3;
        M.emplace("radha",4);

        //Iterate through elements in unordered_map
        cout<<"\nunordered_map elements are : ";
        for(auto i : M)
         cout<<"\n"<<i.first<<" "<<i.second;

        //update elements in unordered_map
        M["gita"]=5;

        //Print updated elements in unordered_map
        cout<<"\nUpdated unordered_map elements are : ";
        for(auto i : M)
         cout<<"\n"<<i.first<<" "<<i.second;

        //delete elements in unordered_map
        M.erase(M.begin(),M.find("girija"));

        //Print elements after deletion in unordered_map
        cout<<"\nunordered_map elements after deletion are : ";
        for(auto i : M)
         cout<<"\n"<<i.first<<" "<<i.second;

        cout<<"\n";

        return 0;
}        
