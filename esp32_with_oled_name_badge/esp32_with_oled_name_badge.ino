/* Copyright (c) 2017 LeRoy Miller
 *  
 *  This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>
 */

#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
#include <Wire.h>
#include "OLEDDisplayUi.h"

SSD1306  display(0x3c, 5, 4);
// SH1106 display(0x3c, D3, D5);

OLEDDisplayUi ui     ( &display );

// Update these with values suitable for your network.

const char* ssid = "Motel6";
const char* password = "";

long lastMsg = 0;
char msg[50];
int value = 0;

void msOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(128, 0, String(millis()));
}

void drawFrame1(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
display->setTextAlignment(TEXT_ALIGN_LEFT);
display->setFont(ArialMT_Plain_16);
display->drawString(0+x, 10+y,"LeRoy Miller");
display->drawString(25+x, 40+y,"KD8BXP");
}

void drawFrame2(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_16);
  display->drawStringMaxWidth(0+x,0+y, 120, "Automation Technology      Club!");
}

void drawFrame3(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // Text alignment demo
  display->setFont(ArialMT_Plain_10);

  // The coordinates define the left starting point of the text
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->drawString(0 + x, 20 + y, "kd8bxp.blogspot.com");
  display->drawString(0 + x, 30 + y, "github.com/kd8bxp");
 }

// This array keeps function pointers to all frames
// frames are the single views that slide in
FrameCallback frames[] = { drawFrame1, drawFrame2, drawFrame3 };

// how many frames are there?
int frameCount = 3;

// Overlays are statically drawn on top of a frame eg. a clock
OverlayCallback overlays[] = { msOverlay };
int overlaysCount = 1;

void setup() {
  
 ui.setTargetFPS(30);
 
// You can change this to
  // TOP, LEFT, BOTTOM, RIGHT
  ui.setIndicatorPosition(BOTTOM);

  // Defines where the first frame is located in the bar.
  ui.setIndicatorDirection(LEFT_RIGHT);

  // You can change the transition that is used
  // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
  ui.setFrameAnimation(SLIDE_UP);

  ui.setFrames(frames, frameCount);
  ui.init();
  display.flipScreenVertically();
  
}




void loop() {

int remainingTimeBudget = ui.update();
if (remainingTimeBudget > 0) {
}
taskYIELD();
//yield();
vTaskDelay(10);
}


