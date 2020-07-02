//Program to demonstrate range based loops.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	//Range based loop for array
	int arr[] = {0,1,2,3,4,5} ;
	cout << "\n\n array elements are : ";
	for ( int num : arr )
	cout << num << " ";
	
	//Range based loop for vector
	vector<char> v={'v','e','c','t','o','r'};
	cout<<"\n\n vector elements are : ";
	for ( auto i : v )
	cout << i <<" ";
	
	//Range based loop for list
	list<char> l={'l','i','s','t'};
	cout<<"\n\n list elements are : ";
	for ( auto i : l )
	cout << i <<" ";
	
	//Range based loop for stack and queue arent there. They should be traversed using their respective functions.
	
        //Range based loop for set
        set<int> s1={5,3,1,2,3};
        cout<<"\n\n Set elements are : ";
        for ( auto i : s1 )
        cout<< i << " ";
        
        //Range based loop for multiset
        multiset<int> m={5,3,1,2,3};
        cout<<"\n\n multiSet elements are : ";
        for ( auto i : m )
        cout<< i << " ";
        
        //Range based loop for map
        map<string,int>Map;
        Map["Raghav"]=1;
        Map["Shyam"]=2;
        Map["rama"]=3;
        Map["rama"]=3;
        
        cout<<"\n\nMap elements are : "<<endl;
        for( auto e : Map )
        cout<<e.first<<" "<<e.second<<endl;
        
        //range based loop for multimap
        multimap<string,int>MM;
        MM.insert(make_pair("b",1));
        MM.insert(make_pair("a",2));
        MM.insert(make_pair("a",3));
        MM.insert(make_pair("b",4));
        cout<<"\n\nMultiMap elements are : "<<endl;
        for( auto e : MM )
        cout<<e.first<<" "<<e.second<<endl;
        
        //range based loop for unordered_set
        unordered_set<int>US;
        US={5,5,6,4,3,2,1};
        cout<<"\n\n Unordered Set elements are : ";
        for ( auto i : US )
        cout<< i << " ";
        
         //range based loop for unordered_multiset
        unordered_multiset<int>UM;
        UM={5,5,6,4,3,2,1};
        cout<<"\n\n Unordered multiSet elements are : ";
        for ( auto i : UM )
        cout<< i << " ";
	cout<<"\n";
	return 0;
}
