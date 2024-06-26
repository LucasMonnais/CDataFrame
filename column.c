//
// Created by anton on 28/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "column.h"


COLUMN *create_column(char* title){

    COLUMN* create = malloc(sizeof(COLUMN));
    create->titre = title;
    create->TP = 256;
    create->TL = 0;
    create->donnees = NULL;

    return create;
}


int insert_value(COLUMN* col, int value){
    if (col->donnees == NULL) {
        col->donnees = malloc(col->TP * sizeof(int));
        if(col->donnees == NULL){
            return 0; //imposibilité d'allouer de la mémoire = manque de mémoire
        }
    }
    if (col->TP == col->TL){
        col->TP += 256;
        int* temp = realloc(col->donnees, col->TP * sizeof(int));
        if (temp == NULL){
            return 0;
        }
        else{
            col->donnees = temp;
        }


    }
    col->donnees[col->TL] = value;
    col->TL++;
    return 1;

}


void delete_column(COLUMN **col){
    free((*col)->donnees);
    (*col)->donnees = NULL;
    free(*col);
    *col = NULL;
}



void print_col(COLUMN* col){
    for (int i = 0; i<col->TL ;i++) {
        printf("[%d]  %d \n", i,  col->donnees[i]);
    }
}

int nombre_occurence(COLUMN* col, int x){
    int occ = 0;
    for (int i = 0; i<col->TL ;i++) {
        if (x == col->donnees[i] ){
            occ++;
        }
    }
    return occ;
}

int recherche_position(COLUMN* col, int x){

    printf("[%d]  %d \n", x,  col->donnees[x]);

}

int nombre_valeurs_supperieures(COLUMN* col, int x){
    int occ = 0;
    for (int i = 0; i<col->TL ;i++) {
        if (x < col->donnees[i] ){
            occ++;
        }
    }
    return occ;
}

int nombre_valeurs_inferieures(COLUMN* col, int x){
    int occ = 0;
    for (int i = 0; i<col->TL ;i++) {
        if (x > col->donnees[i] ){
            occ++;
        }
    }
    return occ;
}

int delete_ligne(COLUMN* col, int number_ligne){
    if( number_ligne+1> col->TL){
        return 0;
    }
    else{
        for (int i = number_ligne; i<col->TL -1; i++){
            col->donnees[i]= col->donnees[i+1];
        }
        col->TL --;
        return 1;
    }
}

int replace(COLUMN* col, int position, int value){
    if (position>col->TL - 1){
        return 0;
    }
    else {
        col->donnees[position]= value;
        return 1;
    }
}