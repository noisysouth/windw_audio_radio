// LittleFS storing method for persistent app settings
// Store last FM frequency and RDS text
// Note: Use on nrf52840 (b/c Preferences library is not implemented for this architecture).

#define USE_LITTLEFS

#ifdef USE_LITTLEFS
# include <Adafruit_LittleFS.h>
# include <InternalFileSystem.h>

using namespace Adafruit_LittleFS_Namespace;
#endif

#define LITTLEFS_FNAME "/app_settings.bin"

/* This example  print out Internal Flash contents up to
 * MAX_LEVEL level of directories (including root)
 * WARNING: This example uses recursive call to print out directory tree
 * be extra careful, high number of MAX_LEVEL can cause memory overflow
 */
#define MAX_LEVEL   2

void app_littlefs_put (void *app_settings, uint16_t len) {
#ifdef USE_LITTLEFS
  // delete if file already exists
  if ( InternalFS.exists(LITTLEFS_FNAME) ) {
    InternalFS.remove(LITTLEFS_FNAME);
  }

  Adafruit_LittleFS_Namespace::File file(InternalFS);
  //Adafruit_LittleFS_Namespace::File file(LITTLEFS_FNAME, O_WRITE, InternalFS);
  //if(!file) {
  if(!file.open(LITTLEFS_FNAME, FILE_O_WRITE)) {
    Serial.println("Warning: Could not create file to write app settings to LittleFS InternalFS.");
    return;
  }
  Serial.println("Writing app settings to LittleFS InternalFS...");
  file.seek(0); // write mode start at the end, seek to beginning
  file.write(len);
  file.write((uint8_t *)app_settings, len);
  file.close();
#endif
}

void app_littlefs_get (void *app_settings, uint16_t settings_len) {
#ifdef USE_LITTLEFS
  // Initialize Internal File System
  InternalFS.begin();

  // Print whole directory tree of root whose level is 0
  printTreeDir("/", 0);
  // Note: you will see here:
  // root
  // |_ adafruit/
  // |  |_ bond_prph/
  // |  |_ bond_cntr/
  // These directories are used when the Bluetooth is bonded with another Bluetooth MAC,
  //  either in Center mode or Peripheral mode:
  // https://github.com/adafruit/Adafruit_nRF52_Arduino/blob/master/libraries/Bluefruit52Lib/src/utility/bonding.cpp

  Serial.println("Reading app settings from LittleFS InternalFS...");

  Adafruit_LittleFS_Namespace::File file(InternalFS);
  if( file.open(LITTLEFS_FNAME, FILE_O_READ) )
  {
    int read_len;

    uint16_t len_in;
    uint8_t *buf_in;

    len_in = file.read();
    if (len_in != settings_len) {
      Serial.print("Warning: Length len_in=");
      Serial.print(len_in);
      Serial.print(" at beginning of file does not match expected settings_len=");
      Serial.println(settings_len);
      Serial.println("Using hardcoded defaults.");
      return;
    }

    buf_in = (uint8_t *)malloc(settings_len);

    read_len = file.read((uint8_t*) buf_in, settings_len);
    if (read_len == settings_len) {
      Serial.print("Loaded settings from file ");
      Serial.println(LITTLEFS_FNAME);
      memmove (app_settings, buf_in, settings_len);
    } else {
      Serial.print("Warning: Length read_len=");
      Serial.print(read_len);
      Serial.print(" size successfully read from file does not match expected settings_len=");
      Serial.println(settings_len);
      Serial.println("Using hardcoded defaults.");
    }
    free(buf_in);
  }

  file.close();
#endif
}

#ifdef USE_LITTLEFS
/**************************************************************************/
/*!
    @brief  Print out whole directory tree of an folder
            until the level reach MAX_LEVEL

    @note   Recursive call
*/
/**************************************************************************/
void printTreeDir(const char* cwd, uint8_t level)
{
  // Open the input folder
  Adafruit_LittleFS_Namespace::File dir(cwd, FILE_O_READ, InternalFS);

  // Print root
  if (level == 0) Serial.println("root");
 
  // File within folder
  Adafruit_LittleFS_Namespace::File item(InternalFS);

  // Loop through the directory 
  while( (item = dir.openNextFile(FILE_O_READ)) )
  {
    // Indentation according to dir level
    for(int i=0; i<level; i++) Serial.print("|  ");

    Serial.print("|_ ");
    Serial.print( item.name() );

    if ( item.isDirectory() )
    {
      Serial.println("/");

      // ATTENTION recursive call to print sub folder with level+1 !!!!!!!!
      // High number of MAX_LEVEL can cause memory overflow
      if ( level < MAX_LEVEL )
      {
        char dpath[strlen(cwd) + strlen(item.name()) + 2 ];
        strcpy(dpath, cwd);
        strcat(dpath, "/");
        strcat(dpath, item.name());
        
        printTreeDir( dpath, level+1 );
      }
    }else
    {
      // Print file size starting from position 30
      int pos = level*3 + 3 + strlen(item.name());

      // Print padding
      for (int i=pos; i<30; i++) Serial.print(' ');

      // Print at least one extra space in case current position > 50
      Serial.print(' ');
      
      Serial.print( item.size() );
      Serial.println( " Bytes");
    }

    item.close();
  }

  dir.close();
}
#endif