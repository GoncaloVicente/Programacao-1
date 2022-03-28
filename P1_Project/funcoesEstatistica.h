#ifndef FUNCOESESTATISTICA_H_INCLUDED
#define FUNCOESESTATISTICA_H_INCLUDED

#include "funcoesEstatistica.h"
#include "estruturas.h"
void pesoMediodasEncomendas(tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int quantEncomendas);
void encomendasPorData(tipoEncomenda vetorEncomendas[], int quantEncomendas,int numeroRegisto);
tipoData lerData (void);
void cargaMediaVeiculos(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);
 void destinoMaisEncomendas(tipoEncomenda vetorEncomendas[], int quantEncomendas);
 void veiculoComMenorViagens(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int *quantVeiculos);
 void destinoMaisEncomendas(tipoEncomenda vetorEncomendas[], int quantEncomendas);
#endif // FUNCOESESTATISTICA_H_INCLUDED
