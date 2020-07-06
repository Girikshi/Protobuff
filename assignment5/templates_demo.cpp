#include<iostream>
using namespace std;

template <typename T>
T division(T x, T y)
{
	if(y==0)
	throw(y);
	
	return x/y;
}

int main()
{
	try
	{
		cout<<"\n 6 divided by 3 is : ";
		cout<<division<int>(6,3);
	}
	catch(int x)
	{
		cout<<"\nException : divide by 0"<<endl;
	}
	try
	{
		cout<<"\n 5 divided by 0 is : ";
		cout<<division<float>(5,0)<<endl;
	}
	catch(float x)
	{
		cout<<"\nException : divide by 0"<<endl;
	}
	return 0;
}
