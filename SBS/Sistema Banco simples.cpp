//Sistema Banco Simples	


//Incluindo as bibliotecas:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <windows.h>

//Definindo as constantes:
#define MaxCad 200
#define MaxCpf 15
#define MaxNome 100
#define MaxStr 101

//Declarando as estruturas:
//Cpf:
struct CPF {
    unsigned int bloco1;
    unsigned int bloco2;
    unsigned int bloco3;
    unsigned int bloco4;
};

//Cpf para confirmação:
struct CpfFornecido {
    unsigned int bloco1;
    unsigned int bloco2;
    unsigned int bloco3;
   	unsigned int bloco4;
	};

//Cadastro:
struct Cadastro{
  char nome[MaxNome];
  struct CPF cpf;
  int atendimento;
  char tipoAtendimento[MaxStr];
};

//Caixa:
struct Caixa{
  int saldo;
  int saque;
  int deposito;
};

//Variáveis globais:
struct CpfFornecido cpfFornecido;
struct Caixa caixa;
int qtdAtendimento = 0;

//Declarando as funções:
void menu();
void menuCad(Cadastro* cadastro, Caixa* caixa, CpfFornecido *cpfFornecido);
void cadastrar(Cadastro* cadastro, Caixa* caixa, CpfFornecido *cF);
void Atendimento(Cadastro* cadastro, Caixa* caixa, CpfFornecido *cF);
void listar(Cadastro* cadastro);
void listarSetor(Cadastro* cadastro);
void AbreCaixa(Cadastro* cadastro, Caixa* caixa, struct CpfFornecido *cF);

//Corpo Principal - Menu:
int main() {
  setlocale(LC_ALL, "Portuguese");

  int opcao;
  Cadastro cadastro;
  Caixa caixa;
  
  

  //Faca menu até que o cliente escolha a opção 'sair': 

  do{

	system("cls");
    
	printf("Bem vindo a central banco SBS!\n\n");
	system("pause");
	printf("\n");
	
	printf("O que deseja fazer?\n\n");
	menu();
	fflush(stdin);
	scanf("%d", &opcao);
	printf("\nVocê será redirecionado...\n\n");
	system("pause");
	system("cls");

	switch(opcao){
      	case 1: menuCad(&cadastro, &caixa, &cpfFornecido);
       		break;
      	case 2: listar(&cadastro);
      			
    		break;
      	case 3: listarSetor(&cadastro);
      			
    		break;
      	case 4: printf("Saindo do sistema...\n\n");
    		break;

      	default: printf("opção invalida!\n");

	}

  }while(opcao != 4);
  
  return 0;
}

//Desenvolvendo as funções que rodarão o código:

//lista de menu:
void menu(){
  printf("1 - Solicitar atendimento:\n");
  printf("2 - Listar atendimentos:\n");
  printf("3 - Listar atendimentos por setor:\n");
  printf("4 - Sair:\n\n");
  
}

//------------------------------------------------------------------------------
void menuCad(Cadastro *cadastro, Caixa *caixa, CpfFornecido *cpfFornecido){
	
	int escolha;
		
	printf("Você já tem cadastro?\n\n");
	printf("1 - Sim\t\t" "2- Não\n\n");
	scanf("%d", &escolha);
	
	if(escolha == 1){	
		Atendimento(cadastro, caixa, cpfFornecido);
	}
	if(escolha == 2){
		
		cadastrar(cadastro, caixa, cpfFornecido);
		Atendimento(cadastro, caixa, cpfFornecido);
	}else{
		printf("Opção inválida!");
	}
	
}

//-------------------------------------------------------------------------------

//Cadastrar e atender os clientes:
void cadastrar(Cadastro* cadastro, Caixa* caixa, CpfFornecido *cpfFornecido){
	
	//Pegando as infos do cliente:
	
	system("cls");
	
	printf("Cadastrando novo cliente:\n\n");
	
	printf("Nome:");
	fflush(stdin);	
	fgets(cadastro[qtdAtendimento].nome, sizeof(cadastro[qtdAtendimento].nome), stdin);
	
	//Remove a nova linha "\n" dado na função 'fgets':
	cadastro[qtdAtendimento].nome[strcspn(cadastro[qtdAtendimento].nome, "\n")] = '\0';
	fflush(stdin);
	printf("\n");
	
		

	printf("CPF (Somente números):\n");
	fflush(stdin);
	scanf("%3d%3d%3d%2d", &(cadastro[qtdAtendimento].cpf.bloco1),&(cadastro[qtdAtendimento].cpf.bloco2),
	&(cadastro[qtdAtendimento].cpf.bloco3), &(cadastro[qtdAtendimento].cpf.bloco4));
	
	printf("\n");
	

	
		

	printf("Olá %s\n", cadastro[qtdAtendimento].nome);
	printf("Agora que temos seus dados, podemos começar o atendimento!\n");


	printf("\n");
	system("pause");
	system("cls");
	
	
	
}

//-------------------------------------------------------------------------------

//Atendimento

void Atendimento(Cadastro* cadastro, Caixa* caixa, CpfFornecido *cF){
	
	system("cls");
	
	int cpfEnc = 0;
	int i = 0;
	
	printf("Digite seu CPF para confirmação:\n");
	scanf("%3d%3d%3d%2d", &(cF->bloco1),&(cF->bloco2),
	&(cF->bloco3), &(cF->bloco4)); 
	fflush(stdin);
	printf("\n\n");
	system("pause");
	
	do{
		if((cadastro[i].cpf.bloco1 == cF->bloco1 &&
			cadastro[i].cpf.bloco2 == cF->bloco2 &&
			cadastro[i].cpf.bloco3 == cF->bloco3 && 
			cadastro[i].cpf.bloco4 == cF->bloco4) != 0){
			cpfEnc = 0;
			
			//Coletando o tipo de cadastro será efetuado:
			printf("Qual o tipo de atendimento deseja ser atendido?\n\n");
			printf("1 - Abertura de conta:\n");
			printf("2 - Caixa:\n");
			printf("3 - Gerente pessoa física:\n");
			printf("4 - Gerente Pessoa jurídica:\n");
			printf("\n");
			scanf("%d", &cadastro[qtdAtendimento].atendimento);
			printf("\n");
			fflush(stdin);
	
			//De acordo com a escolha do cliente, um dos caminhos será tomado:
			switch(cadastro[qtdAtendimento].atendimento){
		       	case 1: strcpy(cadastro[qtdAtendimento].tipoAtendimento, "Abertura de conta");
		               printf("Você escolheu - %d - %s\n", cadastro[qtdAtendimento].atendimento, cadastro[qtdAtendimento].tipoAtendimento);
		               printf("\n");
		               system("pause");
		        	break;
		      	 case 2: strcpy(cadastro[qtdAtendimento].tipoAtendimento, "Caixa");
		               printf("Você escolheu - %d - %s\n", cadastro[qtdAtendimento].atendimento, cadastro[qtdAtendimento].tipoAtendimento);
		               printf("\n");
		               system("pause");
		               AbreCaixa(&cadastro[qtdAtendimento], &caixa[qtdAtendimento], &cpfFornecido);
		        	break;

		       	case 3: strcpy(cadastro[qtdAtendimento].tipoAtendimento, "Gerente pessoa física");
		        	   printf("Você escolheu - %d - %s\n", cadastro[qtdAtendimento].atendimento, cadastro[qtdAtendimento].tipoAtendimento);
		        	   printf("\n");
		        	   system("pause");
		        	break;
		       	case 4: strcpy(cadastro[qtdAtendimento].tipoAtendimento, "Gerente pessoa jurídica");
		               printf("Você escolheu - %d - %s\n", cadastro[qtdAtendimento].atendimento, cadastro[qtdAtendimento].tipoAtendimento);
		               printf("\n");
		               system("pause");
		        	break;
		        case 5: printf("Saindo do sistema...\n\n");
		        	break;
		        	
		       default: printf("opção inválida!\n\n");  
			        
	  	    }
	  
	  		
				
		}else{
			cpfEnc++;
			printf("Cpf não encontrado\n\n");
			break;
		}
			
		qtdAtendimento++;
		
		i++;
		
	}while(cpfEnc == 0 && cadastro[qtdAtendimento].atendimento != 5);
		

	
}

//-------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------

//Listar os clientes por setor:
void listarSetor(Cadastro* cadastro){
	
	system("cls");
	
	//Perguntando qual setor será listado:
	int x = 0;	
	system("cls");
	printf("listando clientes por setor:\n\n");
	printf("Qual setor deseja listar?\n\n");
	printf("1 - Abertura de conta:\n");
	printf("2 - Caixa:\n");
	printf("3 - Gerente pessoa física:\n");
	printf("4 - Gerente Pessoa jurídica:\n\n");
	scanf("%d", &x);
	fflush(stdin);
	printf("\n");
  
    /*

	Listando de acordo com os cadastros já¡ efetuados e 
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
	    
		//Gerente pessoa física
	    if(cadastro[i].atendimento == 3 && x == 3){
	        strcpy(cadastro[i].tipoAtendimento, "Gerente pessoa física");
	        printf("Nome: %s\n", cadastro[i].nome);
    	  printf("CPF: %03d.%03d.%03d-%0d\n", cadastro[i].cpf.bloco1, 
					      cadastro[i].cpf.bloco2, 
					      cadastro[i].cpf.bloco3, 
					      cadastro[i].cpf.bloco4);
										
    	  printf("Atendimento: %d - %s\n",    cadastro[i].atendimento, 
					      cadastro[i].tipoAtendimento);
    	  printf("--------------------------------\n");
	    }
	
		//Gerente pessoa jurídica
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

//-------------------------------------------------------------------------------

//Caixa:
void AbreCaixa(Cadastro *cadastro, Caixa *caixa, CpfFornecido *cF){
	
	system("cls");
	
	int opc = 0;
	caixa->saldo = 0;
    int i = 0;
	int cpfEncontrado = 0;
	
	printf("Bem vindo ao caixa!\n\n");

  //Verifica se o CPF está cadastrado:	
	printf("Digite seu CPF para confirmação:\n");
	scanf("%3d%3d%3d%2d", &(cF->bloco1),&(cF->bloco2),
	&(cF->bloco3), &(cF->bloco4)); 
	fflush(stdin);
	printf("\n\n");
	system("pause");
	
   
    /* 
    Se o CPF já foi cadastrado, o cliente poderá realizar:
    - saque
    - depósito
    - checar o saldo em conta
    */

    do{

    	if((cadastro[i].cpf.bloco1 == cF->bloco1 &&
			cadastro[i].cpf.bloco2 == cF->bloco2 &&
			cadastro[i].cpf.bloco3 == cF->bloco3 && 
			cadastro[i].cpf.bloco4 == cF->bloco4) != 0){
			cpfEncontrado = 0;
				
			printf("Olá %s, o que deseja fazer?\n\n", cadastro[i].nome);
			printf("1 - Saque:\n");
			printf("2 - Depósito:\n");
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
			cpfEncontrado++;
			printf("Cpf não encontrado\n\n");
			system ("pause");
		}
			
		system("cls");	
			
	}while(cpfEncontrado == 0 && opc != 4);
	
		
 }
 
 /*
 	Este é um projeto para aprendizado em estrutura de dados em linguagem baixo nível,
 	conforme o projeto for evoluindo irei postando as mudanças.
 */
 
 //Fim
