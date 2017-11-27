#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void NomEntrada(int *n, char nome[][50]){


    int i = 0;
    int j = 0;

    char temp;

    while(i < 20){

        fgets(nome[i], sizeof nome[i], stdin);

        if(strcmp(nome[i],"\n") == 0){
            break;
        }
        i++;
    }

    *(n) = i;

}

void MatrizEntrada(int n, int matriz[][6]){

    int i = 0;
    int j = 0;
    while(i < n){
        while(j < 4){
            scanf("%d", &matriz[i][j]);
            j++;
        }
        j = 0;
        i++;
    }
}

void processamento(int n, int matriz[][6]){

    int i = 0;

    //pontos ganhos(PG):
    while(i < n){
        matriz[i][4] = 2*matriz[i][0] + matriz[i][1];
        i++;
    }

    i = 0;
    //saldo de gols:
     while(i < n){
        matriz[i][5] = matriz[i][2] - matriz[i][3];
        i++;
    }

}

void Saida(int n, int matriz[][6], char nome[][50]){

     int i = 0;
     int j = 0;

     while(i < n){

        nome[i][strcspn(nome[i],"\n")] = 0;//eliminando o caractere terminal da string

        printf("%s", nome[i]);

        while(j < 6){

            printf("\t%d", matriz[i][j]);
            j++;
        }
        j = 0;
        printf("\n");
        i++;
    }

}

int main()
{
    //definicao de variaveis e entrada de dados:

    int n = 0;

    char nome[20][50];

    NomEntrada(&n,nome);

    int matriz[n][6];

    MatrizEntrada(n,matriz);

    //processamento:

    processamento(n,matriz);

    //saida:

    Saida(n,matriz,nome);

    getch();

}
