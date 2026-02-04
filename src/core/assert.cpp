//
// Created by Rambod ghashghaiabdi on 4.02.2026.
//

#include "assert.h"

#include "log.h"
#include <cstdlib>

namespace helion::assertion
{
    void handle_assert(const char* expr,
                       const char* file,
                       int line,
                       std::string_view message)
    {
        char buffer[512];

        if (!message.empty())
        {
            std::snprintf(buffer, sizeof(buffer),
                          "ASSERT FAILED: %s | %.*s (%s:%d)",
                          expr,
                          static_cast<int>(message.size()), message.data(),
                          file, line);
        }
        else
        {
            std::snprintf(buffer, sizeof(buffer),
                          "ASSERT FAILED: %s (%s:%d)",
                          expr, file, line);
        }

        LOG_ERROR(buffer);

#if defined(_MSC_VER)
        __debugbreak();
#else
        std::abort();
#endif
    }


    void handle_verify(const char* expr,
                   const char* file,
                   int line,
                   std::string_view message)
    {
        char buffer[512];

        if (!message.empty())
        {
            std::snprintf(buffer, sizeof(buffer),
                          "VERIFY FAILED: %s | %.*s (%s:%d)",
                          expr,
                          static_cast<int>(message.size()), message.data(),
                          file, line);
        }
        else
        {
            std::snprintf(buffer, sizeof(buffer),
                          "VERIFY FAILED: %s (%s:%d)",
                          expr, file, line);
        }

        LOG_ERROR(buffer);
    }


} // namespace helion::assertion
