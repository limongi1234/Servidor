#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef WIN32
#include <winsock.h>
#else  // Linux, Unix
  #include <unistd.h>
  #include <netdb.h>
  #include <netinet/in.h>
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <arpa/inet.h>
#endif

#define PORT 1200
#define BACKLOG 4


int main(int argc, char *argv[])
{ struct sockaddr_in server;
  struct sockaddr_in client;
  int sockfd, sockfd2;
  int nSize, nSize2,i;
  
  struct Filmes 
  {
  	char Filme;
  	char Status;
  	int  n_locacoes;};
  	
  	struct Cliente
	{
  	  char Filme;
  	  int codigo_cliente;};
  	
  	  struct Filmes filme[3];
  	  struct Cliente cliente[3];
  	
      char MsgOperacao[128+1];
      char MsgCodigo[128+1];
      char MsgFilme[128+1];
      char szSend[180+1];
      WSADATA wsaData;
      int err;
      int nPorta;
      int finalizar;
  
  	  filme[0].Filme = "Matrix";
  	  filme[0].Status = "Dispon?vel";
  	  filme[0].n_locacoes=0;
  
      filme[1].Filme = "Hercules";
  	  filme[1].Status = "Dispon?vel";
  	  filme[1].n_locacoes = 0;

      filme[2].Filme = "P?nico";
  	  filme[2].Status = "Dispon?vel";
  	  filme[2].n_locacoes = 0;
  	
  	  cliente[0].Filme = "";
  	  cliente[0].codigo_cliente = 1;

  	  cliente[1].Filme = "";
  	  cliente[1].codigo_cliente = 2;
  	
  	  cliente[2].Filme = "";
  	  cliente[2].codigo_cliente = 3;
  	
  	  err = WSAStartup( MAKEWORD(2,2), &wsaData );

	  if(err != 0)
	  {
	     printf("N?o consegui carregar a DLL WINSOCK.DLL.");
         return 0;
	  }


    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
	{
	   printf("N?o consegui abrir o socket.");
       return 0;
    }

    ////////////////////////////////////////////////////////
    memset(&server, 0, sizeof(struct sockaddr_in));

    ////////////////////////////////////////////////////
    
	//printf("Informe o numero da porta neste servidor: ");
	//gets(szMsg);
    //nPorta = (int)atoi(szMsg);
    nPorta = 2000;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( (u_short)nPorta);
    server.sin_family = AF_INET;
    ////////////////////////////////////////////////////
    // Bind
    if( bind(sockfd,(struct sockaddr *)&server,sizeof(struct sockaddr) ) == -1)
	{
	    printf("N?o consegui efetuar o bind.");
       return 0;
    }

    ///////////////////////////////////////////////////////
    // listner
    if( listen(sockfd,BACKLOG))
	{
	    printf("Nao consegui efetuar o listner.");
        return 0;
    }
    //////////////////////////////////////////////////////
    finalizar = 0;
    while(  !finalizar  )
    {

	   nSize = sizeof(struct sockaddr_in);

       printf("Aguardando conex?o do cliente.\n");
       
       if((sockfd2 = accept(sockfd, (struct sockaddr*) &client, &nSize)) == -1)
	   {
	      printf("Erro no accept.\n");
          break;
       }

       printf("Cliente conectado!!!\n");
       
	   memset(MsgOperacao,0,sizeof(MsgOperacao));
       printf("\n\nAguardando a Opera??o!\n");
       if((nSize = recv(sockfd2,(char *)MsgOperacao,sizeof(MsgOperacao),0)) == -1)
	   {
	      printf("Erro no recv.\n");
         break;
       }
	   
	   MsgOperacao[nSize] = '\0';
       
       memset(MsgCodigo,0,sizeof(MsgCodigo));
	   printf("Aguardando o c?digo do filme!\n");
       if((nSize = recv(sockfd2,(char *)MsgCodigo,sizeof(MsgCodigo),0)) == -1)
	   {
	      printf("Erro no recv.\n");
         break;
       }
	   
	   MsgCodigo[nSize] = '\0';       
	   
	   memset(MsgFilme,0,sizeof(MsgFilme));
	   printf("Aguardando o nome do filme!\n");
       if((nSize = recv(sockfd2,(char *)MsgFilme,sizeof(MsgFilme),0)) == -1)
	   {
	      printf("Erro no recv.\n");
          break;
       }
	   
	   MsgFilme[nSize] = '\0'; 
       
       switch (atoi(MsgOperacao))
	   {
	   	 case 1:
	   		for (i = 0; i <= 2 ; i ++)
			{
			   printf("%s",filme[i].Filme);
			   //if (strcmp(filme[i].Filme, MsgFilme)==0){
			   //	printf("V?lido");
			   	   	/*if (filme[i].Status == "Disponivel"){
			   	   		filme[i].Status ="Alugado";
			   	   		filme[i].n_locacoes = filme[i].n_locacoes++;
			   	   		printf("%s",filme[i].Status);
			   	    }*/
			}
			break;
			system("pause");
	   }
			
      //printf("\n\nLimite Maximo = %s; \nLimite Minimo = %s; \n\n",szMsg, szMsg2);
       //strcpy(szSend,"Mensagem recebida com sucesso pelo servidor!");
       //nSize = send(sockfd2,(const char *)szSend,strlen(szSend),0);
       //strcpy(szSend,numRand);
       nSize = send(sockfd2,(const char *)szSend,strlen(szSend),0);
       	        
      if (strcmp(MsgOperacao,"FIM") == 0) 
           finalizar = 1;
      closesocket(sockfd2);
    }
    //////////////////////////////////////////////////////

    closesocket( sockfd );
    WSACleanup();

	return 0;
}
