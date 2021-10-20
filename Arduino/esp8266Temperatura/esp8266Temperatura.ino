#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#include "config.h"  // Sustituir con datos de vuestra red
#include "API.hpp"
#include "ESP8266_Utils.hpp"

float vref = 3.3;
float resolution = vref / 1023;

void setup()
{
  Serial.begin(115200);
  ConnectWiFi_STA();
}

void loop()
{
  float temperature = analogRead(A0);
  temperature = (temperature * resolution);
  temperature = (temperature * 100) - 6;
  Serial.print("La temperatura es: ");
  Serial.println(temperature);
  ConnectWiFi_STA();
  Create(temperature);
  delay(5000);
}
