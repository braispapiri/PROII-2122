/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Brais Fernandez Papiri LOGIN 1: brais.papiri
 * AUTHOR 2: Samanta Karolay Machuca Montalvo LOGIN 2:s.machucam
 * GROUP: 4.3
 * DATE: 08 / 04 / 22
 */

#ifndef PRODUCT_LIST_H
#define PRODUCT_LIST_H

#include "types.h"

typedef struct nodo{
    tItemL ti;
    tPosL posi;
    struct nodo * sig;
};

void createEmptyList(tList*);
bool isEmptyList(tList);
tPosL first(tList);
tPosL last(tList);
tPosL next(tPosL, tList);
tPosL previous(tPosL, tList);
bool insertItem(tItemL item, tList* L);
void deleteAtPosition(tPosL pos, tList L);
tItemL getItem(tPosL, tList);
void updateItem(tItemL, tPosL, tList*);
tPosL findItem(tProductId, tList);

#endif
