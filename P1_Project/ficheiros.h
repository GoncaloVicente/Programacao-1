#ifndef FICHEIROS_H_INCLUDED
#define FICHEIROS_H_INCLUDED

#include "funcoesMenus.h"
#include "estruturas.h"
void guardarFicheiro (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int quantEncomendas);
void lerFicheiro (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int *quantVeiculos, tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int *quantEncomendas);

#endif // FICHEIROS_H_INCLUDED
