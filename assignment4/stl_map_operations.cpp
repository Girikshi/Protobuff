#include<bits/stdc++.h>
using namespace std;

int main()
{
	map<string,int> M;
	
	//Insert the elements in map
	M.insert(make_pair("girija",1));
	M["atharva"]=2;
	M["gita"]=3;
	M.emplace("radha",4);

	//Iterate through elements in map
	cout<<"\nMap elements are : ";
	for(auto i : M)
	 cout<<"\n"<<i.first<<" "<<i.second;
	
	//update elements in map
	M["gita"]=5;

	//Print updated elements in map
	cout<<"\nUpdated Map elements are : ";
        for(auto i : M)
         cout<<"\n"<<i.first<<" "<<i.second;

	//delete elements in map
	M.erase(M.begin(),M.find("girija"));

	//Print elements after deletion in map
        cout<<"\nMap elements after deletion are : ";
        for(auto i : M)
         cout<<"\n"<<i.first<<" "<<i.second;

	cout<<"\n";

	return 0;
		
}
