#include<bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int>pq;

	//insert elements inside priority queue
	pq.push(2);
	pq.push(1);
	pq.push(4);
	pq.push(3);
	pq.push(5);

	//Display and pop the elements in priority queue
	cout<<"\nElements in priority queue are : ";
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}

	cout<<"\n";

	return 0;
}
