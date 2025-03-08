// ----------------------- mp3 sound output ----------------------------
#define USE_MP3_AUDIO
#define MP3_PRINT_DIR

#ifdef USE_MP3_AUDIO
# include <Adafruit_VS1053.h> // for mp3 playing from microSD card; wants same pins as (HX8357) 3.5" sTFT? (16, 15, 0, 2)
# include <SD.h>

# ifdef MP3_PRINT_DIR
File mp3_dir;
# endif
#endif

// Couldn't find MP3 sound output module (VS1053) - no sound output will be used. Check the right pins are defined?
// Reset: pin -1
// MP3 chip select: pin 16
// Data select:     pin 15
// Data request:    pin 0
// SD card chip select: pin 2

// sound module: Adafruit Music Maker FeatherWing
// (3357 headphone version, or 1788 3W stereo amp version)
// These are the pins used
#define VS1053_RESET   -1     // VS1053 reset pin (not used!)

// Feather ESP8266
#if defined(ESP8266)
  #define VS1053_CS      16     // VS1053 chip select pin (output)
  #define VS1053_DCS     15     // VS1053 Data/command select pin (output)
  #define CARDCS          2     // Card chip select pin
  #define VS1053_DREQ     0     // VS1053 Data request, ideally an Interrupt pin

// Feather ESP32
#elif defined(ESP32) && !defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S2) && !defined(ARDUINO_ADAFRUIT_FEATHER_ESP32S3_TFT)
  #define VS1053_CS      32     // VS1053 chip select pin (output)
  #define VS1053_DCS     33     // VS1053 Data/command select pin (output)
  #define CARDCS         14     // Card chip select pin
  #define VS1053_DREQ    15     // VS1053 Data request, ideally an Interrupt pin

// Feather Teensy3
#elif defined(TEENSYDUINO)
  #define VS1053_CS       3     // VS1053 chip select pin (output)
  #define VS1053_DCS     10     // VS1053 Data/command select pin (output)
  #define CARDCS          8     // Card chip select pin
  #define VS1053_DREQ     4     // VS1053 Data request, ideally an Interrupt pin

// WICED feather
#elif defined(ARDUINO_STM32_FEATHER)
  #define VS1053_CS       PC7     // VS1053 chip select pin (output)
  #define VS1053_DCS      PB4     // VS1053 Data/command select pin (output)
  #define CARDCS          PC5     // Card chip select pin
  #define VS1053_DREQ     PA15    // VS1053 Data request, ideally an Interrupt pin

#elif defined(ARDUINO_NRF52832_FEATHER )
  #define VS1053_CS       30     // VS1053 chip select pin (output)
  #define VS1053_DCS      11     // VS1053 Data/command select pin (output)
  #define CARDCS          27     // Card chip select pin
  #define VS1053_DREQ     31     // VS1053 Data request, ideally an Interrupt pin

// Feather RP2040
#elif defined(ARDUINO_ADAFRUIT_FEATHER_RP2040)
  #define VS1053_CS       8     // VS1053 chip select pin (output)
  #define VS1053_DCS     10     // VS1053 Data/command select pin (output)
  #define CARDCS          7     // Card chip select pin
  #define VS1053_DREQ     9     // VS1053 Data request, ideally an Interrupt pin

// Feather M4, M0, 328, ESP32S2, ESP32S3 TFT, nRF52840 or 32u4
#else
  #define VS1053_CS       6     // VS1053 chip select pin (output)
  #define VS1053_DCS     10     // VS1053 Data/command select pin (output)
  #define CARDCS          5     // Card chip select pin
  // DREQ should be an Int pin *if possible* (not possible on 32u4)
  #define VS1053_DREQ     9     // VS1053 Data request, ideally an Interrupt pin

#endif

bool mp3_found = false;
#ifdef USE_MP3_AUDIO
Adafruit_VS1053_FilePlayer musicPlayer =
  Adafruit_VS1053_FilePlayer(VS1053_RESET, VS1053_CS, VS1053_DCS, VS1053_DREQ, CARDCS);
#endif

// ---------------------- MP3 sound output: list SD card files ------------------
#if defined USE_MP3_AUDIO && defined MP3_PRINT_DIR
/// File listing helper
// print files on SD card, which should include sound files for this game
//void mp3_audio_printDirectory(File dir, int numTabs) {
void mp3_audio_printDirectory(int numTabs) {
   while(true) {

     //File entry =  dir.openNextFile();
     File entry =  mp3_dir.openNextFile();
     if (! entry) {
       // no more files
       //Serial.println("**nomorefiles**");
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       //mp3_audio_printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}
#endif

// ------------------ setup ------------------
void setup_mp3_audio(void) {
  // ------------------------ Start mp3 sound output ------------------------------------
#ifdef USE_MP3_AUDIO
  Serial.println(F("Checking MP3 sound output module (VS1053)..."));
  mp3_found = musicPlayer.begin();
  if (!mp3_found) { // initialise the music player
    Serial.println(F("Couldn't find MP3 sound output module (VS1053) - no sound output will be used. Check the right pins are defined?"));
    Serial.print("Reset: pin "); Serial.println(VS1053_RESET);
    Serial.print("MP3 chip select: pin "); Serial.println(VS1053_CS);
    Serial.print("Data select:     pin "); Serial.println(VS1053_DCS);
    Serial.print("Data request:    pin "); Serial.println(VS1053_DREQ);
    Serial.print("SD card chip select: pin "); Serial.println(CARDCS);
  } else {
    Serial.println(F("MP3 sound output module (VS1053) found OK."));

    musicPlayer.sineTest(0x44, 500);    // Make a tone to indicate VS1053 is working
    mp3_found = SD.begin(CARDCS);
    if (!mp3_found) {
      Serial.println(F("MP3 sound SD card failed / not present - no sound output will be used."));
    }
  }
  if (mp3_found) {
    Serial.println(F("MP3 sound SD card is OK!"));

#ifdef MP3_PRINT_DIR
    // list files
    mp3_dir = SD.open("/");
    //mp3_audio_printDirectory(SD.open("/"), 0);
    mp3_audio_printDirectory(0);
#endif

    // Set volume for left, right channels. lower numbers == louder volume!
    musicPlayer.setVolume(10,10);

#if defined(__AVR_ATmega32U4__)
    // Timer interrupts are not suggested, better to use DREQ interrupt!
    // but we don't have them on the 32u4 feather...
    musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT); // timer int
#else
    // If DREQ is on an interrupt pin we can do background
    // audio playing
    musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int
#endif
  }
#else
  Serial.println("mp3 audio skipped - USE_MP3_AUDIO not defined at compile time");
#endif

}
void update_mp3_audio(void) {
 #ifdef USE_MP3_AUDIO
 // TODO: link to something the button knows.
  if (mp3_found) {
    //musicPlayer.startPlayingFile("/radio_gaga.mp3");
    // "Interrupt based playback currently does not work on ESP32 platforms."
    // Source: https://learn.adafruit.com/adafruit-music-maker-featherwing/library-reference
    // Music will start, but after it starts playing, then more input forces the processor to reboot.

    musicPlayer.playFullFile("/radio_gaga.mp3");
  }
#endif
}