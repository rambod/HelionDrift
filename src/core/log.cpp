//
// Created by Rambod ghashghaiabdi on 4.02.2026.
//

#include "log.h"

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdio>

namespace helion::log
{
    static Level g_current_level = Level::Info;

    void set_level(Level level)
    {
        g_current_level = level;
    }

    Level get_level()
    {
        return g_current_level;
    }

    static void write_timestamp(std::ostream& out)
    {
        using clock = std::chrono::system_clock;
        const auto now = clock::now();
        const std::time_t now_time = clock::to_time_t(now);

        std::tm tm{};
#if defined(_WIN32)
        localtime_s(&tm, & now_time);
#else
        localtime_r(&now_time, &tm);
#endif
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &tm);
        out << "[" << buffer << "]";

    }

    static const char* to_string(Level level)
    {
        switch (level)
        {
            case Level::Trace: return "Trace";
            case Level::Info: return "Info";
            case Level::Warn: return "Warn";
            case Level::Error: return "Error";
        }
        return "Unknown";
    }
    void write(Level level, std::string_view message)
    {
        if (level < g_current_level)
        {
            return;
        }
        std::ostream& out = (level == Level::Error) ? std::cerr : std::cout;
#if HELION_LOG_TIMESTAMP
        write_timestamp(out);
#endif
        out << " [" << to_string(level) << "] " << message << std::endl;
    }
}