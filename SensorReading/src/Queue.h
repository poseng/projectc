/*
 * Queue.h
 *
 *  Created on: Sep 7, 2021
 *      Author: poseng
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#define QUEUE_SIZE 10

typedef struct Queue Queue;
struct Queue {
	int size;
	int head;
	int tail;
	int buffer[QUEUE_SIZE];
	// use function pointer to create member operations in a C-Class
	// member function pointers are employed here.
	int (*isFull)(Queue *const me);
	int (*isEmpty)(Queue *const me);
	int (*getSize)(Queue *const me);
	void (*insert)(Queue *const me, int k);
	int (*remove)(Queue *const me);
};
/* Constructor and Deconstructor */
void Queue_Init(Queue *const me, int (*isFullfunction)(Queue *const me),
		int (*isEmptyfunction)(Queue *const me),
		int (*getSizefunction)(Queue *const me),
		void (*insertfunction)(Queue *const me, int k),
		int (*removefunction)(Queue *const me)
		);
void Queue_CleanUp(Queue *const me);
/* Operations */
int Queue_isFull(Queue *const me);
int Queue_isEmpty(Queue *const me);
int Queue_getSize(Queue *const me);
void Queue_insert(Queue *const me, int k);
int Queue_remove(Queue *const me);

Queue* Queue_Create(void);
void Queue_Destroy(Queue *const me);

#endif /* QUEUE_H_ */
