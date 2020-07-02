#include<bits/stdc++.h>
using namespace std;

bool even(const int& value) { return (value % 2) == 0; }

int main()
{
	//Declaration of list 
	list<int> l ;

	//Assign values to the list
	l.assign(20,5);

	//print list elements
	cout<<"\n List elements are : ";
	for(auto i : l)
	cout << i << " ";

	//Modify list elements
	l.front()=3;
	l.back()=4;
	list<int>::iterator it = l.begin();
        // iterator to point to 3rd position
        advance(it,2);
	l.insert(it,1);
	l.emplace(it,3);
	l.push_back(4);
	l.push_front(6);

	//print Modified list elements
        cout<<"\nModified List elements are : ";
        for(auto i : l)
        cout << i << " ";

	//delete list elements
	l.pop_back();
	l.pop_front();
	l.remove(5);
	l.remove_if(even);
	
	//print list after deletion
        cout<<"\nList elements after deletion are : ";
        for(auto i : l)
        cout << i << " ";

	cout<<"\n";
	return 0;
}
