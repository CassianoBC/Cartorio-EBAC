#include <stdio.h> //Bliblioteca de comunicação com o usuário
#include <stdlib.h> //Bliblioteca de alocação de espaço de memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings



int registro() //Responsável por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informaçoes dos usuários
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores da string
	
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
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
  	
	system ("pause");
}
 
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	else
	{
		remove(cpf);
		printf("Usuário deletado com sucesso! \n");
		system("pause");
	}
}



int main()
{
    int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	
	    system("cls"); //Rensonsável por limpar a tela
	    
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("Opção:");  //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls");
	    
	    switch(opcao) //inicio da seleção do menu
	    {
	    	case 1:
	    	registro(); //chamada de funções
    	    break;
    	    
    	    case 2:
    	    consulta();
			break;
		    
		    case 3:
			deletar();
		    break;
		    
		    default:
		    printf("Essa opção não está disponivel!\n");
		    system("pause");
		    break;
		} //fim da seleção
	
	}
		
}
