/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Brais Fernandez Papiri LOGIN 1: brais.papiri
 * AUTHOR 2: Samanta Karolay Machuca Montalvo LOGIN 2: s.machucam
 * GROUP: 4.3
 * DATE: 04 / 03 / 21
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#define LNULL NULL


typedef struct tNode * tPosL;

struct tNode{
    tItemL data;
    tPosL next;
};

typedef tPosL tList;


void createEmptyList(tList*);
/*
 * Objetivo: Crea una lista vacía.
 * Salidas: La lista vacía.
 * PostCD:  La lista queda inicializada y no contiene elementos.
*/
bool isEmptyList(tList);
bool createNode(tPosL*);
/*
 * Objetivo: Comprueba si hay memoria para la variable apuntada e inicializa el valor del puntero a la dirección de esa zona de memoria.
 * Entradas:
 * Salidas: True or false.
 /*

bool isEmptyList(tList);
/*
 * Objetivo: Comprobar si la lista está vacía.
 * Salidas: La lista vacía.
 * PostCD: Lista vacía comprobada y lista para inicializar.
*/
tPosL first(tList);
/*
 * Objetivo: Devolver la posición del primer elemento de la lista.
 * Salidas:
 * PostCD:
*/
tPosL last(tList);
/*
 * Objetivo: Crea una lista vacía.
 * Salidas: la lista vacía.
 * PostCD: PostCD: La lista queda inicializada y no contiene elementos.
*/
tPosL next(tPosL, tList);
/*
 * Objetivo: Crea una lista vacía.
 * Salidas: la lista vacía.
 * PostCD: PostCD: La lista queda inicializada y no contiene elementos.
*/
tPosL previous(tPosL, tList);
/*
 * Objetivo: Crea una lista vacía.
 * Salidas: la lista vacía.
 * PostCD: PostCD: La lista queda inicializada y no contiene elementos.
*/
bool insertItem(tItemL, tPosL, tList*);
/*
 Objetivo: Inserta un elemento en la lista antes de la posición indicada. Si la posición es LNULL, entonces se añade al final.
 Devuelve un valor true si el elemento fue insertado; false en caso contrario.

 -Entradas:                                      -Salidas:
    tItemL - item a insertar                        tList - la lista modificada
    tPosL - posicion donde queremos insertarlo      bool - para saber si se insertó correctamente
    tList - la lista
 -PreCD:
    La posición indicada es una posición válida en la lista o bien nula (LNULL)
 -PostCD:
    Las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haber variado.
*/
void deleteAtPosition(tPosL, tList*);
/*
 * Objetivo: Crea una lista vacía.
 * Salidas: la lista vacía.
 * PostCD: PostCD: La lista queda inicializada y no contiene elementos.
*/
tItemL getItem(tPosL, tList);
/*
 * Objetivo: Crea una lista vacía.
 * Salidas: la lista vacía.
 * PostCD: PostCD: La lista queda inicializada y no contiene elementos.
*/
void updateItem(tItemL, tPosL, tList*);
/*
 * Objetivo: Crea una lista vacía.
 * Salidas: la lista vacía.
 * PostCD: PostCD: La lista queda inicializada y no contiene elementos.
*/
tPosL findItem(tProductId, tList);
/*
 * Objetivo: Crea una lista vacía.
 * Salidas: la lista vacía.
 * PostCD:
*/

#endif
