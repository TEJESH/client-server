#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

int check();

FILE *new,*new1;

int phi,M[200],n1,e,d,C[200],FLAG,C1,k,x2,z;
char buffer[256];

int check()
{
	int i;
	for(i=3;e%i==0 && phi%i==0;i+2)
	{
		FLAG = 1;
	}
FLAG = 0;
}


void error(char *msg)
{
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[])
{

  int p,q,s;

  int sockfd, portno, n,m;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  
  
  
  if(argc < 3)
  {
    fprintf(stderr,"usage %s hostname port\n",argv[0]);
    exit(0);
  }
  
  portno = atoi(argv[2]);
  
  sockfd = socket(AF_INET,SOCK_STREAM,0);
  if(sockfd<0)
  {
    error("ERROR opening socket");
  }
  
  server = gethostbyname(argv[1]);
  
  if(server == NULL)
  {
    fprintf(stderr, "ERROR, no such host\n");
    exit(0);
  }
  
  bzero((char *) &serv_addr, sizeof(serv_addr));
  
  serv_addr.sin_family = AF_INET;
  
  bcopy((char*)server->h_addr,(char*)&serv_addr.sin_addr.s_addr,server->h_length);
  
  serv_addr.sin_port = htons(portno);
  
  if(connect(sockfd,&serv_addr,sizeof(serv_addr))<0)
  {
    error("ERROR connecting");
  }
  
	
     printf("Enter Two Relatively Prime Numbers\t: ");
  	scanf("%d",&p);
	printf("\n");
	scanf("%d",&q);
		n1 = p*q;
		phi=(p-1)*(q-1);
		printf("\nF(n) phi value\t= %d",phi);
	do
	{
		printf("\nEnter e which is prime number and less than phi \t: ",n1);
		scanf("%d",&e);
		check();
	}while(FLAG==1);
	d = 1;
	do
	{
		s = (d*e)%phi;
		d++;
	}while(s!=1);
	
	d = d-1;

printf("\nPublic Key\t: {%d,%d}",e,n1);
printf("\nPrivate Key\t: {%d,%d}",d,n1);
	

printf("enter no of students:\t");
scanf("%d",&x2);

for(k=1;k<=x2;k++)
{
  printf("\nPLease enter the Number\t");
 
	scanf("%d",&M[k]);
        
}  
  new = fopen("simple", "a");

for(k=1;k<=x2;k++)
{
  fprintf(new,"\nMessage: %d\n",M[k]);
} 

 fclose(new);

  
          int i;
	
	
	

	for(k=1;k<=x2;k++)
	{
         C1 = 1;
	for(i=0;i< e;i++)
	
		{
		C1=C1*M[k]%n1;
		C1=C1%n1;
		}
	
	
	
	  C[k]=C1;
	  
	}
	
	for(k=1;k<=x2;k++)
	{
	printf("\n Encrypted keyword : %d\n",C[k]);
	}

  
  new1 = fopen("encrypt", "a");
for(k=1;k<=x2;k++)
{
  fprintf(new1,"\nMessage: %d\n",C[k]);
} 
 fclose(new1);
  

 

 // for(k=1;k<=x2;k++)
 // {
 // n=write(sockfd,&C,sizeof(C));
n=write(sockfd,&C,sizeof(C),sizeof(C)/sizeof(C[0]),10);

    

  
  if(n<0)
  {
    error("ERROR writing to socket");
  }
  
 // }	
//

  
  //for(k=1;k<=x2;k++)
 // {
  //n=read(sockfd,&C,sizeof(C));
n=read(sockfd,&C,sizeof(C),sizeof(C)/sizeof(C[0]),10);
  if(n<0)
  {
    error("ERROR reading from socket");
  }

 // }

  

  
  
  
  return 0;
}
  
  
