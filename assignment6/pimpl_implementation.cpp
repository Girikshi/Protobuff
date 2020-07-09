//Executable file containing all the implementations of functions

#include "pimpl_header.h"
#include<iostream>
using namespace std;

class Person :: Impl
{
	public :
	string name ;
	int age ;

	Impl(string name , int age)
	{
		this->name = name ;
		this->age = age ;
	}

	~Impl(){}
};

Person :: Person ( string name , int age ) : pimpl( new Impl ( name , age ) )
{
}

Person :: ~Person() = default ;	

Person :: Person ( const Person& other ) : pimpl ( new Impl ( *other.pimpl ) )
{
}

Person& Person :: operator= (Person rhs)
{
    swap(pimpl, rhs.pimpl);
    return *this;
}

void Person :: setInfo( string name , int age )
{
	pimpl -> name = name ;
	pimpl -> age  = age  ;
}

void Person :: getInfo()
{
	cout << "\nName : " << pimpl->name ;
	cout << "\nAge  : " << pimpl->age <<endl ;
}


