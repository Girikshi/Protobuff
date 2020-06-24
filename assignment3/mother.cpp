#include<iostream>
using namespace std;

//Base class 
class mother
{ 
	public :

	void display()
	{
		cout << "\nIn mother display" << endl ;
	}
	
};

//derived class deriving public members of base class
class daughter : public mother
{
	public :
	void display()
	{
		cout << "\nIn daughter display" << endl ;
	}

};

int main()
{
	daughter *girija=new daughter();
	//While using pointer use ptr->fun() 
	girija->display();
	//*girija.display() ;
	return 0;
}
