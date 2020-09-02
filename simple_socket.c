#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
short int creat_socket(void);
short int created_socket_bind(short int sock_fd,const char *ip_address,uint16_t port);
int handle_clients(int socket_fd);

short int creat_socket(void){
    short int status;
    printf("[*]creating socket...");
    status=socket(2,1,0);
    if (status>=0)
    {
        printf("done\n");
        return status;
    }else
    {
        printf("error\n");
        exit(EXIT_FAILURE);
        return -1;
    }
}
short int created_socket_bind(short int sock_fd,const char *ip_address,uint16_t port){
    int status;
    struct sockaddr_in server;
    server.sin_family=2;
    server.sin_port=htons(port);
    server.sin_addr.s_addr=INADDR_ANY;//    inet_addr(ip_address);
    printf("[*]Binding socket on %d...",port);
    status=bind(sock_fd,(struct sockaddr*)&server,sizeof(server));
    if (status>=0)
    {
        printf("done\n");
        return status;
    }else
    {
        printf("error\n");
        exit(EXIT_FAILURE);
    }
}

int handle_clients(int socket_fd){

     char buff[1024]="HTTP/1.1 200 OK\r\n\n";
     strcat(buff,"<h1>Hellow Its My First Http Server</h1><br> <p> USING C PROGRAMMING THE MOTHER OF ALL LANGUAGE</p>");
    struct sockaddr_in client_addr;
    int new_sock_fd;
    unsigned int pid;
    socklen_t client_len=sizeof(client_addr);
    char rbuff[3000];

while (1)
    {
          
          new_sock_fd=accept(socket_fd,(struct sockaddr*)&client_addr,(socklen_t*)&client_len);   
          printf("%d",new_sock_fd);  
          printf("\nconnection got from %s:%d",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
         read(new_sock_fd,rbuff,3000);
         printf("%s",rbuff);
         send(new_sock_fd,buff,1024,0);
        //  scanf("%c",&c);
                                                          
   
    }     

}
int main(){	
    unsigned int numhost=10;
    int sockfd=creat_socket();
    created_socket_bind(sockfd,"192.168.43.1",55441);
    listen(sockfd,numhost);
    handle_clients(sockfd);
 return 0;
   }