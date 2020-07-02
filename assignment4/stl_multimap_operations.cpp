#include<bits/stdc++.h>
using namespace std;

int main()
{
        multimap<string,int> M;

        //Insert the elements in map
        M.insert(make_pair("girija",1));
	M.insert(make_pair("girija",2));
        M.emplace("atharva",2);
        M.emplace("gita",3);
	M.emplace("atharva",5);
        M.emplace("radha",4);

        //Iterate through elements in multimap
        cout<<"\nmultiMap elements are : ";
        for(auto i : M)
         cout<<"\n"<<i.first<<" "<<i.second;

        //update elements in multimap
        M.begin()->second=5;

        //Print updated elements in multimap
        cout<<"\nUpdated multiMap elements are : ";
        for(auto i : M)
         cout<<"\n"<<i.first<<" "<<i.second;

        //delete elements in multimap
        M.erase(M.begin(),M.find("girija"));

        //Print elements after deletion in multimap
        cout<<"\nmultiMap elements after deletion are : ";
        for(auto i : M)
         cout<<"\n"<<i.first<<" "<<i.second;

        cout<<"\n";

        return 0;
}                               
