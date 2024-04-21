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


void add_column(COLUMN ** CDF,int *length_line, int length_col){
    (*length_line)++;
    int error = 0;
    COLUMN * temp = realloc(*CDF, *length_line);
    if(temp == NULL){
        printf("Allocation Error : Error during column insertion");
    }
    else{
        *CDF = temp;
        CDF[*length_line-1] = create_column("A" );
        for(int j = 0; j<length_col; j++){
            int check = insert_value(CDF[*length_line], 0);
            if(!check){
                printf("Allocation Error : Error during value insertion");
                break;
            }
        }
    }
}



void del_column(COLUMN ** CDF, int *length_line){
    int del_col;
    printf("Donner la colonne à supprimer : ");
    scanf(" %d", &del_col);
    if (0 < del_col && del_col < *length_line){
        int i = del_col;
        while (i<*length_line-1){
            for (int j = 0; j<CDF[i]->TL; j++){
                CDF[i]->donnees[j] = CDF[i+1]->donnees[j];
            }
            i++;
        }
        delete_column(&CDF[*length_line]);
        (*length_line)--;
    }
    else{
        printf("This column does not exist");
    }

}

void change_name(COLUMN ** CDF, int length_line){
    int col;
    printf("choisir la colonne");
    scanf(" %d", &col);
    if (0 < col && col < length_line){
        char new_title[256];
        printf("choisir le nouveau nom");
        gets(new_title);
        CDF[col]->titre = new_title;
    }
    else{
        printf("This column does not exist");
    }
}

void search_value_CDF(COLUMN ** CDF, int length_line){
    int value;
    int found = 0;
    printf("Quelle valeur cherchez-vous ? ");
    scanf(" %d", &value);
    for(int i = 0; i<length_line; i++){
        for(int j = 0; j<CDF[i]->TL; j++){
            if (CDF[i]->donnees[j] == value){
                printf("found at coord [%d][%d]\n", i, j);
                found = 1;
            }
        }
    }
    if(!found){
        printf("%d not found", value);
    }

}

void print_all_title(COLUMN ** CDF, int length_line){
    for(int i = 0; i<length_line; i++){
        printf("[%d] %s\n", i, CDF[i]->titre);
    }
}



void add_line_of_value(COLUMN ** CDF , int value, int length_line, int *length_col){
    for (int col = 0; col<length_line; col++){

        insert_value(CDF[col], value);
        (*length_col)++;

    }
}

void del_line_of_value(COLUMN ** CDF , int num_ligne, int length_line){
    int verif;
    for (int col = 0; col<length_line; col++){

        verif =delete_ligne(CDF[col], num_ligne);
        if (verif== 0){
            printf("la ligne %d n'existe pas pour la colonne %d \n", num_ligne, col);
        }
    }
}

void replace_value(COLUMN ** CDF , int length_CDF){
    int ncol, line, value;
    printf("veuillez saisir le numero de la colonne a modifier: ");
    scanf("%d", &ncol);
    printf("veuillez saisir le numero de la ligne a modifier: ");
    scanf("%d", &line);
    printf("veuillez saisir la nouvelle valeure: ");
    scanf("%d", &value);
    if (length_CDF< ncol ){
        printf("cette colonne n'existe pas \n");
    }
    else {
        int verification = replace(CDF[ncol], line, value);
        if (verification == 0) {
            printf("cette ligne n'existe pas dans cette colonne \n");
        }

    }
}


// 4 analyse et statistique

void affiche_nb_lignes (int length_col){
    printf("le CDataframe est constitue de %d ligne \n", length_col+ 1);
}

void affiche_nb_col (int length_CDF){
    printf("le CDataframe est constitue de %d colonne \n", length_CDF);
}

int nombre_occurence_in_CD(COLUMN ** CDF,int length_line){
    int value;
    printf("veuillez saisir la valeur chercher dans le CDataframe: ");
    scanf("%d", &value);
    int nboccurencetot =0;
    for (int col = 0; col<length_line; col++){
        nboccurencetot += nombre_occurence(CDF[col], value);
    }
    printf("La valeur %d apparait %d fois \n", value, nboccurencetot);
    return nboccurencetot;
}

int nombre_valeurs_superieures_in_CD(COLUMN ** CDF,int length_line){
    int value;
    printf("veuillez saisir la valeure chercher dans le CDataframe: ");
    scanf("%d", &value);
    int nboccurencesup =0;
    for (int col = 0; col<length_line; col++){
        nboccurencesup += nombre_valeurs_supperieures(CDF[col], value);
    }
    printf("il y a %d nombre superieurs a %d \n", nboccurencesup, value);
    return nboccurencesup;
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