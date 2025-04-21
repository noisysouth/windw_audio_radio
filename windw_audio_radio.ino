// window_audio_radio
// This is the main entry setup() and loop() functions for the app.
// Other sub-modules are called from here.

#include "my_tft.h"

void setup()
{
  delay(3500); // to get Serial Monitor COM port to enumerate, a long delay BEFORE Serial.begin() is key..
  Serial.begin(115200);
  Serial.println("Opened serial");
  //delay(2000);

  setup_tft();
  setup_app_screens();

  setup_mp3_audio();
  setup_fm_tx();

  Wire.begin();        // join i2c bus (address optional for master)
  setup_input_gamepad();

  Serial.println("Setup done");
}

// do_click can be set by touch, kb_in Enter press, or digital input button.
bool  do_click  = false;
bool was_click  = false;

bool  do_unclick = false;
//int until_scan = 0;
int until_io = 0;
void loop()
{
  char kb_in = 0; // no keyboard input

  //Serial.println("loop() start");

  if (until_io <= 0) {
    do_unclick = false;
#if 0
    if (current_screen_is_radio()) {
      if (until_scan <= 0) {
        loop_radio_scan(); // do a scan
        until_scan = 50; // Wait a bit before scanning again.
      }
      until_scan--;
    } else { // !current_screen_is_radio()
      // looking at some other screen
      until_scan = 50; // if we return to the radio screen, wait before scanning again.
    }
#endif
    if (current_screen_is_app()) {
      app_update();
    }

    loop_input_gamepad();
    kb_in = loop_input_cardkb();

    loop_screen(kb_in, do_unclick);
    //until_io = 10; // Wait a bit before doing I/O again.
    until_io = 0; // do I/O again next time
  }
  until_io--;

  //delay(10);
  delay(100);

  //Serial.println("loop() end");
}