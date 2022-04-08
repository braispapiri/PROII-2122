/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Brais Fernandez Papiri LOGIN 1: brais.papiri
 * AUTHOR 2: Samanta Karolay Machuca Montalvo LOGIN 2: s.machucam
 * GROUP: 4.3
 * DATE: 11 / 03 / 22
 */

#include "static_list.h"
#include <string.h>


void createEmptyList(tList* L){
    L-> posicion = LNULL;                                //Inicializamos la lista
}

bool isEmptyList(tList L){
    if (L.posicion == LNULL){                       //se comprueba la lista si es cierto o falso
        return true;
    } else return false;
}

bool insertItem(tItemL item, tList* L){                //insercion(desplazar elemento)
    tPosL p;
    tItemL  item2;
    item2 = L->item[L->posicion];


    if(L->posicion == MAX-1){                       //comprobamos si hay espacio
        return false;                               //si no hay devuelve false y no se hace nada
    }else{
        if (isEmptyList(*L) == true || strcmp(item.productId, item2.productId) > 0) {
            L->posicion++;
            L->item[L->posicion] = item;
        }
        else {
            L->posicion++;                          //añadimos al final de la lista
            for (p = L->posicion-1; p >= 0 || strcmp(item.productId, item2.productId) > 0; p--) {
                item2 = L->item[p];
                L->item[p+1] = L->item[p];
                if (strcmp(item.productId, item2.productId) > 0) {
                    L->item[p+1] = item;
                    break;
                }
                else if(p == 0){                //si la pos es = 0
                    L->item[p] = item;          //sale el mismo item
                    break;
                }
            }
        }
        return true;

    }
}

void updateItem(tItemL item, tPosL pos, tList* L){
    L->item[pos] = item;                            //Le asignamos el valor del item
}

void deleteAtPosition(tPosL pos, tList* L){
    tPosL p;
                                                        //eliminamos de la lista el elemento que ocupa la posición indicada
    L->posicion--;
    for(p = pos; p< L->posicion; p++)
        L->item[p] = L->item[p+1];


}

tPosL findItem(tProductId id, tList L){                     //devuelve la pos del primer elemento de la lista cuyo
    tPosL p;                                                //identificador de producto se corresponda con el indicado
    tItemL item2 = L.item[L.posicion];                      //o nulo si no existe dicho elemento

    if(isEmptyList(L) == true)
        return LNULL;
    else{
        for (p = L.posicion; p >= 0 || strcmp(id, item2.productId) > 0; p--){
            item2 = L.item[p];
            if(p <= L.posicion && ((strcmp(id, item2.productId))==0))
                return p;
        }
        return LNULL;
    }
}


tItemL getItem(tPosL pos, tList L){
    return L.item[pos];                         //Devuelve el contenido del elemento de pos
}

tPosL first(tList L){
    return 0;                                   //Apunta al primer elemento de la lista
}

tPosL last(tList L){
    return L.posicion;                          //Apunta al último elemento de la lista
}

tPosL previous(tPosL pos, tList L){
    return --pos;                               //Apunta al elemento anterior a la posicion de entrada
}

tPosL next(tPosL pos, tList L){
    if(pos == last(L))                   //Si es la última posición, no hay siguiente
        return LNULL;                       //Devuelve LNULL
    else
        return ++pos;                       //Devuelve el siguiente a la posición de entrada
}

