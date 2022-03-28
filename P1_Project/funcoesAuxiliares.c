#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesAuxiliares.h"


// ----------------------- FUNÇÕES AUXILIARES ------------------------------------------


void lerString(char msg[MAX_STRING], char str[MAX_STRING], int tamanho)
{
    int tamTexto;

    do
    {
        printf("%s", msg);
        fgets(str, tamanho, stdin);

        tamTexto = strlen(str);

        if (tamTexto <= 1)
        {
            printf("\n\nERRO: tem de inserir um valor.\n");
        }
        else
        {
            if (str[tamTexto-1] == '\n')
            {
                str[tamTexto-1] = '\0';
            }
            else
            {
                limparBuffer();
            }
        }
    }
    while (tamTexto <= 1);
}


int lerInteiro (char msg[MAX_STRING], int limMin, int limMax)
{
    int num, res;


    do
    {
        printf("%s", msg);
        res = scanf("%d", &num);
        limparBuffer();

        if (res != 1)
        {
            printf("\n\nERRO: o valor inserido tem que ser um numero inteiro.\n");
        }
        else
        {
            if (num < limMin || num > limMax)
            {
                printf("\n\nERRO: o numero tem de pertencer ao intervalo [%d, %d].\n", limMin, limMax);
            }
        }

    }
    while (num < limMin || num > limMax || res != 1);

    return num;
}


float lerFloat (char msg[MAX_STRING], float limMin, float limMax)
{
    float num;
    int res;


    do
    {
        printf("%s", msg);
        res = scanf("%f", &num);
        limparBuffer();

        if (res != 1)
        {
            printf("\n\nERRO: o valor inserido tem que ser um numero inteiro.\n");
        }
        else
        {
            if (num < limMin || num > limMax)
            {
                printf("\n\nERRO: o numero tem de pertencer ao intervalo [%.2f, %.2f].\n", limMin, limMax);
            }
        }

    }
    while (num < limMin || num > limMax || res != 1);

    return num;
}


void limparBuffer (void)
{
    char lixo;

    do
    {
        lixo = getchar();

    }
    while (lixo != '\n' && lixo != EOF);
}
char recebeMatricula()
{
	char matricula[9];
	printf("\n\nIntroduza a matricula do veiculo, formato ##-##-##.\n");
	do
    {
        scanf("%8s", &*matricula);
        matricula[8] = '\0';
	}
	while (!verificaMatricula(matricula));
	printf("\nMatricula valida!\n");
	return *matricula;
}

char lerMatricula(char a)
{
	if (a >= 48 && a <= 57) return 'N';
	if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) return 'L';
	return '-';
}
int verificaMatricula(char *matricula)
{
	char teste[9];
	int i;
	for (i = 0; i < 8; i++, matricula++) {
		teste[i] = lerMatricula(*matricula);
	}
	teste[8] = '\0';
	if (strcmp(teste, "LL-NN-NN") == 0) return 1;
	if (strcmp(teste, "NN-LL-NN") == 0) return 1;
	if (strcmp(teste, "NN-NN-LL") == 0) return 1;
	printf("\nMatricula Invalida! Insira de novo(LL-NN-NN ou NN-LL-NN ou NN-NN-LL) \n");
	return 0;
}

