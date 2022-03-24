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


void createEmptyList (tList*);
/*
 * Objetivo: Crea una lista vacía.
 * Salidas: La lista vacía.
 * PostCD: La lista queda inicializada y no contiene elementos.
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

tPosL findItem(tProductId , tList);
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
bool isEmptyList(tList);
/*
 * Objetivo: Determina si la lista está vacía.
 *
 * Entradas:
 *      tList - la lista
 *
 * Salidas:
 *      bool - devuelve true o false
*/
tItemL getItem(tPosL, tList);               //Devuelve el contenido del elemento de la lista que ocupa la posición indicada.
/*
 * Objetivo:
 * Entradas:
 * Salidas:
 *
 */
tPosL first(tList);                         //Devuelve la posición del primer elemento de la lista.
/*
 * Objetivo del procedimiento/función.
 *Entradas (identificador y breve descripción, una por línea).
 * Salidas (identificador y breve descripción, una por línea).
 * Precondiciones (condiciones que han de cumplir las entradas para el correcto funcionamiento de la subrutina).
 * Postcondiciones otras consecuencias de la ejecución de la subrutina que no quedan reflejadas en la descripción del objetivo o de las salidas
 */
tPosL last(tList);                          //Devuelve la posición del último elemento de la lista.

tPosL previous(tPosL, tList);               //Devuelve la posición en la lista del elemento anterior a la posicion indicada (o LNULL si la posición no tiene anterior)

tPosL next(tPosL, tList);                   //Devuelve la posición en la lista del elemento siguiente a la posicion indicada (o LNULL si la posición no tiene siguiente)

#endif
