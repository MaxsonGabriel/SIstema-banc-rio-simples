/*
	Atividade Sistema Banco Simples
	
*/


//Incluindo as bibliotecas:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

//Definindo as constantes:
#define MaxCad 200
#define MaxCpf 15
#define MaxNome 100
#define MaxStr 101

//Declarando a estrutura:

struct CPF {
    unsigned int bloco1;
    unsigned int bloco2;
    unsigned int bloco3;
    unsigned int bloco4;
};

struct CpfFornecido {
    	unsigned int bloco1;
    	unsigned int bloco2;
    	unsigned int bloco3;
    	unsigned int bloco4;
	};

struct CpfFornecido cpfFornecido;


struct Cadastro{
  char nome[MaxNome];
  struct CPF cpf;
  int atendimento;
  char tipoAtendimento[MaxStr];
};

int qtdAtendimento = 0;


struct Caixa{
  int saldo;
  int saque;
  int deposito;
};

<<<<<<< HEAD
//Declarando as fun�oes:
=======
//Declarando as funçoes:
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4
void menu();
void cadastrar(Cadastro* cadastro, Caixa* caixa);
void listar(Cadastro* cadastro);
void listarSetor(Cadastro* cadastro);
void AbreCaixa(Cadastro* cadastro, Caixa* caixa, struct CpfFornecido *cF);


//Codigo Principal para Menu:
int main() {
  setlocale(LC_ALL, "Portuguese");

  int opcao;
  Cadastro cadastro;
  Caixa caixa;
  CpfFornecido fornecido;
  
<<<<<<< HEAD
  //Faca menu ate que o cliente escolha a op��o 'sair': 
=======
  //Faca menu ate que o cliente escolha a opcao 'sair': 
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4
  do{

	system("cls");
    
	printf("Bem vindo a central banco x!\n\n");
	system("pause");
	printf("\n");
	
	printf("O que deseja fazer?\n\n");
	menu();
	scanf("%d", &opcao);

    switch(opcao){
      case 1: cadastrar(&cadastro, &caixa);
       break;
      case 2: listar(&cadastro);
      			
    	break;
      case 3: listarSetor(&cadastro);
      			
    	break;
      case 4: printf("Saindo do sistema...\n\n");
    	break;
<<<<<<< HEAD
      default: printf("op�ao invalida!\n");
=======
      default: printf("opçao invalida!\n");
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4
      
    }

  }while(opcao != 4);
  
  return 0;
}




<<<<<<< HEAD
//Desenvolvendo as fun��es que rodar�o o c�digo
=======
//Desenvolvendo as funÃ§Ãµes que rodarÃ£o o cÃ³digo
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4

//lista de menu:
void menu(){
  printf("1 - Solicitar atendimento:\n");
  printf("2 - Listar atendimentos:\n");
  printf("3 - Listar atendimentos por setor:\n");
  printf("4 - Sair:\n\n");
  
}



//Cadastrar e atender os clientes:
void cadastrar(Cadastro* cadastro, Caixa* caixa){
	
	//Pegando as infos do cliente:
	
	system("cls");
	
	printf("Cadastrando novo cliente:\n\n");
	
	printf("Nome:");
	fflush(stdin);	
	fgets(cadastro[qtdAtendimento].nome, sizeof(cadastro[qtdAtendimento].nome), stdin);
	
	//Remove a nova linha "\n" dado na função 'fgets'
	cadastro[qtdAtendimento].nome[strcspn(cadastro[qtdAtendimento].nome, "\n")] = '\0';
	printf("\n");
	
		

<<<<<<< HEAD
	printf("CPF (Somente n�meros):\n");
=======
	printf("CPF (Somente números):\n");
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4
	scanf("%3d%3d%3d%2d", &(cadastro[qtdAtendimento].cpf.bloco1),&(cadastro[qtdAtendimento].cpf.bloco2),
	&(cadastro[qtdAtendimento].cpf.bloco3), &(cadastro[qtdAtendimento].cpf.bloco4));
	
	printf("\n");
	

	
		
<<<<<<< HEAD
	printf("Ol� %s\n", cadastro[qtdAtendimento].nome);
	printf("Agora que temos seus dados, podemos come�ar o atendimento!\n");
=======
	printf("Olá %s\n", cadastro[qtdAtendimento].nome);
	printf(" %s, agora que temos seus dados, podemos começar o atendimento!\n");
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4

	printf("\n");
	system("pause");
	system("cls");
	
	//Coletando o tipo de cadastro serÃ¡ efetuado:
	printf("Qual o tipo de atendimento deseja ser atendido?\n\n");
	printf("1 - Abertura de conta:\n");
	printf("2 - Caixa:\n");
<<<<<<< HEAD
	printf("3 - Gerente pessoa f�sica:\n");
	printf("4 - Gerente Pessoa jur�dica:\n");
=======
	printf("3 - Gerente pessoa fí­sica:\n");
	printf("4 - Gerente Pessoa jurí­dica:\n");
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4
	printf("\n");
	scanf("%d", &cadastro[qtdAtendimento].atendimento);
	printf("\n");
	fflush(stdin);
	
	//De acordo com a escolha do cliente, um dos caminhos ser� tomado:
	switch(cadastro[qtdAtendimento].atendimento){
		       case 1: strcpy(cadastro[qtdAtendimento].tipoAtendimento, "Abertura de conta");
		               printf("Voc� escolheu - %d - %s\n", cadastro[qtdAtendimento].atendimento, cadastro[qtdAtendimento].tipoAtendimento);
		               printf("\n");
		               system("pause");
		        	break;
		       case 2: strcpy(cadastro[qtdAtendimento].tipoAtendimento, "Caixa");
		               printf("Voc� escolheu - %d - %s\n", cadastro[qtdAtendimento].atendimento, cadastro[qtdAtendimento].tipoAtendimento);
		               printf("\n");
		               system("pause");
		               AbreCaixa(&cadastro[qtdAtendimento], &caixa[qtdAtendimento], &cpfFornecido);
		        	break;
<<<<<<< HEAD
		       case 3: strcpy(cadastro[qtdAtendimento].tipoAtendimento, "Gerente pessoa f�sica");
		        	   printf("Voc� escolheu - %d - %s\n", cadastro[qtdAtendimento].atendimento, cadastro[qtdAtendimento].tipoAtendimento);
		        	   printf("\n");
		        	   system("pause");
		        	break;
		       case 4: strcpy(cadastro[qtdAtendimento].tipoAtendimento, "Gerente pessoa jur�dica");
		               printf("Voc� escolheu - %d - %s\n", cadastro[qtdAtendimento].atendimento, cadastro[qtdAtendimento].tipoAtendimento);
=======
		       case 3: strcpy(cadastro[qtdAtendimento].tipoAtendimento, "Gerente pessoa fÃ­sica");
		        	   printf("Você escolheu - %d - %s\n", cadastro[qtdAtendimento].atendimento, cadastro[qtdAtendimento].tipoAtendimento);
		        	   printf("\n");
		        	   system("pause");
		        	break;
		       case 4: strcpy(cadastro[qtdAtendimento].tipoAtendimento, "Gerente pessoa jurÃ­dica");
		               printf("Você escolheu - %d - %s\n", cadastro[qtdAtendimento].atendimento, cadastro[qtdAtendimento].tipoAtendimento);
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4
		               printf("\n");
		               system("pause");
		        	break;
		        case 5: printf("Saindo do sistema...\n\n");
		        	break;
		       default: printf("op��o inv�lida!\n\n");  
			        
	  	    }
	  
	  	qtdAtendimento++;
}


//Listar os clientes:
void listar(Cadastro* cadastro){
	
  system("cls");
  
  printf("listando clientes cadastrados:\n\n");
  for(int i = 0; i < qtdAtendimento; i++){
    printf("Nome: %s\n", cadastro[i].nome);
    printf("CPF: %03d.%03d.%03d-%0d\n", cadastro[i].cpf.bloco1, 
					cadastro[i].cpf.bloco2, 
					cadastro[i].cpf.bloco3, 
					cadastro[i].cpf.bloco4);
										
    printf("Atendimento: %d - %s\n",    cadastro[i].atendimento, 
					cadastro[i].tipoAtendimento);
    printf("--------------------------------\n");
    
}

	system("pause");
  
}

//Listar os clientes por setor:
void listarSetor(Cadastro* cadastro){
	
	system("cls");
	
	//Perguntando qual setor ser� listado:
	int x = 0;	
	system("cls");
	printf("listando clientes por setor:\n\n");
	printf("Qual setor deseja listar?\n\n");
	printf("1 - Abertura de conta:\n");
	printf("2 - Caixa:\n");
<<<<<<< HEAD
	printf("3 - Gerente pessoa f�sica:\n");
	printf("4 - Gerente Pessoa jur�dica:\n\n");
=======
	printf("3 - Gerente pessoa física:\n");
	printf("4 - Gerente Pessoa jurí­dica:\n\n");
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4
	scanf("%d", &x);
	fflush(stdin);
	printf("\n");
  
    /*
<<<<<<< HEAD
	Listando de acordo com os cadastros j� efetuados e 
=======
	Listando de acordo com os cadastros já¡ efetuados e 
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4
	a escolha de atendimentos que o cliente deseja listar: */
	
	for(int i = 0; i < qtdAtendimento; i++){

		//Abertura de conta
	    if(cadastro[i].atendimento == 1 && x == 1){
	      strcpy(cadastro[i].tipoAtendimento, "Abertura de conta");
	      printf("Nome: %s\n", cadastro[i].nome);
    	  printf("CPF: %03d.%03d.%03d-%0d\n", cadastro[i].cpf.bloco1, 
					      cadastro[i].cpf.bloco2, 
					      cadastro[i].cpf.bloco3, 
					      cadastro[i].cpf.bloco4);
										
    	  printf("Atendimento: %d - %s\n",    cadastro[i].atendimento, 
					      cadastro[i].tipoAtendimento);
    	  printf("--------------------------------\n");
	    }

		//Caixa
	    if(cadastro[i].atendimento == 2 && x == 2){
	        strcpy(cadastro[i].tipoAtendimento, "Caixa");
	        printf("Nome: %s\n", cadastro[i].nome);
    	  printf("CPF: %03d.%03d.%03d-%0d\n", cadastro[i].cpf.bloco1, 
					      cadastro[i].cpf.bloco2, 
					      cadastro[i].cpf.bloco3, 
					      cadastro[i].cpf.bloco4);
										
    	  printf("Atendimento: %d - %s\n",    cadastro[i].atendimento, 
					      cadastro[i].tipoAtendimento);
    	  printf("--------------------------------\n");
	    }

<<<<<<< HEAD
		//Gerente pessoa f�sica
	    if(cadastro[i].atendimento == 3 && x == 3){
	        strcpy(cadastro[i].tipoAtendimento, "Gerente pessoa f�sica");
=======
		//Gerente pessoa física
	    if(cadastro[i].atendimento == 3 && x == 3){
	        strcpy(cadastro[i].tipoAtendimento, "Gerente pessoa física");
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4
	        printf("Nome: %s\n", cadastro[i].nome);
    	  printf("CPF: %03d.%03d.%03d-%0d\n", cadastro[i].cpf.bloco1, 
					      cadastro[i].cpf.bloco2, 
					      cadastro[i].cpf.bloco3, 
					      cadastro[i].cpf.bloco4);
										
    	  printf("Atendimento: %d - %s\n",    cadastro[i].atendimento, 
					      cadastro[i].tipoAtendimento);
    	  printf("--------------------------------\n");
	    }

<<<<<<< HEAD
		//Gerente pessoa jur�dica
=======
		//Gerente pessoa jurídica
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4
	    if(cadastro[i].atendimento == 4 && x == 4){
	        strcpy(cadastro[i].tipoAtendimento, "Gerente pessoa jurídica");
	        printf("Nome: %s\n", cadastro[i].nome);
    	  printf("CPF: %03d.%03d.%03d-%0d\n", cadastro[i].cpf.bloco1, 
					      cadastro[i].cpf.bloco2, 
					      cadastro[i].cpf.bloco3, 
					      cadastro[i].cpf.bloco4);
										
    	  printf("Atendimento: %d - %s\n",    cadastro[i].atendimento, 
					      cadastro[i].tipoAtendimento);
    	  printf("--------------------------------\n");
	    }
	     
	}
	
  system("pause");
}

//Caixa:
void AbreCaixa(Cadastro *cadastro, Caixa *caixa, CpfFornecido *cF){
	
	system("cls");
	
	int opc = 0;
	caixa->saldo = 0;
    int i = 0;
	bool cpfEncontrado = 0;
	
	printf("Bem vindo ao caixa!\n\n");


<<<<<<< HEAD
  //Verifica se o CPF est� cadastrado:
	
	
	printf("Digite seu CPF para confirma��o:\n");
	scanf("%3d%3d%3d%2d", &(cF->bloco1),&(cF->bloco2),
	&(cF->bloco3), &(cF->bloco4)); 
=======
  //Verifica se o CPF está cadastrado:
	
	
	printf("Digite seu CPF para confirmação:\n");
	scanf("%3d%3d%3d%2d", &(cF->bloco1),&(cF->bloco2),
	&(cF->bloco3), &(cF->bloco4));



	 //Verifica se o CPF está cadastrado:
	char cpfcmp2[MaxCpf];
	
	printf("Digite seu CPF para confirmaÃ§Ã£o:\n");
	scanf("%s", cpfcmp2);
	fflush(stdin);
	printf("\n\n");
	system("pause");
	printf("\n\n");
	
    
    
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4
    
    /* 
    Se o CPF j� foi cadastrado, o cliente poder� realizar:
    - saque
    - dep�sito
    - checar o saldo em conta
    */

    do{

    	if((cadastro[i].cpf.bloco1 == cF->bloco1 &&
			cadastro[i].cpf.bloco2 == cF->bloco2 &&
			cadastro[i].cpf.bloco3 == cF->bloco3 && 
			cadastro[i].cpf.bloco4 == cF->bloco4) != 0){
			cpfEncontrado = true;
				
<<<<<<< HEAD
			printf("Ol� %s, o que deseja fazer?\n\n", cadastro[i].nome);
			printf("1 - Saque:\n");
			printf("2 - Dep�sito:\n");
			printf("3 - Saldo:\n");
			printf("4 - Sair...\n\n");
			scanf("%d", &opc);
			fflush(stdin);
			printf("\n\n");
			
		      
	    
		    switch(opc){
		    	case 1: printf("Quanto deseja sacar?\n\n");
						scanf("%d", &caixa[i].saque);
						fflush(stdin);
						printf("\n");
						if (caixa[i].saldo >= caixa[i].saque) {
						    caixa[i].saldo -= caixa[i].saque;
						    printf("Saque realizado com sucesso!\n\n");
						} else {
						    printf("Saldo insuficiente! Fa�a um dep�sito!\n\n");
						}
						system("pause");
						break;
						   
		
				        
				case 2: printf("quanto deseja depositar?\n\n");
					    scanf("%d", &caixa[i].deposito);
					    fflush(stdin);
					    printf("\n");
					    caixa[i].saldo += caixa[i].deposito;
					    printf("Deposito realizado com sucesso!\n\n");
					    system("pause");
					    break;
				        
				case 3: printf("Seu saldo atual �: R$ %d\n\n", caixa[i].saldo);
					    system("pause");
					    break;
					        
				case 4: printf("Saindo do sistema...\n\n");
					    break;
					        
				default: printf("op��o inv�lida!\n\n");
					     system("pause");    
					}    
					
		}else{
			cpfEncontrado = false;
			printf("Cpf n�o encontrado\n\n");
			system ("pause");
		}
	
			
=======
				printf("Olá %s, o que deseja fazer?\n\n", cadastro[i].nome);
			    	printf("1 - Saque:\n");
				printf("2 - Depósito:\n");
				printf("3 - Saldo:\n");
				printf("4 - Sair...\n\n");
				scanf("%d", &opc);
				fflush(stdin);
				printf("\n\n");
			
		      
	    
		    		switch(opc){
		    			   case 1:
						   printf("Quanto deseja sacar?\n\n");
						   scanf("%d", &caixa[i].saque);
						   fflush(stdin);
						   printf("\n");
						   if (caixa[i].saldo >= caixa[i].saque) {
						       caixa[i].saldo -= caixa[i].saque;
						       printf("Saque realizado com sucesso!\n\n");
						   } else {
						       printf("Saldo insuficiente! Faça um depósito!\n\n");
						   }
						   system("pause");
							break;
		
				        
					    case 2: printf("quanto deseja depositar?\n\n");
					            scanf("%d", &caixa[i].deposito);
					            fflush(stdin);
					            printf("\n");
					            caixa[i].saldo += caixa[i].deposito;
					            printf("Deposito realizado com sucesso!\n\n");
					            system("pause");
					        	break;
				        
					    case 3: printf("Seu saldo atual é: R$ %d\n\n", caixa[i].saldo);
					        	system("pause");
					        	break;
					        
					    case 4: printf("Saindo do sistema...\n\n");
					        	break;
					        
					    default: printf("opção inválida!\n\n");
					        	 system("pause");    
					}    
		}else{
			printf("Cpf não encontrado");
			system ("pause");

    	
    	if(strcmp(cadastro[i].cpf, cpfcmp2) == 0){
    		printf("Olá %s, o que deseja fazer?\n\n", cadastro[i].nome);
	    	printf("1 - Saque:\n");
		    printf("2 - Depósito:\n");
		    printf("3 - Saldo:\n");
		    printf("4 - Sair...\n\n");
		    scanf("%d", &opc);
		    fflush(stdin);
		    printf("\n\n");
		
	      
    
	    	switch(opc){
		        case 1:
					    printf("Quanto deseja sacar?\n\n");
					    scanf("%d", &caixa[i].saque);
					    fflush(stdin);
					    printf("\n");
					    if (caixa[i].saldo >= caixa[i].saque) {
					        caixa[i].saldo -= caixa[i].saque;
					        printf("Saque realizado com sucesso!\n\n");
					    } else {
					        printf("Saldo insuficiente! FaÃ§a um depÃ³sito!\n\n");
					    }
					    system("pause");
					    break;

		        
		        case 2: printf("quanto deseja depositar?\n\n");
		                scanf("%d", &caixa[i].deposito);
		                fflush(stdin);
		                printf("\n");
		                caixa[i].saldo += caixa[i].deposito;
		                printf("Deposito realizado com sucesso!\n\n");
		                system("pause");
		        	break;
		        
		        case 3: printf("Seu saldo atual Ã©: R$ %d\n\n", caixa[i].saldo);
		        		system("pause");
		        	break;
		        
		        case 4: printf("Saindo do sistema...\n\n");
		        	break;
		        
		        default: printf("opÃ§Ã£o invÃ¡lida!\n\n");
		        	system("pause");
		        
			}

        }
		if(strcmp(cadastro[i].cpf, cpfcmp2) != 0){
    		printf("CPF não encontrado!\n\n");
    		system("pause");

		}
	
>>>>>>> fc5cb1e2e6f8a80a5db2a337ed512933d316b4a4
			
		system("cls");	
			
	}while(cpfEncontrado == true && opc != 4);
	
		
 }
