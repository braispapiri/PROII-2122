/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Brais Fernandez Papiri LOGIN 1: brais.papiri
 * AUTHOR 2: Samanta Karolay Machuca Montalvo LOGIN 2: s.machucam
 * GROUP: 4.3
 * DATE: 11 / 03 / 21
 */

#include "static_list.h"
#include <string.h>


void createEmptyList(tList* L){
    L->posicion = LNULL;                                //Inicializamos la lista
}

bool isEmptyList(tList L){
    return L.posicion == LNULL;                         //Comprobamos que esté vacía
}

bool insertItem(tItemL item, tPosL pos, tList* L){
    tPosL p;

    if(L->posicion == MAX-1){
        return false;
    }else{
        L->posicion++;
        if(pos == LNULL){
            L->item[L->posicion+1] = item;
        }else{
            for(p=L->posicion; p>= pos+1; p--){
                L->item[p] = L->item[p-1];
            }
            L->item[pos] = item;
        }
        return true;
    }
}

void updateItem(tItemL item, tPosL pos, tList* L){
    L->item[pos] = item;                            //Le asignamos el valor del item
}

void deleteAtPosition(tPosL pos, tList* L){
    tPosL p;

    L->posicion--;
    for(p = pos; p<=L->posicion; p++){
        L->item[p] = L->item[p+1];
    }
}

tPosL findItem(tProductId d, tList L){
    tPosL p=0;
    tItemL prod;

    while((p!=LNULL)&&(p<MAX)){
        prod=getItem(p, L);
        if((strcmp(prod.productId, d))==0){
            return p;
        }
        p=next(p, L);
    }
    return LNULL;
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
    if(pos == last(L))          //Si es la última posición, no hay siguiente
        return LNULL;                   //Devuelve LNULL
    else
        return ++pos;           //Devuelve el siguiente a la posición de entrada
}

