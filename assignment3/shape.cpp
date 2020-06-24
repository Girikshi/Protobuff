#include<iostream>
using namespace std;

//Base class 
class shape
{
	protected :

	float width , height ;
	shape ( float height , float width )
	{
		this -> width = width ;
		this -> height = height ;
	}
};

//rectangle class deriving protected members of shape
class rectangle : protected shape
{
	public :

	rectangle ( float height , float width ) : shape ( height , width ) {}

	float area ()
	{
		return width * height ;
	}	
};

//triangle class deriving protected members of shape
class triangle  : protected shape
{
	public:
	triangle ( float height , float width ) : shape ( height , width ){}

	float area ()
	{
		return 0.5 * width * height ;
	}
};

int main()
{
	float height , width ; 
	cout << "\nEnter height : ";
	cin >> height ;
	cout << "\nEnter width  : ";
	cin >> width ;
	
	rectangle rect ( height , width ) ;
	triangle tri ( height , width ) ;
	
	//Call to area() function in rectangle class
	cout << "\nArea of rectangle is : " << rect.area() ;
	
	//Call to area() function in triangle class
	cout << "\nArea of triangle is : " << tri.area() << endl << endl ; 
	
	return 0;		
}
