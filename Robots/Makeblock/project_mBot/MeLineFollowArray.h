#ifndef MeLineFollowArray_h
#define MeLineFollowArray_h

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "MeConfig.h"

#ifdef ME_PORT_DEFINED
#include "MePort.h"
#endif /* ME_PORT_DEFINED */

class MeLineFollowArray : public MePort
{    
	public:
    //direction capabilities
    enum direction {can_nowhere,can_forward,can_left,can_right,can_left_right,can_left_right_forward};

		MeLineFollowArray();
    bool readSensor();
    int8_t getPosition();
    direction getDirection();
		uint8_t getRawValue();
 private:
		uint8_t raw=0;
    int8_t weighted=0;
    bool isValidLine(uint8_t raw);
		String fillZero(String bin);
};

#endif
