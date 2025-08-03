#include <Arduino.h>
#include "config.h"
#include "src/logger/logger.h"
#include "src/wifi/wifi.h"
#include "src/ota_update/ota.h"

namespace {
  const char* TAG = "Main";
}


// TODO: Modify bootloader for asymmetric partitions
// Partition A: OTA updater - Run update, reboot to Partition B
// Partition B: Program - Check for updates, if available, reboot to Partition A

// TODO: First boot, start AP and ask for credentials
// Save credentials to non-volatile storage (nvs_flash)

// TODO: Check NVS for credentials, connect to STA
// Run program

// TODO: Check for OTA updates
// If available, switch partitions and reboot

// TODO: OTA error handling, if update fails
// What then?


void setup() {
  Logger::start(LOG_LEVEL_DEBUG);
  MyWiFi::STA_connect(WIFI_STA_SSID, WIFI_STA_PASSWORD);
}

void loop() {
  int firmware_version = 0;
  Logger::info(TAG, "Firmware version: %d", firmware_version);

  delay(2000);

  OTAUpdate::try_update(OTA_UPDATE_URL);

  delay(2000);
 
  // TODO: Check if STA disconnected, reconnect
}
