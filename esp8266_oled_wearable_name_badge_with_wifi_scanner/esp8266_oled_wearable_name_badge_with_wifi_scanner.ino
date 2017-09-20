/* Copyright 2017 LeRoy Miller */

/* Aug 13, 2017 - WIFI Scanner added. LeRoy Miller 2017
 * Based off Arduino ESP8266 OLED 0.9 SSD1306 WiFi Scanner 
 * v 1.1 by Robert Ulbricht 
 */
 
 /*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include "ESP8266WiFi.h"
#include <ESP_SSD1306.h>    // Modification of Adafruit_SSD1306 for ESP8266 compatibility
#include <Adafruit_GFX.h>   // Needs a little change in original Adafruit library (See README.txt file)
#include <Wire.h>

#define OLED_RESET  16  // Pin 15 -RESET digital signal
#define OLED_RESET D0  // RST-PIN for OLED (not used)
#define OLED_SDA    D1  // SDA-PIN for I2C OLED
#define OLED_SCL    D2  // SCL-PIN for I2C OLED

ESP_SSD1306 display(OLED_RESET); // FOR I2C

char draw[30];
char ssid[30];
char mac[30];

#define LINE0 3
#define LINE1 13
#define LINE2 23
#define LINE4 33
#define LINE5 43


void setup() {
  Wire.begin(OLED_SDA, OLED_SCL);
  Wire.setClock(400000);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Switch OLED
  display.clearDisplay();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
}

void loop() {
  badge();
  scanner();
}

void scanner() {
  int n = WiFi.scanNetworks(false,true); // false - async, true - hidden networks
//messageBox("scan done");
  if (n == 0)
    messageBox("no networks found");
  else
  {
    sprintf(draw, "%d netw. found", n);
    messageBox(draw);
    for (int i = 0; i < n; ++i)
    {
      
      // oled
      strcpy(ssid,WiFi.SSID(i).c_str());
      int dl=strlen(ssid);
      if(dl>2) { // hide some details
       // ssid[dl-2]='?';
       // ssid[dl-1]='?';
      }
      strcpy(mac,WiFi.BSSIDstr(i).c_str());
      dl=strlen(mac);
      if(dl>2) { // hide some details
       // mac[dl-2]='?';
       // mac[dl-1]='?';
      }
      display.clearDisplay();
      sprintf(draw,"Net: %d/%d",i+1,n);
      display.setCursor(1, LINE0);
      display.print(draw);
      display.setCursor(1, LINE1);
      display.print(ssid);
      display.setCursor(1, LINE2);
      display.print(mac);
      sprintf(draw,"Sig: %d dBm",WiFi.RSSI(i));
      display.setCursor(1, LINE4);
      display.print(draw);
      sprintf(draw,"Ch: %d",WiFi.channel(i));
      display.setCursor(80, LINE4);
      display.print(draw);
      sprintf(draw,"Enc: %s",getEncryptionType(WiFi.encryptionType(i)));
      display.setCursor(1, LINE5);
      display.print(draw);
      //display.drawRect(0,0,128,64);
      display.display();
      
      delay(2000);
    }
  }
  
}

const char S_WEP[] = "WEP";
const char S_TKIP[] = "WPA";
const char S_CCMP[] = "WPA2";
const char S_NONE[] = "None";
const char S_AUTO[] = "Auto";
const char S_UNKNOWN[] = "Unkn.";

const char* getEncryptionType(int thisType) {
  // read the encryption type and print out the name:
  switch (thisType) {
    case ENC_TYPE_WEP:
      return S_WEP;
    case ENC_TYPE_TKIP:
      return S_TKIP;
    case ENC_TYPE_CCMP:
      return S_CCMP;
    case ENC_TYPE_NONE:
      return S_NONE;
    case ENC_TYPE_AUTO:
      return S_AUTO;
    default:
      return S_UNKNOWN;
  }
}

void badge() {
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
  display.setTextSize(1);
  display.clearDisplay();
  display.setCursor(0,20);
  display.println("kd8bxp.blogspot.com");
  display.setCursor(0,30);
  display.println("github.com/kd8bxp");
  display.display();
  delay(2000);
  display.startscrollleft(0x00, 0x0F);
  delay(15000);
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


void messageBox(const char *message)
{
 
  display.clearDisplay();
  display.setCursor(0,5);
  display.print(message);
  display.display();
}

