#include "wifi_sta.h"
#include "../../logger/logger.h"

namespace {
    const char* TAG = "WiFi-STA";
}


IPAddress MyWiFi_STA::get_IP() {
    return WiFi.localIP();
}

bool MyWiFi_STA::is_connected() {
    return WiFi.status() == WL_CONNECTED;
}

bool MyWiFi_STA::connect(const char* STA_SSID, const char* STA_PASSWORD) {
    if (!is_connected()) {
        WiFi.mode(WIFI_STA);
        WiFi.disconnect();      // Soft reset WiFi to ensure clean state
        delay(250);
        WiFi.begin(STA_SSID, STA_PASSWORD);
        Logger::info(TAG, "Connecting to SSID: %s", STA_SSID);
        return wait_until_connected(30);     
    } else {
        Logger::warning(TAG, "Was already connected.");
        return true;
    }
}

bool MyWiFi_STA::wait_until_connected(int timeout_seconds) {
    int seconds = 0;
    while (seconds < timeout_seconds) {
        delay(1000);
        switch (WiFi.status()) {
            case WL_CONNECTED:
                Logger::info(TAG, "Connected.");
                return true;
            case WL_NO_SSID_AVAIL:
                Logger::error(TAG, "Failed connecting. SSID not available.");
                return false;
            case WL_CONNECT_FAILED:
                Logger::error(TAG, "Failed connecting. Incorrect password?");
                return false;
            default:
                Logger::info(TAG, "Waiting for connection... (%d seconds)", ++seconds);
        }
    }
    Logger::error(TAG, "Failed connecting. Connection timed out.");
    return false;
}

void MyWiFi_STA::disconnect() {
    if (is_connected()) {
        WiFi.disconnect();
        Logger::info(TAG, "Disconnected.");
    } else {
        Logger::warning(TAG, "Was already disconnected.");
    }
}
