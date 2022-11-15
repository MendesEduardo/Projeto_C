#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <locale.h>

//Declarando das Estruturas a serem utilizadas

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


//Declarando das variaveis
int op = 0;
int edit_x;
int senha;
int email;
int senhaCerta;
int emailCerto;
int qtdPedidos;
int tamPedidos;
Pessoa1 *pedido;
FILE *arquivoPEDIDOS;

//Declarando as Funçoes a serem utilizadas
void menuPrincipal();

void login();
void DadosDoUsuario();
void menuClientes();

Pessoa1 receberPedido();
void inserirPedido();
void listarPedidos();
void editEndereco();

void cadrastro();
void removerQuebraLinha();

//Inicio do main
int main(int argc, char** argv)
{
    setlocale(LC_ALL,"Portuguese");
    menuPrincipal();
    return 0;
}

// Informa quando uma operação é mal secedida

void erro(char *nome_arquivo)
{
    printf("\t\t\t\tNao foi possivel abrir o arquivo %s\n", nome_arquivo);
}

// Informa quando uma operação é bem secedida

void sucesso()
{
    system("cls");
    printf ("\t\t\t\tOperacao realizada com sucesso!");
}

// Aqui é o menu inicial

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

// Essa função é usada para o usuario fazer o cadrastro no sistema

void cadrastro()
{
    printf("\n\t\t\t\tDigite seu e-mail: ");
    scanf("%d", &emailCerto);
    printf("\n\t\t\t\tDigite sua senha: ");
    scanf("%d", &senhaCerta);

    sucesso();
    return menuClientes();
}

// Essa função é usada para o usuario fazer o login no sistema

void login()
{
    printf("\n\t\t\t\tDigite seu e-mail: ");
    scanf("%d", &email);
    printf("\n\t\t\t\tDigite sua senha: ");
    scanf("%d", &senha);

    while(senha != senhaCerta || email != emailCerto){
        system("cls");

        printf("\n\t\t\t\tSenha ou e-mail invalidos!\n\n\t\t\t\tDigite os dados corretamente\n ");

        printf("\n\t\t\t\tDigite seu e-mail: ");
        scanf("%d", &email);
        printf("\n\t\t\t\tDigite sua senha: ");
        scanf("%d", &senha);
    }
    system("cls");
    printf("\n\t\t\t\tAcesso permitido!\n");

    return menuClientes();

}

// Esse é o menu apos usuario fazer o login

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

// Aqui lista todos os pedidos já feitos

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
        printf("COR  = %s\n", pedido[c].cor);
        printf("MOD = %s\n", pedido[c].mod);
        printf("TAM = %s\n", pedido[c].tam);
        printf("Endereco cadrastrado\n");
        printf("RUA  = %s\n", pedido[c].rua);
        printf("NUM = %s\n", pedido[c].numero);
        printf("CEP = %s\n", pedido[c].cep);

    }
        fclose(arquivoPEDIDOS);
    }
}

// Remover a quebra de linha no fim de uma string

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

// receber Strings em C

void receberString(char *string_destino, int quantidade_caracteres)
{
    fgets(string_destino, quantidade_caracteres, stdin);
    removerQuebraLinha(string_destino);
}

// Opçoes de escolha dos pedidos

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

// Adicionanr os pedidos

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

// Edita os dados do pedidos

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

// Adicionanr o endereço dos pedidos

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
