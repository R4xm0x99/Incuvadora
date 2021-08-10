#include <Wire.h>      
           
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
LiquidCrystal_I2C lcd(0x27,16,2); //0X27F - 0X20F

#define DHTPIN 12 
#define DHTTYPE DHT22 //DHT22
DHT dht(DHTPIN, DHTTYPE);A
int vcc= 11; //crear pines de 5v

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(vcc,OUTPUT);
  dht.begin();
}
void loop() { 

  digitalWrite(vcc,HIGH);
int h = dht.readHumidity();    // Lee la humedad
int t= dht.readTemperature();

lcd.clear();//Elimina todos los simbolos del LCD
lcd.setCursor(0,0);//Posiciona la primera letra despues del segmento 5 en linea 1              
lcd.print("Humedad: ");
lcd.setCursor(8,0);
lcd.print(h);//Escribe la humedad
lcd.print("%");                     
             
lcd.setCursor(0,1);
lcd.print("Temperatura: "); 
lcd.setCursor(12,1);
lcd.print(t);//Escribe la temperatura
lcd.print("C");                   
delay (2500);

if(t>25)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LAMPARA OFF");
  delay(2000);
  }
  else
  {
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LAMPARA ON");
  delay(2000);
    }
}
