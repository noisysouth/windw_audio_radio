#include "my_tft.h"

// ------------------------- TFT setup -------------------------

void setup_tft(void) {
  // Start TFT display
#ifdef HX8357
  setup_hx8357_tft();
//#else
  // tft is GFXcanvas16  
#endif
  // 1: side w/ more pins is top of screen
  // 2: end w/ USB connector is top of sreen
  // 3: side w/ fewer pins is top of screen
  tft.setRotation(1);
  tft.fillScreen(GetColorBackgr());
  Serial.println(F("Initialized"));
}