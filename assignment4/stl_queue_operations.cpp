#include<bits/stdc++.h>
using namespace std;

int main()
{
	//declaration of queue
	queue<int> q;

	//insertion of elements in queue ( they are added at the end of queue)
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	//iterate and pop first element from queue
	cout<<"\nElements in queue are : ";
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<"\n";
	return 0;
}
