#include "application.h"
#include "HttpClient.h"

/**
* Declaring the variables.
*/
HttpClient http;
unsigned int nextTime = 0;
int lf = 10; // Linefeed in ASCII

http_header_t headers[] = {
    //  { "Content-Type", "application/json" },
    //  { "Accept" , "application/json" },
    { "Accept" , "*/*"},
    { NULL, NULL } // NOTE: Always terminate headers will NULL
};

http_request_t request;
http_response_t response;

int LED = D0;

void setup() {
    Serial.begin(9600);
    Serial1.begin(9600);

    pinMode(LED, OUTPUT);
}

void loop() {
    if (Serial1.available()) {
      Serial.println("----------");
      //We should be receiving/sending bytes instead
      String sensorData = Serial1.readStringUntil(lf);
  	  Serial.println(sensorData);

      digitalWrite(LED, HIGH);
      // request.ip = IPAddress(192,168,43,97);
      request.hostname = "beautiful-oceans.herokuapp.com";
      request.port = 80;
      request.path = "/sensor_data";
      request.body = String(Time.now()) + "," + sensorData;

      http.post(request, response, headers);
      Serial.print("Application>\tResponse status: ");
      Serial.println(response.status);

      Serial.print("Application>\tHTTP Response Body: ");
      Serial.println(response.body);
      digitalWrite(LED, LOW);
    }
}
