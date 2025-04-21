
#define APP_SETTINGS_STR_MAX 100

struct app_settings_s {
  // 'fm' section
  bool tx_enab;
  double freq;
  char rds_station[APP_SETTINGS_STR_MAX];
  char rds_message[APP_SETTINGS_STR_MAX];
  // 'time' section
  bool daylight_observed;
  double  gmt_offset_hours;
  int leap_sec;
  int bright_steps;
};

struct app_settings_s app_settings[1];

void app_settings_print (struct app_settings_s *app_settings) {
  Serial.print("tx_enab: ");
  Serial.println(app_settings->tx_enab);
  Serial.print("freq: ");
  Serial.println(app_settings->freq);
  Serial.print("rds_station: ");
  Serial.println(app_settings->rds_station);
  Serial.print("rds_message: ");
  Serial.println(app_settings->rds_message);

  Serial.print("daylight_observed: ");
  Serial.println(app_settings->daylight_observed);
  Serial.print("gmt_offset_hours: ");
  Serial.println(app_settings->gmt_offset_hours);
  Serial.print("leap_sec: ");
  Serial.println(app_settings->leap_sec);

  Serial.print("bright_steps: ");
  Serial.println(app_settings->bright_steps);
}

void app_settings_put (struct app_settings_s *app_settings) {
#ifdef USE_LITTLEFS
  app_littlefs_put (app_settings, sizeof(app_settings[0]));
#endif
}

void app_settings_get (struct app_settings_s *app_settings) {
  // Set up hardcoded defaults.
  app_settings->tx_enab = 1;
  app_settings->freq = 102.3;
  strncpy (app_settings->rds_station, "AdaRadio",   APP_SETTINGS_STR_MAX);
  strncpy (app_settings->rds_message, "Adafruit g0th Radio!", APP_SETTINGS_STR_MAX);
  
  app_settings->daylight_observed = true;
  app_settings->gmt_offset_hours = -6;
  app_settings->leap_sec = 18;

  app_settings->bright_steps = 0;
#ifdef USE_LITTLEFS
  app_littlefs_get (app_settings, sizeof(app_settings[0]));
#else
  Serial.println("Reading stored Preferences skipped - USE_LITTLEFS was not defined at compile time");
  Serial.println("Using hardcoded defaults:");
#endif
}