/* 
<<<<<<< HEAD
	Atividade Sistema Banco Simples
=======
	Atividade: Sistema Banco Simples
>>>>>>> ccb554b152a14f55006c4b939510b4c73b8b799d
*/


//Incluindo as bibliotecas:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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

//Declarando as funções:
void menu();
void cadastrar(Cadastro* cadastro, Caixa* caixa);
void listar(Cadastro* cadastro);
void listarSetor(Cadastro* cadastro);
void AbreCaixa(Cadastro* cadastro, Caixa* caixa, struct CpfFornecido *cF);


//Código Principal para Menu:
int main() {
  setlocale(LC_ALL, "Portuguese");

  int opcao;
  Cadastro cadastro;
  Caixa caixa;
  CpfFornecido fornecido;
  
  //Faça menu até que o cliente escolha a opção 'sair': 
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
      default: printf("opção inválida!\n");
      
    }

  }while(opcao != 4);
  
  return 0;
}




//Desenvolvendo as funções que rodarão o código

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
	
	//Remove a nova linha "\n" dado na fun��o 'fgets'
	cadastro[qtdAtendimento].nome[strcspn(cadastro[qtdAtendimento].nome, "\n")] = '\0';
	printf("\n");
	
		
<<<<<<< HEAD
	printf("CPF (Somente n�meros):\n");
	scanf("%3d%3d%3d%2d", &(cadastro[qtdAtendimento].cpf.bloco1),&(cadastro[qtdAtendimento].cpf.bloco2),
	&(cadastro[qtdAtendimento].cpf.bloco3), &(cadastro[qtdAtendimento].cpf.bloco4));
	
	printf("\n");
	

	
		
	printf("Ol� %s\n", cadastro[qtdAtendimento].nome);
	printf("Agora que temos seus dados, podemos come�ar o atendimento!\n");
=======
	printf("Então %s, agora que temos seus dados, podemos começar o atendimento!\n", cadastro[qtdAtendimento].nome);
>>>>>>> ccb554b152a14f55006c4b939510b4c73b8b799d
	printf("\n");
	system("pause");
	system("cls");
	
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
										
    printf("Atendimento: %d - %s\n", cadastro[i].atendimento, 
									 cadastro[i].tipoAtendimento);
    printf("--------------------------------\n");
    
}

	system("pause");
  
}

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
	Listando de acordo com os cadastros já efetuados e 
	a escolha de atendimentos que o cliente deseja listar: */
	
	for(int i = 0; i < qtdAtendimento; i++){
	    if(cadastro[i].atendimento == 1 && x == 1){
	      strcpy(cadastro[i].tipoAtendimento, "Abertura de conta");
	      printf("Nome: %s\n", cadastro[i].nome);
    	  printf("CPF: %03d.%03d.%03d-%0d\n", cadastro[i].cpf.bloco1, 
										cadastro[i].cpf.bloco2, 
										cadastro[i].cpf.bloco3, 
										cadastro[i].cpf.bloco4);
										
    	  printf("Atendimento: %d - %s\n",  cadastro[i].atendimento, 
									 		cadastro[i].tipoAtendimento);
    	  printf("--------------------------------\n");
	    }
	    if(cadastro[i].atendimento == 2 && x == 2){
	        strcpy(cadastro[i].tipoAtendimento, "Caixa");
	        printf("Nome: %s\n", cadastro[i].nome);
    		printf("CPF: %03d.%03d.%03d-%0d\n", cadastro[i].cpf.bloco1, 
										cadastro[i].cpf.bloco2, 
										cadastro[i].cpf.bloco3, 
										cadastro[i].cpf.bloco4);
										
    		printf("Atendimento: %d - %s\n", cadastro[i].atendimento, 
									 		 cadastro[i].tipoAtendimento);
    		printf("--------------------------------\n");
	    }
	    if(cadastro[i].atendimento == 3 && x == 3){
<<<<<<< HEAD
	        strcpy(cadastro[i].tipoAtendimento, "Gerente pessoa f�sica");
	        printf("Nome: %s\n", cadastro[i].nome);
    		printf("CPF: %03d.%03d.%03d-%0d\n", cadastro[i].cpf.bloco1, 
										cadastro[i].cpf.bloco2, 
										cadastro[i].cpf.bloco3, 
										cadastro[i].cpf.bloco4);
										
    		printf("Atendimento: %d - %s\n", cadastro[i].atendimento, 
									 		 cadastro[i].tipoAtendimento);
    		printf("--------------------------------\n");
	    }
	    if(cadastro[i].atendimento == 4 && x == 4){
	        strcpy(cadastro[i].tipoAtendimento, "Gerente pessoa jur�dica");
	        printf("Nome: %s\n", cadastro[i].nome);
    		printf("CPF: %03d.%03d.%03d-%0d\n", cadastro[i].cpf.bloco1, 
										cadastro[i].cpf.bloco2, 
										cadastro[i].cpf.bloco3, 
										cadastro[i].cpf.bloco4);
										
    		printf("Atendimento: %d - %s\n", cadastro[i].atendimento, 
									 		 cadastro[i].tipoAtendimento);
    		printf("--------------------------------\n");
=======
	      strcpy(cadastro[i].tipoAtendimento, "Gerente pessoa física");
	      printf("Nome: %s\n", cadastro[i].nome);
	      printf("CPF: %s\n", cadastro[i].cpf);
	      printf("Atendimento: %d - %s\n", cadastro[i].atendimento, cadastro[i].tipoAtendimento);
	      printf("------------------------------\n");
	    }
	    if(cadastro[i].atendimento == 4 && x == 4){
	      strcpy(cadastro[i].tipoAtendimento, "Gerente pessoa jurídica");
	      printf("Nome: %s\n", cadastro[i].nome);
	      printf("CPF: %s\n", cadastro[i].cpf);
	      printf("Atendimento: %d - %s\n", cadastro[i].atendimento, cadastro[i].tipoAtendimento);
	      printf("------------------------------\n");
>>>>>>> ccb554b152a14f55006c4b939510b4c73b8b799d
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
	int cpfEncontrado = 0;
	
	printf("Bem vindo ao caixa!\n\n");

<<<<<<< HEAD
  //Verifica se o CPF est� cadastrado:
	
	
	printf("Digite seu CPF para confirma��o:\n");
	scanf("%3d%3d%3d%2d", &(cF->bloco1),&(cF->bloco2),
	&(cF->bloco3), &(cF->bloco4));
	
	
=======
  //Verifica se o CPF está cadastrado:
	char cpfcmp2[MaxCpf];
	
	printf("Digite seu CPF para confirmação:\n");
	scanf("%s", cpfcmp2);
>>>>>>> ccb554b152a14f55006c4b939510b4c73b8b799d
	fflush(stdin);
	printf("\n\n");
	system("pause");
	printf("\n\n");
	
    
    
    
    /* 
    Se o CPF já foi cadastrado, o cliente poderá realizar:
    - saque
    - depósito
    - checar o saldo em conta
    */

    do{
<<<<<<< HEAD
    	if((cadastro[i].cpf.bloco1 == cF->bloco1 &&
			cadastro[i].cpf.bloco2 == cF->bloco2 &&
			cadastro[i].cpf.bloco3 == cF->bloco3 && 
			cadastro[i].cpf.bloco4 == cF->bloco4) != 0){
				cpfEncontrado = 1;
				
				
				
				
				printf("Ol� %s, o que deseja fazer?\n\n", cadastro[i].nome);
			    printf("1 - Saque:\n");
				printf("2 - Dep�sito:\n");
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
			printf("Cpf n�o encontrado");
			system ("pause");
=======
    	
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
		        
	        
        
        }
		if(strcmp(cadastro[i].cpf, cpfcmp2) != 0){
    		printf("CPF não encontrado!\n\n");
    		system("pause");
>>>>>>> ccb554b152a14f55006c4b939510b4c73b8b799d
		}
		

			    		
			    		
					
			
			
		i++;	
		system("cls");	
			
		}while(!cpfEncontrado && opc != 4);
	
		
     
}




