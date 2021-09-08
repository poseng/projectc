#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "CachedQueue.h"


/*Constructors and destructors */
void CachedQueue_Init(CachedQueue *const me, char *fName,
					  int (*isFullFunction)(CachedQueue *const me),
					  int (*isEmptyFunction)(CachedQueue *const me),
					  int (*getSzeFunction)(CachedQueue *const me),
					  void (*insertFunction)(CachedQueue *const me, int k),
					  int (*removeFunction)(CachedQueue *const me),
					  void (*flushFunction)(CachedQueue *const me),
					  void (*loadFunction)(CachedQueue *const me)){

					  }

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
void CachedQueue_Destroy(CachedQueue * const me)