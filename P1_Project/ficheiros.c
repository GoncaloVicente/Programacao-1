#include <stdio.h>
#include "ficheiros.h"
#include "estruturas.h"

//Guardar ficheiros de dados

void guardarFicheiro (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int quantEncomendas)
{
    FILE *ficheiro;
    int elementosGuardados;

    ficheiro = fopen("dadoBin.dat", "wb");

    if (ficheiro == NULL)
    {
        printf("\nERRO: Falha na abertura do ficheiro.\n");
    }
    else
    {
        elementosGuardados = fwrite(&quantVeiculos, sizeof(int), 1, ficheiro);
        if (elementosGuardados != 1)
        {
            perror("\nERRO: Falha na gravacao do numero de veiculos inseridos.\n");
        }
        else
        {
            elementosGuardados = fwrite(vetorVeiculos, sizeof (tipoVeiculo), quantVeiculos, ficheiro);
            if (elementosGuardados != quantVeiculos)
            {
                perror("\nERRO: Falha na gravacao dos dados dos veiculos inseridos.\n");
            }
            else
            {
                elementosGuardados = fwrite(&quantEncomendas, sizeof(int), 1, ficheiro);
                if (elementosGuardados != 1)
                {
                    perror("\nERRO: Falha na gravacao do numero de encomendas inseridas.\n");
                }
                else
                {
                    elementosGuardados = fwrite(vetorEncomendas, sizeof(tipoEncomenda), quantEncomendas, ficheiro);
                    if (elementosGuardados != quantEncomendas)
                    {
                         perror("\nERRO: Falha na gravacao dos dados das encomendas inseridas.\n");
                    }
                }
            }
        }
        fclose(ficheiro);
    }
}

//Ler ficheiros de dados

void lerFicheiro (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int *quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int *quantEncomendas)
{
    FILE *ficheiro;
    int elementosGuardados;

    *quantEncomendas = 0;
    *quantVeiculos = 0;

    ficheiro = fopen("dadoBin.dat", "rb");

    if (ficheiro == NULL)
    {
        perror("\nERRO: Falha na abertura do ficheiro.\n");
    }
    else
    {
        elementosGuardados = fread(quantVeiculos, sizeof(int), 1, ficheiro);
        if (elementosGuardados != 1)
        {
            perror("\nERRO: Falha na leitura do numero de veiculos inseridos.\n");
        }
        else
        {
            elementosGuardados = fread(vetorVeiculos, sizeof (tipoVeiculo), *quantVeiculos, ficheiro);
            if (elementosGuardados != *quantVeiculos)
            {
                perror("\nERRO: Falha na leitura dos dados dos veiculos inseridos.\n");
                *quantVeiculos = 0;
            }
            else
            {
                elementosGuardados = fread(quantEncomendas, sizeof(int), 1, ficheiro);
                if (elementosGuardados != 1)
                {
                    perror("\nERRO: Falha na leitura do numero de encomendas inseridas.\n");
                }
                else
                {
                    elementosGuardados = fread(vetorEncomendas, sizeof(tipoEncomenda), *quantEncomendas, ficheiro);
                    if (elementosGuardados != *quantEncomendas)
                    {
                         perror("\nERRO: Falha na leitura dos dados das encomendas inseridas.\n");
                         *quantEncomendas = 0;
                    }
                }
            }
        }
        fclose(ficheiro);
    }
}
