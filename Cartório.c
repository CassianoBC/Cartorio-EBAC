#include <stdio.h> //Bliblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Bliblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings



int registro() //Respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa�oes dos usu�rios
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e "w" significa escrever
	fprintf(file,cpf); //Salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //"a" significa atualizar
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	
	}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;
	file = fopen(cpf,"r");
  	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
  	
	system ("pause");
}
 
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("Usu�rio deletado com sucesso! \n");
		system("pause");
	}
}



int main()
{
    int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
	
	
		for(laco=1;laco=1;)
    	{
	
	
		    system("cls"); //Rensons�vel por limpar a tela
	    	
    	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    	printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		    printf("Escolha a op��o desejada do menu:\n\n");
	    	printf("\t1 - Registrar nomes\n");
	    	printf("\t2 - Consultar nomes\n");
	    	printf("\t3 - Deletar nomes\n"); 
	    	printf("\t4 - Sair do programa\n\n");
	    	printf("Op��o:");  //Fim do menu
	
	    	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    	system("cls");
	    
	    	switch(opcao) //inicio da sele��o do menu
	    	{
	    		case 1:
	    		registro(); //chamada de fun��es
    	 	    break;
    	    
    	 	    case 2:
    	 	    consulta();
				break;
		    
			    case 3:
				deletar();
			    break;
		    
			    case 4:
			    printf("Obrigado por usar nosso sistema!\n\n");
			    return 0;
			    break;
		    
			    default:
			    printf("Essa op��o n�o est� disponivel!\n");
			    system("pause");
			    break;
			} //fim da sele��o
	
		}
	}
	
	else
		printf("Senha incorreta!");	
}
