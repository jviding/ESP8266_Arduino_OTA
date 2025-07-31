#pragma once

#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>
#include "../logger/logger.h"


class OTAUpdate {
public:
    static bool try_update(const char* url);
};
