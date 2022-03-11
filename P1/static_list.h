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
bool insertItem(tItemL, tPosL, tList*);
void updateItem(tItemL, tPosL, tList*);
void deleteAtPosition(tPosL, tList*);
tPosL findItem(tProductId , tList);
bool isEmptyList(tList);
tItemL getItem(tPosL, tList);
tPosL first(tList);
tPosL last(tList);
tPosL previous(tPosL, tList);
tPosL next(tPosL, tList);

#endif
