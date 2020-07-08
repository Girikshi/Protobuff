#include<iostream>
using namespace std;

// enum variable to access variables
enum shapeType
{
	CIRCLE , TRIANGLE , RECTANGLE 
};

// abstract class
class shape
{
	public :
	
	virtual void printShape() = 0;
	static shape* create( shapeType type );

};

//derived class 
class circle : public shape
{
	public :

	//overriden method
	void printShape()
	{
		cout << "\nInside circle";
	}
};

class polygon : public shape
{
};

//derives shape class via multilevel inheritance
class triangle : public polygon
{
	public :

	void printShape()
        {
                cout << "\nInside circle";
        }

};

class rectangle : public polygon
{
	public :

	void printShape()
        {
                cout << "\nInside circle";
        }
};

//client class to select particular shape for particular client
class client 
{

	shape* sShape;
	public :
	client()
	{
		shapeType type = CIRCLE;
		sShape = shape :: create(type);

	}

	shape* getShape()
	{
		return sShape;
	}
};

//static method create to create various objects without users intervention
shape* shape::create(shapeType type)
{
	if(type==CIRCLE)
		return new circle();

	 if(type==TRIANGLE)
                return new triangle();

	 if(type==RECTANGLE)
                return new rectangle();


}

int main()
{

	client* cli = new client();
	shape* s = cli->getShape();
	s->printShape();
	cout<<endl;

	return 0;
}
