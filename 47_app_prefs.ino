// Preferences namespace where app settings are stored
//#define USE_PREFS
// Store last WiFi ssid and password. Docs: https://randomnerdtutorials.com/esp32-save-data-permanently-preferences/
// Note: works fine on ESP32-S3. Cannot use on nrf52840.
#ifdef USE_PREFS
# include <Preferences.h>

Preferences preferences;
#endif

void app_prefs_put (struct app_settings_s *app_settings) {
#ifdef USE_PREFS
  Serial.println("Writing preferences...");
  preferences.begin(PREFS_CREDS_SECTION, false /*not read-only*/);
  preferences.putString("ssid",     app_settings->ssid); 
  preferences.putString("password", app_settings->password);
  preferences.end(); // let other namespaces be used later.

  preferences.begin(PREFS_TIME_SECTION, false /*not read-only*/);
  preferences.putBool("daylight_observed", app_settings->daylight_observed);
  preferences.putDouble("gmt_offset_hours", app_settings->gmt_offset_hours);
  preferences.putInt("leap_sec", app_settings->leap_sec);
  preferences.end(); // let other namespaces be used later.

  preferences.begin(PREFS_DISPLAY_SECTION, false /*not read-only*/);
  preferences.putInt("bright_steps", app_settings->bright_steps);
  preferences.end(); // let other namespaces be used later.
#endif
}

void app_prefs_get (struct app_settings_s *app_settings) {
#ifdef USE_PREFS
  Serial.println("Reading preferences...");

  preferences.begin(PREFS_CREDS_SECTION, true /*read-only*/);
  preferences.getString("ssid",     app_settings->ssid,     APP_SETTINGS_STR_MAX); 
  preferences.getString("password", app_settings->password, APP_SETTINGS_STR_MAX);
  preferences.end(); // let other namespaces be used later.

  preferences.begin(PREFS_TIME_SECTION, true /*read-only*/);
  app_settings->daylight_observed = preferences.getBool("daylight_observed", true/*default to observing Daylight Saving Time*/);
  app_settings->gmt_offset_hours = preferences.getInt("gmt_offset_hours", -6/*default to USA Central Standard Time (CST)*/);
  app_settings->leap_sec = preferences.getInt("leap_sec", 18/*announced to date*/);
  preferences.end(); // let other namespaces be used later.

  preferences.begin(PREFS_DISPLAY_SECTION, true /*read-only*/);
  app_settings->bright_steps = preferences.getInt("bright_steps", 16/*full brightness*/);
  preferences.end(); // let other namespaces be used later.

  Serial.println("Read:");
#endif
}