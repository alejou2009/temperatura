#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#include "config.h"  // Sustituir con datos de vuestra red
#include "API.hpp"
#include "ESP8266_Utils.hpp"

int i = 0;

void setup() 
{
  Serial.begin(115200);
  ConnectWiFi_STA();
}

void loop() 
{
  ConnectWiFi_STA();
  Create(i);
  delay(5000);
  i++;
}
