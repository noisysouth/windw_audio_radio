/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is based on the Arduino WiFi Shield library, but has significant changes as newer WiFi functions are supported.
 *  E.g. the return value of `encryptionType()` different because more modern encryption is supported.
 */
#ifdef ESP8266
#  include <ESP8266WiFi.h>
#  define USE_WIFI
#elif defined ESP32
#  include "WiFi.h"
#  define USE_WIFI
#else
 // No WiFi on other boards
#endif

#include "my_tft.h"

//#define WIFI_SCAN_MESSAGES

void setup_wifi(void) {
  // Set WiFi to station mode and disconnect from an AP if it was previously connected.
#ifdef USE_WIFI
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
#else
  Serial.println("WiFi skipped - compiled without USE_WIFI defined.");
#endif
}

void loop_wifi_scan() {
#ifdef USE_WIFI
  Serial.println("Scan start");

  // WiFi.scanNetworks will return the number of networks found.
  int n = WiFi.scanNetworks();
  Serial.println("Scan done");
  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    //Serial.println("Nr | SSID                             | RSSI | CH | Encryption");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      //Serial.printf("%2d",i + 1);
      //Serial.print(" | ");
      //Serial.printf("%-32.32s", WiFi.SSID(i).c_str());

      add_list_item (WiFi.SSID(i).c_str());

      //Serial.print(" | ");
      //Serial.printf("%4ld", WiFi.RSSI(i));
      //Serial.print(" | ");
      //Serial.printf("%2ld", WiFi.channel(i));
      //Serial.print(" | ");
      switch (WiFi.encryptionType(i))
      {
#ifdef ESP8266
      case AUTH_OPEN:
        //Serial.print("open");
        break;
      case AUTH_WEP:
        //Serial.print("WEP");
        break;
      case AUTH_WPA_PSK:
        //Serial.print("WPA");
        break;
      case AUTH_WPA2_PSK:
        //Serial.print("WPA2");
        break;
      case AUTH_WPA_WPA2_PSK:
        //Serial.print("WPA+WPA2");
        break;
      default:
        //Serial.print("unknown");
        break;
#else // ESP23
      case WIFI_AUTH_OPEN:
        //Serial.print("open");
        break;
      case WIFI_AUTH_WEP:
        //Serial.print("WEP");
        break;
      case WIFI_AUTH_WPA_PSK:
        //Serial.print("WPA");
        break;
      case WIFI_AUTH_WPA2_PSK:
        //Serial.print("WPA2");
        break;
      case WIFI_AUTH_WPA_WPA2_PSK:
        //Serial.print("WPA+WPA2");
        break;
      case WIFI_AUTH_WPA2_ENTERPRISE:
        //Serial.print("WPA2-EAP");
        break;
      case WIFI_AUTH_WPA3_PSK:
        //Serial.print("WPA3");
        break;
      case WIFI_AUTH_WPA2_WPA3_PSK:
        //Serial.print("WPA2+WPA3");
        break;
      case WIFI_AUTH_WAPI_PSK:
        //Serial.print("WAPI");
        break;
      default:
        //Serial.print("unknown");
        break;
#endif
      }
      //Serial.println();
      delay(10);
    }
  }
  //Serial.println("");

  // Delete the scan result to free memory for code below.
  WiFi.scanDelete();

  // Draw new list of detected WiFi networks on screen.
  redraw_list();
#endif
}