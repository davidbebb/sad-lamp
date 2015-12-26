Notes
===============================

### ESP8266

 - set ip address https://www.arduino.cc/en/Reference/WiFiConfig
 - useful simple esp8266 web server example https://learn.adafruit.com/esp8266-temperature-slash-humidity-webserver/code
 - esp8266 arduino libs, including esp webserver https://github.com/sandeepmistry/esp8266-Arduino/tree/master/esp8266com/esp8266/libraries
 - useful note on get/put/post/delete (CRUD) implementation (taken from [here](https://github.com/sandeepmistry/esp8266-Arduino/blob/master/esp8266com/esp8266/libraries/ESP8266WebServer/examples/SDWebServer/SDWebServer.ino), line 264 onwards)

``
server.on("/list", HTTP_GET, printDirectory);
server.on("/edit", HTTP_DELETE, handleDelete);
server.on("/edit", HTTP_PUT, handleCreate);
server.on("/edit", HTTP_POST, [](){ returnOK(); });
``
- eeprom read/write values (useful for storing defaults for brightness) https://github.com/sandeepmistry/esp8266-Arduino/blob/master/esp8266com/esp8266/libraries/EEPROM/examples/eeprom_write/eeprom_write.ino
