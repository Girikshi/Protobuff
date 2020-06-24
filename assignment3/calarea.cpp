// Program to demonstrate compile time polymorphism using function calls with different arguements

#include<iostream>
using namespace std;


class calarea
{
	float width , height ;

	public :

	float area ;

	// 2 constructors with different arguements
	
	calarea ( float wid , float hei )
	{
		width = wid ;
		height = hei ;
		area = 0.5 * width * height ;
	}
	calarea ( float hei ) 
	{
		height = hei ;
		area = hei * hei ;
	}

};

int main()
{
	float width , height ;
	cout<<"\n************Area of triangle*****************";
	cout << "\nEnter height of triangle : " ;
	cin >> height ;
	
	cout << "\nEnter width of triangle : " ;
	cin >> width ;
	
	// Call functions with different number of arguements
	calarea triangle(width,height) ;
	cout << "\nArea of triangle is : " << triangle.area ;


	 cout << "\n\n************Area of square*****************";
	cout << "\nEnter height of square : ";
	cin >> height ;	
	calarea square(height) ;	
	cout << "\nArea of square is : " << square.area << endl ;

	return 0 ;

}
