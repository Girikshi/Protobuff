#include<iostream>
using namespace std;

//base class
class area
{
	protected :

	float width , height ;
	float shape_area;

	public :

	area()
	{
		width=10 ;
		height=16 ;
	}

	// overriding function
	virtual void calarea()
	{
		cout << "\nFunction in base class" ;
		shape_area = width * height ;
		cout << "\narea in base class : " << shape_area << endl ;
	}
};

class triangle : public area
{
	public :

	void  calarea()
        {
		cout << "\nFunction in derived class" ;
                shape_area = 0.5 * width * height ;
                cout << "\narea in derived class : " << shape_area << endl ;
        }

};

int main ()
{
	area *bptr ;
	triangle dptr ;

	//store address of derived object in base object
	bptr = &dptr ;
	bptr -> calarea() ;

	return 0;
}
