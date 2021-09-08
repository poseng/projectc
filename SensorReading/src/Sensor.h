/*
 * Sensor.h
 *
 *  Created on: Sep 6, 2021
 *      Author: poseng
 */

#ifndef SENSOR_H_
#define SENSOR_H_
enum SensorInterfaceType {
	MEMORYMAPPED, PORTMAPPED
};
#define WRITEADDR 0x002facbd
#define READADDR 0x002facb1
#define SENSORPORT 13

/*## class Sensor */
typedef struct Sensor Sensor;
struct Sensor {
	int filterFrequency;
	int updateFrequency;
	int value;
	int whatKindOfInterface;
};

int Sensor_getFilterFrequency(const Sensor *const me);
void Sensor_setFilterFrequency(Sensor *const me, int p_filterFrequency);
int Sensor_getUpdateFrequency(const Sensor *const me);
void Sensor_setUpdateFrequency(Sensor *const me, int p_updateFrequency);
int Sensor_getValue(const Sensor *const me);
int acquireValue(Sensor *const me);
Sensor* Sensor_Create(void);
void Sensor_Destroy(Sensor *const me);
#endif /* SENSOR_H_ */
