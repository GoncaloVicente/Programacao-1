#ifndef FUNCOESAUXILIARES_H_INCLUDED
#define FUNCOESAUXILIARES_H_INCLUDED
#define MAX_STRING 50


void converterStringParaMaiusculas (char str[]);
int lerInteiro (char msg[MAX_STRING], int limMin, int limMax);
float lerFloat (char msg[MAX_STRING], float limMin, float limMax);
void lerString(char msg[MAX_STRING], char str[MAX_STRING], int tamanho);
void limparBuffer (void);



#endif // FUNCOESAUXILIARES_H_INCLUDED
