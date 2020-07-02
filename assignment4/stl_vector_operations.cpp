#include<bits/stdc++.h>
using namespace std;

int main()
{
	//declare the vector
	vector<int> V={1,2,3,4,5};
	V.reserve(20);

	//insert the elements
	V.push_back(6);
	//V.at(6)=7;
	V.insert(V.begin()+3,8);
	V.emplace(V.begin()+4,9);

	//Iterate over vector elements
	cout<<"\nVector elements are : ";
	for(auto i : V)
	cout<<i<<" ";

	//Modify vector elements
	V[4]=2;
	V.at(5)=3;
	//V.assign(2,200);
	cout<<"\nVector elements after modification are : ";
        for(auto i : V)
        cout<<i<<" ";


	//Delete vector elements
	V.pop_back();
	V.erase(V.begin(),V.begin()+2);
	cout<<"\nVector elements after deletion are : ";
        for(auto i : V)
        cout<<i<<" ";

	//to delete all the elements from vector
	V.clear();
	cout<<"\n";



	return 0;
}
