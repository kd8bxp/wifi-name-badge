# WIFI Name Badge

This project is based on the D-Duino ESP8266, or the D-Duino ESP32 devices. These devices have a OLED on board.  
There is also code for a TTGO .91 ESP8266 Oled device.  
This project is related to my Wifi Display Badge, which is a MQTT wireless display.  
https://github.com/kd8bxp/Wifi_Display_Badge  

## Versions

1. ESP32 with OLED name Badge - is a simple scrolling name badge.  
        by removing taskYIELD(); and vTaskDelay(10); near the end of the sketch
        add yield(); and the sketch will compile and run on a ESP8266 device.
2. ESP8266 OLED wearable name badge - using a different library created another scrolling name badge.  
3. ESP8266 OLED wearable name badge with wifi scanner - uses the above code, and adds a wifi scanner based on code by Robert Ulbricht  
https://github.com/kd8bxp/a-better-wifi-scanner  
4. ESP8266 Name Badge Weather Station - is a name badge with included Weather display based on code from Squix see for setup instructions:  
https://blog.squix.org/weatherstation-getting-code-adapting-it  
Wifimanager was added for times when you are away from your home wifi network.  
5. TTGO .91 oled esp8266 simple wearable name badge - is based on the ESP8266 OLED wearable name badge above. Mostly pins have changed, there are some minor setting changes for display size.  


## Libraries Needed
You need either the ESP8266 or ESP32 boards loaded in the board manager (or both if you have both)  

SSD1306.h   https://github.com/squix78/esp8266-oled-ssd1306  
ESP_SSD1306.h https://github.com/somhi/ESP_SSD1306  
Adafruit_GFX.h https://github.com/adafruit/Adafruit-GFX-Library  

Other Libraries are included with the respective board managers.  
  
Weather Station Display Librarys, follow the instructions above.

## Video

https://youtu.be/WofG3KXoH4A
https://youtu.be/lGOJQOGoc-w

related:
https://youtu.be/fMKPxThoW1I  

## Usage

## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request

## Support Me

If you find this or any of my projects useful or enjoyable please support me.
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller

## Other Projects

https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w
https://kd8bxp.blogspot.com/


## Credits

Copyright (c) 2017 LeRoy Miller

## License

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>
