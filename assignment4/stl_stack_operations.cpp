#include<bits/stdc++.h>
using namespace std;

int main()
{
	//stack declaration
	stack<string> s;
	
	//stack insertion
	s.push("girija");
	s.push("atharva");
	s.push("radha");
	s.push("krishna");

	//Stack iteration and deletion
	//as we cant iterate the stack without deleting elements in it
	cout << "\nStack elements are : \n";
	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}

	return 0;
}
