#include <stdio.h>
#include "column.h"

/* bonne chance a nous (36 pages :) */
int main() {
    COLUMN *mycol = create_column("My column");
    //printf("%s", mycol->titre);
    int test = 5;
    for (int i = 0; i<270;i++) {
        int verification = insert_value(mycol, i);
        printf("%d\n", mycol->donnees[i]);
    }
    //delete_column(&mycol);
    print_col(mycol);
    for (int i = 0; i<100;i++) {
        int verification = insert_value(mycol, (i-10));
    }
    //print_col(mycol);
    //int nombre = nombre_occurence(mycol, 6);
    //printf("%d", nombre);
    //recherche_position(mycol, 126);
    //printf("%d", nombre_valeurs_inferieures(mycol, 45));
    return 0;

}




