#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int HORIZ,VERT = 0;
const int M,N = 9;
int grid[9][9] = {0};

/*
Pour l'exercice vous aurez besoin de generer des entiers al�atoire : rand() renvoit un entier al�atoire.
il s'utilise : rand() % NOMBREMAX + 1
Pour un entier al�atoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/



// Ecrire la fonction generer(), elle prend en param�tre la grille et renvoie le nombre d'�l�ments non nuls
int generer(){
    int count = 0;
    for (int j=0;j<9;j++){
        for (int i=0;i<9;i++){
            if (grid[j][i] == 0){
                count++;
            }
        }
    }

    return count;
}


/*�crire une fonction saisir() qui demande � l�utilisateur de saisir au clavier les indices i et j et la valeur v � placer � l�emplacement (i,j).
La fonction doit v�rifier la validit� des indices et de la valeur.
Si la case n�est pas occup�e, la valeur doit �tre plac�e dans la grille. remplissage est alors incr�ment�e*/
void saisir(){
    int i,j,v = 0;
    printf("\nVeuillez saisir le numero de colonne : ");
    scanf("%d", &i);
    printf("\nVeuillez saisir le numero de ligne : ");
    scanf("%d", &j);
    printf("\nVeuillez saisir la valeur a affecter : ");
    scanf("%d", &v);

    if (i < 0 || i > 8 || j < 0 || j > 8 || v < 0 || v > 9){
        printf("\nERREUR veuillez entrer une valeur valide (entre 0 et 9) : ");
        saisir(grid);
    }
    else if (grid[i][j] == 0){
        grid[i][j] = v;
        //remplissage++;
    }
}


/*
�crire la fonction verifierLigneColonne() qui prend en param�tre un num�ro et un sens (HORIZ ou VERT)
qui v�rifie que la ligne ou la colonne (suivant les cas) num�ro est bien remplie.
On pourra utiliser un tableau interm�diaire pour v�rifier cela. La fonction retournera 1 si tout s�est bien pass�, 0 sinon.
*/
int verifierLigneColonne(int num,int sens,int ch){
    if (sens == VERT){
        for (int i=0;i<9;i++){
            if (grid[num][i] == ch){
                return 0;
            }
        }
        return 1;
    }
    else if (sens == HORIZ){
       for (int i=0;i<9;i++){
            if (grid[i][num] == ch){
                return 0;
            }
        }
        return 1;
    }
}

/*
�crire la fonction verifierRegion() qui prend en param�tre deux indices k et l qui correspondent � la r�gion (k,l)
et qui renvoie 1 si la r�gion est correctement remplie, 0 sinon.
*/
int verifierRegion(int k,int l, int ch){
    for (int j=0;j<3;j++){
        for (int i=0;i<3;i++){
            if (grid[k+j][l+i] == ch){
                return 0;
            }
        }
    }
    return 1;
}

//�crire la fonction verifierGrille() qui renvoie 1 si la grille est correctement remplie et 0 sinon
int verifierGrille(){
    if (generer()==0){return 1;}
    for (int l=0;l<9;l++){
        for (int c=0;c<9;c++){
            if (grid[l][c] == 0){
                for (int i=1;i<=9;i++){
                    if (verifierRegion(l - (l%3),c - (c%3),i) == 1 && verifierLigneColonne(l,HORIZ,i)== 1 && verifierLigneColonne(c,VERT,i)== 1) {
                        grid[l][c] = i;
                        if (verifierGrille() == 1){return 1;}
                        grid[l][c] = 0;
                    }
                }
            }
        }
    }
    return 0;
}

//�crire le programme principal, en supposant que la seule condition d�arr�t est la r�ussite du sudoku (ce test ne devra �tre fait que si n�cessaire)


int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    int solution[9][9];

    printf("SOLUTION");
    printf("\n");
    printf("---------------------------------");
    printf("\n");
    for(j=0;j<9; ++j)
    {
    for(i=0; i<9; ++i)
        solution[j][i] = (i + j*3 +j /3) %9 +1 ;
    }

    for(i=0;i<9; ++i)
    {
    for(j=0; j<9; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");
    }
    printf("---------------------------------");
    printf("\n");
    //toucher le code entre les commentaires
    printf("SUDOKU : ");
    printf("\n");
    printf("---------------------------------");
    printf("\n");

    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            grid[i][j] = ((rand() % 10) < 4) ? 0:solution[i][j];
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------------");
    printf("\n");
    printf("REPONSE : ");
    printf("\n");
    printf("---------------------------------");
    printf("\n");
    if (verifierGrille(grid) == 1){
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    else{printf("Aucune solution disponible... :(\n");}
    printf("---------------------------------");
    printf("\n");

    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}
