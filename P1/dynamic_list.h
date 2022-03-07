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
bool createNode(tPosL*);
bool isEmptyList(tList);
tPosL first(tList);
tPosL last(tList);
tPosL next(tPosL, tList);
tPosL previous(tPosL, tList);
bool insertItem(tItemL, tPosL, tList*);
void deleteAtPosition(tPosL, tList*);
tItemL getItem(tPosL, tList);
void updateItem(tItemL, tPosL, tList*);
tPosL findItem(tProductId, tList);


#endif
