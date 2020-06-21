//Server program to read message from client, change it and again send it to the client

//headers for socket,protobuff and related functions 

#include <fstream>
#include <google/protobuf/util/time_util.h>
#include <iostream>
#include <fstream>
#include <google/protobuf/util/time_util.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "socketcon.pb.h"
#define MAX1 1000
#define BACKLOG 5
using namespace std;
using google::protobuf::util::TimeUtil; 

//Function to change the information recieved from client
void changeInfo (socketcon::Employees& employee )
{
  for (int i = 0; i < employee.emp_size(); i++)
  {
	    socketcon::Employee_name *person = employee.mutable_emp(i);
	    cout<<"\n\n********Change information in server*********";
	    cout<<"\nExsisting id : "<<person->id();
	    cout<<"\nEnter new id : ";
	    int id;
	    cin>>id;
	    person->set_id(id);
	    cin.ignore(256, '\n');
	    
	    cout << "\nExsisting  Name : " << person->name();
	    cin.ignore(256, '\n');
	    cout << "\nEnter new employee name : ";
	    getline(cin,*person->mutable_name());
	    cout << "\nNew updated Name : " << person->name();
	     
	    cout << " \nUpdated by time : " << TimeUtil::ToString(person->last_updated()) << endl;
   }

}
int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    
    char  serverMessage[MAX1];
    char  clientMessage[MAX1];
    
    //create the server socket
    int  socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

    //If socket is not created properly
    if( socketDescriptor < 0 )
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    }

    //Assign values to structure
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9002);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    //calling bind function to oir specified IP and port
    bind(socketDescriptor, (struct sockaddr*)&serverAddress, sizeof(serverAddress));    

    //Listen to client first
    listen(socketDescriptor, BACKLOG);
    
    //starting the accepting
    int clientSocketDescriptor = accept(socketDescriptor, NULL, NULL);
    
    while (1)
    {
       //Receive protobuff object from client
        int recv_byt=recv(clientSocketDescriptor,clientMessage, sizeof(clientMessage), 0) ;
     
	socketcon::Employees employee;
	//Parse string information into employee object
	 if (!employee.ParseFromString(clientMessage))
	 {
            cerr << "\nFailed to parse Employee info." << endl;
         }
         
         //Change original information
	  changeInfo(employee);
	  
	  //Again send changed information to the client
	  string server;
	  if(!employee.SerializeToString(&server))
         printf("\nentered info not serialized");
         strcpy(serverMessage,server.c_str());
	  send(clientSocketDescriptor, serverMessage, sizeof(serverMessage) , 0);
    }
    
        //close the socket
        close(socketDescriptor);
        return 0;
}
