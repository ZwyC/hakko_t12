#include "config.h"
#include "dspl_oled_i2c.h"

#ifdef DISPLAY_OLED_I2C

void DSPL::init(void) {
  u8x8::begin();
  u8x8::setPowerSave(0);
  u8x8::setFlipMode(1);
  u8x8::setFont(u8x8_font_victoriamedium8_r);
  u8x8::clear();
  full_second_line = false;
}

void DSPL::tip(uint8_t index, bool top) {
  if (index >= max_tips) {
  	u8x8::draw2x2String(0, 3, "  ????  ");
    return;
  }
  char buff[5];
  uint8_t  i = 0;
  const char *p = tip_name[index];
  for ( ; i < 4; ++i)
    if (!(buff[i] = *p++))
      break;
  for ( ; i < 4; ++i) buff[i] = ' ';
  buff[4] = '\0';
  uint8_t  y = 3; if (top) y = 0;
  u8x8::draw2x2String(0, y, buff);
}

void DSPL::msgSelectTip(void) {
  u8x8::draw2x2String(0, 0, "iron tip");
}

void DSPL::tSet(uint16_t t, bool celsius) {
  char buff[5];
  char units = 'C';
  if (!celsius) units = 'F';
  sprintf(buff, "%3d%c", t, units);
  u8x8::draw2x2String(0, 0, buff);
}

void DSPL::tCurr(uint16_t t) {
  char buff[4];
  if (t < 1000) {
    sprintf(buff, "%3d", t);
  } else {
    u8x8::draw2x2String(0, 3, "xxx");
    return;
  }
  u8x8::draw2x2String(0, 3, buff);
  if (full_second_line) {
    u8x8::draw2x2String(0, 3, "    ");
    full_second_line = false;
  }
}

void DSPL::pSet(uint8_t  p) {
  char buff[6];
  sprintf(buff, "P:%3d", p);
  u8x8::draw2x2String(0, 0, buff);
}

void DSPL::timeToOff(uint8_t  sec) {
  char buff[5];
  sprintf(buff, " %3d", sec);
  u8x8::draw2x2String(8, 0, buff);
}

void DSPL::msgReady(void) {
  u8x8::draw2x2String(8, 0, " rdy");
}

void DSPL::msgWorking(void) {
  u8x8::draw2x2String(8, 0, " wrk");
}

void DSPL::msgOn(void) {
  u8x8::draw2x2String(8, 0, "  ON");
}

void DSPL::msgOff(void) {
  u8x8::draw2x2String(8, 0, " OFF");
}

void DSPL::msgCold(void) {
  u8x8::draw2x2String(0, 3, "  cold  ");
  full_second_line = true;
}

void DSPL::msgFail(void) {
  u8x8::draw2x2String(0, 3, " Failed ");
}

void DSPL::msgTune(void) {
  u8x8::draw2x2String(0, 0, "Tune");
}

void DSPL::msgCelsius(void) {
  u8x8::draw2x2String(0, 3, "Celsius ");
}

void DSPL::msgFarneheit(void) {
  u8x8::draw2x2String(0, 3, "Faren.  ");
}

void DSPL::msgDefault() {
  u8x8::draw2x2String(0, 3, " default");
}

void DSPL::msgCancel(void) {
  u8x8::draw2x2String(0, 3, " cancel ");
}

void DSPL::msgApply(void) {
  u8x8::draw2x2String(0, 3, " save   ");
}

void DSPL::setupMode(uint8_t  mode, uint8_t  p) {
  char buff[5];
  u8x8::clear();
  u8x8::draw2x2String(0, 0, "setup");
  switch (mode) {
    case 0:
    u8x8::draw2x2String(2, 3, "off:");
    if (p > 0) {
      sprintf(buff, "%2dm", p);
      u8x8::draw2x2String(9, 3, buff);
    } else {
      u8x8::draw2x2String(9, 3, " NO");
    }
    break;
    case 1:
      u8x8::draw2x2String(2, 3, "units");
      if (p)
        u8x8::draw2x2String(14, 3, "C");
      else
        u8x8::draw2x2String(14, 3, "F");
      break;
    case 2:
      u8x8::draw2x2String(2, 3, "tip cfg");
    case 3:
      u8x8::draw2x2String(2, 3, "tune");
      break;
  }
}

void DSPL::percent(uint8_t  Power) {
  char buff[6];
  sprintf(buff, " %3d%c", Power, '%');
  u8x8::draw2x2String(6, 3, buff);

  byte bars = map(Power, 0, 100, 0, 16);
  u8x8::setInverseFont(1);
  for (byte i=0; i<bars; i++){
    u8x8::drawString(i, 7, " ");
  }
  u8x8::setInverseFont(0);
  for (byte i=bars; i<16; i++){
    u8x8::drawString(i, 7, "-"); 
  }

}

void DSPL::calibrated(bool calibrated) {
  char buff[5];
  for (uint8_t  i = 0; i < 4; ++i) buff[i] = ' ';
  if (!calibrated) buff[3] = '*';
  buff[4] = '\0';
  u8x8::draw2x2String(8, 3, buff);
}

#endif
