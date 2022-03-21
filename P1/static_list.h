/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Brais Fernandez Papiri LOGIN 1: brais.papiri
 * AUTHOR 2: Samanta Karolay Machuca Montalvo LOGIN 2: s.machucam
 * GROUP: 4.3
 * DATE: 11 / 03 / 21
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
#include <stdbool.h>

#define LNULL -1
#define MAX 1000

typedef int tPosL;
typedef struct {
    tItemL item[MAX];
    tPosL posicion;
}tList;


void createEmptyList (tList*);              //Crea una lista vacía.

bool insertItem(tItemL, tPosL, tList*);     //Inserta un elemento en la lista antes de la posición indicada. Si la posición es LNULL, entonces se añade al final.
                                            //Devuelve un valor true si el elemento fue insertado; false en caso contrario.

void updateItem(tItemL, tPosL, tList*);

void deleteAtPosition(tPosL, tList*);       //

tPosL findItem(tProductId , tList);

bool isEmptyList(tList);                    //Determina si la lista está vacía

tItemL getItem(tPosL, tList);

tPosL first(tList);                         //Devuelve la posición del primer elemento de la lista.

tPosL last(tList);                          //Devuelve la posición del último elemento de la lista.

tPosL previous(tPosL, tList);               //Devuelve la posición en la lista del elemento anterior a la posicion indicada (o LNULL si la posición no tiene anterior)

tPosL next(tPosL, tList);                   //Devuelve la posición en la lista del elemento siguiente a la posicion indicada (o LNULL si la posición no tiene siguiente)

#endif
