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
 * Salidas:
 *          tList - La lista vacía.
 * PostCD:  La lista queda inicializada y no contiene elementos.
*/

bool createNode(tPosL*);
/*
 * Objetivo: Comprueba si hay memoria para la variable apuntada e inicializa el valor del puntero a la dirección de esa zona de memoria.
 * Entradas:
 *          tPosL* - puntero
 * Salidas: True or false.
 */

bool isEmptyList(tList);
/*
 * Objetivo: Determina si la lista está vacía.
 *
 * Entradas:
 *          tList - la lista
 *
 * Salidas:
 *          bool - devuelve true o false
*/

tPosL first(tList);
/*
 * Objetivo: Devuelve la posición del primer elemento de la lista.
 * Entradas:
 *          tList - lista
 * Salidas:
 *          tPosL - posicion actualizada
 * PreCD: La lista no está vacía.
 */

tPosL last(tList);
/*
 * Objetivo: Devuelve la posición del último elemento de la lista.
 * Entradas:
 *           tList - lista
 * Salidas:
 *          tPosL - posicion actualizada
 *PreCD: La lista no está vacía.
 */

tPosL next(tPosL, tList);
/*
 * Objetivo: Devuelve la posición en la lista del elemento siguiente al de la posición indicada (o LNULL si la posición no tiene siguiente).
 * Entradas:
 *          tPosL - posicion
 *          tList - lista
 * Salidas:
 *          tPosL - posición actualizada
 *PreCD: La posición indicada es una posición válida en la lista.
 */

tPosL previous(tPosL, tList);
/*
 * Objetivo: Devuelve la posición en la lista del elemento anterior al de la posición indicada (o LNULL si la posición no tiene anterior).
 * Entradas:
 *           tPosL - posicion
 *           tList - lista
 * Salidas:
 *          tPosL - posición actualizada
 *PreCD: La posición indicada es una posición válida en la lista.
 */

bool insertItem(tItemL, tPosL pos, tList*);
/*
Objetivo: Inserta un elemento en la lista antes de la posición indicada. Si la posición es LNULL, entonces se añade al final.
Devuelve un valor true si el elemento fue insertado; false en caso contrario.

Entradas:                                      Salidas:
    tItemL - item a insertar                        tList - la lista modificada
    tPosL - posicion donde queremos insertarlo      bool - para saber si se insertó correctamente
    tList - la lista

PreCD: La posición indicada es una posición válida en la lista o bien nula (LNULL)
PostCD: Las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haber variado.
*/

void deleteAtPosition(tPosL, tList*);
/*
 * Objetivo: Elimina de la lista el elemento que ocupa la posición indicada.
 *
 * Entradas:
 *      tPosL - la posicion
 *      tList - la lista
 *
 * Salidas:
 *      tList - la lista actualizada
 *
 * PreCD: La posición indicada es una posición válida en la lista.
 *
 * PostCD: Las posiciones de los elementos de la lista posteriores a la de la posición eliminada pueden haber variado.
 */

tItemL getItem(tPosL, tList);
/*
 * Objetivo: Devolver el contenido del elemento de la lista que ocupa la posición indicada.
 * Entradas:
 *           tPosL - posición
 *           tList - lista
 * Salidas: tItemL
 *PreCD: La posición indicada es una posición válid en la lista.
 */

void updateItem(tItemL, tPosL, tList*);
/*
 * Objetivo: Modifica el contenido del elemento situado en la posición indicada.
 *
 * Entradas:
 *      tItemL - el item a actualizar
 *      tPosL - la posicion
 *      tList - la lista
 *
 * Salidas:
 *      tList - la lista actualizada
 *
 * PreCD: La posición indicada es una posición válida en la lista.
 *
 * PostCD: El orden de los elementos de la lista no se ve modificado.
 */

tPosL findItem(tProductId, tList);
/*
 * Objetivo: Devuelve la posición del primer elemento de la lista cuyo identificador
 * de producto se corresponda con el indicado (o LNULL si no existe tal elemento).
 *
 * Entradas:
 *      tProductId - identificador del elemento a buscar
 *      tList - la lista
 *
 * Salidas:
 *      tPosL - la posicion del elemento buscado
 */

#endif
