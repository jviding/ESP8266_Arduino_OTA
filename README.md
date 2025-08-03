# ESP8266_Arduino_OTA

OTA updates for ESP8266 projects, using the Arduino framework.

# Build tools
Install arduino-cli, but not with snap. <br/>
Snap sandbox doesn't allow accessing system Python.

Install the ESP8266 core: <br/>
\$ arduino-cli config add board_manager.additional_urls \ <br/>
    http://arduino.esp8266.com/stable/package_esp8266com_index.json <br/>
\$ arduino-cli core update-index <br/>
\$ arduino-cli core install esp8266:esp8266

List supported boards: <br/>
\$ arduino-cli board listall

# Build
For ESP8266-12F, use esp8266:esp8266:generic. <br/>
\$ arduino-cli compile --fqbn esp8266:esp8266:generic --build-path ./build .

Builds to: <br/>
./build/main.ino.bin

# Flash
Using esptool: <br/>
\$ esptool.py --port /dev/ttyUSB0 --baud 115200 write_flash 0x00000 ./ESP8266_Arduino_OTA.ino.bin

# Monitor
Read serial: <br/>
\$ minicom -D /dev/ttyUSB0 -o -b 115200

# Serve OTA updates
See the 'server.php' file for reference.
