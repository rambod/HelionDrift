//
// Created by Rambod ghashghaiabdi on 4.02.2026.
//

#ifndef HELIONDRIFT_LOG_H
#define HELIONDRIFT_LOG_H
#pragma once
#ifndef HELION_LOG_TIMESTAMP
#define HELION_LOG_TIMESTAMP 1
#endif

#include <cstdint>

namespace helion::log
{
    enum class Level : std::uint8_t
    {
        Trace,
        Info,
        Warn,
        Error,
    };
    class log {

    };
}

#include <string_view>

namespace helion::log
{
    void set_level(Level level);
    Level get_level();

    void write(Level level, std::string_view msg);
}

#ifndef HELION_LOG_LEVEL
#ifdef NDEBUG
#define HELION_LOG_LEVEL helion::log::Level::Info
#else
#define HELION_LOG_LEVEL helion::log::Level::Trace
#endif
#endif

#define LOG_TRACE(msg) \
do { \
if (HELION_LOG_LEVEL <= helion::log::Level::Trace) \
helion::log::write(helion::log::Level::Trace, msg); \
} while (0)

#define LOG_INFO(msg) \
do { \
if (HELION_LOG_LEVEL <= helion::log::Level::Info) \
helion::log::write(helion::log::Level::Info, msg); \
} while (0)

#define LOG_WARN(msg) \
do { \
if (HELION_LOG_LEVEL <= helion::log::Level::Warn) \
helion::log::write(helion::log::Level::Warn, msg); \
} while (0)

#define LOG_ERROR(msg) \
do { \
helion::log::write(helion::log::Level::Error, msg); \
} while (0)


#endif //HELIONDRIFT_LOG_H
