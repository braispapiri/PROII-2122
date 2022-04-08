/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Brais Fernandez Papiri LOGIN 1: brais.papiri
 * AUTHOR 2: Samanta Karolay Machuca Montalvo LOGIN 2:s.machucam
 * GROUP: 4.3
 * DATE: 08 / 04 / 22
 */

#ifndef BID_STACK_H
#define BID_STACK_H

#include "types.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SNULL NULL

typedef int tItemS;
typedef struct tNodeS *tPosS;

struct tNodeS {
    tItemS data;
    tPosS down;
};

typedef tPosS tStack;

void createEmptyStack(tStack *S);
bool createNode(tPosS *p);
bool push(tItemS d, tStack *S);
void pop(tStack *S);
tItemS peek(tStack S);
bool isEmptyStack(tStack S);

#endif
