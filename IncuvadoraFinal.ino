#include <Wire.h>      
           
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
LiquidCrystal_I2C lcd(0x27,16,2); //0X27F - 0X20F

#define DHTPIN 12 
#define DHTTYPE DHT22 //DHT22
DHT dht(DHTPIN, DHTTYPE);
int f=3;
int v=4;
int vcc= 11;//crear pines de 5v
int vcc2= 9;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(f,OUTPUT);
  pinMode(v,OUTPUT);
  pinMode(vcc,OUTPUT);
  pinMode(vcc2,OUTPUT);
  dht.begin();
}
void loop() { 

  digitalWrite(vcc,HIGH);
  digitalWrite(vcc2,HIGH);
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

if(t>32)
{
  digitalWrite(f,LOW);
  digitalWrite(v,HIGH);
  delay(100);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fan On");
  delay(2000);
  }
  else if (t<28)
  {
   digitalWrite(f,HIGH);
    digitalWrite(v,LOW);
    delay(100);
      lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Light on");
    delay(2000);
    }
}
