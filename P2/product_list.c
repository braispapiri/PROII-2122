/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Brais Fernandez Papiri LOGIN 1: brais.papiri
 * AUTHOR 2: Samanta Karolay Machuca Montalvo LOGIN 2:s.machucam
 * GROUP: 4.3
 * DATE: 08 / 04 / 22
 */

#include "product_list.h"

//tList lista de productos ordenada alfabeticamente
//tItemL datos de un elemento de la lista
//tPosL posicion de un elemento de la lista de productos
//LNULL cte usada para indicar posiciones nulas de la lista


void createEmptyList(tList *L){
    *L = LNULL;
}

bool isEmptyList(tList L){
    return (L == LNULL);
}

bool createNode (tPosL *p) {
    *p = malloc(sizeof(struct tNode));
    return *p != LNULL;
}

tPosL findPosition(tList L, tItemL item) {
    tPosL p;

    p=L;
    while ((p->next != LNULL) && (p->next->data < item)) {
        p = p->next;
    } return p;
}

bool insertItem(tItemL item, tList *L){

    tPosL q, p;

    if (!createNode(&q)) {
        return false;
    } else {
        q->data = item;
        q->next = LNULL;

        if (isEmptyList(*L)) {
            *L = q;
        } else if (item < (*L)->data) {
            q->next = *L;
            *L = q;
        } else {
            p = findPosition(*L, item);
            q->next = p->next;
            p->next = q;
        }
        return true;
    }
}

void deleteAtPosition(tPosL pos, tList* L) {

    tPosL q;
    if (p == *L) {
        *L = (*L)->next;
    } else if (p->next == LNULL) {
        for (q = *L; q->next->next != p; q = q->next);
        q->next LNULL;
    } else {
        q = p->next;
        p->data = q->data;
        p->next = q->next;
        p = q;
    }
    free(p);
}


tItemL getItem(tPosL pos, tList L) {                //Devuelve el contenido del elemento de pos
    return pos->data;
}

void updateItem(tItemL item, tPosL pos, tList *L) {    //Le asignamos el valor de nuestro item a pos
    pos->data = d;
}

tPosL findItem(tItemL d, tList L) {             //Devuelve la posición del primer elemento de la lista que se corresponda con el indicado
    tPosL p;                                        //o nulo si no existe dicho elemento

    for (p=L; (p!=LNULL) && (p->data < d); p=p->next);
    if(p != LNULL && p->data == d){
        return p;
    }else{
        return LNULL;
    }
}

tPosL first(tList L){                       // la lista apunta al primer elemento de ésta
    return L;
}

tPosL last(tList L) {                       //la lista devuelve la posición del último elemento
    tPosL pos;
    for(pos=L; pos->next != LNULL; pos=pos->next);
    return pos;
}

tPosL previous(tPosL pos, tList L) {        //muestra la posición del anterior elemento al de la posición indicada
                                            //dicha posición está dentro de la lista.
    tPosL q;

    if(pos==L){
        q = LNULL;
    }else{
        for(q=L; q->next != pos; q=q->next);
    }
    return q;
}

tPosL next(tPosL pos, tList L) {            //devuelve la posición del siguiente elemento de la posición indicada o
    return pos->next;                      //o devuelve nulo si la posición no tiene siguiente.

}
