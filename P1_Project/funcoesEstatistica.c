#include <stdio.h>
#include <ctype.h>

#include "funcoesMenus.h"
#include "funcoesAuxiliares.h"
#include "funcoesEstatistica.h"
#include "estruturas.h"


tipoData lerData (void);

void pesoMediodasEncomendas(tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int quantEncomendas)
{
    int somaPesoEncomenda=0, i;
    float mediapesoEncomenda=0;
    printf("\n\t\t ->->-> Peso medio das encomendas -<-<-<\n");
    if (quantEncomendas==0)
    {
        printf("\n\tAinda nao foram adicionados encomendas.\n\n\n");
    }
    else
    {
        for(i=0; i<quantEncomendas; i++)
        {
            somaPesoEncomenda+=vetorEncomendas[i].peso;
        }
        mediapesoEncomenda = (float) somaPesoEncomenda/quantEncomendas;
        printf("\n\tA media peso das encomendas e: %.2f\n\n\n", mediapesoEncomenda);
    }
}

void encomendasPorData(tipoEncomenda vetorEncomendas[], int quantEncomendas, int numRegisto)
{
    tipoData data;
    int  i, contador=0, numero, posicao;
    printf("\n\t\t ->->-> Encomendas entregues numa data -<-<-<\n\n\n");
    if (quantEncomendas==0)
    {
        printf("\n\tAinda nao foram adicionadas encomendas.\n\n\n");
    }
    else
    {
        data = lerData();

        for (i=0; i<quantEncomendas; i++)
        {

            if (vetorEncomendas[i].dataRegisto.ano==data.ano && vetorEncomendas[i].dataRegisto.mes==data.mes && vetorEncomendas[i].dataRegisto.dia==data.dia)
            {
                escreveDadosEncomenda(vetorEncomendas[i]);
                contador++;
            }
        }
        if(contador==0)
        {
            printf("\n\tNao foi adicionada nenhuma encomenda na data inserida.\n\n\n");
        }
    }
}


void cargaMediaVeiculos(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
    int somaCargaVeiculo=0, i;
    float mediaCargaVeiculo=0;
    printf("\n\t\t ->->-> Carga media dos veiculos -<-<-<\n");
    if (quantVeiculos==0)
    {
        printf("\n\tAinda nao foram adicionados veiculos.\n\n\n");
    }
    else
    {
        for(i=0; i<quantVeiculos; i++)
        {
            somaCargaVeiculo+=vetorVeiculos[i].carga;
        }
        mediaCargaVeiculo = (float) somaCargaVeiculo/quantVeiculos;
        printf("\n\tA carga media dos veiculos e: %.2f\n\n\n", mediaCargaVeiculo);
    }
}
void veiculoComMenorViagens(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int *quantVeiculos)
{
    int posicaoMenosViagens=0,i;
    if(*quantVeiculos==0)
    {
        printf("\n NAO EXISTE VEICULOS INSERIDOS");
    }
    else
    {

        for(i=1; i<*quantVeiculos; i++)
        {
            if(vetorVeiculos[i].numViagensEfetuadas < vetorVeiculos[posicaoMenosViagens].numViagensEfetuadas)
            {
                posicaoMenosViagens=i;
            }
        }
        vetorVeiculos[posicaoMenosViagens].matricula ;
        escreveDadosVeiculo(vetorVeiculos[posicaoMenosViagens], 0, quantVeiculos);
    }
}


void destinoMaisEncomendas(tipoEncomenda vetorEncomendas[], int quantEncomendas)
{
    int numMax=-1, numeroRepeticoes, posicaoComDestino;
    int i,j;
    if (quantEncomendas==0)
    {
        printf("\n NAO EXISTEM ENCOMENDAS");
    }
    else
    {


        for (i = 0; i < quantEncomendas; ++i)
        {
            for (j = 0; j < quantEncomendas; ++j)
            {
                if (i!=j)
                {
                    if (strcmp(vetorEncomendas[i].destino, vetorEncomendas[j].destino)==0)
                    {
                        numeroRepeticoes++;
                    }
                }
            }
            if (numeroRepeticoes>numMax)
            {
                numMax=numeroRepeticoes;
                posicaoComDestino=i;
            }
        }
        if (numMax = -1)
        {
            printf("Ambos tem o numero igual de encomendas");
        }
        else
        {
            printf("O destino com mais entregas é: %s\n", vetorEncomendas[posicaoComDestino].destino);

        }
    }
}
