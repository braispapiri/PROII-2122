/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Brais Fernandez Papiri LOGIN 1: brais.papiri
 * AUTHOR 2: Samanta Karolay Machuca Montalvo LOGIN 2: s.machucam
 * GROUP: 4.3
 * DATE: 04 / 03 / 21
 */

#include "dynamic_list.h"

void createEmptyList(tList* L) {                //Inicializamos la lista
    *L = LNULL;
}

bool isEmptyList(tList L) {                   //Comprobamos si la lista está vacía
    if (L == LNULL) {
        return true;
    } else return false;
}

bool createNode(tPosL* p){               //comprueba si se puede reservar memoria, si no existe memoria suficiente
    *p = malloc(sizeof(**p));           //para reservar el operador asigna nulo al puntero
    return *p != LNULL;
}

bool insertItem(tItemL item, tPosL pos, tList* L) {            //inserta un elemento en la lista antes de la posición indicada.
    tPosL q, r;                                                //q --> elemento que queremos insertar, r --> elemento anterior a q

    if(!createNode(&q)){
        return false;
    }else{                                                 //si no hay memoria suficiente devuelve false
        q-> data = item;                                      //sino asigna una nueva variable dinámica
        q-> next = LNULL;
        if(*L== LNULL){
            *L = q;
        }else if(pos == LNULL){                          //Si la posicion dada es NULL, añadimos el elemento al final de la lista
            for(r=*L; r-> next != LNULL; r = r-> next);   //Nos movemos al final de la lista
            r-> next = q;
        }else if(pos == *L){                            //Insertamos en el primer elemento
            q-> next = pos;
            *L = q;
        }else{                                         //Insertamos en posicion intermedia
            q-> data = pos-> data;
            pos->data = item;
            q-> next = pos-> next;
            pos-> next = q;
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
        free(pos);                  //Liberar memoria
    }
}

tItemL getItem(tPosL pos, tList L) {                //Devuelve el contenido del elemento de pos
    return pos->data;
}

void updateItem(tItemL d, tPosL pos, tList *L) {    //Le asignamos el valor de nuestro item a pos
    pos->data = d;
}

tPosL findItem(tProductId d, tList L) {             //Devuelve la posición del primer elemento de la lista que se corresponda con el indicado
    tPosL p;                                        //o nulo si no existe dicho elemento
    if (isEmptyList(L))
        p = LNULL;
    else {
        for (p=L; (p!=LNULL)&&(strcmp(p->data.productId,d)!=0); p=p->next);
        return p;
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




