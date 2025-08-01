#include "wifi_ap.h"
#include "../../logger/logger.h"

namespace {
    const char* TAG = "WiFi-AP";
}


IPAddress MyWiFi_AP::get_IP() {
    return WiFi.softAPIP();
}

void MyWiFi_AP::start(const char* AP_SSID, const char* AP_PASSWORD) {
    WiFi.mode(WIFI_AP);
    WiFi.softAP(AP_SSID, AP_PASSWORD);
    Logger::info(TAG, "Access Point started.");
    Logger::info(TAG, "SSID: %s", AP_SSID);
    Logger::info(TAG, "Password: %s", AP_PASSWORD);
}

void MyWiFi_AP::stop() {
    WiFi.softAPdisconnect(true);
    Logger::info(TAG, "Access Point stopped.");
}
