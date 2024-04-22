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

    printf("Veuillez saisir les dimensions d'un CDataframe \n ");
    printf("Veuillez saisir le nombre de collones \n ");
    scanf("%d",&length_CDF);
    printf("Veuillez saisir le nombre de lignes \n ");
    scanf("%d",&length_col);

    COLUMN ** MyCDF = create_CDataFrame(length_CDF);


    printf("Veuillez choisir un nombre entre 1 et 2 pour choisir une fonction principale: \n ");
    printf("Option 1:creation d'un CDataframe a vide (constitue de 0)  \n");
    printf("Option 2:remplisage du CDataframe avec des saisies  \n");
    int fonctionprin=0;
    scanf("%d",&fonctionprin);
    if (fonctionprin==1){
        fill_CDataFrame(MyCDF, length_CDF, length_col);
    }
    if (fonctionprin==2){
        user_fill_CDataFrame(MyCDF, length_CDF, length_col);
    }
    int fonctionsec=0;
    int value;
    while (fonctionsec !=1 ){
        printf("Veuillez choisir de choisir un nombre entre 1 et 17 pour choisir une fonction : \n ");
        printf("Option 1:quitter le programme  \n");
        printf("Option 2:Afficher tout le CDataframe  \n");
        printf("Option 3:Afficher une partie des lignes du CDataframe selon une limite fournie par l'utilisateur  \n");
        printf("Option 4:Afficher une partie des colonnes du CDataframe selon une limite fournie par l'utilisateur  \n");
        printf("Option 5:Ajouter une ligne de valeurs au CDataframe  \n");
        printf("Option 6:Supprimer une ligne de valeurs du CDataframe  \n");
        printf("Option 7:Ajouter une colonne au CDataframe  \n");
        printf("Option 8:Supprimer une colonne du CDataframe  \n");
        printf("Option 9:Renommer le titre d'une colonne du CDataframe  \n");
        printf("Option 10:Verifier l'existence d'une valeur (recherche) dans le CDataframe  \n");
        printf("Option 11:Remplacer la valeur se trouvant dans une cellule du CDataframe en utilisant son numero de ligne et de colonnes ");
        printf("Option 12:Afficher les noms des colonnes  \n");
        printf("Option 13:Afficher le nombre de lignes  \n");
        printf("Option 14:Afficher le nombre de colonnes  \n");
        printf("Option 15:Nombre de cellules contenant une valeur egale a x   \n");
        printf("Option 16:Nombre de cellules contenant une valeur superieure a x  \n");
        printf("Option 17:Nombre de cellules contenant une valeur inferieure a x  \n");
        scanf("%d",&fonctionsec);
        if (fonctionsec==1){
            printf("au revoir");
            break;
        }        if (fonctionsec==2){
            print_all_CDataFrame(MyCDF, length_CDF);
        }        if (fonctionsec==3){
            print_not_full_line(MyCDF, length_CDF);
        }        if (fonctionsec==4){
            print_not_full_column(MyCDF, length_CDF);
        }        if (fonctionsec==5){
            printf("veuillez rentrez la valeure que vous voulez ajouter :");
            scanf("%d",&value);
            add_line_of_value(MyCDF, value, length_CDF, &length_col);
        }        if (fonctionsec==6){
            printf("veuillez rentrez le numero de ligne que vous voulez supprimer :");
            scanf("%d",&value);
            del_line_of_value(MyCDF , value, length_CDF);
        }        if (fonctionsec==7){
            add_column(MyCDF,&length_CDF,length_col);
        }        if (fonctionsec==8){
            del_column(MyCDF, &length_CDF);
        }        if (fonctionsec==9){
            change_name(MyCDF,length_CDF);
        }        if (fonctionsec==10){
            search_value_CDF(MyCDF, length_CDF);
        }        if (fonctionsec==11){
            replace_value(MyCDF , length_CDF);
        }        if (fonctionsec==12){
            print_all_title(MyCDF,length_CDF);
        }        if (fonctionsec==13){
            affiche_nb_lignes (length_col);
        }        if (fonctionsec==14){
            affiche_nb_col (length_CDF);
        }        if (fonctionsec==15){
            nombre_occurence_in_CD(MyCDF,length_CDF);
        }        if (fonctionsec==16){
            nombre_valeurs_supperieures_in_CD(MyCDF,length_CDF);
        }
        if (fonctionsec==17){
            nombre_valeurs_inferieures_in_CD(MyCDF,length_CDF);
        }
    }





    //COLUMN ** MyCDF = create_CDataFrame(length_CDF);
    //user_fill_CDataFrame(MyCDF, length_CDF, length_col);
    //fill_CDataFrame(MyCDF, length_CDF, length_col);
    //print_all_CDataFrame(MyCDF, length_CDF);
    //print_not_full_line(MyCDF, length_CDF);
    //print_not_full_column(MyCDF, length_CDF);
    //add_column(MyCDF, &length_CDF, length_col);
    //del_column(MyCDF, &length_CDF);
    //change_name(MyCDF, length_CDF);
    //search_value_CDF(MyCDF, length_CDF);
    //print_all_title(MyCDF, length_CDF);
    //add_line_of_value(MyCDF , 5, length_CDF, &length_col);
    //print_all_CDataFrame(MyCDF, length_CDF);
    //del_line_of_value(MyCDF, 2, length_CDF);
    //print_all_CDataFrame(MyCDF, length_CDF);

    //replace_value(MyCDF , length_CDF);
    //affiche_nb_col(length_CDF);
    //affiche_nb_lignes(length_col);
    //int nbocctot = nombre_valeurs_inferieures_in_CD(MyCDF,length_CDF);
    return 0;

}




