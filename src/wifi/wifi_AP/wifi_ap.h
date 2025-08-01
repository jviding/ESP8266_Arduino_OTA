#pragma once

#include <Arduino.h>
#include <ESP8266WiFi.h>


class MyWiFi_AP {
public:
    static IPAddress get_IP();
    static void start(const char* AP_SSID, const char* AP_PASSWORD);
    static void stop();
};
