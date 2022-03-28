#ifndef FUNCOESMENUS_H_INCLUDED
#define FUNCOESMENUS_H_INCLUDED
#include "estruturas.h"
char menu(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int *quantVeiculos, int *quantEncomendas);
//char menu (int quantVeiculos, int quantViagensEfetuadas); //int quantEquipamentos, float percEquipAvariados)
int subMenuVeiculos(void);
int menuAlterarVeiculo (void);
int subMenuDadosEstatisticos (void);
int subMenuEncomendas (void);

#endif // FUNCOESMENUS_H_INCLUDED
