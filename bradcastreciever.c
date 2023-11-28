#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/socket.h>
int main()
{
	char str[100];
	struct sockaddr_in serv;
	int reuse=1,sock,len;
	sock=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&serv,sizeof(serv));
	setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
	serv.sin_family=AF_INET;
	serv.sin_port=htons(12345);
	serv.sin_addr.s_addr=INADDR_ANY;
	len=sizeof(serv);
	bind(sock,(struct sockaddr *)&serv,sizeof(serv));
	while(1)
	{
		bzero(str,100);
	 	recvfrom(sock,str,100,0,(struct sockaddr *)&serv,&len);
	 	printf("%s",str);
	}
	
	close(sock);
}