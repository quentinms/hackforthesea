#include <Adafruit_CircuitPlayground.h>
#include <SoftwareSerial.h>

SoftwareSerial ser(0, 1);

int pin = 10;
void setup() {
  // put your setup code here, to run once:
  ser.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float t = CircuitPlayground.temperature();
  int c = CircuitPlayground.readCap(pin);
  int l = CircuitPlayground.lightSensor();
  ser.println(String(t) + "," + String(c) +"," + String(l));
  delay(5000);
}

