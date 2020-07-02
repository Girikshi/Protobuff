#include<iostream>
using namespace std;

int addition(int &x ,int &y)
{
	//this function demonstrates pass by reference.
	
	return x+y;
}

int multiplication(int *x ,int *y)
{
	//this function demonstrates pass by pointer.
	
	return *x * *y;
}

int main()
{
	int x,y;
	
	cout << "\nEnter first number : ";
	cin >> x;
	
	cout << "\nEnter second number :";
	cin >> y;
	
	int add = addition(x,y);
	int multiply=multiplication(&x,&y);
	
	cout << "\nAddition is :" << add;
	cout << "\nMultiplication is :" << multiply << endl ;
	return 0;
}
