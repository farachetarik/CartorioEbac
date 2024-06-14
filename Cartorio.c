#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	//Inicio da cria��o das vari�veis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e "w" significa escrever
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ", "); //salva a ,
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ", "); //salva a ,
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, sobrenome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ", "); //salva a ,
	fclose(file); //fecha o arquivo
	
	printf("digite o cargo a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, cargo); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	system("pause"); //Pausando a tela
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	//Inicio da cria��o das vari�veis/string
	char cpf [40];
	char conteudo[200];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo 
	file = fopen(cpf, "r"); //l� o arquivo
	
	if (file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es dos usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausando a tela
	
}

int deletar()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main() //Definindo Vari�veis
{
	int opcao = 0; //Definindo Vari�veis
	int laco = 1;
	
	for(laco = 1; laco = 1;) //loop para retornar ao Menu
	{
		system("cls"); //Respons�vel por limpar a tela
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");	//Inicio do Menu
		printf("Escolha a op��o desejada do Menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
	
		switch(opcao) //Inicio da sele��o do Menu
		{
			case 1:
			registro(); //Chamada de fun��es
			break;
			
			case 2:
			consulta(); //Chamada de fun��es
			break;
			
			case 3:
			deletar(); //Chamada de fun��es
			break;
			
			default:
			printf("Essa op��o n�o existe!\n");
			system("pause"); //Pausando a tela
			break;
		} //Fim da sele��o do Menu
    }
}
