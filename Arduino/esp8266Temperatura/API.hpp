String ApiHost = "http://localhost:3000";

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

void Create(String newData)
{
	HTTPClient http;
	http.begin(ApiHost + "/");
	http.addHeader("Content-Type", "application/json");
	
	String message = "";
	StaticJsonDocument<300> jsonDoc;
	jsonDoc["data"] = newData;
	serializeJson(jsonDoc, message);
	
	int httpCode = http.POST(message);
	processResponse(httpCode, http);
}