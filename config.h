#ifndef _CONFIG_H
#define _CONFIG_H

#include <Arduino.h>
// Select appropriate display type

//#define DISPLAY_0802
//#define DISPLAY_1602_I2C
#define DISPLAY_OLED_I2C

#ifdef DISPLAY_OLED_I2C
#include "dspl_oled_i2c.h"
#endif

#ifdef DISPLAY_1602_I2C
#include "dspl_1602_i2c.h"
#endif

#ifdef DISPLAY_0802
#include "dspl_0802.h"
#endif

/*
 * max_tips value depend on the number of tips you are going to use. See tip_name[] in tips.h
 */
#define max_tips 5
extern const char *tip_name[max_tips];

#endif
