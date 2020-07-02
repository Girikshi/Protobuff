#include<bits/stdc++.h>
using namespace std;
int main ()
{
	//array declaration
	array< int , 10 > arr = {1,2,3,4,5,6,7};

	//array insertion
	arr[7]=8;

	//iterate
	cout<<"\nArray elements are : ";
	for(int i : arr)
	cout<<i<<" ";

	//update
	arr.at(8)=9;
	arr.front()=1;
	arr.back()=10;

	//show modified array 
	cout<<"\nModified Array elements are : ";
        for(int i : arr)
        cout<<i<<" ";

	return 0;

}
