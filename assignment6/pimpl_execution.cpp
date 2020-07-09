//File that includes library header. No need to recompile again if header file changes.

#include<iostream>
#include "pimpl_header.h"
using namespace std;

int main()
{
	Person p1 ( "girija", 22 ) ;
	Person p2 ( "atharva", 14 ) ; 

	p1.getInfo();
	p2.getInfo();

	p1.setInfo( "Mayuri" , 22 );
	p1.getInfo();
	return 0;
}

