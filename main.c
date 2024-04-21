#include <stdio.h>
#include "column.h"
#include "cdataframe.h"

/* bonne chance a nous (36 pages :) */
int main() {
 /*
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
    */



    int length_CDF = 5;
    int length_col = 2;
    COLUMN ** MyCDF = create_CDataFrame(length_CDF);
    //user_fill_CDataFrame(MyCDF, length_CDF, length_col);
    fill_CDataFrame(MyCDF, length_CDF, length_col);
    //print_all_CDataFrame(MyCDF, length_CDF);
    //print_not_full_line(MyCDF, length_CDF);
    //print_not_full_column(MyCDF, length_CDF);
    add_ligne_of_value(MyCDF , 5, length_CDF, &length_col);
    print_all_CDataFrame(MyCDF, length_CDF);
    //del_ligne_of_value(MyCDF, 2, length_CDF);
    //print_all_CDataFrame(MyCDF, length_CDF);

    //replace_value(MyCDF , length_CDF);
    //affiche_nb_col(length_CDF);
    //affiche_nb_lignes(length_col);
    int nbocctot = nombre_valeurs_inferieures_in_CD(MyCDF,length_CDF);
    return 0;

}




