#include <stdio.h> // biblioteca de comunica��o com o us�ario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de textos por regiao
#include <string.h> //  biblioteca respons�vel por cuidar dos string 

int registro()//Fun��o responsavem por cadastrar os usu�rios no sistema


{

	//inicio cria��o de vari�veis /string   
    char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da  cria��o de vari�veis /string   

	printf("Digite o CPF a ser cadastrado:"); // coletando informa��o do usuario 
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo,cpf); // Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo  e o "w" significa escrever 
	fprintf(file,cpf); // salvo o valor da variavel 
	fclose(file); //fecha o arquivo 
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado");
	scanf ("%s",nome);
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);	
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file= fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadasreado");
	scanf("%s",cargo);
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	 }

int consulta()
{
 	setlocale(LC_ALL,"Portuguese");//Definindo a linguagem
    
	char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado");
    scanf("%s",cpf);
    
    FILE *file;
    file=fopen(cpf,"r");
    
    if(file== NULL)
    
    {
    	printf("N�o foi posivel abrir o arquivo, n�o localizado!");
	}
 	
 	while(fgets(conteudo,200, file)!=NULL)
 	
 	{
 		printf("\nEssas s�o as informa��es do usuario:");
 		printf("%s", conteudo);
 		printf("\n\n");
	 }
	 
	 system("pause");
	 
	 
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser digitado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file=fopen(cpf,"r"); 
	
	if(file == NULL) 
	{
		printf("O usuario n�o se encontra no sistema!.\n");
		system("pause");
	}	
	
}

int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); 
			
		setlocale(LC_ALL,"Portuguese");//Definindo a linguagem
	
		printf("### Cardapio Fafia's ###\n\n");//inicio do menu 
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1- Registrar nomes\n");
		printf("\t2- Consultar nomes\n");
		printf("\t3- Deletar nomes\n\n");
		printf("\t4- Sair do sistema\n\n ");
		printf("Op��o:"); //fim do menu
	
		scanf("%d", &opcao);//armazenando a escolha do uzuario 
	
		system("cls"); // responsavel por limpar a tela
		
		
		switch(opcao)
		{
			case 1:
			registro();	//chamada de fun��es 
			break;
			
			case 2:
			consulta();	
			break;
		
			case 3:
			deletar();	
			break;
			
			case 4:
			printf("obrigada por utilizar o sistema! \n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o esta disponivel!\n");
			system("pause");
			break;
				
			}
   
    }
}    

 
