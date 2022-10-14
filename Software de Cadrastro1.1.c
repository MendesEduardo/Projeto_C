#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//Declaração das Estruturas a serem utilizadas

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

typedef struct AFuncionarios
{
char cargo[30];
char apelido[40];
char idade[3];
char NMatricola[10];
char horario[20];
char CPFisica[12];
char salario[15];
} Aventureiros;


//Declaração das variáveis
int op = 0;
int edit_x;
int senha;
int senhaC = 777;
int senhaF = 888;
int qtdClientes;
int qtdPedidos;
int qtdEndereco;
int tamClientes;
int tamPedidos;
int qtdFuncionarios;
int tamFuncionarios;
Aventureiros *FunAnve;
Pessoa *clientes;
Pessoa1 *pedido;
FILE *arquivoFUNCIONARIO;
FILE *arquivoPEDIDOS;
char clientes_dir[] = "Clientes.bin";

//Declaração dos Procedimentos e Funções a serem utilizados
void menuPrincipal();

void LSCliente();
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

void LSFuncionario();
void menuFuncionarios();
void editDadosCargo();
void editCadrastral();
Aventureiros receberFuncionarios();
void inserirFuncionario();

void removerQuebraLinha();

//Início do main
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
        printf("\n");
        printf ("\t\t\t\t  DREAM MACHINE\n\n");
        printf("\t\t\t\t 1 - Area Cliente          \n");
        printf("\t\t\t\t 2 - Area Funcionario         \n");
        printf("\t\t\t\t 0 - Sair             \n");
        printf ("\t\t\t\t                      \n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &op);
        system("cls");
        switch(op)
        {
        case 1:
            LSCliente();
            break;
        case 2:
            LSFuncionario();
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

void LSCliente()
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

void LSFuncionario()
{
    printf("\n\t\t\t\tDigite sua senha: ");
    scanf("%d", &senha);

    while(senha != senhaF){
        printf("\n\t\t\t\tSenha invalida!\n\n\t\t\t\tDigite a senha correta: ");
        scanf("%d", &senha);
    }

    printf("\n\t\t\t\tAcesso permitido!\n");
    return menuFuncionarios();

}

void menuFuncionarios()
{
    do
    {
        printf("\n");
        printf ("\t\t\t\t  DREAM MACHINE\n\n");
        printf ("\t\t\t\t                      \n");
        printf("\t\t\t    1 - Consultar todos os funcionarios              \n");
        printf("\t\t\t    2 - Novo Funcionario       \n");
        printf("\t\t\t    3 - Alterar Dados Cadrastrais    \n");
        printf("\t\t\t    4 - Alterar Dados Do Cargo     \n");
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
            listarFuncionarios();
            break;
        case 2:
            fflush(stdin);
            inserirFuncionarios(receberFuncionarios());
            break;
        case 3:
            editCadrastral(FunAnve, edit_x);
            break;
        case 4:
            editDadosCargo(FunAnve, edit_x);
            break;
        case 0:
            menuPrincipal;
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(op != 0);
    system("cls");
}
void editDadosCargo (struct AFuncionarios *FunAnve, int x)
{
    printf("Adicione os novos dados\n");
    printf("Novo Cargo: ");
    fflush(stdin);
    fgets(FunAnve[x].cargo, 40, stdin);

    printf("Novo Horario: ");
    fflush(stdin);
    fgets(FunAnve[x].horario, 15, stdin);

    printf("Novo Salario: ");
    fflush(stdin);
    fgets(FunAnve[x].salario, 15, stdin);

    printf("Nova Matricula: ");
    fflush(stdin);
    fgets(FunAnve[x].NMatricola, 15, stdin);

     sucesso();
    }

void editCadrastral (struct AFuncionarios *FunAnve, int x)
{
    printf("Adicione os novos dados\n");
    printf("Nome: ");
    fflush(stdin);
    fgets(FunAnve[x].apelido, 50, stdin);

    printf("Nova Idade: ");
    fflush(stdin);
    fgets(FunAnve[x].idade, 60, stdin);

    printf("Novo CPF: ");
    fflush(stdin);
    fgets(FunAnve[x].CPFisica, 80, stdin);

     sucesso();
}

void listarFuncionarios()
{
    int c;
    printf("\n%d pedido cadastrados\n", qtdFuncionarios);
    for(c=0; c < qtdFuncionarios; c++)
    {
        printf("-----------------------------------\n");
        printf("(%d)\n", c+1);
        printf("Status Andamento\n");
        printf("Cargo = %s\n", FunAnve[c].cargo);
        printf("Nome = %s\n", FunAnve[c].apelido);
        printf("Salario = %s\n", FunAnve[c].salario);
        printf("Numero de matricula  = %s\n", FunAnve[c].NMatricola);
        printf("CPF = %s\n", FunAnve[c].CPFisica);
    }
}

Aventureiros receberFuncionarios()
{
        arquivoFUNCIONARIO = fopen("arquivoFUNCIONARIO.txt", "a");

    if (arquivoFUNCIONARIO == NULL)
    {
        printf("Erro na abertura do Arquivo");
        exit(EXIT_SUCCESS);
    }
    else
    {
    Aventureiros p;

    printf("Cargo: ");
    receberString(p.cargo, 30);
    printf ("Nome: ");
    receberString(p.apelido, 40);
    fflush(stdin);
    printf ("Salario: ");
    receberString(p.salario, 15);
    fflush(stdin);
    printf ("Idade: ");
    receberString(p.idade, 3);
    fflush(stdin);
    printf ("Numero de matricula: ");
    receberString(p.NMatricola, 10);
    fflush(stdin);
    printf ("Horario de Trabalho: ");
    receberString(p.horario, 20);
    fflush(stdin);
    printf ("CPF: ");
    receberString(p.CPFisica, 12);
    fflush(stdin);

    fprintf(arquivoFUNCIONARIO,"============================\n", FunAnve);
    fprintf(arquivoFUNCIONARIO,"CARGO: ", FunAnve);
    fprintf(arquivoFUNCIONARIO, p.cargo, FunAnve);
    fprintf(arquivoFUNCIONARIO,"\n", FunAnve);

    fprintf(arquivoFUNCIONARIO,"NOME: ", FunAnve);
    fprintf(arquivoFUNCIONARIO, p.apelido, FunAnve);
    fprintf(arquivoFUNCIONARIO,"\n", FunAnve);

    fprintf(arquivoFUNCIONARIO,"SALARIO: ", FunAnve);
    fprintf(arquivoFUNCIONARIO, p.salario, FunAnve);
    fprintf(arquivoFUNCIONARIO,"\n", FunAnve);

    fprintf(arquivoFUNCIONARIO,"IDADE: ", FunAnve);
    fprintf(arquivoFUNCIONARIO, p.idade, FunAnve);
    fprintf(arquivoFUNCIONARIO,"\n", FunAnve);

    fprintf(arquivoFUNCIONARIO,"NUMERO DA MATRICOLA: ", FunAnve);
    fprintf(arquivoFUNCIONARIO, p.NMatricola, FunAnve);
    fprintf(arquivoFUNCIONARIO,"\n", FunAnve);

    fprintf(arquivoFUNCIONARIO,"HORARIO DE TRABALHO: ", FunAnve);
    fprintf(arquivoFUNCIONARIO, p.horario, FunAnve);
    fprintf(arquivoFUNCIONARIO,"\n", FunAnve);

    fprintf(arquivoFUNCIONARIO,"CPF: ", FunAnve);
    fprintf(arquivoFUNCIONARIO, p.CPFisica, FunAnve);
    fprintf(arquivoFUNCIONARIO,"\n", FunAnve);
    fprintf(arquivoFUNCIONARIO,"=============================", FunAnve);

    fclose(arquivoFUNCIONARIO);

    sucesso();
    return p;
    }
}

void inserirFuncionarios(Aventureiros p)
{
    if(qtdFuncionarios == tamFuncionarios)
    {
        tamFuncionarios *= 1.5;
        FunAnve = realloc(FunAnve, tamFuncionarios*sizeof(Aventureiros));
    }
    FunAnve[qtdFuncionarios] = p;
    qtdFuncionarios++;
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


void listarPedidos()
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

    printf("Cor desejada: ");
    receberString(p.cor, 39);
    printf ("Modelo desejado: ");
    receberString(p.mod, 13);
    fflush(stdin);
    printf ("Tamanho : ");
    receberString(p.tam, 11);
    fflush(stdin);
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

