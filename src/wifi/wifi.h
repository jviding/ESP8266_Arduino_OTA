#pragma once

#include <Arduino.h>
#include <ESP8266WiFi.h>


class MyWiFi {
public:
    // WIFI AP
    static IPAddress get_AP_IP();
    static void AP_start(const char* AP_SSID, const char* AP_PASSWORD);
    static void AP_stop();

    // WIFI STA
    static IPAddress get_STA_IP();
    static bool is_STA_connected();
    static bool STA_connect(const char* STA_SSID, const char* STA_PASSWORD);
    static void STA_disconnect();
};
