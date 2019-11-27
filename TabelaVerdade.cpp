#include<stdio.h>
#include<string.h>

#define TRUE              1
#define FALSE             0

// macro para calcular o valor da implicacao
#define IMP(b1, b2)       (b1 && !b2 ? FALSE : TRUE)

// numero de variaveis proposicionais na formula
#define VARS              3

// constantes para os indices das tres variaveis
#define P                 0
#define Q                 1
#define R                 2

// representacao da formula
char nome[VARS];     // nome das variaveis
int I[VARS];         // interpretacao das variaveis

struct gateLogic
{
    char name[100]; //nome da porta logica
};
struct input  // quantidade de entradas do circuit
{
    int qntdEntrada;
};
struct conecEnt  // // linhas que entram na porta
{
    int entrada;
};
struct conecSai
{
    int linhasaida; // linha que sai
};
struct output
{
    char saidas;
};

void porta_and()
{
    int matriz[3][2];
    int i=0;
    while(i < 2)
    {
        matriz[i][0]=0;
        i++;
    }
    while(i < 4)
    {
        matriz[i][0]=1;
        i++;
    }
    i=0;
    while (i<4)
    {
        if(i%2==0)
        {
            matriz[i][1]=0;
        }
        else
        {
            matriz[i][1]=1;
        }
        i++;
    }
    i=0;
    ////////SAIDA DA AND //////////
    while(i<4)
    {
        if(i==3)
        {
            matriz[i][2]=1;
        }
        else
        {
            matriz[i][2]=0;
        }
        i++;
    }
}


void porta_or()
{
    int matriz[3][2];
    int i=0;
    while(i < 2)
    {
        matriz[i][0]=0;
        i++;
    }
    while(i < 4)
    {
        matriz[i][0]=1;
        i++;
    }
    i=0;
    while (i<4)
    {
        if(i%2==0)
        {
            matriz[i][1]=0;
        }
        else
        {
            matriz[i][1]=1;
        }
        i++;
    }
    i=0;
    ////////SAIDA DA OR //////////
    while(i<4)
    {
        if(i==0)
        {
            matriz[i][2]=0;
        }
        else
        {
            matriz[i][2]=1;
        }
        i++;
    }
}

void port_nand()
{
    int matriz[3][2];
    int i=0;
    while(i < 2)
    {
        matriz[i][0]=0;
        i++;
    }
    while(i < 4)
    {
        matriz[i][0]=1;
        i++;
    }
    i=0;
    while (i<4)
    {
        if(i%2==0)
        {
            matriz[i][1]=0;
        }
        else
        {
            matriz[i][1]=1;
        }
        i++;
    }
    i=0;
    ////////SAIDA DA NAND//////////
    while(i<4)
    {
        if(i==3)
        {
            matriz[i][2]=0;
        }
        else
        {
            matriz[i][2]=1;
        }
        i++;
    }
}

void porta_nor()
{
    int matriz[3][2];
    int i=0;

    while(i < 2)
    {
        matriz[i][0]=0;
        i++;
    }
    while(i < 4)
    {
        matriz[i][0]=1;
        i++;
    }
    i=0;
    while (i<4)
    {
        if(i%2==0)
        {
            matriz[i][1]=0;
        }
        else
        {
            matriz[i][1]=1;
        }
        i++;
    }
    i=0;
    ////////SAIDA DA NOR//////////
    while(i<4)
    {
        if(i==0)
        {
            matriz[i][2]=1;
        }
        else
        {
            matriz[i][2]=0;
        }
        i++;
    }
}

void porta_xor()
{
    int matriz[3][2];
    int i=0;
    while(i < 2)
    {
        matriz[i][0]=0;
        i++;
    }
    while(i < 4)
    {
        matriz[i][0]=1;
        i++;
    }
    i=0;
    while (i<4)
    {
        if(i%2==0)
        {
            matriz[i][1]=0;
        }
        else
        {
            matriz[i][1]=1;
        }
        i++;
    }
    i=0;
    ////////SAIDA DA XOR

    while(i<4)
    {
        if(i==0 || i==3)
        {
            matriz[i][2]=0;
        }
        else
        {
            matriz[i][2]=1;
        }
        i++;
    }
}

void porta_not()
{
    int matriz[2][2];
    int i=0;

    matriz[0][0]=0;
    matriz[1][0]=1;
    matriz[0][1]=1;
    matriz[1][1]=0;
}

void inicializa_formula()
{
  nome[P] = 'P';
  nome[Q] = 'Q';
  nome[R] = 'R';

  for (int c = 0; c < VARS; c++)
    I[c] = FALSE;
}

// retorna TRUE se a interpretacao atual eh a ultima na tabela-verdade
int ultima_interpretacao()
{
  int res = 1;

  for (int c = 0; c < VARS; c++) {
    res = res && I[c];
  }

  return res;
}

// altera a interpretacao atual no array I[] para a proxima na
// ordem da tabela-verdade
void proxima_interpretacao()
{
  int c = VARS - 1;

  while (c >= 0 && I[c] != 0) {
    I[c--] = 0;
  }

  if (c >= 0)
    I[c] = 1;
}

int valor_formula()
{
  return IMP(I[P], I[Q]) && (I[Q] || (!I[R]));
}

void mostra_tabela()
{
  int fim = FALSE;

  inicializa_formula();

  for (int c = 0; c < VARS; c++) {
    printf(" %c |", nome[c]);
  }
  printf(" H\n");

  for (int c = 0; c < 4 * VARS + 3; c++)
    printf("-");
  printf("\n");

  while (!fim) {
    // imprime valores atuais das variaveis
    for (int c = 0; c < VARS; c++) {
      if (I[c])
        printf(" 1 |");
      else
        printf(" 0 |");
    }

    // calcula e imprime o valor da formula
    if (valor_formula())
      printf(" 1\n");
    else
      printf(" 0\n");

    // verifica se acabou a tabela ou passa para
    // a proxima linha
    if (ultima_interpretacao())
      fim = TRUE;
    else
      proxima_interpretacao();
  }
}
int main()
{
    int n,i;
    struct input qntd[5];
    struct gateLogic nome;
    struct conecEnt entradas[20];
    struct conecSai saida[20];



  FILE *pont_arq;
  char texto[100];

  //abrindo o arquivo em modo "somente leitura"
  pont_arq = fopen("ArqTeste.txt", "r");

  //enquanto não for fim de arquivo o looping será executado
  //e será impresso o texto
  while(fgets(texto, 100, pont_arq) != NULL)
  printf("%s", texto);

  //fechando o arquivo
  fclose(pont_arq);


    return 0;
}