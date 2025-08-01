#pragma once

#include <Arduino.h>
#include <ESP8266WiFi.h>


class MyWiFi_STA {
public:
    static IPAddress get_IP();
    static bool is_connected();
    static bool connect(const char* STA_SSID, const char* STA_PASSWORD);
    static void disconnect();

private:
    static bool wait_until_connected(int timeout_seconds);
};
