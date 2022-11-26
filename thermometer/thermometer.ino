#include <DHT.h>
#include <DHT_U.h>

int temperatureOffset = -2;        // Versatz um die ungenauigkeit des sensors auszugleichen
unsigned int portToBitOffset = 3;  // Das niedrigste Bit liegt auf diesem digitalen Port
unsigned int bitsToShow = 7;       // Anzahl der Bits, die angezeigt werden können
long lastTimestamp = 0;
long startUpTimestamp = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, INPUT);
  Serial.begin(9600);
  startUpTimestamp = lastTimestamp = millis();
}

void loop() {

  long currentTimestamp = millis();
  bool testDisplay = currentTimestamp - startUpTimestamp < 3000;
  bool buttonPressed = HIGH == digitalRead(12);
  
  if(buttonPressed)
  {
    lastTimestamp = currentTimestamp;
  }

  bool enableDisplay = currentTimestamp - lastTimestamp < 3000;

  DHT dht = DHT(2, DHT11);

  int temperature = (int)dht.readTemperature() + temperatureOffset;

  for (int i = 0; i < bitsToShow; i++) {
    bool bitIsSet = bitRead(temperature, i);
    digitalWrite(i + portToBitOffset, bitIsSet && enableDisplay || testDisplay ? HIGH : LOW);
  }

  //delay(1000);
}