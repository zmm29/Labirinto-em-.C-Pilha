#include <stdio.h>
#include "pilhaEncadeada.h"
#include <stdlib.h>
#define MAX 15


void cria(char l[MAX][MAX]){
    int i,j,x,y;
    srand(time(NULL));
    for(i=0;i<MAX;i++){
        for (j=0; j<MAX;j++) {
        if ((rand()%5) == 1){
            l[i][j]='|';
        } else {
        l[i][j]='.';
        }
    }
}
    
    for(i=0;i<MAX;i++){
        l[0][i]='*';
        l[MAX-1][i]='*';
        l[i][0]='*';
        l[i][MAX-1]='*';
    }
    
	x=  rand() % MAX;
    y=  rand() % MAX;
    l[x][y]='Q';
}
     
void mostraLab(char mat[MAX][MAX],int linha,int col){
    int i,j;
    for (i=0;i<linha;i++){
        printf("\n");
        for (j=0;j<col;j++){
        printf(" %c ",mat[i][j]);
        }
    }
}
     
 int functionRato(char lab[MAX][MAX],int i, int j){

    tpilha linha, coluna;
    inicializa(& linha);
    inicializa(&coluna);
     
// while para percorrer as direções...
     while (lab[i][j] != 'Q'){
        lab[i][j] = 'R';

        if (lab[i][j+1]=='.' || lab[i][j+1]=='Q'){
            push(&linha, i);
            push(&coluna, j);
            j++;
        } else if(lab[i+1][j]=='.' || lab[i+1][j]=='Q'){
            push(&linha, i);
            push(&coluna, j);
            i++;
        } else if(lab[i][j-1]=='.' || lab[i][j-1]=='Q'){
            push(&linha, i);
            push(&coluna, j);
            j--;
        } else if (lab[i - 1][j]=='.' || lab[i-1][j]=='Q'){
            push(&linha, i);
            push(&coluna, j);
            i--;
        } else {
            if(!isEmpty(linha) && !isEmpty(coluna)){
            lab[i][j] = 'x';
            i = pop(&linha);
            j = pop(&coluna);
        } else {
            printf("\nQueijo nao encontrado, o rato vai morrer de fome :(\n");
            return;
            }
        }

        Sleep(200);
        system("cls");
        mostraLab(lab, MAX, MAX);
     }
	printf("\nO rato vai encher a barriga! Queijo encontrado na posicao: \nlinha: %i\ncoluna: %i\n", i, j);
 }



int main(){
    char lab[MAX][MAX];
    int x,y;
    cria(lab);
    mostraLab(lab,MAX,MAX);
    printf("\nLinha inicial? ");
    scanf_s("%i",&x);
    printf("\nColuna inicial? ");
    scanf_s("%i", &y);
    functionRato(lab, x, y);
    getch();
}
