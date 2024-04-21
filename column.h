//
// Created by anton on 28/03/2024.
//

#ifndef UNTITLED_COLUMN_H
#define UNTITLED_COLUMN_H

typedef struct {
    char *titre;
    int TL;
    int TP;
    int *donnees;
}COLUMN;

/**
* Create a column
* @param1 : Column title
* @return : Pointer to created column
*/
COLUMN *create_column(char* title);

/**
* @brief : Add a new value to a column
* @param1 : Pointer to a column
* @param2 : The value to be added
* @return : 1 if the value is added 0 otherwise
*/
int insert_value(COLUMN* col, int value);

/**
* @brief : Free allocated memory
* @param1 : Pointer to a column
*/
void delete_column(COLUMN **col);

/**
* @brief: Print a column content
* @param: Pointer to a column
*/
void print_col(COLUMN* col);

int nombre_occurence(COLUMN* col, int );

int recherche_position(COLUMN* col, int );

int nombre_valeurs_supperieures(COLUMN* col, int x);

int nombre_valeurs_inferieures(COLUMN* col, int x);

int delete_ligne(COLUMN* col, int number_ligne);

int replace(COLUMN* col, int position, int value);
#endif //UNTITLED_COLUMN_H







