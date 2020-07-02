#include<bits/stdc++.h>
using namespace std;

int main()
{
	//set declaration
	set<int> s={11,12,13,11,15,13,16};

	//insertion of elements in set
	s.insert(14);
	s.emplace(17);

	//print the elements in set
	cout<<"\nElements in the set are : ";
	for(auto i : s)
	 cout<<i<<" ";

	//delete elements in set
	s.erase(s.begin());
	s.erase(17);

	//print elements in the set after deletion
	cout<<"\nElements in the set after deletion are : ";
	for(auto i :s)
	cout<<i<<" ";
	cout<<"\n";
	return 0;
}
