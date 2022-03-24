#include <BH1750.h>

#include <NewPing.h>

#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter;
#define PIN_RELAY 39
#define PIN_PHOTO_SENSOR 22
#define red_1 34
#define grn_1 35
#define blu_1 32
#define red_2 33
#define grn_2 25
#define blu_2 26
#define red_3 27
#define grn_3 14
#define blu_3 12


void setup() {
pinMode(red_1, OUTPUT);
pinMode(red_2, OUTPUT);
pinMode(red_3, OUTPUT);
pinMode(grn_1, OUTPUT);
pinMode(grn_2, OUTPUT);
pinMode(grn_3, OUTPUT);
pinMode(blu_1, OUTPUT);
pinMode(blu_2, OUTPUT);
pinMode(blu_3, OUTPUT);
double lux;
Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();

  Serial.println(F("BH1750 тест"));
}

void loop() {

double lux = lightMeter.readLightLevel();
   if (lux < 45)
  {
  digitalWrite(red_1, HIGH);
  digitalWrite(grn_2, HIGH);
  digitalWrite(blu_3, HIGH);
  
  delay(1000);
  
  digitalWrite(red_1, LOW);
  digitalWrite(grn_2, LOW);
  digitalWrite(blu_3, LOW);
  
  digitalWrite(red_2, HIGH);
  digitalWrite(grn_3, HIGH);
  digitalWrite(blu_1, HIGH);
  
  delay(1000);
  
  digitalWrite(red_2, LOW);
  digitalWrite(grn_3, LOW);
  digitalWrite(blu_1, LOW);
  
  digitalWrite(red_3, HIGH);
  digitalWrite(grn_1, HIGH);
  digitalWrite(blu_2, HIGH);
  
  delay(1000);
  
  digitalWrite(red_3, LOW);
  digitalWrite(grn_1, LOW);
  digitalWrite(blu_2, LOW);
  }
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println("lux");
  delay(1000);
  
  if (lux > 45)
  {
   digitalWrite(red_1, LOW);
  digitalWrite(grn_2, LOW);
  digitalWrite(blu_3, LOW);
  digitalWrite(red_2, LOW);
  digitalWrite(grn_3, LOW);
  digitalWrite(blu_1, LOW);
  digitalWrite(red_3, LOW);
  digitalWrite(grn_1, LOW);
  digitalWrite(blu_2, LOW);
  }
}
  