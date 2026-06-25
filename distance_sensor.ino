#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



void setup() {
  pinMode(2, OUTPUT);//define arduino pin
  pinMode(4, INPUT);//define arduino pin
  Serial.begin(9600);//enable serial monitor

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  pinMode(A0, OUTPUT);      // Set the analog pin A0 as a digital output
  digitalWrite(A0, LOW);   // Set the A0 pin to LOW

}
void loop() {
  //pulse output
  digitalWrite(2, LOW);
  delayMicroseconds(4);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  
  float t = pulseIn(4, HIGH);//input pulse and save it veriable
  
  float inches = t / 74 / 2; //time convert distance
  float cm = t / 29 / 2; //time convert distance
  String inch = " inches t";
  String CM = " cm";

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Dist=");
  display.print(inches,2);
  display.println("in ");
  display.display();

  if (inches < 2.0) {
    digitalWrite(A0, HIGH);
  }
  else {
    digitalWrite(A0, LOW);
  }

  delay(100);//delay
  display.clearDisplay();


}
