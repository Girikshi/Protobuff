#include<iostream>
#include<string.h>
using namespace std;

//Base class
class animal
{
	protected :

	 int age ;
	 char* name ;

	public :

	 animal()
	 {
		 cout << "\n\nbase constructor called" ;
		 name = new char[20] ;
	 }
	 void set_data ( int age1,char* name1 )
	 {
		 age = age1 ;
		 strcpy ( name , name1 ) ;
	 }
};

class zebra : public animal
{
	public :

	void show_message ()
	{
		cout << "\n\nAge of zebra is : " << age << " and name is : " << name ;
		cout << "\nHe is from Africa." ;
	}
};

class dolphin : public animal
{
	public :

        void show_message()
        {
                cout<<"\n\nAge of dolphin is : "<<age<<" and name is : "<<name;
                cout<<"\nHe is from south america.";
        }

};

int main()
{
	zebra z1;
	dolphin d1;

	z1.set_data ( 3 , "bingo" ) ;
	d1.set_data ( 4 , "simba" ) ;

	z1.show_message() ;
	d1.show_message() ;
	
	cout<<"\n";
	return 0;
}
