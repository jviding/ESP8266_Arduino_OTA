#include "ota.h"

namespace {
    const char* TAG = "OTA";
}


bool OTAUpdate::try_update(const char* ota_url) {
    Logger::info(TAG, "Checking for updates...");

    WiFiClient client;
    ESPhttpUpdate.rebootOnUpdate(false); // Disable automatic reboot after update
    t_httpUpdate_return ret = ESPhttpUpdate.update(client, ota_url);    

    switch (ret) {
        case HTTP_UPDATE_FAILED:
            Logger::error(TAG, "Update failed. Error (%d): %s",
                            ESPhttpUpdate.getLastError(),
                            ESPhttpUpdate.getLastErrorString().c_str());
            return false;
        case HTTP_UPDATE_NO_UPDATES:
            Logger::info(TAG, "No updates available.");
            return true;
        case HTTP_UPDATE_OK:
            Logger::info(TAG, "Update successful. Rebooting...");
            Logger::flush();
            ESP.restart();
            return true;
        default:
            Logger::error(TAG, "Something went wrong.");
            return false;
    }
}
