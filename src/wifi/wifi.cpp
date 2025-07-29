#include "wifi.h"

namespace {
    const char* TAG = "WiFi";
}


IPAddress MyWiFi::get_AP_IP() {
    return WiFi.softAPIP();
}

IPAddress MyWiFi::get_STA_IP() {
    return WiFi.localIP();
}

void MyWiFi::start_AP(const char* AP_SSID, const char* AP_PASSWORD) {
    WiFi.mode(WIFI_AP);
    WiFi.softAP(AP_SSID, AP_PASSWORD);
    Logger::info(TAG, "Access Point started.");
    Logger::info(TAG, "SSID: %s", AP_SSID);
    Logger::info(TAG, "Password: %s", AP_PASSWORD);
}

void MyWiFi::stop_AP() {
    WiFi.softAPdisconnect(true);
    Logger::info(TAG, "Access Point stopped.");
}

void MyWiFi::start_STA(const char* STA_SSID, const char* STA_PASSWORD) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(STA_SSID, STA_PASSWORD);
    Logger::info(TAG, "Connecting to WiFi as Station.");
    int seconds = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Logger::info(TAG, "Attempting connection... (%d seconds)", ++seconds);
    }
    Logger::info(TAG, "Connected.");
}

void MyWiFi::stop_STA() {
    WiFi.disconnect();
    Serial.println("Disconnected from WiFi as Station");
}
