#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//Declara��o das Estruturas a serem utilizadas

typedef struct CPStruct
{
char nome[40];
char reg[12];
char rg[10];
char telefone[11];
} Pessoa;

typedef struct PedidoStruct
{
char cor[10];
char mod[10];
char tam[10];
char rua[40];
char numero[10];
char cep[10];
char bairro[15];
char cidade[15];
char estado[15];
} Pessoa1;


//Declara��o das vari�veis
int op = 0;
int edit_x;
int senha;
int senhaC = 777;
int qtdClientes;
int qtdPedidos;
int qtdEndereco;
int tamClientes;
int tamPedidos;
Pessoa *clientes;
Pessoa1 *pedido;
FILE *arquivoPEDIDOS;
char clientes_dir[] = "Clientes.bin";

//Declara��o dos Procedimentos e Fun��es a serem utilizados
void menuPrincipal();

void BuscarPedido();
void login();
void menuClientes();
void menuAlterarCliente();
Pessoa receberCliente();
void inserirCliente();
void listarClientes();

Pessoa1 receberPedido();
void inserirPedido();
void listarPedidos();
void enderecoEntrega();
void alterarEndereco();
void edit();
void editEndereco();

void cadrastro();
void editDadosCargo();
void editCadrastral();
void inserirFuncionario();

void removerQuebraLinha();

//In�cio do main
int main(int argc, char** argv)
{
    menuPrincipal();
    return 0;
}

void erro(char *nome_arquivo)
{
    printf("\t\t\t\tNao foi possivel abrir o arquivo %s\n", nome_arquivo);
}

void sucesso()
{
    system("cls");
    printf ("\t\t\t\tOperacao realizada com sucesso!");
}

void menuPrincipal()
{
    do
    {
        system("cls");
        printf("\n");
        printf ("\t\t\t\t  DREAM MACHINE\n\n");
        printf("\t\t\t\t 1 - CADRASTRO          \n");
        printf("\t\t\t\t 2 - LOGIN         \n");
        printf("\t\t\t\t 0 - Sair             \n");
        printf ("\t\t\t\t                      \n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &op);
        system("cls");
        switch(op)
        {
        case 1:
            cadrastro();
            break;
        case 2:
            login();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(op != 0);
    system("cls");
}

void cadrastro()
{
}

void login()
{
    printf("\n\t\t\t\tDigite sua senha: ");
    scanf("%d", &senha);

    while(senha != senhaC){
        printf("\n\t\t\t\tSenha invalida!\n\n\t\t\t\tDigite a senha correta: ");
        scanf("%d", &senha);
    }

    printf("\n\t\t\t\tAcesso permitido!\n");
    return menuClientes();

}


void menuClientes()
{
    do
    {
        printf("\n");
        printf ("\t\t\t\t  DREAM MACHINE\n\n");
        printf ("\t\t\t\t                      \n");
        printf("\t\t\t    1 - Verificar Pedidos              \n");
        printf("\t\t\t    2 - Novo Pedido       \n");
        printf("\t\t\t    3 - Alterar Endereco    \n");
        printf("\t\t\t    4 - Alterar Pedido     \n");
        printf("\t\t\t    5 - buscar               \n");
        printf("\t\t\t    0 - Menu Principal                 \n");
        printf ("\t\t\t                             \n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione a opcao desejada: ");
        fflush(stdin);
        scanf("%d", &op);
        system("cls");
        switch(op)
        {
        case 1:
            listarPedidos();
            break;
        case 2:
            fflush(stdin);
            inserirPedido(receberPedido());
            break;
        case 3:
            editEndereco(pedido, edit_x);
            break;
        case 4:
            editUrso(pedido, edit_x);
            break;
        case 5:
            buscar();
            break;
        case 0:
            menuPrincipal();
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(op != 0);
    system("cls");
}


void buscar()
{
/*
    int texto,palavra;

    int i, tamP, tamT, j;
    tamP = strlen(palavra)-1;
    tamT = strlen(texto)-1;
    for(i=0;i<=tamT-tamP;i++){
        j=0;
        while(j<tamP){
            if(palavra[j] != texto [i+j]) break;
            j++;
        }
        if(j == tamP) printf("SSSS");
        }
*/

}

void listarPedidos()
{
        arquivoPEDIDOS = fopen("arquivoPEDIDOS.txt", "r");

    if (arquivoPEDIDOS == NULL)
    {
        printf("Erro na abertura do Arquivo");
        exit(EXIT_SUCCESS);
    }
    else
    {

    int c;
    printf("\n%d pedido cadastrados\n", qtdPedidos);
    for(c=0; c < qtdPedidos; c++)
    {
        printf("-----------------------------------\n");
        printf("(%d)\n", c+1);
        printf("Status Andamento\n");
        printf("COR  = %s\n", "arquivoPEDIDOS.txt", "r");
        printf("MOD = %s\n", "arquivoPEDIDOS.txt", "r");
        printf("TAM = %s\n", "arquivoPEDIDOS.txt", "r");
        printf("Endereco cadrastrado\n");
        printf("RUA  = %s\n", pedido[c].rua);
        printf("NUM = %s\n", pedido[c].numero);
        printf("CEP = %s\n", pedido[c].cep);

    }
        fclose(arquivoPEDIDOS);
    }
}

void removerQuebraLinha(char *string)
{
    if(string != NULL && strlen(string) > 0)
    {
        short tamanho = strlen(string);
        if(string[tamanho-1] == '\n')
        {
            string[tamanho-1] = '\0';
        }
    }
}

void receberString(char *string_destino, int quantidade_caracteres)
{
    fgets(string_destino, quantidade_caracteres, stdin);
    removerQuebraLinha(string_destino);
}

Pessoa1 receberPedido()
{
    arquivoPEDIDOS = fopen("arquivoPEDIDOS.txt", "a");

    if (arquivoPEDIDOS == NULL)
    {
        printf("Erro na abertura do Arquivo");
        exit(EXIT_SUCCESS);
    }
    else
    {
    Pessoa1 p;

    printf(" Novo Pedido  \n");
    printf(" Esolha o Modelo: \n ");
    printf(" 1 - Urso\n");
    printf(" 2 - Gato\n");
    printf(" 3 - Cachorro\n");
    printf(" 4 - Coelho\n");
    printf(" 5 - Sapo\n");
    printf(" 6 - Lhama\n");
    fflush(stdin);
    receberString(p.mod,10);
    system("cls");


    printf(" Escolha uma Cor:  \n ");
    printf(" 1 - Rosa\n");
    printf(" 2 - Azul\n");
    printf(" 3 - Branco\n");
    printf(" 4 - Preto\n");
    printf(" 5 - Marrom\n");
    printf(" 6 - Amarelo\n");
    printf(" 7 - Lilás\n");
    printf(" 8 - Verde\n");
    fflush(stdin);
    receberString(p.cor, 13);
    system("cls");


    printf("Esolha o Tamanho:  \n");
    printf(" 1 - Pequeno\n");
    printf(" 2 - Médio\n");
    printf(" 3 - Grande\n");
    printf(" 4 - Extra Grande\n");
    receberString(p.tam, 11);
    fflush(stdin);
    system("cls");


    printf("\nInforme o endereco de entrega:\n\n");
    printf ("CEP: ");
    receberString(p.cep, 9);
    fflush(stdin);
    printf ("Rua: ");
    receberString(p.rua, 39);
    fflush(stdin);
    printf ("Numero: ");
    receberString(p.numero, 5);
    fflush(stdin);
    printf ("Bairro: ");
    receberString(p.bairro, 15);
    fflush(stdin);
    printf ("Cidade: ");
    receberString(p.cidade, 15);
    fflush(stdin);
    printf ("Estado: ");
    receberString(p.estado, 10);
    fflush(stdin);

    fprintf(arquivoPEDIDOS,"==============================\n", pedido);
    fprintf(arquivoPEDIDOS,"COR: ", pedido);
    fprintf(arquivoPEDIDOS, p.cor, pedido);
    fprintf(arquivoPEDIDOS,"\n", pedido);

    fprintf(arquivoPEDIDOS,"MODELO: ", pedido);
    fprintf(arquivoPEDIDOS, p.mod, pedido);
    fprintf(arquivoPEDIDOS,"\n", pedido);

    fprintf(arquivoPEDIDOS,"TAMANHO: ", pedido);
    fprintf(arquivoPEDIDOS, p.tam, pedido);
    fprintf(arquivoPEDIDOS,"\n", pedido);
    fprintf(arquivoPEDIDOS,"Informe o endereco de entrega:\n", pedido);

    fprintf(arquivoPEDIDOS,"CEP: ", pedido);
    fprintf(arquivoPEDIDOS, p.cep, pedido);
    fprintf(arquivoPEDIDOS,"\n", pedido);

    fprintf(arquivoPEDIDOS,"RUA: ", pedido);
    fprintf(arquivoPEDIDOS, p.rua, pedido);
    fprintf(arquivoPEDIDOS,"\n", pedido);

    fprintf(arquivoPEDIDOS,"NUMERO: ", pedido);
    fprintf(arquivoPEDIDOS, p.numero, pedido);
    fprintf(arquivoPEDIDOS,"\n", pedido);

    fprintf(arquivoPEDIDOS,"BAIRRO: ", pedido);
    fprintf(arquivoPEDIDOS, p.bairro, pedido);
    fprintf(arquivoPEDIDOS,"\n", pedido);

    fprintf(arquivoPEDIDOS,"CIDADE: ", pedido);
    fprintf(arquivoPEDIDOS, p.cidade, pedido);
    fprintf(arquivoPEDIDOS,"\n", pedido);

    fprintf(arquivoPEDIDOS,"ESTADO: ", pedido);
    fprintf(arquivoPEDIDOS, p.estado, pedido);
    fprintf(arquivoPEDIDOS,"\n", pedido);
    fprintf(arquivoPEDIDOS,"===============================", pedido);
    system("cls");


    fclose(arquivoPEDIDOS);

    sucesso();
    return p;
    }
}

void inserirPedido(Pessoa1 p)
{
    if(qtdPedidos == tamPedidos)
    {
        tamPedidos *= 1.5;
        pedido = realloc(pedido, tamPedidos*sizeof(Pessoa1));
    }
    pedido[qtdPedidos] = p;
    qtdPedidos++;
}


void editUrso(struct PedidoStruct *pedido, int x)
{
    printf("Adicione os novos dados\n");
    printf("Nova cor: ");
    fflush(stdin);
    fgets(pedido[x].cor, 20, stdin);

    printf("Novo modelo: ");
    fflush(stdin);
    fgets(pedido[x].mod, 20, stdin);

    printf("Novo tamanho: ");
    fflush(stdin);
    fgets(pedido[x].tam, 20, stdin);

     sucesso();
}

void editEndereco(struct PedidoStruct *pedido, int x) {
    printf("Adicione os novos dados\n");
    printf("Novo cep: ");
    fflush(stdin);
    fgets(pedido[x].cep, 20, stdin);

    printf("Nova rua: ");
    fflush(stdin);
    fgets(pedido[x].rua, 30, stdin);

    printf("Novo numero: ");
    fflush(stdin);
    fgets(pedido[x].numero, 10, stdin);

    printf("Novo bairro: ");
    fflush(stdin);
    fgets(pedido[x].bairro, 15, stdin);

    printf("Nova Cidade: ");
    fflush(stdin);
    fgets(pedido[x].cidade, 15, stdin);

    printf("Novo estado: ");
    fflush(stdin);
    fgets(pedido[x].estado, 15, stdin);

     sucesso();
}
