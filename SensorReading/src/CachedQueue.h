#ifndef CHACHEDQUEUE_H_
#define CHACHEDQUEUE_H_
#include "Queue.h"

typedef struct CachedQueue
{
	Queue *queue; /*based class*/
	/*new attributes*/
	char filename[80];
	int numberElementsOnDisk;
	/*aggretate in subclass*/
	Queue *outputQueue;

	/*inherited virtual functions*/
	int (*isFull)(CachedQueue *const me);
	int (*isEmpty)(CachedQueue *const me);
	int (*getSize)(CachedQueue *const me);
	void (*insert)(CachedQueue *const me, int k);
	int (*remove)(CachedQueue *const me);

	/*new virtual function*/
	void (*flush)(CachedQueue *const me);
	void (*load)(CachedQueue *const me);
}CachedQueue;

/*Constructors and destructors */
void CachedQueue_Init(CachedQueue *const me, char *fName,
					  int (*isFullFunction)(CachedQueue *const me),
					  int (*isEmptyFunction)(CachedQueue *const me),
					  int (*getSzeFunction)(CachedQueue *const me),
					  void (*insertFunction)(CachedQueue *const me, int k),
					  int (*removeFunction)(CachedQueue *const me),
					  void (*flushFunction)(CachedQueue *const me),
					  void (*loadFunction)(CachedQueue *const me));

void CachedQueue_Cleanup(CachedQueue * const me);


/*operations*/

int CachedQueue_isFull(CachedQueue * const me);
int CachedQueue_isEmpty(CachedQueue * const me);
int CachedQueue_getSize(CachedQueue * const me);
void CachedQueue_insert(CachedQueue * const me, int k);
int CachedQueue_remove(CachedQueue * const me);
void CachedQueue_flush(CachedQueue * const me);
void CachedQueue_load(CachedQueue * const me);

CachedQueue * CachedQueue_Create(void);
void CachedQueue_Destroy(CachedQueue * const me);


#endif /*CHACHEDQUEUE_H_*/