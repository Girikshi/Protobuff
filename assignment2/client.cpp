//client program to input employee information from user, send it to server using socket and reflect the changes done by server.

//headers and related functions for socket and protobuff
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
#define h_addr h_addr_list[0] 
#define PORT 9002 
#define MAX1 1000
#define BACKLOG 5
using namespace std;
using google::protobuf::util::TimeUtil;

//Function to input information from user
void PromptForInfo(socketcon::Employee_name* emp_name)
{
	  cout<<"\n\n*********Input employee information**********";
	  cout << "\nEnter Employee's ID number: ";
	  int id;
	  cin >> id;
	  emp_name->set_id(id);
	  cin.ignore(256, '\n');

	  cout << "\nEnter employee name: ";
	  getline(cin, *emp_name->mutable_name());
	  
	  cout << "\nEnter email address of employee(blank for none): ";
	  string email;
	  getline(cin, email);
	  if (!email.empty()) {
	    emp_name->set_email(email);
	  }
	  
	  *emp_name->mutable_last_updated() = TimeUtil::SecondsToTimestamp(time(NULL));
	  cout<<"\nInfo Completed."<<endl;
}

//Function to show changed information by server
void ListPeople(const socketcon::Employees& employee) 
{
	  cout<<"\n\n*********Changed information by server**********";
	  for (int i = 0; i <employee.emp_size(); i++)
	   {
		    const socketcon::Employee_name&  person = employee.emp(i);
		    cout<<"\nUpdated id by server: "<<person.id();

		    cout << "\nupdated Name by server: " << person.name() ;

		    cout << "\nUpdated by time: " << TimeUtil::ToString(person.last_updated());
	   }
}


int main()
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	
	char serverMessage[MAX1];
        char clientMessage[MAX1];

        //creating a socket
        int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
        char hostname[MAX1], ipaddress[MAX1];
	struct hostent *hostIP; 
	//placeholder for the_emp ip address
	//if the gethostname returns a name then the program will get the ip address
	
	if(gethostname(hostname,sizeof(hostname))==0)
	{
	    hostIP = gethostbyname(hostname);//the netdb.h fucntion gethostbyname
	}
	else
	{
		printf("ERROR:FCC4539 IP Address Not ");
	}

	struct sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(PORT);
	serverAddress.sin_addr.s_addr = INADDR_ANY; 

	connect(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	// getting the address port and remote host
	printf("\nLocalhost: %s\n", inet_ntoa(*(struct in_addr*)hostIP->h_addr));
	printf("Local Port: %d\n", PORT);
	printf("Remote Host: %s\n", inet_ntoa(serverAddress.sin_addr));

                                                                                                                            
 while (1)
    {
	 socketcon::Employees employee; 
	 //Input user info          
	 PromptForInfo(employee.add_emp());
	 
	 //Serialize user info to string
	 string client;
         if(!employee.SerializeToString(&client))
         printf("\nentered info not serialized");
         strcpy(clientMessage,client.c_str());
         
         //Send converted string over socket
	 int send_byt=send(socketDescriptor, clientMessage,sizeof(clientMessage), 0);
       	
	 //Recieve changes done by server
         int recv_byt=recv(socketDescriptor,serverMessage, sizeof(serverMessage), 0) ;
        
         //If string doesn't parse correctly
         if (!employee.ParseFromString(serverMessage))
         {
            printf("\nFailed to parse address book.");
         }
         //Show the changes done by server
	 ListPeople(employee);
	

    }
        //close the socket
        close(socketDescriptor);
        return 0;
}

