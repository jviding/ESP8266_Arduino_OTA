#pragma once
#include <Arduino.h>


enum LogLevel {
    LOG_LEVEL_DEBUG = 0,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
};

class Logger {
public:
    static void start(LogLevel level);
    static void set_log_level(LogLevel level);

    static void debug(const char* tag, const char* message, ...);
    static void info(const char* tag, const char* message, ...);
    static void warning(const char* tag, const char* message, ...);
    static void error(const char* tag, const char* message, ...);

private:
    static LogLevel _log_level;
    static void start_serial();
    static void write(const char* level_tag, const char* tag, const char* message, va_list args);
};
