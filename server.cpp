#include<cstring>

#include<iostream>

#include<sys/socket.h>

#include<sys/types.h>

#include<arpa/inet.h>

#include<netinet/in.h>

#include<unistd.h>

using namespace std;



int main()

{

int ls,cs;

ls=socket(AF_INET,SOCK_STREAM,0);

if(ls==-1)

{

cerr<<"cant create";

return 0;

}



sockaddr_in server,client;

server.sin_family=AF_INET;

server.sin_port=htons(54000);

server.sin_addr.s_addr=INADDR_ANY;



memset(server.sin_zero,8,0);

unsigned len=sizeof(sockaddr_in);

if((bind(ls,(sockaddr*)&server,len))==-1)

{

cerr<<"cant bind";

return 0;

}



if(listen(ls,5)==-1)

{



	cerr<<"cant listen";

	return 0;

}

if((cs=accept(ls,(sockaddr*)&client,&len))==-1){

cerr<<"cant listen";

return 0;

}

close(ls);

char buf[4096];

string msg;

while(1){

memset(buf,4096,0);

int br=recv(cs,buf,4096,0);

if(br>0){

int sent=send(cs,buf,br+1,0);

cout<<"sent"<<sent<<"bytes to client"<<inet_ntoa(client.sin_addr)<<endl;

}

}

close(cs);

return 0;

}
