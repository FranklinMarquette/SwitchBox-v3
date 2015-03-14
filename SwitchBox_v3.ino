//Created by FrankyMonez
//SWITCHBOX v3

#include <NewPing.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// If using software SPI (the default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13

#define RELAY_ON 0
#define RELAY_OFF 1

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

/* Uncomment this block to use hardware SPI
#define OLED_DC     6
#define OLED_CS     7
#define OLED_RESET  8
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);
*/

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#define TRIGGER_PIN  8  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define RELAY_ON 1
#define RELAY_OFF 0

int motion = 1;

//buzzer pin
int buzzerPin = 2;
//led output
int LED_OUT = 3;
//indicator LED for bench LEDs
int LED_IND = 4;
//output that turns everything off
int OFF = 5;
//on indicator
int STATUSLED_RELAY = 6;
//main control relay
int MAIN_RELAY = 7;

//turns LED on
int LED_ACTIVATOR = 14;
//led pot control
int LED_POTPIN = 15;

//default pot control value
int knobValue = 0;
//main control state
int MAIN_STATE = 0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


void setup(){
  
  Serial.begin(9600);
  
  pinMode(LED_OUT, OUTPUT);
  pinMode(STATUSLED_RELAY, OUTPUT);
  pinMode(LED_IND, OUTPUT);
  pinMode(MAIN_RELAY, OUTPUT);
  pinMode(OFF, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  digitalWrite(OFF, LOW);
  
    BOOT_UP();
}

void loop() {
     LED_CONTROL();
     
     MOTION();
     }

void BOOT_UP() {
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
     display.begin(SSD1306_SWITCHCAPVCC);
     // init done
  
     //get display ready and display "logo"
     display.display();
     display.clearDisplay();
  
     display.setTextSize(3);
     display.setTextColor(BLACK, WHITE);
     display.setCursor(0, 20);
     display.println("MARTECH");
     display.display();
     delay(1899);
     display.clearDisplay();
  
     //do some fancy initializing shit
     display.setTextSize(1.99);
     display.setTextColor(WHITE);
     display.setCursor(0, 20);
     display.println("Initializing ");
     display.println("MARTECH");
     display.println("SWITCHBOX System.");
     display.display();
     digitalWrite(STATUSLED_RELAY, RELAY_OFF);
     delay(1000);
  
     display.clearDisplay();
     display.setTextSize(1.99);
     display.setTextColor(WHITE);
     display.setCursor(0, 20);
     display.println("Initializing ");
     display.println("MARTECH");
     display.println("SWITCHBOX System..");
     display.display();
     digitalWrite(STATUSLED_RELAY, RELAY_ON);
     delay(1000);
     digitalWrite(STATUSLED_RELAY, RELAY_OFF);
  
     display.clearDisplay();
     display.setTextSize(1.99);
     display.setTextColor(WHITE);
     display.setCursor(0, 20);
     display.println("Initializing ");
     display.println("MARTECH");
     display.println("SWITCHBOX System...");
     display.display();
     digitalWrite(STATUSLED_RELAY, RELAY_ON);
     delay(1000);
     digitalWrite(STATUSLED_RELAY, RELAY_OFF);
  
     display.clearDisplay();
     display.setTextSize(1.99);
     display.setTextColor(WHITE);
     display.setCursor(0, 20);
     display.println("Initializing ");
     display.println("MARTECH");
     display.println("SWITCHBOX System.");
     display.display();
     digitalWrite(STATUSLED_RELAY, RELAY_ON);
     delay(1000);
     digitalWrite(STATUSLED_RELAY, RELAY_OFF);
  
     display.clearDisplay();
     display.setTextSize(1.99);
     display.setTextColor(WHITE);
     display.setCursor(0, 20);
     display.println("Initializing ");
     display.println("MARTECH");
     display.println("SWITCHBOX System..");
     display.display();
     digitalWrite(STATUSLED_RELAY, RELAY_ON);
     delay(1000);
     digitalWrite(STATUSLED_RELAY, RELAY_OFF);
  
     display.clearDisplay();
     display.setTextSize(1.99);
     display.setTextColor(WHITE);
     display.setCursor(0, 20);
     display.println("Initializing ");
     display.println("MARTECH");
     display.println("SWITCHBOX System...");
     display.display();
     digitalWrite(STATUSLED_RELAY, RELAY_ON);
     delay(1000);
     digitalWrite(STATUSLED_RELAY, RELAY_OFF);
  
     display.clearDisplay();
     display.setTextSize(1.99);
     display.setTextColor(WHITE);
     display.setCursor(0, 20);
     display.println("Initializing ");
     display.println("MARTECH");
     display.println("SWITCHBOX System.");
     display.display();
     digitalWrite(STATUSLED_RELAY, RELAY_ON);
     delay(1000);
     digitalWrite(STATUSLED_RELAY, RELAY_OFF);
  
     display.clearDisplay();
     display.setTextSize(1.99);
     display.setTextColor(WHITE);
     display.setCursor(0, 20);
     display.println("Initializing ");
     display.println("MARTECH");
     display.println("SWITCHBOX System..");
     display.display();
     digitalWrite(STATUSLED_RELAY, RELAY_ON);
     delay(1000);
     digitalWrite(STATUSLED_RELAY, RELAY_OFF);
  
     display.clearDisplay();
     display.setTextSize(1.99);
     display.setTextColor(WHITE);
     display.setCursor(0, 20);
     display.println("Initializing ");
     display.println("MARTECH");
     display.println("SWITCHBOX System...");
     display.display();
     digitalWrite(STATUSLED_RELAY, RELAY_ON);
     delay(1000);
     digitalWrite(STATUSLED_RELAY, RELAY_OFF);
     
   //boot up sound
  for(int i=0; i<30; i++){
    tone(buzzerPin, 50+10*i, 30);
    delay(30);
  }
  tone(buzzerPin, 350);
  delay(100);
  digitalWrite(STATUSLED_RELAY, RELAY_ON);
  digitalWrite(MAIN_RELAY, HIGH);
  delay(1000);
  
     display.setTextSize(3);
     display.setTextColor(BLACK, WHITE);
     display.setCursor(0, 20);
     display.println("MARTECH");
     display.display();
  
}

void SCAN(){
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
  
  delay(30);
  motion =  sonar.ping_in(); // Convert ping time to distance in in and assign it to waxDis - is 0 if distance is out of limit
  Serial.println(motion);
  Serial.print(" in");
}

void MOTION() {
  SCAN();
  if(motion > 0) {

  }
  else if (motion == 0) {
    display.clearDisplay();
    display.setTextSize(1.99);
    display.setTextColor(WHITE);
    display.setCursor(0, 20);
    display.println("      No       ");
    display.println("Activity");
    display.println("  Sensed  ");
    display.display();
    delay(2000);
    SCAN();
    if(motion > 0) {
    }
    else if(motion == 0) {
      for(int i=0;i<8;i++){
      tone(buzzerPin, 262, 500);
      delay(1000);
      }
      SCAN();
      if(motion > 0) {
      }
      else if(motion == 0) {
        delay(1000);
        SCAN();
        if (motion > 0) {
        }
        else if(motion == 0) {
          delay(1000);
          SCAN();
          if(motion > 0) {
          }
          else if(motion == 0) {
            delay(1000);
            SCAN();
            if(motion > 0) {
            }
            else if (motion == 0) {
                display.clearDisplay();
                display.setTextSize(1.99);
                display.setTextColor(WHITE);
                display.setCursor(0, 20);
                display.println("System will ");
                display.println("shut down");
                display.println("in five seconds");
                display.display();
                delay(5000);
                SCAN();
                if(motion > 0) {
                }
                else if(motion == 0) {
                  
                  display.setTextSize(1.99);
                  display.setTextColor(WHITE);
                  display.setCursor(0, 20);
                  display.println("Shutting down ");
                  display.println("MARTECH");
                  display.println("SWITCHBOX System.");
                  display.display();

  
                  display.clearDisplay();
                  display.setTextSize(1.99);
                  display.setTextColor(WHITE);
                  display.setCursor(0, 20);
                  display.println("Shutting down ");
                  display.println("MARTECH");
                  display.println("SWITCHBOX System..");
                  display.display();
  
  
                  display.clearDisplay();
                  display.setTextSize(1.99);
                  display.setTextColor(WHITE);
                  display.setCursor(0, 20);
                  display.println("Shutting down ");
                  display.println("MARTECH");
                  display.println("SWITCHBOX System...");
                  display.display();
     
  
                  display.clearDisplay();
                  display.setTextSize(1.99);
                  display.setTextColor(WHITE);
                  display.setCursor(0, 20);
                  display.println("Shutting down ");
                  display.println("MARTECH");
                  display.println("SWITCHBOX System.");
                  display.display();
     
  
                  display.clearDisplay();
                  display.setTextSize(1.99);
                  display.setTextColor(WHITE);
                  display.setCursor(0, 20);
                  display.println("Shutting down ");
                  display.println("MARTECH");
                  display.println("SWITCHBOX System..");
                  display.display();
   
  
                  display.clearDisplay();
                  display.setTextSize(1.99);
                  display.setTextColor(WHITE);
                  display.setCursor(0, 20);
                  display.println("Shutting down ");
                  display.println("MARTECH");
                  display.println("SWITCHBOX System...");
                  display.display();
     
  
                  display.clearDisplay();
                  display.setTextSize(1.99);
                  display.setTextColor(WHITE);
                  display.setCursor(0, 20);
                  display.println("Shutting down ");
                  display.println("MARTECH");
                  display.println("SWITCHBOX System.");
                  display.display();
    
  
                  display.clearDisplay();
                  display.setTextSize(1.99);
                  display.setTextColor(WHITE);
                  display.setCursor(0, 20);
                  display.println("Shutting down ");
                  display.println("MARTECH");
                  display.println("SWITCHBOX System..");
                  display.display();
  
                  display.clearDisplay();
                  display.setTextSize(1.99);
                  display.setTextColor(WHITE);
                  display.setCursor(0, 20);
                  display.println("Shutting down ");
                  display.println("MARTECH");
                  display.println("SWITCHBOX System...");
                  display.display();
     
                  display.clearDisplay();

                  digitalWrite(MAIN_RELAY, LOW);
                  digitalWrite(STATUSLED_RELAY, RELAY_OFF);
                  digitalWrite(OFF, HIGH);
                }
            }
          }
      }
    }
    }
}//end main else if
}//end SCAN

 void LED_CONTROL() {
  int LED_READ = analogRead(LED_ACTIVATOR);
  int LED_FINAL = LED_READ/204.6;
  
  if (LED_FINAL > 4) {
    
     knobValue = analogRead(LED_POTPIN)/4;
        
     analogWrite(LED_OUT, knobValue);
     analogWrite(LED_IND, knobValue);
     }
      
   else {
      analogWrite(LED_OUT, 0);
      analogWrite(LED_IND, 0);
          }
 }
