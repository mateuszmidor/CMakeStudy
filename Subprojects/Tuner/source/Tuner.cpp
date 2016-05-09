/*
 * Tuner.cpp
 *
 *  Created on: May 4, 2016
 *      Author: mateusz
 */


#include "Tuner.h"
#include "STUBS.h"

unsigned Tuner::getHwVersion() {
	return HWConfig_GetValue(0, 0);
}
