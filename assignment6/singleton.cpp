// only single instance of class singleobject can be created

#include<iostream>
using namespace std;


class SingleObject
{
	//this class member is private as if declared public , 
	//it is declared as static , because the variable remains same for all objects and for initialization as null
	//it is pointer variable , because in c++ we cant declare same class variable inside that class as 
	//compiler cant get its actual size
	static SingleObject *object ;
	
	//Constructor is made private to prevent creation of multiple instances of class
	SingleObject()
	{
	}

	public :
	int i;
	//function to create single instance of a class
	static SingleObject*  getvalue()
	{
		//If object is null then only create the instance of it.
 		if(object==NULL)
		{
			object = new SingleObject;
			object->i=3;
			
			return object;
		}

		return NULL;
	}

};

//Initialize the static variable
SingleObject* SingleObject::object = NULL;

int main()
{
	//Initialize single instance of class
	SingleObject *s = s->getvalue();
	cout << "\n Value of i for only one instance of object : "<< s->i;
	return 0;
}
