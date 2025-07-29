#include "logger.h"

static const char* TAG = "Logger";
LogLevel Logger::_log_level = LOG_LEVEL_DEBUG;


void Logger::start(LogLevel level) {
    start_serial();
    set_log_level(level);
    info(TAG, "Logger started.");
}

void Logger::start_serial() {
    Serial.begin(115200);
    while (!Serial) { ; } // Wait for Serial to be ready
    Serial.println("[!][Logger] Serial started.");
}

void Logger::set_log_level(LogLevel level) {  
    if (level < LOG_LEVEL_DEBUG || level > LOG_LEVEL_ERROR) {
        _log_level = LOG_LEVEL_DEBUG;
        warning(TAG, "Invalid log level provided.");
        warning(TAG, "Defaulting to log level DEBUG.");
    } else {
        _log_level = level;
        static const char* log_levels_str_arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
        info(TAG, "Log level set to: %s", log_levels_str_arr[_log_level]);
    }
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
