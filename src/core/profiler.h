//
// Created by Rambod ghashghaiabdi on 4.02.2026.
//

#ifndef HELIONDRIFT_PROFILER_H
#define HELIONDRIFT_PROFILER_H

#pragma once
#include <string>
#include <chrono>

namespace helion::profile
{
    class ScopedTimer
    {
        public:
        explicit ScopedTimer(std::string_view name);
        ~ScopedTimer();

        ScopedTimer(const ScopedTimer&) = delete;
        ScopedTimer& operator=(const ScopedTimer&) = delete;

        private:
        std::string_view m_name;
        std::chrono::steady_clock::time_point m_start;

    };
}

#ifndef HELION_ENABLE_PROFILING
#ifdef NDEBUG
#define HELION_ENABLE_PROFILING 0
#else
#define HELION_ENABLE_PROFILING 1
#endif
#endif

#if HELION_ENABLE_PROFILING

#define HELION_PROFILE_SCOPE(name) \
helion::profile::ScopedTimer _helionScopedTimer##__LINE__(name)

#else

#define HELION_PROFILE_SCOPE(name) ((void)0)

#endif



#endif //HELIONDRIFT_PROFILER_H
