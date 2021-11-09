#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_CLIENTES 100
#define MAX_CONTAS 100
#define MAX_CONTASsec 100
#define MAX_transacoes 1000

//=====================================================================     Struct para os clientes     =====================================================================//
typedef struct{
    char nome[50];
    char endereco[100];
    int COD;
    long long int TEL;
    long long int DOC;
    int ativo;
} Cliente;
Cliente clientes [MAX_CLIENTES];

//=====================================================================     Struct para as contas     =====================================================================//
typedef struct{
    int agencia;
    int numConta;
    
    double saldo;
    int ativoConta;
} Conta;
Conta conta [MAX_CONTAS];

typedef struct{
    int agenciaSec;
    int numContaSec;
    double saldoSec;
    int ativoContaSec;
} ContaSec;
ContaSec contasec [MAX_CONTAS];

//=====================================================================     Struct para as transações     =====================================================================//
typedef struct{
    char type[15];
    char description[100];
    double valor;
    int data;
    int COD;
    int conta;
    int ativoTransacoes;
    time_t tempo;
} Transacoes;
Transacoes transacoes [MAX_transacoes];

//=====================================================================     Prototipagem de funções      =====================================================================//

void menu(void);
void menuc(void);
void menut(void);
void cadastroCliente(void);
void ordenarClientes(void);
void listarClientes(void);
void buscarClientes(void);
void atualizarClientes(void);
void excluirClientes(void);
void cadastroConta(void);
void cadastroContaSec(void);
void ordenarContas(void);
void listarContas(void);
void buscarContas(void);
void saques(void);
void depositos(void);
void transferencia(void);
void extrato(void);

//=====================================================================     Variáveis globais      =====================================================================//

int quantClientes = 2;
int quantContas = 2;
int quantContasSec = 0;
int quantTransacoes = 0;

//Main iniciate ===========================================================================================================================================================
int main(int argc, char const *argv[]){
        //Clientes pre-cadastrado
        strcpy(clientes[0].nome, "Ariel");
        strcpy(clientes[0].endereco, "Rua 3, n 572, Setor Oeste");
        clientes[0].DOC = 75620561100;
        clientes[0].TEL = 62982637228;
        clientes[0].COD = 1;
        clientes[0].ativo = 1;

        strcpy(clientes[1].nome, "Ana Victoria");
        strcpy(clientes[1].endereco, "Rua 7, n 16, Setor Aeroporto");
        clientes[1].DOC = 70019210175;
        clientes[1].TEL = 62982916874;
        clientes[1].COD = 2;
        clientes[1].ativo = 1;

        //Contas pre-cadastradas
        //Ariel
        conta[0].agencia = 1;
        conta[0].numConta = 1;
        conta[0].saldo = 1000;
        conta[0].ativoConta = 1;

        //Ana Victoria
        conta[1].agencia = 2;
        conta[1].numConta = 2;
        conta[1].saldo = 200;
        conta[1].ativoConta = 1;

        menu();                 //Chama menu principal
    return 0;
}
//Funções ==============================================================================================================================================================
void menu(void){
    system("cls");

    char op;  
        printf("======== Bem vindo! ========\n");
        printf("Digite um comando para prosseguir:\n");        //Menu inicial
        printf("C - Gerenciar Clientes\n");
        printf("T - Gerenciar Contas\n");
        printf("S - Sair\n \n");
        scanf("%c", &op);
        if (op == 'C' || op == 'c')
        {
            menuc();
        }
        if (op == 'T' || op == 't')
        {
            menut();
        }
       /* if (op == 'S')
        {
            return 0;
        } */
        
        
}

//Menu atalho C======================================================================================================================================================
void menuc(void){
    system("cls");      
    char op1;
    printf("========= Gerenciar Clientes ==========\n");
    printf("Digite um comando para prosseguir:\n");
    printf("C - Cadastrar clientes\n");
    printf("L - Listar todos os clientes\n");                                   
    printf("B - Buscar cliente ja cadastrado\n");
    printf("A - Atualizar cliente ja cadastrado\n");
    printf("E - Excluir cliente ja cadastrado\n");
    printf("S - Sair\n");
    fflush(stdin);
    scanf("%c", &op1);
    //Caso usuário digite C
    if (op1 == 'C' || op1 == 'c')
    {
        cadastroCliente();      //Chama funcao cadastro de clientes
    }

    //Caso usário digite L
    if (op1 == 'L' || op1 == 'l')
    {
        system("cls");
        fflush(stdin);
        int voltar;
        ordenarClientes();      //Chama funcao para ordenar clientes
        listarClientes();       //Chama funcao de listagem
        j:
        printf("\nPara voltar aperte 0\n");
        scanf("%d", &voltar);
        if(voltar == 0)
        {
            menuc();
        }else{
            printf("Valor invalido. Tente novamente:\n");
            fflush(stdin);
            goto j;             //Retorna para linha 112
        }
    }
    
    //Caso usuário digite B
    if (op1 == 'B' || op1 == 'b')
    {
        buscarClientes();       //Chama funcao para bucar clientes
    }

    //Caso usuário digite A
    if (op1 == 'A' || op1 == 'a')
    {
        atualizarClientes();    //Chama funcao de atualizar clientes
    }

    //Caso usuário digite E
    if (op1 == 'E' || op1 == 'e')
    {
        excluirClientes();      //Chama funcao para excluir clientes
    }

    //Caso usuário digite S
    if (op1 == 'S' || op1 == 's')
    {
        fflush(stdin);
        menu();                 //Volta para o menu principal --Chama funcao menu--
    }
    
}

//Menu atalho T======================================================================================================================================================
void menut(void){
    system("cls");
    fflush(stdin);
    char op1;
    int op2; 
    printf("========= Gerenciar Contas ==========\n");
    printf("Digite um comando para prosseguir:\n");
    printf("R - Listagem de todas as contas cadastradas.\n");
    printf("C - Cadastrar uma conta para um cliente.\n");
    printf("L - Listar todas as contas de um cliente.\n");
    printf("W - Realizar um saque em uma conta.\n");
    printf("D - Realizar um deposito em uma conta.\n");
    printf("T - Realizar transferencia entre contas.\n");
    printf("E - Exibir extrato de uma conta.\n");
    printf("S - Sair.\n");
    scanf("%c", &op1);

    //Caso usuário digite C
    if (op1 == 'C' || op1 == 'c')
    {
        printf("1 - Cadastrar primeira conta\n");
        printf("2 - Cadastrar seggunda conta\n");
        fflush(stdin);
        scanf("%d", &op2);
        if (op2 == 1)
        {
            fflush(stdin);
            cadastroConta();
        }
        if (op2 == 2)
        {
            fflush(stdin);
            cadastroContaSec();
        }
    }

    //Caso usuário digite R
    if (op1 == 'R' || op1 == 'r')
    {
        system("cls");
        fflush(stdin);
        int voltar;
        ordenarContas();      //Chama funcao para ordenar contas
        listarContas();       //Chama funcao de listagem de contas
        j:
        printf("\nPara voltar aperte 0\n");
        scanf("%d", &voltar);
        if(voltar == 0)
        {
            menuc();
        }else{
            printf("Valor invalido. Tente novamente:\n");
            fflush(stdin);
            goto j;             //Retorna para linha 112
        }
    }

    //Caso usuario digite D
    if (op1 == 'D' || op1 == 'd')
    {
        depositos();
    }

    //Caso usuário digite W
    if (op1 == 'W' || op1 == 'w')
    {
        system("cls");
        saques();
    }

    //Caso usuário digite L
    if (op1 == 'L' || op1 == 'l')
    {
        buscarContas();
    }

    //Caso usuário digite T
    if (op1 == 'T' || op1 == 't')
    {
        transferencia();
    }

    //Caso usuário digite E
    if (op1 == 'E' || op1 == 'e')
    {
        extrato();
    }

    //Caso usuário digite S
    if (op1 == 'S' || op1 == 's')
    {
        menu();
    }
}

//Função cadastro de cliente================================================================================================================================================
void cadastroCliente(void){
    char nome[50];
    char endereco[100];
    int COD;
    long long int TEL;
    long long int DOC;
    int op2;
    int i, j, op3;
    int codPERMITION;
    do{
        fflush(stdin);
        system("cls");
        printf("Nome: \n");
        fflush(stdin);
        fgets(nome, sizeof(nome), stdin);
        printf("Endereco: \n");
        fflush(stdin);
        fgets(endereco, sizeof(endereco), stdin);
        printf("Codigo cliente: \n");
        fflush(stdin);
        scanf("%d", &COD);
        printf("Telefone: \n");
        fflush(stdin);
        scanf("%lld", &TEL);
        printf("Documento, CPF ou CNPJ: \n");
        fflush(stdin);
        scanf("%lld", &DOC);
        for (j = 0; j < MAX_CLIENTES; j++)
        {
            if (COD == clientes[j].COD)
            {
                codPERMITION = 2;
                break;
            }         
        }        
        for (i = 0; i < MAX_CLIENTES; i++)
        {
            if (clientes[i].ativo == 0)
            {
                if (codPERMITION == 2)
                {
                    printf("Codigo ja cadastrado, cliente nao registrado.\n");
                    printf("Para tentar novamente aperte 1, ou 0 para sair:\n");
                    fflush(stdin);
                    scanf("%d", &op3);
                    if(op3 == 1)
                    {
                        cadastroCliente();
                    }
                    if(op3 == 0)
                    {
                        menuc();
                    }
                 }else{
                    strcpy(clientes[i].nome, nome);
                    strcpy(clientes[i].endereco, endereco);
                    clientes[i].COD = COD;
                    clientes[i].TEL = TEL;
                    clientes[i].DOC = DOC;
                    clientes[i].ativo = 1;
                    quantClientes++;
                    break;
                }
            }          
        }
        printf("Para sair digite - 0, para continuar digite qualquer valor.\n");
        getchar();
        scanf("%d", &op2);
    }while(op2 != 0);
    menuc();
}

//Função para ordenação de clientes============================================================================================================================================
void ordenarClientes(void){
    int x, y, r;
    char auxNome[50];
    char auxEnd[50];
    int auxCOD;
    long long int auxTel;
    long long int auxDOC;
    int auxATV;
    for(x = 0; x < quantClientes; x++){
        for (y = x+1; y < quantClientes; y++){
            r = strcmp(clientes[x].nome, clientes[y].nome);
            if(r > 0){
                strcpy(auxNome, clientes[x].nome);
                strcpy(clientes[x].nome, clientes[y].nome);
                strcpy(clientes[y].nome, auxNome);

                strcpy(auxEnd, clientes[x].endereco);
                strcpy(clientes[x].endereco, clientes[y].endereco);
                strcpy(clientes[y].endereco, auxEnd);

                auxCOD = clientes[x].COD;
                clientes[x].COD = clientes[y].COD;
                clientes[y].COD = auxCOD;

                auxTel = clientes[x].TEL;
                clientes[x].TEL = clientes[y].TEL;
                clientes[y].TEL = auxTel;

                auxDOC = clientes[x].DOC;
                clientes[x].DOC = clientes[y].DOC;
                clientes[y].DOC = auxDOC;  

                auxATV = clientes[x].ativo;
                clientes[x].ativo = clientes[y].ativo;
                clientes[y].ativo = auxATV;            
            }
        }  
    }
}

//Função para listagem de clientes============================================================================================================================================
void listarClientes(void){
    system("cls");
    int x;
    for(x = 0; x < quantClientes; x++){
        if (clientes[x].ativo == 0)
        {
            printf("Nenhum cliente cadastrado!\n");
        }
        if (clientes[x].ativo == 1)
        {
            printf("==========================================\n");
            printf("Nome: %s\n", clientes[x].nome);
            printf("Codigo: %d\n", clientes[x].COD);
            printf("==========================================\n");
        }       
    }
}

//Função para Buscar clientes======================================================================================================================================================
void buscarClientes(void){
    int COD, x, op1;
    system("cls");
    printf("Digite o codigo do cliente: \n");
    fflush(stdin);
    scanf("%d", &COD);
    for(x = 0; x < quantClientes; x++){
        if (clientes[x].ativo == 1)
        {
            if (COD == clientes[x].COD)
            {
                printf("=======================================\n");
                printf("Nome: %s\n", clientes[x].nome);
                printf("Endereco: %s\n", clientes[x].endereco);
                printf("Telefone: %d\n\n", clientes[x].TEL);
                printf("Documento: %d\n\n", clientes[x].DOC);
                printf("Codigo: %d\n\n", clientes[x].COD);
                printf("=======================================\n");
            }          
        }
    }
    printf("\nPara buscar mais clientes digite 0, ou 1 para sair\n");
    fflush(stdin);
    scanf("%d", &op1);
    if (op1 == 0)
    {
            buscarClientes();
    }
    if (op1 == 1)
    {
        menuc();
    }
}

//Função para atualizar clientes======================================================================================================================================================
void atualizarClientes(void){
    long int COD, x, op;
    char newName[50];
    char newEnd[100];
    int newCOD;
    long long int newTEL;
    long long int newDOC;
    system("cls");
    printf("Digite o codigo do cliente para atualizacao: \n");
    fflush(stdin);
    scanf("%d", &COD);
    for(x = 0; x < quantClientes; x++){
        if (clientes[x].ativo == 1)
        {
            if (COD == clientes[x].COD)
            {
                //Coletando dados atualizados
                printf("Nome atualizado: \n");
                fflush(stdin);
                fgets(newName, sizeof(newName), stdin);
                printf("Endereco atualizado: \n");
                fflush(stdin);
                fgets(newEnd, sizeof(newEnd), stdin);
                printf("Codigo atualizado: \n");
                fflush(stdin);
                scanf("%d", &newCOD);
                printf("Telefone atualizado: \n");
                fflush(stdin);
                scanf("%lld", &newTEL);
                printf("Documento atualizado: \n");
                fflush(stdin);
                scanf("%lld", &newDOC);

                //Substituindo dados antigos pelos atualizados
                strcpy(clientes[x].nome, newName);
                strcpy(clientes[x].endereco, newEnd);
                clientes[x].COD = newCOD;
                clientes[x].TEL = newTEL;
                clientes[x].DOC = newDOC;

                //Confirmando atualizacao
                printf("\nCliente atualizado com sucesso!\n \n");
                printf("Para sair aperte 0, ou 1 para continuar cadastrando.\n");
                fflush(stdin);
                scanf("%d", &op);
                if (op == 0)
                {
                    fflush(stdin);
                    menuc();
                }
                if (op == 1)
                {
                    fflush(stdin);
                    atualizarClientes();
                }
            }
        }
    }
}

//Função para excluir clientes======================================================================================================================================================
void excluirClientes(void){
    system("cls");
    fflush(stdin);
    int COD, x, op1, op2;
    printf("Digite o codigo do cliente a ser excluido: \n");
    fflush(stdin);
    scanf("%d", &COD);
    for ( x = 0; x < MAX_CLIENTES; x++)
    {
        if (clientes[x].ativo == 1)
        {
            if (COD == clientes[x].COD)
            {
                fflush(stdin);
                printf("Nome: %s", clientes[x].nome);
                printf("Endereco: %s", clientes[x].endereco);
                printf("Codigo: %d \n", clientes[x].COD);
                printf("Telefone: %lld \n", clientes[x].TEL);
                printf("Documento: %lld \n", clientes[x].DOC);
                printf("\nVoce realmente deseja excluir esse cliente?\n");
                printf("Para confirmar digite 1, ou 0 para voltar ao menu de clientes\n");
                scanf("%d", &op1);
                if (op1 == 1)
                {
                    clientes[x].ativo = 0;
                    //CONFIRMACAO
                    printf("Cliente excluido com sucesso!\n");
                    printf("Para excluir mais clientes digite 1, ou 0 para sair. \n");
                    fflush(stdin);
                    scanf("%d", &op2);
                    if (op2 == 1)
                    {
                        excluirClientes();
                    }
                    if (op2 == 0)
                    {
                        menuc();
                    }
                }
                if (op1 == 0)
                {
                    menuc();
                }
                break;
            }
        }
    }
}     

//Função cadastro de conta======================================================================================================================================================
void cadastroConta(void){
    system("cls");
    fflush(stdin);
    int COD, i, numConta, agencia;
    int j, permit;
    int op1, op2;
    printf("Digite o codigo do cliente: \n");
    scanf("%d", &COD);
    for (i = 0; i < MAX_CLIENTES; i++)
    {
        if (clientes[i].ativo == 1)
        {
            if (COD == clientes[i].COD)
            {
                printf("Digite o numero da conta: \n");
                fflush(stdin);
                scanf("%d", &numConta);
                printf("Digite a agencia: \n");
                fflush(stdin);
                scanf("%d", &agencia);
                //Conferindo se combinacao agencia - conta existe
                for (j = 0; j < MAX_CLIENTES; j++)
                {
                    if (numConta == conta[j].numConta && agencia == conta[j].agencia)
                    {
                        permit = 1;
                        break;
                    }
                    if (numConta == contasec[j].numContaSec && agencia == contasec[j].agenciaSec)
                    {
                        permit = 1;
                        break;
                    }
                }
                //Caso exista
                if (permit == 1)
                {
                    printf("Conta ja existente\n");
                    printf("Para: tentar novamente - 0 ou sair - 1 \n");
                    fflush(stdin);
                    scanf("%d", &op1);
                    //Tentar novamente - Chama novamente a funcao de cadastro de contas
                    if (op1 == 0)
                    {
                        fflush(stdin);
                        cadastroConta();
                    }
                    //Sair retorna para o menu T
                    if (op1 == 0){
                        fflush(stdin);
                        menut();
                    }
                }else{
                    //cadastrar conta
                    conta[i].numConta = numConta;
                    conta[i].agencia = agencia;
                    conta[i].saldo = 0;
                    conta[i].ativoConta = 1;
                    quantContas++;
                    printf("Conta cadastrada com sucesso\n");
                    printf("Para continuar cadastrando - 0\n");
                    printf("Para sair - 1\n");
                    fflush(stdin);
                    scanf("%d", &op2);
                    if (op2 == 1)
                    {
                        menut();
                    }
                    if (op2 == 0)
                    {
                        cadastroConta();
                    }
                }
            }
        }     
    }    
}

//Função cadastro de conta secundária======================================================================================================================================================
void cadastroContaSec(void){
    system("cls");
    fflush(stdin);
    int COD, i, numConta, agencia;
    int j, permit;
    int op1, op2;
    printf("Digite o codigo do cliente: \n");
    scanf("%d", &COD);
    for (i = 0; i < MAX_CLIENTES; i++)
    {
        if (clientes[i].ativo == 1)
        {
            if (COD == clientes[i].COD)
            {
                printf("Digite o numero da conta: \n");
                fflush(stdin);
                scanf("%d", &numConta);
                printf("Digite a agencia: \n");
                fflush(stdin);
                scanf("%d", &agencia);
                //Conferindo se combinacao agencia - conta existe
                for (j = 0; j < MAX_CLIENTES; j++)
                {
                    if (numConta == conta[j].numConta && agencia == conta[j].agencia)
                    {
                        permit = 1;
                        break;
                    }
                    if (numConta == contasec[j].numContaSec && agencia == contasec[j].agenciaSec)
                    {
                        permit = 1;
                        break;
                    }
                }
                //Caso exista
                if (permit == 1)
                {
                    printf("Conta ja existente\n");
                    printf("Para: tentar novamente - 0 ou sair - 1 \n");
                    fflush(stdin);
                    scanf("%d", &op1);
                    //Tentar novamente - Chama novamente a funcao de cadastro de contas
                    if (op1 == 0)
                    {
                        cadastroContaSec();
                    }
                    //Sair retorna para o menu T
                    if (op1 == 0){
                        menut();
                    }
                }else{
                    //cadastrar conta
                    contasec[i].numContaSec = numConta;
                    contasec[i].agenciaSec = agencia;
                    contasec[i].saldoSec = 0;
                    contasec[i].ativoContaSec = 1;
                    quantContasSec++;
                    printf("Conta cadastrada com sucesso\n");
                    printf("Para continuar cadastrando - 0\n");
                    printf("Para sair - 1\n");
                    fflush(stdin);
                    scanf("%d", &op2);
                    if (op2 == 1)
                    {
                        menut();
                    }
                    if (op2 == 0)
                    {
                        cadastroContaSec();
                    }
                }
            }
        }     
    }    
}

//Função para ordenar contas em ordem alfabética================================================================================================================================================
void ordenarContas(void){
    int x, y, r;
    //Auxiliares cliente
    char auxNome[50];
    char auxEnd[50];
    int auxCOD;
    long long int auxTel;
    long long int auxDOC;
    int auxATV;

    //Auxiliares conta
    int auxConta;
    int auxAgencia;
    int auxSaldo;
    int auxAtivo;

    //Auxiliares contaSec
    int auxContaSec;
    int auxAgenciaSec;
    int auxSaldoSec;
    int auxAtivoSec;

    for(x = 0; x < quantClientes; x++){
        for (y = x+1; y < quantClientes; y++){
            r = strcmp(clientes[x].nome, clientes[y].nome);
            if(r > 0){
                //Trocando clientes
                strcpy(auxNome, clientes[x].nome);
                strcpy(clientes[x].nome, clientes[y].nome);
                strcpy(clientes[y].nome, auxNome);

                strcpy(auxEnd, clientes[x].endereco);
                strcpy(clientes[x].endereco, clientes[y].endereco);
                strcpy(clientes[y].endereco, auxEnd);

                auxCOD = clientes[x].COD;
                clientes[x].COD = clientes[y].COD;
                clientes[y].COD = auxCOD;

                auxTel = clientes[x].TEL;
                clientes[x].TEL = clientes[y].TEL;
                clientes[y].TEL = auxTel;

                auxDOC = clientes[x].DOC;
                clientes[x].DOC = clientes[y].DOC;
                clientes[y].DOC = auxDOC;  

                auxATV = clientes[x].ativo;
                clientes[x].ativo = clientes[y].ativo;
                clientes[y].ativo = auxATV;

                //Trocando contas
                auxConta = conta[x].numConta;
                conta[x].numConta = conta[y].numConta;   
                conta[y].numConta = auxConta;

                auxAgencia = conta[x].agencia;
                conta[x].agencia = conta[y].agencia;
                conta[y].agencia = auxAgencia;

                auxSaldo = conta[x].saldo;
                conta[x].saldo = conta[y].saldo;
                conta[y].saldo = auxSaldo;

                auxAtivo = conta[x].ativoConta;
                conta[x].ativoConta = conta[y].ativoConta;
                conta[y].ativoConta = auxAtivo;

                //Trocando contas secundárias
                auxContaSec = contasec[x].numContaSec;
                contasec[x].numContaSec = contasec[y].numContaSec;   
                contasec[y].numContaSec = auxContaSec;

                auxAgenciaSec = contasec[x].agenciaSec;
                contasec[x].agenciaSec = contasec[y].agenciaSec;
                contasec[y].agenciaSec = auxAgenciaSec;

                auxSaldoSec = contasec[x].saldoSec;
                contasec[x].saldoSec = contasec[y].saldoSec;
                contasec[y].saldoSec = auxSaldoSec;

                auxAtivoSec = contasec[x].ativoContaSec;
                contasec[x].ativoContaSec = contasec[y].ativoContaSec;
                contasec[y].ativoContaSec = auxAtivoSec;
            }
        }  
    }
}

//Função para listar as contas======================================================================================================================================================
void listarContas(void){
    system("cls");
    int x;
    for(x = 0; x < quantContas; x++){
        if (conta[x].ativoConta == 0 && contasec[x].ativoContaSec == 0)
        {
            printf("Nenhuma conta cadastrado!\n");
        }
        if (conta[x].ativoConta == 1 && contasec[x].ativoContaSec == 0)
        {
            printf("==========================================\n");
            printf("Nome: %s\n", clientes[x].nome);
            printf("\nAgencia conta primaria: %d\n", conta[x].agencia);
            printf("Numero conta primaria: %d\n", conta[x].numConta);
            printf("Saldo conta primaria: %d\n", conta[x].saldo);
            printf("==========================================\n");
        }
        if (conta[x].ativoConta == 0 && contasec[x].ativoContaSec == 1)
        {
            printf("==========================================\n");
            printf("Nome: %s\n", clientes[x].nome);
            printf("\n Agencia conta secundaria: %d\n", contasec[x].agenciaSec);
            printf("Numero conta secundaria: %d\n", contasec[x].numContaSec);
            printf("Saldo conta secundaria: %d\n", contasec[x].saldoSec);
            printf("==========================================\n");
        }
        if (conta[x].saldo > contasec[x].saldoSec && conta[x].ativoConta == 1 && contasec[x].ativoContaSec == 1)
        {
            printf("==========================================\n");
            printf("Nome: %s\n", clientes[x].nome);
            printf("\nAgencia conta primaria: %d\n", conta[x].agencia);
            printf("Numero conta primaria: %d\n", conta[x].numConta);
            printf("Saldo conta primaria: %d\n", conta[x].saldo);
            printf("\n Agencia conta secundaria: %d\n", contasec[x].agenciaSec);
            printf("Numero conta secundaria: %d\n", contasec[x].numContaSec);
            printf("Saldo conta secundaria: %d\n", contasec[x].saldoSec);
            printf("==========================================\n");
        }
        if (conta[x].saldo < contasec[x].saldoSec && conta[x].ativoConta == 1 && contasec[x].ativoContaSec == 1)
        {
            printf("==========================================\n");   
            printf("Nome: %s\n", clientes[x].nome);
            printf("\n Agencia conta secundaria: %d\n", contasec[x].agenciaSec);
            printf("Numero conta secundaria: %d\n", contasec[x].numContaSec);
            printf("Saldo conta secundaria: %d\n", contasec[x].saldoSec);
            printf("\nAgencia conta primaria: %d\n", conta[x].agencia);
            printf("Numero conta primaria: %d\n", conta[x].numConta);
            printf("Saldo conta primaria: %d\n", conta[x].saldo);            
            printf("==========================================\n");                  
        }       
    }
}

//Função para listar as contas de um cliente======================================================================================================================================================
void buscarContas(void){
    int x, cod, optionSaida;
    system("cls");
    fflush(stdin);
    printf("Digite o codigo do cliente: \n");
    scanf("%d", &cod);
    for(x = 0; x < quantClientes; x++)
    {
        if (clientes[x].ativo == 1)
        {
            if (cod == clientes[x].COD)
            {
                if (conta[x].ativoConta == 1)
                {
                    printf("===============================================\n");
                    printf("Nome: %s\n", clientes[x].nome);
                    printf("Numero da conta: %d\n", conta[x].numConta);
                    printf("Agencia: %d\n", conta[x].agencia);
                    printf("Saldo: %.2lf\n", conta[x].saldo);
                    printf("===============================================\n");
                }
                if (contasec[x].ativoContaSec == 1)
                {
                    printf("===============================================\n");
                    printf("Nome: %s\n", clientes[x].nome);
                    printf("Numero da conta: %d\n", contasec[x].numContaSec);
                    printf("Agencia: %d\n", contasec[x].agenciaSec);
                    printf("Saldo: %d\n", contasec[x].saldoSec);
                    printf("===============================================\n");
                }
            }          
        }
    } 
    printf("Para buscar mais clientes digite 0, ou 1 para sair: \n");
    fflush(stdin);
    scanf("%d", &optionSaida);
    if (optionSaida == 0)
    {
        buscarContas();
    }
    if (optionSaida == 1)
    {
        menut();
    }
}

//Função para realização de saque=========================================================================================================================================================
void saques(void){
    system("cls");
    fflush(stdin);
    int x, y;
    int AGENCIA, CONTA;
    int saque;
    char description[100];
    int quantNotas200, quantNotas100, quantNotas50, quantNotas20, quantNotas10, quantNotas5, quantNotas2;
    int op1, op2;
    printf("Digite o numero da conta a qual deseja realizar um saque: \n");
    scanf("%d", &CONTA);
    printf("Digite a agencia correspondente: \n");
    fflush(stdin);
    scanf("%d", &AGENCIA);
    for(x = 0; x < quantContas; x++){
        //VERIFICANDO CORRESPONDENCIA COM CONTA PRIMÁRIA
        if (AGENCIA == conta[x].agencia && CONTA == conta[x].numConta)
        {
            //PRINTANDO DADOS DO CLIENTE
            system("cls");
            printf("=========== DADOS DO PROPRIETARIO DA CONTA ===========\n");
            printf("Nome: %s\n", clientes[x].nome);
            printf("Endereco: %s\n", clientes[x].endereco);
            printf("Documento: %lld\n", clientes[x].DOC);
            printf("Telefone: %lld\n", clientes[x].TEL);
            printf("Codigo: %d\n", clientes[x].COD);
            printf("======================================================\n");
            printf("\nInforme o valor de saque: \n");
            fflush(stdin);
            scanf("%d", &saque);
            if (saque < conta[x].saldo)
            {
                //REALIZANDO O SAQUE, ATUALIZANDO O SALDO
                printf("Descreve brevemente a transacao. - MAX 100 CARACTERES -\n");
                fflush(stdin);
                fgets(description, sizeof(description), stdin);
                conta[x].saldo = conta[x].saldo - saque;

                //CALCULANDO QUANTIDADE DE NOTAS
                quantNotas200 = saque/200;
                quantNotas100 = (saque%200)/100;
                quantNotas50 = ((saque%200)%100)/50;
                quantNotas20 = (((saque%200)%100)%50)/20;
                quantNotas10 = ((((saque%200)%100)%50)%20)/10;
                quantNotas5 = (((((saque%200)%100)%50)%20)%10)/5;
                quantNotas2 = ((((((saque%200)%100)%50)%20)%10)%5)/2;

                //PRINTANDO QUANTIDADE DE NOTAS
                printf("Quantidade notas de 200: %d\n", quantNotas200);
                printf("Quantidade notas de 100: %d\n", quantNotas100);
                printf("Quantidade notas de 50: %d\n", quantNotas50);
                printf("Quantidade notas de 20: %d\n", quantNotas20);
                printf("Quantidade notas de 10: %d\n", quantNotas10);
                printf("Quantidade notas de 5: %d\n", quantNotas5);
                printf("Quantidade notas de 2: %d\n", quantNotas2);

                //CADASTRANDO TRANSAÇÃO
                for(y = 0; y < MAX_transacoes; y++){
                    if (transacoes[y].ativoTransacoes == 0)
                    {
                        strcpy(transacoes[y].description, description);
                        strcpy(transacoes[y].type, "DEBITO");
                        transacoes[y].ativoTransacoes = 1;
                        transacoes[y].valor = saque;
                        transacoes[y].conta = CONTA;
                        transacoes[y].COD = clientes[y].COD;
                        transacoes[y].tempo = time(NULL);
                        quantTransacoes++;
                        break;
                    }
                }
                //CONTINUANDO O SISTEMA E CONFIRMANDO
                printf("Saque realizado com sucesso!\n");
                printf("Para realizar outro saque, digite 1, ou 0 para sair: \n");
                fflush(stdin);
                scanf("%d", &op1);
                if (op1 == 1)
                {
                    saques();
                }
                if (op1 == 0)
                {
                    menut();
                }
            }else{
                //CASO O SAQUE SEJA MAIOR QUE O SALDO
                printf("Saldo insuficiente\n");
                printf("Para tentar realizar outro saque escolha 1, ou 0 para sair: \n");
                fflush(stdin);
                scanf("%d", &op1);
                if (op1 == 1)
                {
                    saques();
                }
                if (op1 == 0)
                {
                    menut();
                }
            }
        }
        //VERIFICANDO CORRESPONDENCIA COM CONTA SECUNDÁRIA
        if (AGENCIA == contasec[x].agenciaSec && CONTA == contasec[x].numContaSec)
        {
            //PRINTANDO DADOS DO CLIENTE
            system("cls");
            printf("=========== DADOS DO PROPRIETARIO DA CONTA ===========\n");
            printf("Nome: %s\n", clientes[x].nome);
            printf("Endereco: %s\n", clientes[x].endereco);
            printf("Documento: %lld\n", clientes[x].DOC);
            printf("Telefone: %lld\n", clientes[x].TEL);
            printf("Codigo: %d\n", clientes[x].COD);
            printf("======================================================\n");
            printf("\nInforme o valor de saque: \n");
            fflush(stdin);
            scanf("%d", &saque);
            if (saque < contasec[x].saldoSec)
            {
                //REALIZANDO O SAQUE, ATUALIZANDO O SALDO
                printf("Descreve brevemente a transacao. - MAX 100 CARACTERES -\n");
                fflush(stdin);
                fgets(description, sizeof(description), stdin);
                contasec[x].saldoSec = contasec[x].saldoSec - saque;

                //CALCULANDO QUANTIDADE DE NOTAS
                quantNotas200 = saque/200;
                quantNotas100 = (saque%200)/100;
                quantNotas50 = ((saque%200)%100)/50;
                quantNotas20 = (((saque%200)%100)%50)/20;
                quantNotas10 = ((((saque%200)%100)%50)%20)/10;
                quantNotas5 = (((((saque%200)%100)%50)%20)%10)/5;
                quantNotas2 = ((((((saque%200)%100)%50)%20)%10)%5)/2;

                //PRINTANDO QUANTIDADE DE NOTAS
                printf("Quantidade notas de 200: %d\n", quantNotas200);
                printf("Quantidade notas de 100: %d\n", quantNotas100);
                printf("Quantidade notas de 50: %d\n", quantNotas50);
                printf("Quantidade notas de 20: %d\n", quantNotas20);
                printf("Quantidade notas de 10: %d\n", quantNotas10);
                printf("Quantidade notas de 5: %d\n", quantNotas5);
                printf("Quantidade notas de 2: %d\n", quantNotas2);

                //CADASTRANDO TRANSAÇÃO E CONFIRMANDO
                for(y = 0; y < MAX_transacoes; y++){
                    if (transacoes[y].ativoTransacoes == 0)
                    {
                        strcpy(transacoes[y].description, description);
                        strcpy(transacoes[y].type, "DEBITO");
                        transacoes[y].ativoTransacoes = 1;
                        transacoes[y].valor = saque;
                        transacoes[y].conta = CONTA;
                        transacoes[y].COD = clientes[y].COD;
                        transacoes[y].tempo = time(NULL);
                        quantTransacoes++;
                        break;
                    }
                }
                //DANDO CONTINUIDADE NO SISTEMA
                printf("Saque realizada com sucesso!\n");
                printf("Para realizar outro saque escolha 1, ou 0 para sair: \n");
                fflush(stdin);
                scanf("%d", &op2);
                if (op2 == 1)
                {
                    saques();
                }
                if (op2 == 0)
                {
                    menut();
                }
            }else{
                //CASO SALDO SEJA INSUFICIENTE
                printf("Saldo insuficiente!\n");
                printf("Para tentar realizar outro saldo escolha 1, ou 0 para sair: \n");
                fflush(stdin);
                scanf("%d", &op2);
                if (op2 == 1)
                {
                    saques();
                }
                if (op2 == 0)
                {
                    menut();
                }
            }
        }
    }
}

//Função para realização de depósito======================================================================================================================================================
void depositos(void){
    system("cls");
    fflush(stdin);
    int x, y;
    int AGENCIA, CONTA;
    double deposito;
    char description[100];
    int op2;
    printf("Digite o numero da conta a qual deseja realizar um deposito: \n");
    scanf("%d", &CONTA);
    printf("Digite a agencia correspondente: \n");
    fflush(stdin);
    scanf("%d", &AGENCIA);
    for(x = 0; x < quantContas; x++){
        //VERIFICANDO CORRESPONDENCIA COM CONTA PRIMÁRIA
        if (AGENCIA == conta[x].agencia && CONTA == conta[x].numConta)
        {
            //PRINTANDO DADOS DO CLIENTE
            system("cls");
            printf("=========== DADOS DO PROPRIETARIO DA CONTA ===========\n");
            printf("Nome: %s\n", clientes[x].nome);
            printf("Endereco: %s\n", clientes[x].endereco);
            printf("Documento: %lld\n", clientes[x].DOC);
            printf("Telefone: %lld\n", clientes[x].TEL);
            printf("Codigo: %d\n", clientes[x].COD);
            printf("======================================================\n");

            //Recebendo valor de deposito
            printf("\nInforme o valor de deposito: \n");
            fflush(stdin);
            scanf("%lf", &deposito);

            //Recebendo descrição
            printf("Escreva uma breve descricao do deposito -MAX 100 CARACTERES-.\n");
            fflush(stdin);
            fgets(description, sizeof(description), stdin);

            //Atualizando saldo
            conta[x].saldo = conta[x].saldo + deposito;

            //CADASTRANDO TRANSAÇÃO
                for(y = 0; y < MAX_transacoes; y++){
                    if (transacoes[y].ativoTransacoes == 0)
                    {
                        strcpy(transacoes[y].description, description);
                        strcpy(transacoes[y].type, "CREDITO");
                        transacoes[y].ativoTransacoes = 1;
                        transacoes[y].valor = deposito;
                        transacoes[y].conta = CONTA;
                        transacoes[y].COD = clientes[x].COD;
                        transacoes[y].tempo = time(NULL);
                        quantTransacoes++;
                        break;
                    }
                }
            //DANDO CONTINUIDADE NO SISTEMA E CONFIRMANDO
            printf("Deposito realizado com sucesso!\n");
            printf("\nPara realizar outro deposito, digite 1, ou 0 para sair: \n");
            fflush(stdin);
            scanf("%d", &op2);
            if (op2 == 1)
            {
                depositos();
            }
            if (op2 == 0)
            {
                menut();
            }
        }
        if (AGENCIA == contasec[x].agenciaSec && CONTA == contasec[x].numContaSec)
        {
            //PRINTANDO DADOS DO CLIENTE
            system("cls");
            printf("=========== DADOS DO PROPRIETARIO DA CONTA ===========\n");
            printf("Nome: %s\n", clientes[x].nome);
            printf("Endereco: %s\n", clientes[x].endereco);
            printf("Documento: %lld\n", clientes[x].DOC);
            printf("Telefone: %lld\n", clientes[x].TEL);
            printf("Codigo: %d\n", clientes[x].COD);
            printf("======================================================\n");

            //Recebendo valor de deposito
            printf("\nInforme o valor de deposito: \n");
            fflush(stdin);
            scanf("%lf", &deposito);

            //Recebendo descrição
            printf("Escreva uma breve descricao do deposito -MAX 100 CARACTERES-.\n");
            fflush(stdin);
            fgets(description, sizeof(description), stdin);

            //Atualizando saldo
            contasec[x].saldoSec = contasec[x].saldoSec + deposito;

            //CADASTRANDO TRANSAÇÃO
                for(y = 0; y < MAX_transacoes; y++){
                    if (transacoes[y].ativoTransacoes == 0)
                    {
                        strcpy(transacoes[y].description, description);
                        strcpy(transacoes[y].type, "CREDITO");
                        transacoes[y].ativoTransacoes = 1;
                        transacoes[y].valor = deposito;
                        transacoes[y].conta = CONTA;
                        transacoes[y].COD = clientes[x].COD;
                        transacoes[y].tempo = time(NULL);
                        quantTransacoes++;
                        break;
                    }
                }
            //DANDO CONTINUIDADE NO SISTEMA E CONFIRMANDO
            printf("Deposito realizado com sucesso!\n");
            printf("\nPara realizar outro deposito, digite 1, ou 0 para sair: \n");
            fflush(stdin);
            scanf("%d", &op2);
            if (op2 == 1)
            {
                depositos();
            }
            if (op2 == 0)
            {
                menut();
            }
        }
    }
}

//Função para transferência=================================================================================================================================================================
void transferencia(void){
    system("cls");
    fflush(stdin);
    int op1;
    int x, y, z;
    double valorTransferencia;
    int agenciaOrigem, numContaOrigem;
    int agenciaDestino, numContaDestino;
    printf("Digite a agencia de origem: \n");
    scanf("%d", &agenciaOrigem);
    fflush(stdin);
    printf("Digite o numero da conta de origem: \n");
    scanf("%d", &numContaOrigem);
    for(x = 0; x < quantContas; x++){
        if (agenciaOrigem == conta[x].agencia && numContaOrigem == conta[x].numConta)
        {
            //Printando dados da conta de origem
            system("cls");
            printf("======================================================\n");
            printf("Nome cliente: %s", clientes[x].nome);
            printf("Endereco: %s\n", clientes[x].endereco);
            printf("Documento: %lld\n", clientes[x].DOC);
            printf("Telefone: %lld\n", clientes[x].TEL);
            printf("Codigo: %d\n", clientes[x].COD);
            printf("Saldo: %.2lf\n", conta[x].saldo);
            printf("======================================================\n");

            //Lendo dados da conta final
            printf("\nDigite a agencia de destino: \n");
            fflush(stdin);
            scanf("%d", &agenciaDestino);
            printf("Digite o numero da conta de destino: \n");
            fflush(stdin);
            scanf("%d", &numContaDestino);
            for(y = 0; y < quantContas; y++){
                if (agenciaDestino == conta[y].agencia && numContaDestino == conta[y].numConta){
                    printf("======================================================\n");
                    printf("Nome cliente: %s\n", clientes[y].nome);
                    printf("Endereco: %s\n", clientes[y].endereco);
                    printf("Documento: %lld\n", clientes[y].DOC);
                    printf("Telefone: %lld\n", clientes[y].TEL);
                    printf("Codigo: %d\n", clientes[y].COD);
                    printf("Saldo: %.2lf\n", conta[y].saldo);
                    printf("======================================================\n");

                    //Recebendo valor da transferência
                    printf("Digite o valor a ser transferido: \n");
                    fflush(stdin);
                    scanf("%lf", &valorTransferencia);
                    if (valorTransferencia < conta[x].saldo)
                    {
                        conta[x].saldo = conta[x].saldo - valorTransferencia;
                        conta[y].saldo = conta[y].saldo + valorTransferencia;
                    }
                    //CADASTRANDO TRANSAÇÕES
                    for(z = 0; z < MAX_transacoes; z++){
                        if (transacoes[z].ativoTransacoes == 0)
                        {
                            strcpy(transacoes[z].description, "transferencia envio");
                            strcpy(transacoes[z].type, "DEBITO");
                            transacoes[z].ativoTransacoes = 1;
                            transacoes[z].valor = valorTransferencia;
                            transacoes[z].conta = conta[x].numConta;
                            transacoes[z].COD = clientes[x].COD;
                            transacoes[z].tempo = time(NULL);
                            quantTransacoes++;

                            strcpy(transacoes[z + 1].description, "transferencia recebimento");
                            strcpy(transacoes[z + 1].type, "CREDITO");
                            transacoes[z + 1].ativoTransacoes = 1;
                            transacoes[z + 1].valor = valorTransferencia;
                            transacoes[z + 1].conta = conta[y].numConta;
                            transacoes[z + 1].COD = clientes[y].COD;
                            transacoes[z + 1].tempo = time(NULL);
                            quantTransacoes++;

                            //Confirmando transferencia
                            printf("Tranferencia realizada com sucesso.");

                            //Dando continuidade no sistema
                            printf("Para realizar outra transferencia digite 0, ou 1 para sair: \n");
                            fflush(stdin);
                            scanf("%d", &op1);
                            if (op1 == 0)
                            {
                                transferencia();
                            }
                            if (op1 == 1)
                            {
                                menut();
                            }
                        }
                      }
                    }

                    if (agenciaDestino == contasec[y].agenciaSec && numContaDestino == contasec[y].numContaSec){
                    printf("======================================================\n");
                    printf("Nome cliente: %s\n", clientes[y].nome);
                    printf("Endereco: %s\n", clientes[y].endereco);
                    printf("Documento: %lld\n", clientes[y].DOC);
                    printf("Telefone: %lld\n", clientes[y].TEL);
                    printf("Codigo: %d\n", clientes[y].COD);
                    printf("Saldo: %.2lf\n", contasec[y].saldoSec);
                    printf("======================================================\n");

                    //Recebendo valor da transferência
                    printf("Digite o valor a ser transferido: \n");
                    fflush(stdin);
                    scanf("%lf", &valorTransferencia);
                    if (valorTransferencia < conta[x].saldo)
                    {
                        conta[x].saldo = conta[x].saldo - valorTransferencia;
                        contasec[y].saldoSec = contasec[y].saldoSec + valorTransferencia;
                    }
                    //CADASTRANDO TRANSAÇÕES
                    for(z = 0; z < MAX_transacoes; z++){
                        if (transacoes[z].ativoTransacoes == 0)
                        {
                            strcpy(transacoes[z].description, "transferencia envio");
                            strcpy(transacoes[z].type, "DEBITO");
                            transacoes[z].ativoTransacoes = 1;
                            transacoes[z].valor = valorTransferencia;
                            transacoes[z].conta = conta[x].numConta;
                            transacoes[z].COD = clientes[x].COD;
                            transacoes[z].tempo = time(NULL);
                            quantTransacoes++;

                            strcpy(transacoes[z + 1].description, "transferencia recebimento");
                            strcpy(transacoes[z + 1].type, "CREDITO");
                            transacoes[z + 1].ativoTransacoes = 1;
                            transacoes[z + 1].valor = valorTransferencia;
                            transacoes[z + 1].conta = contasec[y].numContaSec;
                            transacoes[z + 1].COD = clientes[y].COD;
                            transacoes[z + 1].tempo = time(NULL);
                            quantTransacoes++;

                            //Confirmando transferencia
                            printf("Tranferencia realizada com sucesso.");
                        }
                      }
                    //Dando continuidade no sistema
                    printf("Para realizar outra transferencia digite 0, ou 1 para sair: \n");
                    fflush(stdin);
                    scanf("%d", &op1);
                    if (op1 == 0)
                    {
                        transferencia();
                    }
                    if (op1 == 1)
                    {
                        menut();
                    }
                    }
                }
            }

        if (agenciaOrigem == contasec[x].agenciaSec && numContaOrigem == contasec[x].numContaSec)
        {
            //Printando dados da conta de origem
            system("cls");
            printf("======================================================\n");
            printf("Nome cliente: %s\n", clientes[x].nome);
            printf("Endereco: %s\n", clientes[x].endereco);
            printf("Documento: %lld\n", clientes[x].DOC);
            printf("Telefone: %lld\n", clientes[x].TEL);
            printf("Codigo: %d\n", clientes[x].COD);
            printf("Saldo: %.2lf\n", contasec[x].saldoSec);
            printf("======================================================\n");

            //Lendo dados da conta final
            printf("\nDigite a agencia de destino: \n");
            fflush(stdin);
            scanf("%d", &agenciaDestino);
            printf("Digite o numero da conta de destino: \n");
            fflush(stdin);
            scanf("%d", &numContaDestino);
            for(y = 0; y < quantContas; y++){
                if (agenciaDestino == conta[y].agencia && numContaDestino == conta[y].numConta){
                    printf("======================================================\n");
                    printf("Nome cliente: %s\n", clientes[y].nome);
                    printf("Endereco: %s\n", clientes[y].endereco);
                    printf("Documento: %lld\n", clientes[y].DOC);
                    printf("Telefone: %lld\n", clientes[y].TEL);
                    printf("Codigo: %d\n", clientes[y].COD);
                    printf("Saldo: %.2lf\n", conta[y].saldo);
                    printf("======================================================\n");

                    //Recebendo valor da transferência
                    printf("Digite o valor a ser transferido: \n");
                    fflush(stdin);
                    scanf("%lf", &valorTransferencia);
                    if (valorTransferencia < contasec[x].saldoSec)
                    {
                        conta[x].saldo = contasec[x].saldoSec - valorTransferencia;
                        conta[y].saldo = conta[y].saldo + valorTransferencia;
                    }
                    //CADASTRANDO TRANSAÇÕES
                    for(z = 0; z < MAX_transacoes; z++){
                        if (transacoes[z].ativoTransacoes == 0)
                        {
                            strcpy(transacoes[z].description, "transferencia envio");
                            strcpy(transacoes[z].type, "DEBITO");
                            transacoes[z].ativoTransacoes = 1;
                            transacoes[z].valor = valorTransferencia;
                            transacoes[z].conta = contasec[x].numContaSec;
                            transacoes[z].COD = clientes[x].COD;
                            transacoes[z].tempo = time(NULL);
                            quantTransacoes++;

                            strcpy(transacoes[z + 1].description, "transferencia recebimento");
                            strcpy(transacoes[z + 1].type, "CREDITO");
                            transacoes[z + 1].ativoTransacoes = 1;
                            transacoes[z + 1].valor = valorTransferencia;
                            transacoes[z + 1].conta = conta[y].numConta;
                            transacoes[z + 1].COD = clientes[y].COD;
                            transacoes[z + 1].tempo = time(NULL);
                            quantTransacoes++;

                            //Confirmando transferencia
                            printf("Tranferencia realizada com sucesso.");
                            }
                        }
                      }
                            //Dando continuidade no sistema
                            printf("Para realizar outra transferencia digite 0, ou 1 para sair: \n");
                            fflush(stdin);
                            scanf("%d", &op1);
                            if (op1 == 0)
                            {
                                transferencia();
                            }
                            if (op1 == 1)
                            {
                                menut();
                    }

                    if (agenciaDestino == contasec[y].agenciaSec && numContaDestino == contasec[y].numContaSec){
                    printf("======================================================\n");
                    printf("Nome cliente: %s\n", clientes[y].nome);
                    printf("Endereco: %s\n", clientes[y].endereco);
                    printf("Documento: %lld\n", clientes[y].DOC);
                    printf("Telefone: %lld\n", clientes[y].TEL);
                    printf("Codigo: %d\n", clientes[y].COD);
                    printf("Saldo: %.2lf\n", contasec[y].saldoSec);
                    printf("======================================================\n");

                    //Recebendo valor da transferência
                    printf("Digite o valor a ser transferido: \n");
                    fflush(stdin);
                    scanf("%lf", &valorTransferencia);
                    if (valorTransferencia < conta[x].saldo)
                    {
                        conta[x].saldo = conta[x].saldo - valorTransferencia;
                        contasec[y].saldoSec = contasec[y].saldoSec + valorTransferencia;
                    }
                    //CADASTRANDO TRANSAÇÕES
                    for(z = 0; z < MAX_transacoes; z++){
                        if (transacoes[z].ativoTransacoes == 0)
                        {
                            strcpy(transacoes[z].description, "transferencia envio");
                            strcpy(transacoes[z].type, "DEBITO");
                            transacoes[z].ativoTransacoes = 1;
                            transacoes[z].valor = valorTransferencia;
                            transacoes[z].conta = conta[x].numConta;
                            transacoes[z].COD = clientes[x].COD;
                            transacoes[z].tempo = time(NULL);
                            quantTransacoes++;

                            strcpy(transacoes[z + 1].description, "transferencia recebimento");
                            strcpy(transacoes[z + 1].type, "CREDITO");
                            transacoes[z + 1].ativoTransacoes = 1;
                            transacoes[z + 1].valor = valorTransferencia;
                            transacoes[z + 1].conta = contasec[y].numContaSec;
                            transacoes[z + 1].COD = clientes[y].COD;
                            transacoes[z + 1].tempo = time(NULL);
                            quantTransacoes++;

                            //Confirmando transferencia
                            printf("Tranferencia realizada com sucesso.");
                        }
                      }
                            //Dando continuidade no sistema
                            printf("Para realizar outra transferencia digite 0, ou 1 para sair: \n");
                            fflush(stdin);
                            scanf("%d", &op1);
                            if (op1 == 0)
                            {
                                transferencia();
                            }
                            if (op1 == 1)
                            {
                                menut();
                            }
                    }
                }
            }else{
                printf("Agencia ou conta inexistente!\n");
            }         
        }
    }

//Função para extrato=================================================================================================================================================================
void extrato(void){
    system("cls");
    fflush(stdin);
    int i, x, op1;
    int agencia, numconta;
    int dias, periodo;
    time_t tempo, extratoTime;
    printf("Digite a agencia: \n");
    scanf("%d", &agencia);
    printf("Digite o numero da conta: \n");
    fflush(stdin);
    scanf("%d", &numconta);
    for (i = 0; i < MAX_CONTAS; i++)
    {
        //Buscando cliente e printando seus dados -- CASE PRIM -
        if (agencia == conta[i].agencia && numconta == conta[i].numConta)
        {
            printf("\n==============Dados do cliente==============\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("Codigo: %d\n", clientes[i].COD);
            printf("Endereco: %s\n", clientes[i].endereco);
            printf("Telefone: %lld\n", clientes[i].TEL);
            printf("Documento: %lld\n", clientes[i].DOC);
            printf("SALDO: %.2lf\n", conta[i].saldo);
            printf("\n=============================================\n");

            //Lendo periodo do extrato
            printf("\nPeriodo em dias do extrato: \n");
            fflush(stdin);
            scanf("%d", &dias);

            //Salvando tempo de solicitação
            tempo = time(NULL);

            //Convertendo dias para segundos
            periodo = dias * 24 * 60 * 60;
            
            //Analisando todas as transações
            for ( x = 0; x < MAX_transacoes; x++ )
            {
                if ( clientes[i].COD == transacoes[x].COD && periodo > (tempo - transacoes[x].tempo))
                {
                    printf("=============================================\n");
                    printf("Tipo: %s\n", transacoes[x].type);
                    printf("Descricao: %s\n", transacoes[x].description);
                    printf("Valor: %.2lf\n", transacoes[x].valor);
                    printf("=============================================\n");
                }
            }
            
            //Continuando o programa
            printf("Para puxar mais algum extrato, digite 1, ou 0 para sair\n");
            fflush(stdin);
            scanf("%d", &op1);
            if(op1 == 1)
            {
                extrato();
            }
            if(op1 == 0)
            {
                menut();
            }
        }
        
        //Buscando cliente e printando seus dados -- CASE SEC -
        if (agencia == contasec[i].agenciaSec && numconta == contasec[i].numContaSec)
        {
            printf("\n==============Dados do cliente==============\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("Codigo: %d\n", clientes[i].COD);
            printf("Endereco: %s", clientes[i].endereco);
            printf("Telefone: %lld\n", clientes[i].TEL);
            printf("Documento: %lld\n", clientes[i].DOC);
            printf("SALDO: %.2lf\n", contasec[i].saldoSec);
            printf("\n=============================================\n");

            //Lendo periodo do extrato
            printf("\nPeriodo em dias do extrato: \n");
            fflush(stdin);
            scanf("%d", &dias);

            //Salvando tempo de solicitação
            tempo = time(NULL);

            //Convertendo dias para segundos
            periodo = dias * 24 * 60 * 60;

            //Analisando todas as transações
            for (x = 0; x < MAX_transacoes; x++)
            {
                if ( clientes[i].COD == transacoes[x].COD && periodo < (tempo - transacoes[x].tempo))
                {
                    printf("=============================================\n");
                    printf("Tipo: %s\n", transacoes[x].type);
                    printf("Descricao: %s\n", transacoes[x].description);
                    printf("Valor: %lf\n", transacoes[x].valor);
                    printf("=============================================\n");
                }
            }

            //Continuando o programa
            printf("Para puxar mais algum extrato, digite 1, ou 0 para sair\n");
            fflush(stdin);
            scanf("%d", &op1);
            if(op1 == 1)
            {
                extrato();
            }
            if(op1 == 0)
            {
                menut();
            }
        }
    }
}