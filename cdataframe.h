//
// Created by monna on 19/04/2024.
//

#ifndef UNTITLED_CDATAFRAME_H
#define UNTITLED_CDATAFRAME_H
COLUMN ** create_CDataFrame(int length);
void user_fill_CDataFrame(COLUMN ** CDF, int length_line, int length_column);
void fill_CDataFrame(COLUMN ** CDF, int length_line, int length_column);
void print_all_CDataFrame(COLUMN ** CDF,int length_line);
void print_not_full_column(COLUMN ** CDF, int length_line);
void print_not_full_line(COLUMN ** CDF, int length_line);
void add_ligne_of_value(COLUMN ** CDF , int value, int length_line, int *length_col);
void del_ligne_of_value(COLUMN ** CDF, int num_ligne, int length_line);
void replace_value(COLUMN ** CDF , int length_CDF);
void affiche_nb_lignes (int length_col);
void affiche_nb_col (int length_CDF);
int nombre_occurence_in_CD(COLUMN ** CDF,int length_line);
int nombre_valeurs_supperieures_in_CD(COLUMN ** CDF,int length_line);
int nombre_valeurs_inferieures_in_CD(COLUMN ** CDF,int length_line);
#endif //UNTITLED_CDATAFRAME_H
