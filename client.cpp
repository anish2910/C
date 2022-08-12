#include <unistd.h> 

#include <sys/socket.h> 

#include<cstring>

#include<sys/types.h>

#include <netinet/in.h> 

#include<arpa/inet.h>

#include<iostream>

using namespace std;

int main() 

{ 

string ipAddress="127.0.0.1";

int port=54000;

	//create socket

	int client=socket(AF_INET,SOCK_STREAM,0);

	if(client==-1)

	{

		cerr<<"cant create";

		return 0;

	}	

//fill sockaddr_in struct

sockaddr_in hint;

hint.sin_family=AF_INET;

hint.sin_port=htons(54000);

inet_pton(AF_INET,ipAddress.c_str(),&hint.sin_addr);	

//connect to server

int con=connect(client, (sockaddr*)&hint ,sizeof(hint));

if(con==-1)

{

	cerr<<"cant connect";

	return 0;

}

//do while

char buf[4096];

string msg;

do

{

//prompt the user

	cout<<"> ";

	getline(cin,msg);

	if(msg.length()>0)

	{

	//send the msg to our server back

	int sent=send(client,msg.c_str(),msg.size()+1,0);

	if(sent!=-1)

	{

		//wait for server reply

		memset(buf,4096,0);

		int br=recv(client,buf,4096,0);

		if(br>0)

		{

			//print

			cout<<"server>"<<string(buf,0,br)<<endl;

		}

	}

	}

}while(msg.length()>0);

close(client);

return 0; 

} 
