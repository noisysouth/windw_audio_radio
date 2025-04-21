#define HX8357 // for the Adafruit 3.5" TFT (HX8357) FeatherWing

#include <Adafruit_GFX.h>    // Core graphics library
#ifdef HX8357
  // This is our library for the Adafruit 3.5" TFT (HX8357) FeatherWing
  // ----> http://www.adafruit.com/products/3651
  #include "Adafruit_HX8357.h" // on 3.5" TFT (HX8357) FeatherWing

  // If using the rev 1 with STMPE resistive touch screen controller uncomment this line:
  //#include <Adafruit_STMPE610.h>
  // If using the rev 2 with TSC2007, uncomment this line:
  #include <Adafruit_TSC2007.h>
#else
  // tft is GFXcanvas16
#endif
