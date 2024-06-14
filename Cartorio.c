#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	//Inicio da criação das variáveis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e "w" significa escrever
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ", "); //salva a ,
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ", "); //salva a ,
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, sobrenome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ", "); //salva a ,
	fclose(file); //fecha o arquivo
	
	printf("digite o cargo a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, cargo); //salva o valor da variável
	fclose(file); //fecha o arquivo
	system("pause"); //Pausando a tela
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	//Inicio da criação das variáveis/string
	char cpf [40];
	char conteudo[200];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo 
	file = fopen(cpf, "r"); //lê o arquivo
	
	if (file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações dos usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //Pausando a tela
	
}

int deletar()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}

int main() //Definindo Variáveis
{
	int opcao = 0; //Definindo Variáveis
	int laco = 1;
	
	for(laco = 1; laco = 1;) //loop para retornar ao Menu
	{
		system("cls"); //Responsável por limpar a tela
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");	//Inicio do Menu
		printf("Escolha a opção desejada do Menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
	
		switch(opcao) //Inicio da seleção do Menu
		{
			case 1:
			registro(); //Chamada de funções
			break;
			
			case 2:
			consulta(); //Chamada de funções
			break;
			
			case 3:
			deletar(); //Chamada de funções
			break;
			
			default:
			printf("Essa opção não existe!\n");
			system("pause"); //Pausando a tela
			break;
		} //Fim da seleção do Menu
    }
}
