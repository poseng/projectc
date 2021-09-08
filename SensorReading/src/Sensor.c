/*
 * Sensor.c
 *
 *  Created on: Sep 7, 2021
 *      Author: poseng
 *  the file serves as the encapsulation boundary, and stylistically two file (.h and .c)
 *  group together the elements within a single class.
 *  This approach support objec-based programming very well, but doesn't implement
 *  virtual function in a fashion that can be easily overriddent in sublcasses.
 *	An alternatice approach that suuport object-oriented programming is to embed function
 *	pointer withint the struct itself.
 */

#include "Sensor.h"
#include <memory.h>
#include <stdlib.h>
void Sensor_Init(Sensor *const me) {

}

void Sensor_Cleanup(Sensor *const me) {

}

int Sensor_getFilterFrequency(const Sensor *const me) {
	return me->filterFrequency;
}
void Sensor_setFilterFrequency(Sensor *const me, int p_filterFrequency) {
	me->filterFrequency = p_filterFrequency;
}
int Sensor_getUpdateFrequency(const Sensor *const me) {
	return me->updateFrequency;
}
void Sensor_setUpdateFrequency(Sensor *const me, int p_udapteFrequency) {
	me->updateFrequency = p_udapteFrequency;
}
int Sensor_getValue(const Sensor *const me) {
	return me->value;
}
/**
 * for demo only
 * Polymorphism the hard way !!!
 */
//int acquireValue(Sensor * const me){
//	int *read, *write; /*read and write addresses*/
//	int j;
//	switch(me->whatKindOfInterface){
//	case MEMORYMAPPED:
//		write = (int *)WRITEADDR; /* address to write to sensor*/
////uncomment this line		*write = WRITEMASK; /*sensor command to force a read*/
//		for (j = 0; j< 100; j++){/*wait loop*/};
//		read = (int*)READADDR; /*address of returned value*/
//		me->value = *read;
//		break;
//	case PORTMAPPED:
//		me->value = inp(SENSORPORT);
//		/* inp() is compiler-specific port function*/
//		break;
//	}; /*end switch*/
//	return me->value;
//};
Sensor* Sensor_Create(void) {
	Sensor *me = (Sensor*) malloc(sizeof(Sensor));
	if (me != NULL) {
		Sensor_Init(me);
	}
	return me;
}

void Sensor_Destroy(Sensor *const me) {
	if (me != NULL) {
		Sensor_Cleanup(me);
	}
	free(me);
}

