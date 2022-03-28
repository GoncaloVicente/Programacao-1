#include <stdio.h>
#include <ctype.h>

#include "funcoesMenus.h"
#include "funcoesAuxiliares.h"

int subMenuVeiculos (void)
{
    int opc;

    printf("\n\n\n------------- MENU VEICULOS ------------------------------------------\n\n");
    printf("\t1 - Inserir veiculo\n");
    printf("\t2 - Consultar dados veiculos\n");
    printf("\t3 - Listar veiculos\n");
    printf("\t4 - Mostrar veiculos consoante as encomendas\n ");
    printf("\t5 - Alterar o veiculo\n");
    printf("\t6 - Ordenar por ordem decrescente\n");

    printf("\n\t0 - Voltar atras\n");
    opc = lerInteiro("\n\t\tOPCAO --> ", 0, 6);

    return opc;
}

int subMenuEncomendas (void)
{
    int opc;

    printf("\n\n\n------------- MENU ENCOMENDAS ------------------------------------------\n\n");
    printf("\t1 - Inserir encomendas\n");
    printf("\t2 - Consultar encomendas\n");
    printf("\t3 - Listar encomendas\n");
    printf("\t4 - Eliminar encomenda\n");
    printf("\t5 - Alterar destino da encomenda devolvida\n");
    printf("\t6 - Alterar estado encomenda");


    printf("\n\t0 - Voltar atras\n");
    opc = lerInteiro("\n\t\tOPCAO --> ", 0, 6);

    return opc;
}

int subMenuDadosEstatisticos (void)
{
    int opc;

    printf("\n\n\n------------- MENU DADOS ESTATISTICOS ------------------------------------------\n\n");
    printf("\t1 - Peso medio das encomendas\n");
    printf("\t2 - Quantidade de encomendas entregues\n");
    printf("\t3 - Carga media dos veiculos\n");
    printf("\t4 - Veiculos com menos viagens efetuadas\n");
    printf("\t5 - Destino com maior quantidade de encomendas entregues\n");

    printf("\n\t0 - Voltar atras\n");
    opc = lerInteiro("\n\t\tOPCAO --> ", 0, 5);

    return opc;
}

char menu(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int *quantVeiculos, int *quantEncomendas){
    char opc;
   char op;
    float percEncomendasEntregues=0.0;
    int  contadorEncomendas=0, i, contadorEncomendasDevolvidas=0, contadorEncomendasEntregues=0;


    	for (i=0; i<*quantEncomendas; i++)
    	{
    		if((strcmp(vetorEncomendas[i].estado, ESTADO_ENTREGUE))==0){
                contadorEncomendasEntregues++;
    		}
    		if((strcmp(vetorEncomendas[i].estado, ESTADO_DEVOLVIDA))==0){
                contadorEncomendasDevolvidas++;
    		}
    		if (((strcmp(vetorEncomendas[i].estado, ESTADO_ENTREGUE))==0) || ((strcmp(vetorEncomendas[i].estado, ESTADO_DEVOLVIDA))==0) || ((strcmp(vetorEncomendas[i].estado, ESTADO_CARREGADA))==0) || ((strcmp(vetorEncomendas[i].estado, ESTADO_REGISTADA))==0))
    		{
    			contadorEncomendas++;
    		}
    	}
    	if(*quantEncomendas!= 0){
                percEncomendasEntregues=(float)(contadorEncomendasEntregues)/(*quantEncomendas)*100;
    	}
    printf("\n\n\n\n-----------------------------------------------------------------------------------\n");
    printf("# Veiculos: %d\t\t\t\t# "/*Quantas Viagens Efetuadas: %d\n*/, *quantVeiculos /*quantViagensEfetuadas*/);
    printf("# Encomendas Registadas: %d\t\t# Encomendas Entregues (Percentagem): %.2f\n", contadorEncomendas, percEncomendasEntregues);
    printf("# Encomendas Devolvidas: %d\n", contadorEncomendasDevolvidas);
    printf("\n\n------------ MENU PRINCIPAL -------------------------------------------------------\n");
    printf("\n\tG - Gerir Veiculos\n");
    printf("\n\tE - Gerir Encomendas\n");
    printf("\n\tD - Verificar dados estatisticos\n");
    printf("\n\tF - Guardar ficheiros de dados\n");
    printf("\n\tL - Ler ficheiros de dados\n");


    printf("\n\tS - Sair do Programa\n");
    do
    {

        printf("\n\t\tOPCAO --> ");
        scanf(" %c", &opc);
        opc = toupper(opc);

        if (opc != 'G' && opc != 'S' && opc != 'E' && opc != 'D' && opc!= 'F' && opc!='L')
        {
            printf("\nERRO: Opcao desconhecida. Tente novamente.\n");
        }
    }
    while (opc != 'G' && opc != 'S' && opc != 'E' && opc != 'D' && opc!= 'F' && opc!='L');

    return opc;
}
