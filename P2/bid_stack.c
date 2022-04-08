/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */


#include "bid_stack.h"

void createEmptyStack(tStack *S) {          //Inicializamos la pila
    *S = SNULL;
}

bool createNode(tPosS *p) {
    *p = malloc(sizeof(struct tNodeS));
    return (*p != SNULL);
}

bool push(tItemS d, tStack *S) {        //Añade un elemento a la pila
    tPosS aux;

    if (!(createNode(&aux))) {
        return false;
    } else {
        aux->data = d;
        aux->down = *S;
        *S = aux;
        return true;
    }
}

void pop(tStack *S) {                   //lee y retira el elemento superior de la pila
    tPosS aux;

    aux = *S;
    *S = (*S)->down;
    free(aux);
}

tItemS peek(tStack S) {                 //lee el elemento superior de la pila
    return S->data;
}

bool isEmptyStack(tStack S) {           //devuelve cierto si la pila está sin elementos
    return (S == SNULL);                                    // o falso en caso de que contenga alguno
}
