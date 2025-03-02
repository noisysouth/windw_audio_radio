// Preferences namespace where app settings are stored
//#define USE_PREFS
// Store last WiFi ssid and password. Docs: https://randomnerdtutorials.com/esp32-save-data-permanently-preferences/
#ifdef USE_PREFS
# include <Preferences.h>
#endif

#define PREFS_CREDS_SECTION "credentials"
#define PREFS_TIME_SECTION  "time"
#define PREFS_DISPLAY_SECTION  "display"

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

#ifdef USE_PREFS
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
#else
  Serial.println("Reading stored Preferences skipped - USE_PREFS not defined at compile time");
  strncpy (app_settings->ssid,     "No SSID",   APP_SETTINGS_STR_MAX);
  strncpy (app_settings->password, "No Passwd", APP_SETTINGS_STR_MAX);
  app_settings->daylight_observed = true;
  app_settings->gmt_offset_hours = -6;
  app_settings->leap_sec = 18;
  app_settings->bright_steps = 0;
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