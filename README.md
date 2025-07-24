# ESP8266_Arduino_OTA

OTA updates for ESP8266 projects, using the Arduino framework.

# Build tools
Install arduino-cli, but not with snap.
Snap sandbox doesn't allow access to system Python.

Install the ESP8266 core:
\$ arduino-cli config add board_manager.additional_urls \
    http://arduino.esp8266.com/stable/package_esp8266com_index.json
\$ arduino-cli core update-index
\$ arduino-cli core install esp8266:esp8266

List supported boards:
\$ arduino-cli board listall


# Build
For ESP8266-12F, use esp8266:esp8266:generic.
\$ arduino-cli compile --fqbn esp8266:esp8266:generic --build-path ./build main

Builds to:
./build/main.ino.bin

# Flash
Using esptool:
\$ esptool.py --port /dev/ttyUSB0 --baud 115200 write_flash 0x00000 ./main.ino.bin
