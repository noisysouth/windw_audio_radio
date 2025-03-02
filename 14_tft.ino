#include "my_tft.h"

//#ifdef ESP32_S3_TFT
  
//#elif defined HX8357
  
//#else
  // tft is GFXcanvas16
  //GFXcanvas16 tft(480, 320); // like HX8357
  //GFXcanvas16 tft(240, 135); // like ESP32 S3 TFT
  // cause boot looping for some reason. don't use this..
//#endif

// ------------------------- TFT setup -------------------------

void setup_tft(void) {
  // Start TFT display
#ifdef ESP32_S3_TFT
  setup_esp32_s3_tft();
#elif defined HX8357
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