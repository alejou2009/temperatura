String ApiHost = "http://192.168.131.195:3000";

void processResponse(int httpCode, HTTPClient& http)
{
  if (httpCode > 0) {
    Serial.printf("Response code: %d\t", httpCode);

    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    }
  }
  else {
    Serial.printf("Request failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
}

void GetAll()
{
  HTTPClient http;
  http.begin(ApiHost + "/");
  int httpCode = http.GET();
  processResponse(httpCode, http);
}

void Create(int newTemp)
{
  HTTPClient http;
  http.begin(ApiHost + "/");
  http.addHeader("Content-Type", "application/json");
  
  String message = "";
  StaticJsonDocument<300> jsonDoc;
  jsonDoc["temperatura"] = newTemp;
  serializeJson(jsonDoc, message);
  
  int httpCode = http.POST(message);
  processResponse(httpCode, http);
}
