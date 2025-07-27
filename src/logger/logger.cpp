#include "logger.h"

LogLevel Logger::_log_level = LOG_LEVEL_DEBUG;

void Logger::start(LogLevel level) {
    Serial.begin(115200);
    while (!Serial) { ; } // Wait for Serial to be ready
    Serial.println("Serial started");
    _log_level = level;
    Serial.println("Logger started");
}

void Logger::debug(const char* tag, const char* message, ...) {
    if (LOG_LEVEL_DEBUG >= _log_level) {
        va_list args;
        va_start(args, message);
        write("[D]", tag, message, args);
        va_end(args);
    }
}

void Logger::info(const char* tag, const char* message, ...) {
    if (LOG_LEVEL_INFO >= _log_level) {
        va_list args;
        va_start(args, message);
        write("[I]", tag, message, args);
        va_end(args);
    }
}

void Logger::warning(const char* tag, const char* message, ...) {
    if (LOG_LEVEL_WARNING >= _log_level) {
        va_list args;
        va_start(args, message);
        write("[W]", tag, message, args);
        va_end(args);
    }
}

void Logger::error(const char* tag, const char* message, ...) {
    if (LOG_LEVEL_ERROR >= _log_level) {
        va_list args;
        va_start(args, message);
        write("[E]", tag, message, args);
        va_end(args);
    }
}

void Logger::write(const char* level_tag, const char* tag, const char* message, va_list args) {
    // Format string with variadic arguments
    char temp[128];
    vsnprintf(temp, sizeof(temp), message, args);
    // Print the formatted message
    Serial.print(level_tag);
    Serial.printf("[%s] ", tag);
    Serial.println(temp);
}
