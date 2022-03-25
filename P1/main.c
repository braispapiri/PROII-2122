/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif


void New(tProductId productId, tUserId seller, tProductCategory productCategory, tProductPrice productPrice, tList* L) { //struct tItemL productId
    /*
        * OBJETIVO: añadir un nuevo ítem a la lista de usuarios
        * ENTRADA: el nick del que se pretende que sea el nuevo ítem, su categoría y la lista a modificar
        * SALIDA: una lista con el nuevo item si no existía o la misma lista sin modificar
        * PRECONDICIÓN: la lista tiene que estar inicializada
    */


    tPosL pos;
    tItemL item;

    if (((pos = last(*L)) == LNULL)) {

        item = getItem(pos, *L);
        strcpy(item.productId, productId);
        strcpy(item.seller, seller);

        item.productPrice = productPrice;
        item.bidCounter = 0;
        item.productCategory=productCategory;


        if (item.productCategory == painting){
            printf("* New: product %s seller %s category painting price %.2f\n", item.productId, item.seller,item.productPrice);
            insertItem(item, pos, L);
        }
        else if(item.productCategory == book) {
            printf("* New: product %s seller %s category book price %.2f\n", item.productId, item.seller,item.productPrice);
            insertItem(item, pos, L);
        }
    } else {
        printf("+ Error: New not possible\n");
    }

}




void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4) {

    switch (command) {
        case 'N':
            printf("Command: %s %c %s %s %s %s\n", commandNumber, command, param1, param2, param3, param4);
            break;
        case 'S':
            break;
        case 'B':
            break;
        case 'D':
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}






