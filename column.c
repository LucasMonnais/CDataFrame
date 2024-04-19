//
// Created by anton on 28/03/2024.
//
#include <stdlib.h>
#include "column.h"

/**
* Create a column
* @param1 : Column title
* @return : Pointer to created column
*/
COLUMN *create_column(char* title){

    COLUMN* create = malloc(sizeof(COLUMN));
    create->titre = title;
    create->TP = 256;
    create->TL = 0;
    create->donnees = NULL;

    return create;
}
