#include<bits/stdc++.h>
using namespace std;

int main()
{
	//initialize deque
	deque<int> dq={1,2,3,4,5};

	//insert elements in deque
	dq.push_front(0);
	dq.push_back(6);
	dq.insert(dq.begin()+2,8);
	dq.emplace(dq.begin()+2,9);

	//Print the elements in deque
	cout<<"\nElements in deque are : ";
	for(auto i : dq)
	cout << i << " ";

	//modify elements in deque
	dq[2]=9;
	dq[3]=7;

	//elements in deque after modification
	cout<<"\nElements in deque after modification are : ";
        for(auto i : dq)
        cout << i << " ";

	//delete elements in deque
	dq.pop_front();
	dq.pop_back();
	dq.erase(dq.begin()+2,dq.begin()+4);

	//elements in deque after deletion
        cout<<"\nElements in deque after deletion are : ";
        for(auto i : dq)
        cout << i << " ";
	cout<<"\n";

	return 0;

}
