//*Project code created by me(David Z),with a small help of the gemenii AI
///**The AI generated code will be highlithed with : */*/*
#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h> 
#include <DHT.h>
#include <SPI.h>
#include <MFRC522.h>

const int PIN_PIR       = 5;
const int PIN_DHT       = 4;
const int PIN_BUTTON    = 6;
const int PIN_RFID_RST  = 7;
const int PIN_RFID_SDA  = 53;

const int PIN_BUZZER    = 3; 
const int PIN_LED       = 2;

const int PIN_RELAY_LIGHT  = 8;
const int PIN_RELAY_WINDOW = 9;

const int LCD_ADDR = 0x3F;//0x24
const int TEMP_THRESHOLD = 28; 
const int LCD_UPDATE_MS = 2000;
#define DHTTYPE DHT11           

LiquidCrystal_PCF8574 lcd(LCD_ADDR);
DHT dht(PIN_DHT, DHTTYPE);
MFRC522 rfid(PIN_RFID_SDA, PIN_RFID_RST);

unsigned long lastLcdUpdate = 0; // */*/*
// */*/*
void setup() {
  Serial.begin(9600);

  dht.begin();
  
  Wire.begin();
  lcd.begin(16, 2);
  lcd.setBacklight(255);

  SPI.begin();
  rfid.PCD_Init();

  pinMode(PIN_BUTTON, INPUT_PULLUP); 
  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_LED, OUTPUT);

  pinMode(PIN_RELAY_LIGHT, OUTPUT);
  pinMode(PIN_RELAY_WINDOW, OUTPUT);
  digitalWrite(PIN_RELAY_LIGHT, HIGH);
  digitalWrite(PIN_RELAY_WINDOW, HIGH);

  lcd.clear();
  lcd.print("System Boot ...");
  delay(1500);
  lcd.clear();
}

void loop() {
  unsigned long currentMillis = millis();   //*/*/*
//
  if (digitalRead(PIN_PIR) == HIGH) {
    digitalWrite(PIN_RELAY_LIGHT, LOW);
    digitalWrite(PIN_LED, HIGH);
  } else {   
    digitalWrite(PIN_RELAY_LIGHT, HIGH);
    digitalWrite(PIN_LED, LOW);
  }

  if (currentMillis - lastLcdUpdate >= LCD_UPDATE_MS) {
    lastLcdUpdate = currentMillis; 
    
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    if (isnan(temp) || isnan(hum)) {
      lcd.setCursor(0,0);
      lcd.print("Sensor Error    ");
    } else {
      lcd.home();
      lcd.print("T:"); lcd.print(temp, 1); lcd.print("C ");
      lcd.print("H:"); lcd.print(hum, 0); lcd.print("%");

      lcd.setCursor(0, 1);
      if (temp > TEMP_THRESHOLD) {
        digitalWrite(PIN_RELAY_WINDOW, LOW);
        lcd.print("HOT G! OPEN UP ");
      } else {
        digitalWrite(PIN_RELAY_WINDOW, HIGH);
        lcd.print("Temp ok        ");
      }
    }
  } 

  if (digitalRead(PIN_BUTTON) == LOW) {
    digitalWrite(PIN_BUZZER, HIGH); 
    delay(100);
    digitalWrite(PIN_BUZZER, LOW);  
    delay(200); 
  } 

}