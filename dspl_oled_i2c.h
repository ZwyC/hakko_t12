#ifndef _DSPLOLED_I2C_H
#define _DSPLOLED_I2C_H
//#include "config.h"

#ifdef DISPLAY_OLED_I2C
#include <U8x8lib.h>

#define u8x8  U8X8_SSD1306_128X64_NONAME_HW_I2C
// The LCD 1602 I2C interface
const byte LCD_RS_PIN     = 7;

//------------------------------------------ class lcd DSPLay for soldering IRON -----------------------------
class DSPL : protected u8x8 {
  public:
    DSPL(void) : u8x8( LCD_RS_PIN) { }
    void init(void);
    void clear(void) { u8x8::clear(); }
    void tip(uint8_t  index, bool top);        	// Show the current tip (on top line)
    void tSet(uint16_t t, bool celsuis);        // Show the temperature set
    void tCurr(uint16_t t);                     // Show The current temperature
    void pSet(uint8_t  p);                      // Show the power set
    void timeToOff(uint8_t  sec);               // Show the time to automatic off the IRON
    void msgReady(void);                        // Show 'Ready' message
    void msgWorking(void);                      // Show 'Working' message
    void msgOn(void);                           // Show 'On' message
    void msgOff(void);                          // Show 'Off' message
    void msgCold(void);                         // Show 'Cold' message
    void msgFail(void);                         // Show 'Fail' message
    void msgTune(void);                         // Show 'Tune' message
    void msgCelsius(void);                      // Show 'Celsius' message
    void msgFarneheit(void);                    // Show 'Fahren.' message
    void msgDefault();                          // Show 'default' message (load default configuration)
    void msgCancel(void);                       // Show 'cancel' message
    void msgApply(void);                        // Show 'save' message
    void msgSelectTip(void);                    // Show 'tip:' message
    void setupMode(uint8_t  mode, uint8_t  p = 0);      // Show the configuration mode [0 - 3]
    void percent(uint8_t  Power);               // Show the percentage
    void calibrated(bool calibrated);           // Show '*' if the tip was not calibrated
  private:
    bool full_second_line;                      // Whether the second line is full with the message
};

#endif
#endif
