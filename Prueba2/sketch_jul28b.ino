#include <LiquidCrystal_I2C.h>
#include <Wire.h>    // incluye libreria para interfaz I2C
#include "DHT.h"


LiquidCrystal_I2C lcd(0x27, 16, 2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 
#define DHTPIN 3 
#define DHTTYPE DHT22 //DHT22
DHT dht(DHTPIN, DHTTYPE);
int temperatura;
int humedad;
int vcc= 11;


void setup() {
  // put your setup code here, to run once:
//Serial.begin(9600);
dht.begin();
lcd.init();
lcd.clear();
lcd.backlight();
 lcd.setCursor(0,1);
lcd.print("DHT22 sensor on");
delay(2000);
lcd.clear();
}

void loop() {
    digitalWrite(vcc,HIGH);
  // put your main code here, to run repeatedly:
  
temperatura=dht.readTemperature();
humedad=dht.readHumidity();
delay(500);

 lcd.clear();
 lcd.setCursor(1,2);
 lcd.print("ENGINAUT");
 lcd.setCursor(1,1);
 lcd.print("Temperatura:  ");
 lcd.print(temperatura);
 lcd.setCursor(1,0);
 lcd.print("Humedad:      ");
 lcd.print(humedad);
 lcd.print("%");
if(temperatura>21)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperatura>21C");
  delay(2000);
}
else
{
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Temperatura<21C");
  delay(2000);
}
}
