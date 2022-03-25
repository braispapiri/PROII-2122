/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Brais Fernandez Papiri LOGIN 1: brais.papiri
 * AUTHOR 2: Samanta Karolay Machuca Montalvo LOGIN 2:s.machucam
 * GROUP: 4.3
 * DATE: 11 / 03 / 21
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

/*
* OBJETIVO: añadir un nuevo ítem a la lista de usuarios
* ENTRADA: el nick del que se pretende que sea el nuevo ítem, su categoría y la lista a modificar
* SALIDA: una lista con el nuevo item si no existía o la misma lista sin modificar
* PRECONDICIÓN: la lista tiene que estar inicializada
*/
void New(tProductId productId, tUserId seller, tProductCategory productCategory, tProductPrice productPrice, tList* L) { //struct tItemL productId

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
            printf("New: product %s seller %s category painting price %.2f\n", item.productId, item.seller,item.productPrice);
            insertItem(item, pos, L);
        }
        else if(item.productCategory == book) {
            printf("New: product %s seller %s category book price %.2f\n", item.productId, item.seller,item.productPrice);
            insertItem(item, pos, L);
        }
    } else {
        printf("+ Error: New not possible\n");
    }

}

/*
* OBJETIVO: baja de un producto
* ENTRADA: id del producto y lista
* SALIDA: si se busca el producto en la lista, se borrará e imprimirá el mensaje de borrado si no existiese imprimirá un error.
 */
void delete(tProductId productId, tList* L){
    tPosL pos;
    tItemL aux;

        if((pos = findItem(productId, *L)) != NULL){
            aux = getItem(pos, *L);
            if(aux.productCategory == 0){
                printf("Delete: product %s seller %s category book price %.2f bids %d\n", aux.productId, aux.seller, aux.productPrice, aux.bidCounter);
            }else if(aux.productCategory == 1){
                printf("Delete: product %s seller %s category painting price %.2f bids %d\n", aux.productId, aux.seller, aux.productPrice, aux.bidCounter);
                deleteAtPosition(pos, L);
            }
        }else{
            printf("Error: Delete not possible");
        }
}

/*
*
* OBJETIVO: Listado de los productos actuales y sus datos
* ENTRADA: la lista
* SALIDA: la lista completa de productos actuales con su categoria de producto, el numero de productos y la suma de todos los productos de dicha categoria y el precio medio
*pero si estuviese vacia imprimiria un mensaje de error.
 */
void Stats(tList L) {
    tPosL pos;
    tItemL item;

    if (!isEmptyList(L)) {
        pos = first(L);
        while (pos != LNULL) {
            item = getItem(pos, L);
            if (item.productCategory == 0) {
                printf("Product %s seller %s category book price %.2f bids %d\n\n", item.productId, item.seller,
                       item.productPrice, item.bidCounter);
            } else if (item.productCategory == 1) {
                printf("Product %s seller %s category painting price %.2f bids %d\n\n", item.productId, item.seller,
                       item.productPrice, item.bidCounter);
            }
            pos = next(pos, L);
        }
    } else if (isEmptyList(L)) {
        printf("Error: Stats not possible");
    }

    pos = first(L);
    tProductPrice total, avg;

    while(pos!= LNULL){
        item = getItem(pos, L);

        if(item.productCategory == 0){
            int book = 0;
            float totalB = 0;
            float avgB;

            totalB += item.productPrice;
            book++;
            avgB = totalB / (float)book;
            printf("Category  Products    Price  Average\n");
            printf("Book      %8d %8.2f %8.2f\n", book, totalB, avgB);
        }
        else if(item.productCategory==1){
            int painting = 0;
            float totalP=0;
            float avgP;

            totalP += item.productPrice;
            painting++;
            avgP = totalP/(float)painting;
            printf("Category  Products    Price  Average\n");
            printf("Painting  %8d %8.2f %8.2f\n", painting, totalP, avgP);
        }
        pos = next(pos, L);
    }
}

/*
 * Objetivo: Puja por un determinado producto
 * Entrada: lista de productos
 * Salida: se muestra el producto con el precio y contador de pujas actualizadas.
 * Si no existiese ningún producto con ese identificador, si el vendedor del producto es el mismo que el pujador o si el precio de la puja no es superior al precio actual, se imprimirá error.
 */
void Bid(tList* L, tProductPrice productPrice, tProductId productId, tUserId userId) {
    tPosL pos;
    tItemL aux;

    if ((pos = findItem(productId, *L)) != LNULL) {
        aux = getItem(pos, *L);
        aux.productPrice = productPrice;
        aux.bidCounter = aux.bidCounter + 1;

        updateItem(aux, pos, L);
        if (aux.productCategory == 0) {
            printf("Bid:product %s seller %s category book price %.2f bids %d\n", aux.productId, aux.seller,
                   aux.productPrice, aux.bidCounter);
        }else if (aux.productCategory == 1) {
            printf("Bid: product %s seller %s category painting price %.2f bids %d\n", aux.productId, aux.seller,
                   aux.productPrice, aux.bidCounter);
        }else {
            printf("Error: Bid not possible");
        }
    }
}

void processCommand(char *cn, char c, tProductId productId, tUserId userId, tProductCategory productCategory, tProductPrice productPrice, tList *L) {

    switch (c) {
        case 'N':
            printf("%s %c: product %s seller %s category %c price %.2f\n", cn, c, productId, userId, productCategory, productPrice);
            New(productId, userId, productPrice, productCategory, L);
            break;
        case 'S':
            printf("%s %c", cn, c);
            Stats(*L);
            break;
        case 'B':
            printf("%s %c: product %s bidder %s price %.2fn\n", cn, c, productId, userId, productPrice);
            Bid(L, productPrice, productId, userId);
            break;
        case 'D':
            printf("%s %c: product %s\n", cn, c, productId);
            delete(productId, L);
            break;
        default:
            printf("%c is not a valid command\n", c);
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *cn, *c, *productId, *userId, *productCategory;
    float productPrice;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];
    tList L;
    tProductCategory wt;

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            cn = strtok(buffer, delimiters);
            c = strtok(NULL, delimiters);

            if(*c == 'N'){
                productId = strtok(NULL, delimiters);
                userId = strtok(NULL, delimiters);
                productCategory = strtok(NULL, delimiters);
                productPrice = atof(strtok(NULL, delimiters));
            }else if (*c == 'S'){
                productId = "p1";
                userId = "user1";
                productCategory = "painting";
                productPrice = 150;
            }else if(*c == 'D'){
                productId = strtok(NULL, delimiters);
                userId = "user1";
                productCategory = "painting";
                productPrice = 150;
            }else if(*c == 'B'){
                productId = strtok(NULL, delimiters);
                userId = strtok(NULL, delimiters);
                productCategory = "painting";
                productPrice = atof(strtok(NULL, delimiters));
            }
            if(strcmp(productCategory, "book") == 0)
                wt = book;
            else if (strcmp(productCategory, "painting") == 0)
                wt = painting;

            processCommand(cn, c[0], productId, userId, wt,productPrice, L);
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

