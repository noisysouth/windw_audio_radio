
#define APP_SETTINGS_STR_MAX 100

struct app_settings_s {
  // 'credentials' section
  char ssid    [APP_SETTINGS_STR_MAX];
  char password[APP_SETTINGS_STR_MAX];
  // 'time' section
  bool daylight_observed;
  double  gmt_offset_hours;
  int leap_sec;
  int bright_steps;
};

struct app_settings_s app_settings[1];

void app_settings_put (struct app_settings_s *app_settings) {
#ifdef USE_PREFS
  app_prefs_put (app_settings);
#endif
#ifdef USE_LITTLEFS
  app_littlefs_put (app_settings, sizeof(app_settings[0]));
#endif
}

void app_settings_get (struct app_settings_s *app_settings) {
  // Set up hardcoded defaults.
  strncpy (app_settings->ssid,     "No SSID",   APP_SETTINGS_STR_MAX);
  strncpy (app_settings->password, "No Passwd", APP_SETTINGS_STR_MAX);
  app_settings->daylight_observed = true;
  app_settings->gmt_offset_hours = -6;
  app_settings->leap_sec = 18;
  app_settings->bright_steps = 0;
#if defined USE_PREFS
  app_prefs_get (app_settings);
#elif defined USE_LITTLEFS
  app_littlefs_get (app_settings, sizeof(app_settings[0]));
#else
  Serial.println("Reading stored Preferences skipped - neither USE_PREFS nor USE_LITTLEFS defined at compile time");
  Serial.println("Using hardcoded defaults:");
#endif

  Serial.print("ssid: ");
  Serial.println(app_settings->ssid);
  Serial.print("password: ");
  Serial.println(app_settings->password);

  Serial.print("daylight_observed: ");
  Serial.println(app_settings->daylight_observed);
  Serial.print("gmt_offset_hours: ");
  Serial.println(app_settings->gmt_offset_hours);
  Serial.print("leap_sec: ");
  Serial.println(app_settings->leap_sec);

  Serial.print("bright_steps: ");
  Serial.println(app_settings->bright_steps);
}