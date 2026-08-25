/******************************************************
* UNP.h the is the head file of UNP.C
* by Lian Wen on March 12, 1998
* most program are used for network process
*******************************************************/
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h> 
#include<netdb.h>
#include<sys/time.h>
#include<fcntl.h>
#define MAXLINE 80
#define SA struct sockaddr
#define LISTENQ 10


int Socket(int family, int type, int protocol);
unsigned long Inet_addr(char *p_address);
void Connect(int sockfd, SA *p_servaddr, int p_size);
void Shutdown(int sockfd,int type);
int Read(int sockfd, char *recvline, int p_maxnum);
void Fputs(char *recvline,FILE *f);
void Bind(int sockfd, SA *p_servaddr, int p_size);
void Listen(int sockfd, int backlog);
int Accept(int socket, SA *address, int *address_len);
ssize_t Write(int field, void *buff,int p_len);
void Close(int field);
struct hostent *Gethostbyname(const char *hostname);
struct hostent *Gethostbyaddr(const char *addr, size_t len,int family);
struct servent *Getservbyname(const char *servname,const char *protoname);
ssize_t writen(int fd,const void *vptr,size_t n);
ssize_t Writen(int fd,const void *vptr,size_t n);
ssize_t readn(int fd, void *vptr, size_t n);