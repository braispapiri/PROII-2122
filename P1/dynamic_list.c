/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Brais Fernandez Papiri LOGIN 1: brais.papiri
 * AUTHOR 2: Samanta Karolay Machuca Montalvo LOGIN 2: s.machucam
 * GROUP: 4.3
 * DATE: 04 / 03 / 21
 */

#include "dynamic_list.h"

void createEmptyList(tList* L) {                                        //Inicializamos la lista
    *L = LNULL;
}

bool isEmptyList(tList L) {                                             //Comprobamos si está vacía
    return L == LNULL;
}

tPosL first(tList L){
    return L;           // L apunta al primer elemento de la lista
}

tPosL last(tList L) {
    tPosL pos;
    for(pos=L; pos->next != LNULL; pos=pos->next);
    return pos;
}

tPosL previous(tPosL pos, tList L) {
    tPosL q;
    for(q=L; q->next != LNULL; q=q->next);
    return q;
}

tPosL next(tPosL pos, tList L) {
    return pos->next;
}

bool createNode(tPosL* p){
    *p = malloc(sizeof(**p));
    return *p != LNULL;
}

bool insertItem(tItemL d, tPosL pos, tList* L) {
    tPosL q, r;             //q --> elemento que queremos insertar
                            //r --> elemento anterior a q
    if(!createNode(&q)){
        return false;
    }else{
        q->data = d;
        q->next = LNULL;
        if(isEmptyList(*L)){
            *L = q;
        }else if(pos == LNULL){         //Si la posicion dada es NULL, añadimos el elemento al final de la lista
            for(r=*L; r->next != LNULL; r = r->next);   //Nos movemos al final de la lista
            r->next = q;
        }else if(pos == *L){    //Insertamos en el primer elemento
            q->next = pos;
            *L = q;
        }else{                  //Insertamos en posicion intermedia
            q->data = pos->data;
            pos->data = d;
            q->next = pos->next;
            pos->next = q;
        }
        return true;
    }
}

void deleteAtPosition(tPosL pos, tList* L) {
    tPosL q;

    if(pos==*L) {                   //Eliminar el primer elemento
        *L =(*L)->next;
    } else {
        if(pos->next == LNULL) {    //Eliminar el ultimo elemento
            for(q=*L; q->next != pos; q= q->next);
            q->next = LNULL;
        } else {                    //Eliminar una posición intermedia
            //Queremos eliminar pos sobreescribiendo con q

            q = pos->next;          //El siguiente de pos a q
            pos->data = q->data;    //Le pasamos el item apuntado por q a pos
            pos->next = q->next;    //El siguiente de q a pos
            pos = q;                //pos ahora tiene la posicion q
        }
        free(pos);          //Liberar memoria
    }
}

tItemL getItem(tPosL pos, tList L) {
    return pos->data;               //Devuelve el contenido del elemento de pos
}

void updateItem(tItemL d, tPosL pos, tList *L) {
    pos->data = d;                  //Le asignamos el valor de nuestro item a pos
}

tPosL findItem(tProductId d, tList L) {
    tPosL p;
    if (L==NULL) return p;
    else {
        for (p=L; (p!=LNULL)&&(strcmp(p->data.productId,d)!=0); p=p->next);
        return p;
    }
}



