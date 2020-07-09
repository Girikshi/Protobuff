//This is just a header file , no implementation is written in it

#include<memory>
#include<string>
using namespace std ;

class Person
{
	public :
	//Declare constructors and destructors
	Person ( string name , int age ) ;
	~Person () ;

	//Assignment operator and copy constructor
	Person ( const Person& other ) ;
	Person& operator = ( Person rhs );

	void getInfo();

	void setInfo(string name , int age);

	private :
	class Impl ;

	unique_ptr<Impl> pimpl ;


};
