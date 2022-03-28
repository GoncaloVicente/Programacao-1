#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoesMenus.h"
#include "funcoesAuxiliares.h"
#include "ficheiros.h"
#include "estruturas.h"
#include "funcoesEstatistica.h"


void escreveData (tipoData data);
tipoData lerData(void);
///----------------Funcoes veiculo---------------------------------------------------
tipoVeiculo leDadosVeiculos(int quantVeiculos, tipoVeiculo vetorVeiculo[MAX_VEICULOS]);
int calculos (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);
void inserirVeiculo (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int *quantVeiculos);
int procuraVeiculo (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, char matricula[MAX_MATRICULA]);
void listaEncomendaVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);
void escreveDadosVeiculo(tipoVeiculo veiculo, int cabecalho);
void listaVeiculos (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);
void consultaVeiculoDesignacao (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);
int comparaNumEncomendasVeiculos(const void *v1, const void *v2);
void alterarVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int quantEncomendas, int quantVeiculos );
void ordenarVeiculosOrdemCrescente( tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);

///------------------Funcoes encomenda--------------------------------------------------
void inserirEncomenda (tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int *quantEncomendas);
void eliminarEncomenda(tipoEncomenda vetorEncomenda[MAX_ENCOMENDAS], int *quantEncomendas);
int procuraEncomenda (tipoEncomenda vetorEncomenda[MAX_ENCOMENDAS], int quantEncomendas, int numRegisto);
void consultaEncomendaNrRegisto (tipoEncomenda vetorEncomenda[MAX_ENCOMENDAS], int quantEncomendas);
void escreveDadosEncomenda (tipoEncomenda encomenda, int cabecalho);
void listaEncomenda (tipoEncomenda vetorEncomenda[MAX_ENCOMENDAS], int quantEncomendas);
void editarEncomenda(tipoEncomenda vetorEncomenda[MAX_ENCOMENDAS], int quantEncomendas);
void alterarEstadoEncomenda(tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS],tipoVeiculo vetorVeiculos[MAX_VEICULOS],  int quantEncomendas, int quantVeiculos );


void escreveLog(tipoEncomenda encomenda);

int main(void)
{
    tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS];
    tipoVeiculo vetorVeiculos[MAX_VEICULOS];
    int quantVeiculos=0;
    int quantViagensEfetuadas=0;
    int quantEncomendas=0;
    int numRegisto=0;
    char opc;
    int subOpc;


    do
    {
        quantViagensEfetuadas = calculos(vetorVeiculos, quantVeiculos);
        opc =  menu(vetorVeiculos, vetorEncomendas,&quantVeiculos, &quantEncomendas);
        switch (opc)
        {
        case 'G': // gerir Veiculos
            do
            {
                subOpc = subMenuVeiculos();
                switch (subOpc)
                {
                case 1:  // Inserir um novo veiculo
                    inserirVeiculo(vetorVeiculos, &quantVeiculos);
                    break;
                case 2:
                    consultaVeiculoDesignacao(vetorVeiculos, quantVeiculos);
//
                    break;
                case 3:  // Listar TODOS os veiculos
                    listaVeiculos(vetorVeiculos, quantVeiculos);

                    break;
                case 4:
                    listaEncomendaVeiculo(vetorVeiculos,quantVeiculos);
                    break;
                case 5:
                    alterarVeiculo(vetorVeiculos, vetorEncomendas, quantEncomendas, quantVeiculos );
                    break;
                case 6:
                    ordenarVeiculosOrdemCrescente(vetorVeiculos, quantVeiculos);
                    break;
                }
            }
            while (subOpc != 0);
            break;
        case 'E': //gerir emcomendas
            do
            {
                subOpc = subMenuEncomendas();
                switch (subOpc)
                {
                case 1: // Inserir encomendas
                    inserirEncomenda (vetorEncomendas, &quantEncomendas);
                    break;
                case 2: // Consultar encomendas
                    consultaEncomendaNrRegisto (vetorEncomendas, quantEncomendas);
                    break;
                case 3: // Listar encomendas
                    listaEncomenda (vetorEncomendas, quantEncomendas);
                    break;
                case 4: // Eliminar encomendas
                    eliminarEncomenda( vetorEncomendas,  &quantEncomendas);

                    break;
                case 5: // Alterar destino da encomenda devolvida
                    editarEncomenda(vetorEncomendas, quantEncomendas);
                    break;
                case 6:
                     alterarEstadoEncomenda(vetorEncomendas, vetorVeiculos,  quantEncomendas,  quantVeiculos );

                    break;
                }
            }
            while (subOpc != 0);
            break;
        case 'D': //gerir emcomendas
            do
            {
                subOpc = subMenuDadosEstatisticos();
                switch (subOpc)
                {
                case 1: // Peso medio das encomendas
                    pesoMediodasEncomendas( vetorEncomendas, quantEncomendas);
                    break;
                case 2: // Quantidade de encomendas entregues
                    encomendasPorData(vetorEncomendas, quantEncomendas, numRegisto);
                    break;
                case 3: // Carga media dos veiculos
                    cargaMediaVeiculos( vetorVeiculos, quantVeiculos);
                    break;
                case 4: // Veiculos com menos viagens efetuadas
                    veiculoComMenorViagens( vetorVeiculos, &quantVeiculos);
                    break;
                case 5: // Destino com maior quantidade de encomendas entregues
                    destinoMaisEncomendas( vetorEncomendas,  quantEncomendas);
                    break;
                }
            }
            while (subOpc != 0);
            break;

        case 'F': //Gravar ficheiros de dados
            guardarFicheiro (vetorVeiculos, quantVeiculos,vetorEncomendas, quantEncomendas);
            break;
        case 'L'://Ler ficheiro de dados
            lerFicheiro (vetorVeiculos, &quantVeiculos, vetorEncomendas, &quantEncomendas);
            break;
        case 'S': //Sair
            break;

        }

    }
    while(opc!= 'S');
    return 0;
}
// Função para calcular o total de viagens efetuadas
int calculos (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
    int i, quantViagensEfetuadas;

    quantViagensEfetuadas = 0;

    for (i=0; i < quantVeiculos; i++)
    {
        (quantViagensEfetuadas) += vetorVeiculos[i].numViagensEfetuadas;
    }

    return quantViagensEfetuadas;
}

///----------------------------Funcoes Veiculos-------------------------------------------
void inserirVeiculo (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int *quantVeiculos)
{
    int posicao;

    if (*quantVeiculos == MAX_VEICULOS)
    {
        printf("\n\nATENCAO: Impossivel inserir um novo veiculo(MAXIMO atingido).\n");
    }
    else
    {
        printf("\n\n-------------- INSERIR Veiculo --------------  \n");
        lerString("\nMatricula: ", vetorVeiculos[*quantVeiculos].matricula, MAX_MATRICULA);
        //recebeMatricula();
        posicao = procuraVeiculo(vetorVeiculos, *quantVeiculos, vetorVeiculos[*quantVeiculos].matricula);
        if (posicao == NAO_EXISTE)  // Veiculo não existe no vetor
        {
            vetorVeiculos[*quantVeiculos].dataFabrico=lerData();
            vetorVeiculos[*quantVeiculos].numViagensEfetuadas = lerInteiro("\n Nr. viagens efetuadas: ", 0, 9999999);
            vetorVeiculos[*quantVeiculos].carga=lerInteiro("\n Carga (kl): ",0, MAX_CARGA);
            vetorVeiculos[*quantVeiculos].quantidadeEncomendasTransportadas= 0;
            printf("Quantidade de encomendas: %d", vetorVeiculos[*quantVeiculos].quantidadeEncomendasTransportadas);
            strcpy(vetorVeiculos[*quantVeiculos].estado, ESTADO_DISPONIVEL);
            printf("\n Estado %s",vetorVeiculos[*quantVeiculos].estado);

            (*quantVeiculos)++;
        }
        else
        {
            escreveDadosVeiculo(vetorVeiculos[posicao], 0);
            printf("\n\nATENCAO: O veiculo %s ja existe.\n", vetorVeiculos[*quantVeiculos].matricula);
        }
    }
}
void alterarVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int quantEncomendas, int quantVeiculos )
{
    int posicao,i;
    int contadorPeso;
    int numeroAuxiliar;
    char matricula [MAX_MATRICULA];
    printf("\n ALterar estado do veiculo");
    lerString("\nMatricula: ", vetorVeiculos[quantVeiculos].matricula, MAX_MATRICULA);
    posicao = procuraVeiculo(vetorVeiculos, quantVeiculos, vetorVeiculos[quantVeiculos].matricula);
    if(posicao==NAO_EXISTE)
    {
        printf("\n VEICULO NAO ESXITE");
    }
    else
    {
        printf("\n  Altera estado");
        do
        {
            printf("\n 1 - Disponivel");
            printf("\n 2 - Em carga");
            printf("\n 3 - A transportar");
            printf("\n 4 - De regresso");
            printf("\n 5 - Avariado");
            printf("\n Estado: ");
            scanf("%d", &numeroAuxiliar);

            switch(numeroAuxiliar)
            {
            case 1:
                strcpy(vetorVeiculos[posicao].estado, ESTADO_DISPONIVEL);
                if(strcmp(vetorVeiculos[posicao].estado, ESTADO_DISPONIVEL))
                {
                    printf("Veiculo ja se encontra disponivel");
                }
                break;
            case 2:
                strcpy(vetorVeiculos[posicao].estado, ESTADO_EM_CARGA);
                if(strcmp(vetorVeiculos[posicao].estado, ESTADO_EM_CARGA))
                {
                    printf("Veiculo ja se encontra em carga");
                }
                break;
            case 3:

                for(i=0; i<quantEncomendas; i++)
                {
                    if (strcmp(vetorEncomendas[i].veiculo, vetorVeiculos[posicao].matricula)==0)
                    {
                        contadorPeso+=vetorEncomendas[i].peso;
                    }
                }
                if(contadorPeso>(0.8*vetorVeiculos[posicao].carga)&& contadorPeso<=vetorVeiculos[posicao].carga)
                {
                    strcpy(vetorVeiculos[posicao].estado, ESTADO_TRANSPORTAR);
                }
                else
                {
                    printf("\n Erro na quantidade do peso necessario para o (transportar) ");
                }

                break;
            case 4:
                strcpy(vetorVeiculos[posicao].estado, ESTADO_DE_REGRESSO);
                if(strcmp(vetorVeiculos[posicao].estado, ESTADO_DE_REGRESSO))
                {
                    printf("Veiculo ja se encontra de regresso");
                }
                break;
            case 5:
                strcpy(vetorVeiculos[posicao].estado, ESTADO_AVARIADO);
                if(strcmp(vetorVeiculos[posicao].estado, ESTADO_AVARIADO))
                {
                    printf("Veiculo ja se encontra avariado");
                }
                break;
            }
        }
        while (numeroAuxiliar!=1 && numeroAuxiliar!=2 && numeroAuxiliar!=3 && numeroAuxiliar!=4 && numeroAuxiliar!=5);
    }





}
// função que procura um veiculo tendo em conta a sua designação
int procuraVeiculo (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, char matricula[MAX_MATRICULA])
{
    int posicao, i;

    posicao=NAO_EXISTE;

    for (i=0; i < quantVeiculos; i++)
    {
        if (strcmp(vetorVeiculos[i].matricula, matricula) == 0)
        {
            posicao = i;
            i = quantVeiculos;
        }
    }

    return posicao;
}


// Função que escreve no ecra os dados do veiculo passado por parâmetro. O parâmetro cabeçalho é uma flag que indica se os títulos da listagem são ou não escritos no ecra
void escreveDadosVeiculo(tipoVeiculo veiculo, int cabecalho)
{

    if (cabecalho == 0)
    {
        printf("\nMatricula \tData Fabrico \tCarga \tQuantidade de encomendas transportadas\tViagens realizadas\tEstado          \n");
        printf("_______________________________________________________________________________________________________________\n");
    }

    printf("\n%s\t\t%4d-%2d-%2d\t%d\t\t\t\t%d\t\t\t%d\t\t%s", veiculo.matricula, veiculo.dataFabrico.ano, veiculo.dataFabrico.mes,veiculo.dataFabrico.dia,veiculo.carga,veiculo.quantidadeEncomendasTransportadas, veiculo.numViagensEfetuadas, veiculo.estado);


}

// Função que lista no ecra todos os veiculos registados
void listaVeiculos (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
    int i;

    if (quantVeiculos == 0)
    {
        printf("\n\nATENCAO: Nao existem veiculos inseridos.\n");
    }
    else
    {
        printf("\n\n------------------------- LISTAGEM DE VEICULOS -------------------------  \n");

        for (i=0; i < quantVeiculos; i++)
        {
            escreveDadosVeiculo(vetorVeiculos[i], i);
        }
    }
}


// Função que escreve no ecra os dados de um veiculo selecionado pelo utlizador através do campo designacao

void consultaVeiculoDesignacao (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
    int posicao;
    char matricula[MAX_MATRICULA];

    if (quantVeiculos == 0)
    {
        printf("\n\nATENCAO: Nao existem veiculos inseridos.\n");
    }
    else
    {
        listaVeiculos(vetorVeiculos, quantVeiculos);
        printf("\n\n----------- CONSULTA VEICULOS -----------  \n");
        lerString("\nMatricula do veiculos: ", matricula, MAX_MATRICULA);

        posicao = procuraVeiculo(vetorVeiculos, quantVeiculos, matricula);

        if (posicao == NAO_EXISTE)
        {
            printf("\n\nATENCAO: O veiculo com a matricula %s nao existe.\n", matricula);
        }
        else
        {
            escreveDadosVeiculo(vetorVeiculos[posicao], 0);
        }
    }
}
int comparaNumEncomendasVeiculos(const void *v1, const void *v2)
{
    tipoVeiculo *valor1, *valor2;
    int comp;

    valor1 = (tipoVeiculo *) v1;
    valor2 = (tipoVeiculo *) v2;

    comp = valor2->quantidadeEncomendasTransportadas -valor1->quantidadeEncomendasTransportadas;
    return comp;
}
void listaEncomendaVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
    int i;
    printf("\n\t\t ->->-> Lista encomendas nos Veiculos -<-<-<\n");
    qsort(vetorVeiculos, quantVeiculos, sizeof(tipoVeiculo), comparaNumEncomendasVeiculos); //ordena o vetor por ordem crescente

    for(i=0; i<quantVeiculos;i++){
        consultaVeiculoDesignacao(vetorVeiculos[i].matricula, quantVeiculos);
    }
}


///--------------------------------------Funcoes encomendas-------------------------------

void inserirEncomenda (tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int *quantEncomendas)
{
    int posicao;

    if (*quantEncomendas == MAX_ENCOMENDAS)
    {
        printf("\n\nATENCAO: Impossivel inserir uma nova Encomenda (MAXIMO atingido).\n");
    }
    else
    {
        do
        {
            printf("\n\n----------- INSERIR ENCOMENDA-----------  \n");
            vetorEncomendas[*quantEncomendas].numRegisto = lerInteiro("\nNumero de Registo: ", 0, 99);

            posicao = procuraEncomenda(vetorEncomendas, *quantEncomendas, vetorEncomendas[*quantEncomendas].numRegisto);

            if (posicao == NAO_EXISTE)
            {
                printf("\nData de Registo: ");
                vetorEncomendas[*quantEncomendas].dataRegisto = lerData();
                vetorEncomendas[*quantEncomendas].peso=lerInteiro("\n Insira o peso (0-1000): ", 0, 1000);
                lerString("Destino: ",vetorEncomendas[*quantEncomendas].destino, MAX_STRING);

                strcpy(vetorEncomendas[*quantEncomendas].estado, ESTADO_REGISTADA);
                printf("\n Estado %s", vetorEncomendas[*quantEncomendas].estado);

                (*quantEncomendas)++;
            }
            else
            {
                escreveDadosEncomenda(vetorEncomendas[posicao], 0);
                printf("\n\nATENCAO: A encomenda nr. %d ja existe.\n", vetorEncomendas[*quantEncomendas].numRegisto);
            }
        }
        while (posicao != NAO_EXISTE);
    }

}
//Eliminar encomenda

void eliminarEncomenda(tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int *quantEncomendas)
{
    int numero, posicao, i;
    if(*quantEncomendas == 0)
    {
        printf("\n Nao ha encomendas inseridas");
    }
    else
    {
        numero = lerInteiro("\n Numero da encomenda a eliminar: ",1,999);
        posicao = procuraEncomenda(vetorEncomendas, *quantEncomendas, numero);
        if(posicao == -1)
        {
            printf("\n Encomenda %d nao existe.", numero);
        }
        else
        {
            if (strcmp(vetorEncomendas[posicao].estado, ESTADO_ENTREGUE)==0)
            {
                printf("\n Encomenda %d ja foi entregue impossivel eliminar.", numero);
            }
            else
            {
                for(i=posicao; i<*quantEncomendas-1; i++)
                {
                    vetorEncomendas[i] = vetorEncomendas[i+1];
                }
                (*quantEncomendas)--;
            }
        }
    }
}
void editarEncomenda(tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int quantEncomendas)
{

    int pos, num;
    printf("\n\t\t ->->-> Editar Encomendas -<-<-<\n");
    if (quantEncomendas==0)
    {
        printf("\n\tNao existem encomendas.");
    }
    else
    {
        do
        {

            num = lerInteiro("Intruduza o numero de registo da encomenda ",1, MAX_ENCOMENDAS);
            pos = procuraEncomenda(vetorEncomendas, quantEncomendas, num);
            if (pos==-1)
            {
                printf("\tO numero de registo da encomenda inserido nao existe.");
            }
        }
        while (pos==-1);
        if (strcmp(vetorEncomendas[pos].estado, ESTADO_ENTREGUE)==0 && pos!=-1)
        {
            printf("\n\tA encomenda ja foi entregue e por essa razao nao o destino nao pode ser alterado.");
        }
        else
        {
            escreveDadosEncomenda(vetorEncomendas[pos], 0);
            printf("\n\n\tAlteracoes:\n");
            lerString("Novo Destino: ",vetorEncomendas[pos].destino, MAX_STRING);


        }
    }
}




void alterarEstadoEncomenda(tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS],tipoVeiculo vetorVeiculos[MAX_VEICULOS],  int quantEncomendas, int quantVeiculos )
{
    int numRegisto,posicao;
    char matricula [MAX_MATRICULA];
    int posicaoVeiculo;
    int numeroAuxiliar;
    printf("\n Alterar o estado\n");
    numRegisto=lerInteiro("Insira o numero de registo de uma encomenda ", 0, MAX_ENCOMENDAS);
    posicao=procuraEncomenda(vetorEncomendas, quantEncomendas, numRegisto);
    if (posicao==NAO_EXISTE)
    {
        printf("\n ERRO NUMERO DE REGISTO NAO EXISTE");

    }
    else
    {
        do
        {
            printf("\n1 - Registada");
            printf("\n2 - Carregada");
            printf("\n3 - Entrege");
            printf("\n4 - Devolvida");
            printf("\n Estado: ");
            scanf("%d", &numeroAuxiliar);
            switch(numeroAuxiliar)
            {
            case 1:
                strcpy(vetorEncomendas[posicao].estado, ESTADO_REGISTADA);
                if(strcmp(vetorEncomendas[posicao].estado, ESTADO_REGISTADA))
                {
                    printf("\nEncomenda ja se encontra registada!");
                }
                break;
            case 2:

                lerString("\nMatricula do veiculos: ", matricula, MAX_MATRICULA);

                posicaoVeiculo = procuraVeiculo(vetorVeiculos, quantVeiculos, matricula);

                if (posicaoVeiculo == NAO_EXISTE)  // veiculo não existe no vetor
                {
                    printf("\n\nATENCAO: O veiculo com a matricula %s nao existe.\n", matricula);
                }
                else
                {
                    if(strcmp(vetorVeiculos[posicaoVeiculo].estado, ESTADO_EM_CARGA)!=0)
                    {
                        printf("\n VEICULO NAO DISPONIVEL!");
                    }
                    else
                    {
                        strcpy(vetorEncomendas[posicao].veiculo,matricula);
                        strcpy(vetorEncomendas[posicao].estado, ESTADO_CARREGADA);
                        vetorVeiculos[posicaoVeiculo].carga+=vetorEncomendas[posicao].peso;
                        vetorVeiculos[posicaoVeiculo].quantidadeEncomendasTransportadas++;
                    }
                }
                break;
            case 3:
                strcpy(vetorEncomendas[posicao].estado, ESTADO_ENTREGUE);
                if(strcmp(vetorEncomendas[posicao].estado, ESTADO_ENTREGUE))
                {
                    printf("\nEncomenda ja se encontra entregue");
                }
                break;
            case 4:
                strcpy(vetorEncomendas[posicao].estado, ESTADO_DEVOLVIDA);
                escreveLog(vetorEncomendas[posicao]);

                if(strcmp(vetorEncomendas[posicao].estado, ESTADO_DEVOLVIDA))
                {
                    printf("\nEncomenda ja se encontra devolvida");
                }
                break;

            }
        }
        while (numeroAuxiliar!=1 && numeroAuxiliar!=2 && numeroAuxiliar!=3 && numeroAuxiliar!=4 );



    }




}
//Procurar se a encomenda já existe

int procuraEncomenda (tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int quantEncomendas, int numRegisto)
{
    int posicao, i;

    posicao=NAO_EXISTE;

    for (i=0; i < quantEncomendas; i++)
    {
        if (vetorEncomendas[i].numRegisto == numRegisto)
        {
            posicao = i;
            i = quantEncomendas;
        }
    }

    return posicao;
}

//Consultar encomendas pelo numero de registo

void consultaEncomendaNrRegisto (tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int quantEncomendas)
{
    int posicao, numRegisto;

    if (quantEncomendas == 0)
    {
        printf("\n\nATENCAO: Nao existem encomendas inseridas.\n");
    }
    else
    {
        printf("\n\n----------- CONSULTAR ENCOMENDAS -----------  \n");
        numRegisto = lerInteiro("\nNr. de registo: ", 0, MAX_ENCOMENDAS);

        posicao = procuraEncomenda(vetorEncomendas, quantEncomendas, numRegisto);

        if (posicao == NAO_EXISTE)
        {
            printf("\n\nATENCAO: A encomenda com o nr %d nao existe.\n", numRegisto);
        }
        else
        {
            escreveDadosEncomenda(vetorEncomendas[posicao], 0);
        }
    }
}

//Escreve dados da encomenda

void escreveDadosEncomenda (tipoEncomenda encomenda, int cabecalho)
{
    if (cabecalho == 0)
    {
        printf("\nData Registo\t\tPeso\tNr. de Registo\t\tDestino\t\tEstado\t\tVeiculo\n");
        printf("___________________________________________________________________________________________________________\n");
    }

    escreveData(encomenda.dataRegisto);
    printf("\t\t%d\t%d\t     %18s \t%s \t%s", encomenda.peso, encomenda.numRegisto, encomenda.destino, encomenda.estado, encomenda.veiculo);

}

//Listar encomenda

void listaEncomenda (tipoEncomenda vetorEncomendas[MAX_ENCOMENDAS], int quantEncomendas)
{
    int i;

    if (quantEncomendas == 0)
    {
        printf("\n\nATENCAO: Nao existem encomendas inseridas.\n");
    }
    else
    {
        printf("\n\n----------------------------------------- LISTAGEM DE ENCOMENDAS ----------------------------------------- \n");

        for (i=0; i < quantEncomendas; i++)
        {
            escreveDadosEncomenda(vetorEncomendas[i], i);
        }
    }
}

void ordenarVeiculosOrdemCrescente( tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos){
    int i, j;
    tipoVeiculo aux[MAX_VEICULOS];
    for(i=0; i<quantVeiculos; i++){
        for(j=j+1; j< quantVeiculos; j++){
            if(vetorVeiculos[j].quantidadeEncomendasTransportadas > vetorVeiculos[i].quantidadeEncomendasTransportadas){
                aux[i]=vetorVeiculos[j];
                vetorVeiculos[j]=vetorVeiculos[i];
                vetorVeiculos[i]=aux[i];
            }
        }
    }
    listaVeiculos(vetorVeiculos, quantVeiculos);
}

///-----------------------------------------------------Funcoes auxiliares--------------------------------------

void escreveData (tipoData data)
{
    printf("%02d-%02d-%4d", data.dia, data.mes, data.ano);
}

tipoData lerData(void)
{
    tipoData data;
    int maxDiasMes;

    printf("\tData \n");
    do
    {
        printf("\t\tAno: ");
        scanf("%d", &data.ano);
        if (data.ano<2017 || data.ano>2018)
        {
            printf("\t\t\tNumero Invalido, o numero tem que estar entre 2017 e 2018.\n");
        }
    }
    while(data.ano>2018 || data.ano<2017);
    do
    {
        printf("\t\tMes: ");
        scanf("%d", &data.mes);
        if (data.mes<1 || data.mes>12)
        {
            printf("\t\t\tNumero Invalido, o numero tem que estar entre 1 e 12.\n");
        }
    }
    while(data.mes>12 || data.mes<1);

    switch (data.mes)
    {
    case 2:
        if ((data.ano % 400 == 0) || (data.ano % 4 == 0 && data.ano % 100 != 0))
        {
            maxDiasMes = 29;
        }
        else
        {
            maxDiasMes = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDiasMes = 30;
        break;
    default:
        maxDiasMes = 31;
    }

    do
    {
        printf("\t\tDia: ");
        scanf("%d", &data.dia);
        if (data.dia<1 || data.dia>maxDiasMes)
        {
            printf("\t\t\tNumero Invalido, o numero tem que estar entre 1 e %d\n", maxDiasMes);
        }
    }
    while(data.dia>maxDiasMes || data.dia<1);

    return data;
}

void escreveLog(tipoEncomenda encomenda)
{


	FILE *logTexto;
	logTexto=fopen("logTexto.txt", "a+");
	if (logTexto==NULL)
	{
		printf ("Impossível abrir ficheiro");
	}
	else
	{
		fprintf(logTexto,"Numero de registo: %d\n", encomenda.numRegisto);
		fprintf(logTexto,"Estado: %s\n", encomenda.estado);
		fprintf(logTexto,"Destino: %s\n", encomenda.destino);
		 encomenda.dataDevolucao=lerData();
		fprintf(logTexto,"Data registo encomenda: %d/%d/%d\n-------------------------------------------\n\n\n", encomenda.dataDevolucao.dia, encomenda.dataDevolucao.mes, encomenda.dataDevolucao.ano);
       lerString("\nRazao para a devolucao: ", encomenda.observacoes, TEXTO_LONGO);
        fprintf(logTexto,"Porque de ser devolvida?: %s\n",encomenda.observacoes );
	}
	fclose(logTexto);
}
