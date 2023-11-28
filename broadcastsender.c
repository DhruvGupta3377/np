#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/socket.h>
int main()
{
	char str[100],ans[10];
	struct sockaddr_in serv;
	int broad=1,sock;
	sock=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&serv,sizeof(serv));
	bzero(ans,10);
	setsockopt(sock,SOL_SOCKET,SO_BROADCAST,&broad,sizeof(broad));
	serv.sin_family=AF_INET;
	serv.sin_port=htons(12345);
	serv.sin_addr.s_addr=inet_addr("255.255.255.255");
	while(1)
	{
		printf("Do you want to broadcast?");
		fgets(ans,10,stdin);
		if(strncmp(ans,"yes",3)==0)
		{
			bzero(str,100);
			printf("Enter the data");
			fgets(str,100,stdin);
			sendto(sock,str,strlen(str),0,(struct sockaddr *)&serv,sizeof(serv));
		}
	}
	
	close(sock);
}