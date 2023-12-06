//
// Created by sudo on 12/05/2023.
//

#include <stdio.h>

#define Ex96

#ifdef Ex91

/*1 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na função main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main().
*/

int compararStrings( char *str1,  char *str2) {

    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }


    return (str1[i] == '\0' && str2[i] == '\0') ? 1 : 0;
}

int main() {
    char string1[11], string2[11];

    printf("Digite a primeira string (max 10 caracteres): ");
    scanf("%s", string1);

    printf("Digite a segunda string (max 10 caracteres): ");
    scanf("%s", string2);

    if (compararStrings(string1, string2)) {
        printf("São Iguais\n");
    } else {
        printf("São diferentes\n");
    }

    return 0;
}

#endif

#ifdef Ex92

/* 2 - Escreva um programa que receba n valores via teclado e receba tambem a
    operação a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operações aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.
    As variaveis sao LOCAIS na funcao main().                                */

int operacao(int *pnum, int *pnum2);
int soma(int *pnum, int *pnum2);
int subtracao(int *pnum, int *pnum2);
int multi(int *pnum, int *pnum2);
int divisao(int *pnum, int *pnum2);
void finalizar();

void main()
{
    int num, num2, *pnum = &num, *pnum2 = &num2;
    printf("Aperte a tecla ' = ' para receber o resultado das operacoes.\n");
    printf("\nResultado da operacao = %d\n", operacao(pnum, pnum2));

    finalizar();

}

int operacao(int *pnum, int *pnum2)
{

    char operador;
    printf("Digite um numero: ");
    scanf("%d", pnum);

    do
    {
        do
        {
            printf("\n'+' para soma, '-' para subtracao , '*' para mult. '/' para div.");
            printf("\nOperacao: ");
            operador = getche();
        }
        while(operador != '+' && operador != '-' && operador != '*' && operador != '/' && operador != '=');

        if(operador != '=')
        {
            printf("\n\nDigite o proximo numero: ");
            scanf("%d", pnum2);
        }
        switch (operador)
        {

        case '+':
            soma(pnum, pnum2);
            break;

        case '-':
            subtracao(pnum, pnum2);
            break;

        case '*':
            multi(pnum, pnum2);
            break;

        case '/':
            divisao(pnum, pnum2);
            break;

        case '=':
            return *pnum;
            break;
        }
    }
    while(operador != '=');
}

int soma(int *pnum, int *pnum2)
{
    *pnum += *pnum2;
}
int subtracao(int *pnum, int *pnum2)
{
    *pnum -= *pnum2;
}
int multi(int *pnum, int *pnum2)
{
    *pnum *= *pnum2;
}
int divisao(int *pnum, int *pnum2)
{
    *pnum /= *pnum2;
}

void finalizar()
{
     printf("\nDigite X para sair  \n");
        char saida;
        while(saida != 'X' && saida != 'x')
            {
                scanf(" %c", &saida);

                if(saida != 'X' && saida != 'x')
                    {
                        printf("Erro, digite novamente  \n");
                    }
            }

        return;
}

#endif

#ifdef Ex93

/* 3 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa
    usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y                                              */

void finalizar();

int procurar(char *pc, char *pvetor)
{
    int i = -1;

    while(*(pvetor + i))
    {
        i++;
        if(*pc == *(pvetor + i))
        {
            return 1;
        }
    }
}
void main()
{
    char vetorComparar[] = {"bdfhjkmoqsuwy"};
    char *pvetor = &vetorComparar;
    char c, *pc = &c;
    fflush(stdin);

    printf("Digite uma letra: ");
    scanf("%c", pc);

    procurar(pc, pvetor) == 1 ? printf("Iguais") : printf("Diferentes");
    finalizar();

}


void finalizar()
{
     printf("\nDigite X para sair  \n");
        char saida;
        while(saida != 'X' && saida != 'x')
            {
                scanf(" %c", &saida);

                if(saida != 'X' && saida != 'x')
                    {
                        printf("Erro, digite novamente  \n");
                    }
            }
        return;
}




#endif


#ifdef Ex94

/* 4 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato(também numa função).

    estrutura: char, int, long, float, double, unsigned char, unsigned int,
    unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long               */


void finalizar();



struct estrutura
{
    char char1[1];
    int int1;
    long long1;
    float float1;
    double double1;
    unsigned char uchar1[1];
    unsigned int uint1;
    unsigned long ulong1;
};


void varChar(struct estrutura *ponteiro);
void varNum(struct estrutura *ponteiro);
void varUnsigned(struct estrutura *ponteiro);
void imprimir(struct estrutura *ponteiro);

void main()
{

        struct estrutura dados;
        struct estrutura *ponteiro = &dados;

        varChar(ponteiro);
        varNum(ponteiro);
        varUnsigned(ponteiro);
        imprimir(ponteiro);

        finalizar();

}

void varChar(struct estrutura *ponteiro)
{
    fflush(stdin);
    printf("Digite um char: ");
    gets(ponteiro->char1);

    return;

}

void varNum(struct estrutura *ponteiro)
{
    printf("Digite um int: ");
    scanf("%d", &ponteiro->int1);
    printf("Digite um long: ");
    scanf("%ld", &ponteiro->long1);
    printf("Digite um float: ");
    scanf("%f", &ponteiro->float1);
    printf("Digite um double: ");
    scanf("%lf", &ponteiro->double1);

    return;

}

void varUnsigned(struct estrutura *ponteiro)
{
    printf("Digite um unsigned char: ");
    scanf("%s", &ponteiro->uchar1);
    printf("Digite um unsigned int: ");
    scanf("%u", &ponteiro->uint1);
    printf("Digite um unsigned long: ");
    scanf("%lu", &ponteiro->ulong1);

    return;
}

void imprimir(struct estrutura *ponteiro)
{
    printf("        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-1s         %-6d    %-11ld         %-8.1f            %-9.1lf\n", ponteiro->char1, ponteiro->int1, ponteiro->long1, ponteiro->float1, ponteiro->double1);
    printf("          %-1s                   %-5u               %-10lu", ponteiro->uchar1, ponteiro->uint1, ponteiro->ulong1);
    return;

}
void finalizar()
{
     printf("\nDigite X para sair  \n");
        char saida;
        while(saida != 'X' && saida != 'x')
            {
                scanf(" %c", &saida);

                if(saida != 'X' && saida != 'x')
                    {
                        printf("Erro, digite novamente  \n");
                    }
            }

        return;
}

#endif

#ifdef Ex95

struct Registro {
    char nome[50];
    char endereco[100];
    char cidade[50];
    char estado[3];
    char cep[10];
};

void cadastrarRegistros(struct Registro *registros);

void exibirRegistros(struct Registro *registros);

void menu();

int main() {
    typedef struct Registro Registro;
    Registro registros[4], *ptr;
    ptr = &registros[0];
    int opcao;

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarRegistros(registros);
                break;
            case 2:
                exibirRegistros(registros);
                break;
            case 3:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);


    return 0;
}

void cadastrarRegistros(struct Registro *registros) {
    for (int i = 0; i < 4; ++i) {
        printf("\nRegistro %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", registros[i].nome);
        printf("Endereco: ");
        scanf("%s", registros[i].endereco);
        printf("Cidade: ");
        scanf("%s", registros[i].cidade);
        printf("Estado: ");
        scanf("%s", registros[i].estado);
        printf("CEP: ");
        scanf("%s", registros[i].cep);
    }
}

void exibirRegistros(struct Registro *registros) {
    printf("\nRegistros cadastrados:\n");
    for (int i = 0; i < 4; ++i) {
        printf("\nRegistro %d:\n", i + 1);
        printf("Nome: %s\n", registros[i].nome);
        printf("Endereco: %s\n", registros[i].endereco);
        printf("Cidade: %s\n", registros[i].cidade);
        printf("Estado: %s\n", registros[i].estado);
        printf("CEP: %s\n", registros[i].cep);
    }
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Cadastrar registros\n");
    printf("2. Exibir registros\n");
    printf("3. Sair\n");
}



#endif


#ifdef Ex96



struct Registro {
    char nome[50];
    char endereco[100];
    char cidade[50];
    char estado[3];
    char cep[10];
};

void cadastrarRegistros(struct Registro *registros);
void exibirRegistros(struct Registro *registros);
void procurarRegistro(struct Registro *registros);
void alterarRegistro(struct Registro *registros);
void excluirRegistro(struct Registro *registros);
void menu();

int main() {
    typedef struct Registro Registro;
    Registro registros[4], *ptr;
    ptr = &registros[0];
    int opcao;

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarRegistros(registros);
                break;
            case 2:
                exibirRegistros(registros);
                break;
            case 3:
                procurarRegistro(registros);
                break;
            case 4:
                alterarRegistro(registros);
                break;
            case 5:
                excluirRegistro(registros);
                break;
            case 6:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

void cadastrarRegistros(struct Registro *registros) {
    for (int i = 0; i < 4; ++i) {
        printf("\nRegistro %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", registros[i].nome);
        printf("Endereco: ");
        scanf("%s", registros[i].endereco);
        printf("Cidade: ");
        scanf("%s", registros[i].cidade);
        printf("Estado: ");
        scanf("%s", registros[i].estado);
        printf("CEP: ");
        scanf("%s", registros[i].cep);
    }
}

void exibirRegistros(struct Registro *registros) {
    printf("\nRegistros cadastrados:\n");
    for (int i = 0; i < 4; ++i) {
        printf("\nRegistro %d:\n", i + 1);
        printf("Nome: %s\n", registros[i].nome);
        printf("Endereco: %s\n", registros[i].endereco);
        printf("Cidade: %s\n", registros[i].cidade);
        printf("Estado: %s\n", registros[i].estado);
        printf("CEP: %s\n", registros[i].cep);
    }
}

void procurarRegistro(struct Registro *registros) {
    char nome[50];
    printf("Digite o nome para buscar: ");
    scanf("%s", nome);

    for (int i = 0; i < 4; ++i) {
        int j;
        for (j = 0; registros[i].nome[j] != '\0' && nome[j] != '\0'; ++j) {
            if (registros[i].nome[j] != nome[j]) {
                break; // Caracteres diferentes, sair do loop interno
            }
        }

        if (registros[i].nome[j] == '\0' && nome[j] == '\0') {
            printf("\nRegistro encontrado:\n");
            printf("Nome: %s\n", registros[i].nome);
            printf("Endereco: %s\n", registros[i].endereco);
            printf("Cidade: %s\n", registros[i].cidade);
            printf("Estado: %s\n", registros[i].estado);
            printf("CEP: %s\n", registros[i].cep);
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}

void alterarRegistro(struct Registro *registros) {
    char nome[50];
    printf("Digite o nome do registro para alterar: ");
    scanf("%s", nome);

    for (int i = 0; i < 4; ++i) {
        int j;
        for (j = 0; registros[i].nome[j] != '\0' && nome[j] != '\0'; ++j) {
            if (registros[i].nome[j] != nome[j]) {
                break;
            }
        }

        if (registros[i].nome[j] == '\0' && nome[j] == '\0') {
            printf("\nAlterando o registro:\n");
            printf("Novo Nome: ");
            scanf("%s", registros[i].nome);
            printf("Novo Endereco: ");
            scanf("%s", registros[i].endereco);
            printf("Nova Cidade: ");
            scanf("%s", registros[i].cidade);
            printf("Novo Estado: ");
            scanf("%s", registros[i].estado);
            printf("Novo CEP: ");
            scanf("%s", registros[i].cep);
            printf("Registro alterado com sucesso.\n");
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}


void excluirRegistro(struct Registro *registros) {
    char nome[50];
    printf("Digite o nome do registro para excluir: ");
    scanf("%s", nome);

    for (int i = 0; i < 4; ++i) {
        int j;
        for (j = 0; registros[i].nome[j] != '\0' && nome[j] != '\0'; ++j) {
            if (registros[i].nome[j] != nome[j]) {
                break;
            }
        }

        if (registros[i].nome[j] == '\0' && nome[j] == '\0') {
            printf("\nExcluindo o registro:\n");
            registros[i].nome[0] = '\0';
            registros[i].endereco[0] = '\0';
            registros[i].cidade[0] = '\0';
            registros[i].estado[0] = '\0';
            registros[i].cep[0] = '\0';
            printf("Registro excluido com sucesso.\n");
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}


void menu() {
    printf("\nMenu:\n");
    printf("1. Cadastrar registros\n");
    printf("2. Exibir registros\n");
    printf("3. Procurar registro\n");
    printf("4. Alterar registro\n");
    printf("5. Excluir registro\n");
    printf("6. Sair\n");
}


#endif