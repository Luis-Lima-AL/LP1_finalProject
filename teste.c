#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void Tela_inicial()
{
    int op_int;

	printf("Bem vindo ao ZAP RAIZ\n");
	printf("1-Login\n2-Criar conta\n3-Sobre o ZAP RAIZ\n4-Sair\n");
	printf("Digite a opção desejada: ");
	scanf("%d", &op_int);
}

void Criar_conta()
{

    char *conta[1000];
    FILE *conta_txt;
    
    printf("\nDigite seu nome completo: ");
    scanf("%s", &conta);
    fprintf(conta_txt, "Nome: %s\n", conta);

    printf("Digite seu nome de usuário: ");
    scanf("%s", &conta);
    fprintf(conta_txt, "Nome de usuário: %s\n", conta);

    printf("Digite sua senha: ");
    scanf("%s", &conta);
    fprintf(conta_txt, "Senha: %s\n", conta);

    printf("Conta criada com sucesso!\nAgora retorne à tela inicial e realize seu login");
}

void Login()
{   
    FILE *conta_txt;
    size_t len = 100;
    char *linha = malloc(len);
    conta_txt = fopen("conta.txt", "r");
    char conta[100];
    char credencial[100];

    printf("\nDigite seu nome de usuário: ");
    scanf("%s", &conta);
    printf("Digite sua senha: ");
    scanf("%s", &credencial);

    while (getline(&linha, &len,conta_txt)>0)
    {
        for (int i = 0; i <(strlen(linha)); ++i)
        {   
            conta[i] = linha[i];
            if(linha[i] == '_'){
                printf("Login realizado com sucesso\n");
                break;
            }
        }
        if(conta == credencial)
        {
            printf("Dentro do if que compara email e credenciais\n");
            break;
        }
        else
        {
            printf("Deu errado as strings nao sao iguais\n");
        }
    }

    fclose(conta_txt);
}

void Encerrar()
{
    printf("O programa será encerrado\n");
    exit(1);
}

void Sobre()
{
    printf("Projeto para a disciplina Linguagem de Programação 1, para o curso de Matemática Computacional\nO projeto foi desenvolvido pelo aluno Luís Henrique Augusto de Lima, do segundo período do curso\n");
}

void Criar_contato()
{
    int op_int;
    char contatos[1000];
    FILE *contatos_txt;
    contatos_txt = fopen("contatos.txt", "a");

    printf("\nDigite o nome do contato: ");
    scanf("%s", &contatos);
    fprintf(contatos_txt, "Nome: %s\n", contatos);

    printf("Digite o IP do usuário: ");
    scanf("%d", &contatos);
    fprintf(contatos_txt, "IP: %d\n", contatos);
}

void Start_chat()
{

    int op_int;

    printf("Bem vindo ao ZAP RAIZ\n");
    printf("1-Iniciar conversa\n2-Participar de uma conversa\n3-VOltar\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &op_int);

}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char *conta[1000], *contatos[1000];
    FILE *contatos_txt, *conta_txt;
    int op_int;
    bool chat;

    contatos_txt = fopen("contatos.txt", "a");
    conta_txt = fopen("conta.txt", "a");

    chat = true;

    while(chat)
    {

        Tela_inicial();

        if(conta_txt == NULL)
        {
            printf("Arquivo não pode ser aberto");
            getchar();
            exit(1);
        }

        switch (op_int)
        {
            case 1:
                Login();
                continue;
            case 2:
                Criar_conta();
                continue;
            case 3:
                Sobre();
                continue;
            case 4:
                Encerrar();
                continue;
        }
    }

	return 0;
}