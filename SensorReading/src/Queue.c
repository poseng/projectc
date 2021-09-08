/*
 * Queue.c
 *
 *  Created on: Sep 7, 2021
 *      Author: poseng
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "Queue.h"

/* Constructor and Deconstructor */
void Queue_Init(Queue *const me, int (*isFullfunction)(Queue *const me),
		int (*isEmptyfunction)(Queue *const me),
		int (*getSizefunction)(Queue *const me),
		void (*insertfunction)(Queue *const me, int k),
		int (*removefunction)(Queue *const me)) {
	/*initialize attributes*/
	me->head = 0;
	me->size = 0;
	me->tail = 0;
	/*initialize member function pointers*/
	me->isFull = isFullfunction;
	me->isEmpty = isEmptyfunction;
	me->getSize = getSizefunction;
	me->insert = insertfunction;
	me->remove = removefunction;
}

/*operation CleanUp*/
void Queue_CleanUp(Queue *const me) {
	/*empty at the moment*/
}
/* Operations */
/* operation isFull()*/
int Queue_isFull(Queue *const me) {
	return (me->head + 1) % QUEUE_SIZE == me->tail;
}
/* operation isEmpty()*/
int Queue_isEmpty(Queue *const me) {
	return (me->head == me->tail);
}
/* operation getSize()*/
int Queue_getSize(Queue *const me) {
	return me->size;
}
/* operation insert(int k)*/
void Queue_insert(Queue *const me, int k) {
	if (!me->isFull(me)) {
		me->buffer[me->head] = k;
		me->head = (me->head + 1) % QUEUE_SIZE;
		++me->size;
	}
}
/* operation remove*/
int Queue_remove(Queue *const me) {
	int value = -9999; /*sentinel value*/
	if (!me->isEmpty(me)) {
		value = me->buffer[me->tail];
		me->tail = (me->tail + 1) % QUEUE_SIZE;
		--me->size;
	}
	return value;
}
/*Operation create or constructor implementation*/
Queue* Queue_Create(void){
	Queue * me = (Queue *)malloc(sizeof(Queue));
	if (me != NULL){
		Queue_Init(me, Queue_isFull, Queue_isEmpty, Queue_getSize, Queue_insert, Queue_remove);
	}
	return me;
}
/* Destructor */
void Queue_Destroy(Queue *const me)
{
	if (me != NULL){
		Queue_CleanUp(me);
	}
	free(me);
}
