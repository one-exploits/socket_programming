#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
short int creat_socket(void);
short int created_socket_bind(short int sock_fd,const char *ip_address,uint16_t port);
short int creat_socket(void){
    short int status;
    printf("[*]creating... socket\n");
    status=socket(2,1,0);
    if (status>=0)
    {
        printf("[*]socket created successfully.\n");
        return status;
    }else
    {
        printf("[!]creation of socket fail....!\n");
        return -1;
    }
}
short int created_socket_bind(short int sock_fd,const char *ip_address,uint16_t port){
    int status;
    struct sockaddr_in server;
    server.sin_family=2;
    server.sin_port=htons(port);
    server.sin_addr.s_addr=inet_addr(ip_address);
    printf("[*]Binding... socket\n");
    status=bind(sock_fd,(struct sockaddr*)&server,sizeof(server));
    if (status>=0)
    {
        printf("[*]Socket bind successfull\n");
    }else
    {
        printf("[!]Socket bind unsuccessfull!!!\n");
    }
    
    


}
int main(){

    int fd=creat_socket();
    int c=created_socket_bind(fd,"192.168.43.47",8080);
    listen(fd,100);
    //accept()
   /*  printf("size of  unsigned short int is:>>>>%d bytes \n",sizeof(unsigned short int));
    printf("size of  uint16_t is:>>>>%d bytes \n",sizeof(u_int16_t));
    printf("size of uint32_t is:>>>>%d bytes \n",sizeof(u_int32_t)); */
   /*  int vfd=socket(2,1,0);
    struct sockaddr_in myaddr;
    myaddr.sin_family=2;
    myaddr.sin_port=htons(80);
    myaddr.sin_addr.s_addr=INADDR_ANY;
    inet_pton(AF_INET,"www.google.com",&myaddr.sin_addr);
    int s;
    if((s=connect(vfd,(struct sockaddr*)&myaddr,sizeof(myaddr)))>0){
        printf("open port ");
    }
      inet_addr();

    printf("%d",s); */
    return 0;
   }