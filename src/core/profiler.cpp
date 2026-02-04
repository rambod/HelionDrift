//
// Created by Rambod ghashghaiabdi on 4.02.2026.
//

#include "profiler.h"
#include "log.h"

#include <chrono>
#include <cstdint>

namespace helion::profile
{

    using Clock = std::chrono::steady_clock;

    static std::int64_t to_microseconds(Clock::duration d)
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
    }

    ScopedTimer::ScopedTimer(std::string_view name)
        : m_name(name)
        , m_start(Clock::now())
    {
    }

    ScopedTimer::~ScopedTimer()
    {
        const auto end = Clock::now();
        const auto elapsed = to_microseconds(end - m_start);

        char buffer[128];
        std::snprintf(buffer, sizeof(buffer),
                      "[PROFILE] %.*s: %.3f ms",
                      static_cast<int>(m_name.size()), m_name.data(),
                      static_cast<double>(elapsed) / 1000.0);

        LOG_INFO(buffer);
    }

} // namespace helion::profile
