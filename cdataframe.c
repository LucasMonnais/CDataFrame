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
    int value = 0;
    int error = 0;
    for (int i = 0; i<length_line ; i++){
        if(!error){
            for (int j = 0; j < length_column; j++){
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


void print_all_CDataFrame(COLUMN ** CDF,int length_line){
    for (int col = 0; col<length_line; col++){
        print_col(CDF[col]);
    }

}


void print_not_full_column(COLUMN ** CDF, int length_line){
    int limit;
    printf("Saisir la limite de la colonne");
    scanf(" %d", &limit);
    if(0<limit<=length_line){
        for(int i = 0; i < limit; i++){
            printf("[%d]", i);
            print_col(CDF[i]);
        }
    }
    else{
        printf("index Error : limit out of range");
    }
}

void print_not_full_line(COLUMN ** CDF, int length_line){
    int limit;
    printf("Saisir la limite de la ligne");
    scanf(" %d", &limit);
    for (int i = 0; i<length_line; i++){
        if(0<limit<=CDF[i]->TL){
            for(int j = 0; j<limit; j++){
                printf("[%d][%d]  %d \n", i, j,  CDF[i]->donnees[j]);
            }
        }
        else{
            printf("index Error : limit out of range");
            break;
        }
    }
}
