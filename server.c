#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int phi,M[200],n1,e,d,C[200],FLAG,p,q,s,C1[200],k,x;

int check();


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
  exit(1);
}

int main(int argc, char *argv[])
{
  
  int sockfd, newsockfd, portno, clilen;

char buffer[256];
 
  
  struct sockaddr_in serv_addr, cli_addr;
  int n;
  
  if(argc < 2)
  {
    fprintf(stderr, "ERROR, no part provided\n");
    exit(1);
  }
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  
  if(sockfd < 0)
  {
    error("EROR opemimg socket");
  }
  
  bzero((char *) &serv_addr, sizeof(serv_addr));
  
  portno = atoi(argv[1]);
  
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);
  
  if(bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr))<0)
  {
    error("ERROR on binding");
  }
  
  listen(sockfd,5);
  clilen = sizeof(cli_addr);
  
  
  newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);

  
  if(newsockfd<0)
  {
    error("ERROR on accept");
  }

 // for(k=1;k<=x2;k++)
 // {
  //n = read(newsockfd,&C,sizeof(C));
 
  n = read(newsockfd,&C,sizeof(C),sizeof(C)/sizeof(C[0]),10);
  
  if(n<0)
  {
    error("ERROR reading from socket");
  }

 // }

printf("Enter Two Relatively Prime Numbers\t: ");
  	scanf("%d%d",&p,&q);
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
printf("\nPrivate Key\t: {%d,%d}\n",d,n1);

for(k=1;k<=10;k++)
{
printf("\ncyphered text is: %d\n",C[k]);

 int i;
int m=1;

                for( i=0;i<d;i++)
		{ 
		m=m*C[k]%n1;
		m = m%n1;
			
		}

  M[k]=m;


		printf("\n Decrypted Message: %d\n",m);

}
  //printf("\nEnter the Cipher text\t: ");




//for(k=1;k<=10;k++)
//{
  //scanf("%d",&C[k]);
  
        
	
	
//}



//for(k=1;k<=10;k++)
//{

		
	
//}


  
  //printf("here is the messege:%s\n",C1);
	
  n=write(newsockfd,"i got your message",18);

  if(n<0)
  {
    error("ERROR writing to socket");
  }


  return 0;
}
  
