#include "wifi.h"
#include "../logger/logger.h"
#include "wifi_AP/wifi_ap.h"
#include "wifi_STA/wifi_sta.h"

namespace {
    const char* TAG = "WiFi";
}


// WIFI AP

IPAddress MyWiFi::get_AP_IP() {
    return MyWiFi_AP::get_IP();
}

void MyWiFi::AP_start(const char* AP_SSID, const char* AP_PASSWORD) {
    MyWiFi_AP::start(AP_SSID, AP_PASSWORD);
}

void MyWiFi::AP_stop() {
    MyWiFi_AP::stop();
}


// WIFI STA

IPAddress MyWiFi::get_STA_IP() {
    return MyWiFi_STA::get_IP();
}

bool MyWiFi::is_STA_connected() {
    return MyWiFi_STA::is_connected();
}

bool MyWiFi::STA_connect(const char* STA_SSID, const char* STA_PASSWORD) {
    return MyWiFi_STA::connect(STA_SSID, STA_PASSWORD);
}

void MyWiFi::STA_disconnect() {
    MyWiFi_STA::disconnect();
}
