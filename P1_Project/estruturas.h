#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED
#define TEXTO_BREVE 20
#define TEXTO_LONGO 200
#define MAX_MATRICULA 7
#define MAX_CARGA 1000
#define MAX_STRING 50
#define ESTADO_DISPONIVEL "Disponivel"
#define ESTADO_EM_CARGA "Em carga"
#define ESTADO_TRANSPORTAR "A transportar"
#define ESTADO_DE_REGRESSO "De regresso"
#define ESTADO_AVARIADO "Avariado"
#define MAX_VEICULOS 9
#define NAO_EXISTE -1
#define ESTADO_REGISTADA "Registada"
#define ESTADO_CARREGADA "Carregada"
#define ESTADO_ENTREGUE "Entregue"
#define ESTADO_DEVOLVIDA "Devolvida"
#define MAX_ENCOMENDAS 99

typedef struct
{
    int dia;
    int mes;
    int ano;
} tipoData;

typedef struct
{
    int numRegisto;
    tipoData dataRegisto;
    int peso;
    char destino [TEXTO_BREVE];
    char estado [TEXTO_BREVE];   //pode ser registada, carregada, entregue, devolvida
    tipoData dataEntrega;
    tipoData dataDevolucao;
    char veiculo[MAX_MATRICULA];
    char observacoes[TEXTO_LONGO];
} tipoEncomenda;

typedef struct
{
    char matricula[MAX_MATRICULA];
    tipoData dataFabrico;
    char estado[TEXTO_BREVE];
    int carga ;
    int numViagensEfetuadas;
    int quantidadeEncomendasTransportadas;
    int numRegisto[MAX_ENCOMENDAS];
    //int encomendasNoVeiculo[MAX_ENCOMENDAS];
     //int quantEquipamentosInstalados;
} tipoVeiculo ;


#endif // ESTRUTURAS_H_INCLUDED
