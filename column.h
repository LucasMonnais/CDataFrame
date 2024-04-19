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

#endif //UNTITLED_COLUMN_H





