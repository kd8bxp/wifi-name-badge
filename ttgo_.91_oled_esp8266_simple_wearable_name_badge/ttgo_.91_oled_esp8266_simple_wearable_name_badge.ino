/* Copyright 2017 LeRoy Miller */

#include <ESP_SSD1306.h>    // Modification of Adafruit_SSD1306 for ESP8266 compatibility
#include <Adafruit_GFX.h>   // Needs a little change in original Adafruit library (See README.txt file)
#include <Wire.h>

//#define OLED_RESET  16  // Pin 15 -RESET digital signal
#define OLED_RESET D2  // RST-PIN for OLED (not used)
#define OLED_SDA    D4  // SDA-PIN for I2C OLED
#define OLED_SCL    D5  // SCL-PIN for I2C OLED

ESP_SSD1306 display(OLED_RESET); // FOR I2C

void setup() {
  Wire.begin(OLED_SDA, OLED_SCL);
  Wire.setClock(400000);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Switch OLED
  display.clearDisplay();

}

void loop() {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(8,0);
  display.clearDisplay();
  display.println("LeRoy");
  display.setCursor(15, 20);
  display.println("Miller");
  display.setCursor(25, 40);
  display.println("KD8BXP");
  display.display();
  scroll();
  delay(1000);
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Automation");
  display.setCursor(0,20);
  display.println("Technology");
  display.setCursor(25,40);
  display.println("Club");
  display.display();
  scroll();
  delay(1000);
  /*display.setTextSize(2);
  display.clearDisplay();
  display.setCursor(0,20);
  display.println("kd8bxp.blogspot.com");
  display.setCursor(0,30);
  display.println("github.com/kd8bxp");
  display.display();
  delay(2000);
  display.startscrollleft(0x00, 0x0F);
  delay(15000);*/
  display.stopscroll();
}

void scroll() {
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrolldiagright(0x00, 0x07);
  delay(4000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(4000);
  display.stopscroll();
}

