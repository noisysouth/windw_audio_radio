#define USE_FM_TX

#ifdef USE_FM_TX
# include <Adafruit_Si4713.h>
#endif

#define FM_RDS_STATION_MAX 8
#define FM_RDS_MESSAGE_MAX 32

#define FM_RESETPIN 12
#define FMSTATION 10230      // 10230 == 102.30 MHz

bool fm_found = false;

#ifdef USE_FM_TX
Adafruit_Si4713 radio = Adafruit_Si4713(FM_RESETPIN);
#endif

void setup_fm_tx(void) {
#ifdef USE_FM_TX
  pinMode(FM_RESETPIN, OUTPUT);

  digitalWrite(FM_RESETPIN, HIGH);
  delay(100);
  digitalWrite(FM_RESETPIN, LOW);
  delay(100);
  digitalWrite(FM_RESETPIN, HIGH);
  delay(100);
  Serial.println("FM Reset complete");

  if (! radio.begin()) {  // begin with address 0x63 (CS high default)
    Serial.println("FM Tx radio not found - check connection, pins");
    return;
  }
  fm_found = true;

  // Uncomment to scan power of entire range from 87.5 to 108.0 MHz
  /*
  for (uint16_t f  = 8750; f<10800; f+=10) {
   radio.readTuneMeasure(f);
   Serial.print("Measuring "); Serial.print(f); Serial.print("...");
   radio.readTuneStatus();
   Serial.println(radio.currNoiseLevel);
   }
   */

  Serial.print("\nSet TX power");
  radio.setTXpower(115);  // dBuV, 88-115 max

  Serial.print("\nTuning into "); 
  Serial.print(FMSTATION/100); 
  Serial.print('.'); 
  Serial.println(FMSTATION % 100);
  radio.tuneFM(FMSTATION); // 102.3 mhz

  // This will tell you the status in case you want to read it from the chip
  radio.readTuneStatus();
  Serial.print("\tCurr freq: "); 
  Serial.println(radio.currFreq);
  Serial.print("\tCurr freqdBuV:"); 
  Serial.println(radio.currdBuV);
  Serial.print("\tCurr ANTcap:"); 
  Serial.println(radio.currAntCap);

  // begin the RDS/RDBS transmission
  radio.beginRDS();
  radio.setRDSstation("AdaRadio");
  radio.setRDSbuffer( "Adafruit g0th Radio!");

  Serial.println("RDS on!");  
#else
  Serial.println("FM Tx skipped - compiled without USE_FM_TX defined.");
  //set_app_fm_btn ("FM Off");
  //set_fm_freq_label ("FM Disabled");
#endif
}

void loop_fm_tx(void) {
#ifdef USE_FM_TX
  if (!fm_found) {
    return;
  }
  radio.readASQ();
  Serial.print("\tCurr ASQ: 0x"); 
  Serial.println(radio.currASQ, HEX);
  Serial.print("\tCurr InLevel:"); 
  Serial.println(radio.currInLevel);
#endif
}