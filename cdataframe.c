//
// Created by monna on 19/04/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "cdataframe.h"



COLUMN ** create_CDataFrame(int length){
    COLUMN ** CDataFrame = malloc(length*sizeof(COLUMN*));
    for (int i = 0; i<length; i++ ){
        CDataFrame[i] = create_column("A" ); // trouver un moyen de faire changer le titre : mettre indice
    }
    return CDataFrame;
}

void user_fill_CDataFrame(COLUMN ** CDF, int length_line, int length_column){
    int value;
    int error = 0;
    for (int i = 0; i<length_line ; i++){
        if(!error){
            for (int j = 0; j < length_column; j++){
                printf("Saisir la valeur [%d] [%d] :", i, j);
                scanf(" %d", &value);

                if(!(insert_value(CDF[i], value))){
                error = 1;
                break;
                }
            }
        }
    }
    if (error){
        printf("Allocation Error : CDataFrame is not filled due to an error during insertion");
    }
}



void fill_CDataFrame(COLUMN ** CDF, int length_line, int length_column){
    int error = 0;
    for (int i = 0; i<length_line ; i++){
        if(!error){
            for (int j = 0; j < length_column; j++){
                if(!(insert_value(CDF[i], 0))){
                    error = 1;
                    break;
                }
            }
        }
    }
    if (error){
        printf("Allocation Error : CDataFrame is not filled due to an error during insertion");
    }
}


void print_all_CDataFrame(COLUMN ** CDF,int length_line){
    for (int col = 0; col<length_line; col++){
        print_col(CDF[col]);
    }

}


void print_not_full_column(COLUMN ** CDF, int length_line){
    int limit;
    printf("Saisir la limite de la colonne : ");
    scanf(" %d", &limit);
    if(0<limit && limit<=length_line){
        for(int i = 0; i < limit; i++){
            printf("[i = %d]\n", i);
            print_col(CDF[i]);
        }
    }
    else{
        printf("index Error : limit out of range\n");
    }
}

void print_not_full_line(COLUMN ** CDF, int length_line){
    int limit;
    printf("Saisir la limite de la ligne : ");
    scanf(" %d", &limit);
    for (int i = 0; i<length_line; i++){
        if(0<limit && limit<=CDF[i]->TL){ //ne fonctionne pas réellement pour cette fonction
            for(int j = 0; j<limit; j++){
                //printf("a : %d", CDF[i]->TL);
                printf("[%d][%d]  %d \n", i, j,  CDF[i]->donnees[j]);
            }
        }
        else{
            printf("index Error : limit out of range\n");
            break;

        }
    }
}

/*
void add_column(COLUMN ** CDF,int *length_line, int length_col){
    (*length_line)++;
    int error = 0;
    COLUMN ** temp = realloc(CDF, *length_line * sizeof(COLUMN) );
    if(temp == NULL)
    CDF[*length_line-1] = create_column("A" );
    for(int j = 0; j<length_col; j++){
        insert_value(CDF[*length_line], 0);
    }

}
*/
void add_ligne_of_value(COLUMN ** CDF , int value, int length_line, int *length_col){
    for (int col = 0; col<length_line; col++){

        insert_value(CDF[col], value);
        length_col++;

    }
}

void del_ligne_of_value(COLUMN ** CDF , int num_ligne, int length_line){
    int verif;
    for (int col = 0; col<length_line; col++){

        verif =delete_ligne(CDF[col], num_ligne);
        if (verif== 0){
            printf("la ligne %d n'existe pas pour la collone %d \n", num_ligne, col);
        }
    }
}

void replace_value(COLUMN ** CDF , int length_CDF){
    int ncol, line, value;
    printf("veuillez saisir le numero de la collone a modifier: ");
    scanf("%d", &ncol);
    printf("veuillez saisir le numero de la ligne a modifier: ");
    scanf("%d", &line);
    printf("veuillez saisir la nouvelle valeure: ");
    scanf("%d", &value);
    if (length_CDF< ncol ){
        printf("cette collone n'existe pas \n");
    }
    else {
        int verification = replace(CDF[ncol], line, value);
        if (verification == 0) {
            printf("cette ligne n'existe pas dans cette collone \n");
        }

    }
}


// 4 analyse et statistique

void affiche_nb_lignes (int length_col){
    printf("le CDataframe est constitue de %d ligne \n", length_col+ 1);
}

void affiche_nb_col (int length_CDF){
    printf("le CDataframe est constitue de %d collone \n", length_CDF);
}

int nombre_occurence_in_CD(COLUMN ** CDF,int length_line){
    int value;
    printf("veuillez saisir la valeure chercher dans le CDataframe: ");
    scanf("%d", &value);
    int nboccurencetot =0;
    for (int col = 0; col<length_line; col++){
        nboccurencetot += nombre_occurence(CDF[col], value);
    }
    printf("La valeur %d apparait %d fois \n", value, nboccurencetot);
    return nboccurencetot;
}

int nombre_valeurs_supperieures_in_CD(COLUMN ** CDF,int length_line){
    int value;
    printf("veuillez saisir la valeure chercher dans le CDataframe: ");
    scanf("%d", &value);
    int nboccurencesupp =0;
    for (int col = 0; col<length_line; col++){
        nboccurencesupp += nombre_valeurs_supperieures(CDF[col], value);
    }
    printf("il y a %d nombre superieurs a %d \n", nboccurencesupp, value);
    return nboccurencesupp;
}

int nombre_valeurs_inferieures_in_CD(COLUMN ** CDF,int length_line){
    int value;
    printf("veuillez saisir la valeure chercher dans le CDataframe: ");
    scanf("%d", &value);
    int nboccurencesinf =0;
    for (int col = 0; col<length_line; col++){
        nboccurencesinf += nombre_valeurs_inferieures(CDF[col], value);
    }
    printf("il y a %d nombre inferieures a %d \n", nboccurencesinf, value);
    return nboccurencesinf;
}