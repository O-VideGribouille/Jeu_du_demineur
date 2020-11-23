#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE 6 // une ligne et un col serviron pour l'affichage, le reste pour le jeu
#define NBm 3
#define VALMIN 1
#define VALMAX 5

/* FEATURE :
- Afficher plateau de jeu
- Position aléatoire des mines
- Selectionner des coordonnées (x,y)
- Affichage des cases prochent des mines par des chiffres
- Fin du jeu si selection coordonnée mine
*/

//PROTOTYPES
//void afficheplateau(char *afficheplateau, char plateauJ[][]);
void afficheplateau(char plateau2[TAILLE][TAILLE]);
void selectCoor(char plateau[TAILLE][TAILLE], char plateau2[TAILLE][TAILLE], int *Mines);
void Initplateau(char plateau2[TAILLE][TAILLE]);
void randomMine(int placeMines, char plateau[TAILLE][TAILLE]);


int main()
{
    char plateau2[TAILLE][TAILLE]={{Initplateau},{Initplateau}};
    char plateau[TAILLE][TAILLE]={{Initplateau},{Initplateau}};
    //char plateauJ[][];
    //int caze;
    //int cazeNum;
    //int score;
    int placeMines;
    int Mines=NBm;

    //char affichage; // sert pour le visuel du plateau du jeu
    char selectC;

    printf("Jeu du demineur\n");

    //afficheplateau(&affichage, plateauJ[][]);
   afficheplateau(plateau2);

    srand(time(0));
    randomMine(placeMines, plateau2);



    //while(mine==3){
        selectCoor(&selectC);

   // }
    return 0;
}

void randomMine(int placeMines,char plateau[TAILLE][TAILLE]){

    do{
    int i;

    for(i=0;i<NBm;i++){
    //genere trois postion aléatoire pour les mines
            int MineX=(rand()%(VALMAX-VALMIN+1))+VALMIN;
           // printf(" %d, ",MineX);

            int MineY=(rand()%(VALMAX-VALMIN+1))+VALMIN;
           // printf("%d \n",MineY);

            plateau[MineX][MineY]=('M');
    }
    }while(plateau[MineX][MineY]!=('M'));
}


//void afficheplateau(char *afficheplateau, char plateau2[][]){
void Initplateau(char plateau2[TAILLE][TAILLE]){
    int i, j;

    for(i = 1; i < TAILLE; i++){
            if(i==0){
                plateau2[i][j]=j+'0';
            }
    }
        for(j = 0; j < TAILLE; j++){
            if(j==0){
                plateau2[i][0]=i+'0';
                printf("%4d|",plateau2[i][j]);
                printf("\n");
            }
            else{
            printf("-|");
            }
        }


    printf("\n");
}

void afficheplateau(char plateau2[TAILLE][TAILLE]){
    int i;
    int j;
    //int nbi=0;
    //int nbj=1;

    //V2

    for(i = 1; i < TAILLE; i++){
        printf("\n");
        for(j = 0; j < TAILLE; j++){
            if(i==0||j==0){
                printf("%4d|",plateau2[i][j]);//%4d sert a creer une marge
            }
            else{
            printf("-|");
            }
        }
    }
    printf("\n");
}


void selectCoor(char plateau[TAILLE][TAILLE], char plateau2[TAILLE][TAILLE],int *Mines){
    int x=0;
    int y=0;

    printf("\nEntrez les coordonnees de x : ");
    scanf("%d",&x);
    printf("\nEntrez les coordonnees de y : ");
    scanf("%d",&y);

    if(plateau2[x][y]=='M'){
        (*Mines)--;
        printf("\nFin du jeu");
    }

    else{
        plateau2[x][y]=plateau[x][y];//revoir application d'affichage
        printf("\nEt on continue_n");
    }



}
