#pragma once

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "../logger/logger.h"


class MyWiFi {
public:
    static IPAddress get_AP_IP();
    static IPAddress get_STA_IP();
    
    static void start_AP(const char* AP_SSID, const char* AP_PASSWORD);
    static void stop_AP();

    static void start_STA(const char* STA_SSID, const char* STA_PASSWORD);
    static void stop_STA();
};