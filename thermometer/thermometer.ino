#include <DHT.h>
#include <DHT_U.h>

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

bool needsInitialization = true;
int temperatureOffset = -2;       // Versatz um 
unsigned int portToBitOffset = 3; // Das niedrigste Bit liegt auf diesem digitalen Port
unsigned int bitsToShow = 7;      // Anzahl der Bits, die angezeigt werden können

void loop() {

  if(needsInitialization) {
    // einmal alle LEDs zum Testen anmachen
    for (int i = 0; i < bitsToShow; i++) {
      //digitalWrite(i + portToBitOffset, HIGH);
    }
    needsInitialization = false;
  }

  DHT dht = DHT(2, DHT11);

  //if(dht.read())
  {
    int temperature = (int)dht.readTemperature() + temperatureOffset;

    for (int i = 0; i < bitsToShow; i++) {
      //bool bitIsSet = temperature & (1 << i);
      bool bitIsSet = bitRead(temperature, i);
      Serial.print(bitIsSet ? 1 : 0);
      digitalWrite(i + portToBitOffset, bitIsSet ? HIGH : LOW);
    }
    Serial.println();
    Serial.println(temperature);
  }
  //else
  {
    //Serial.write("Could not read from sensor\n");
  }

  delay(3000);
  //digitalWrite(LED_BUILTIN, HIGH);
  //delay(1000);
  //digitalWrite(LED_BUILTIN, LOW);
  //delay(1000);
}