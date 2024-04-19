#include <stdio.h>
#include "column.h"
/* bonne chance a nous (36 pages :) */
int main() {
    printf("Hello, World!\n");
    COLUMN *mycol = create_column("My column");
    printf("%s", mycol->titre);
    return 0;

}




