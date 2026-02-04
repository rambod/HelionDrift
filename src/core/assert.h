//
// Created by Rambod ghashghaiabdi on 4.02.2026.
//

#ifndef HELIONDRIFT_ASSERT_H
#define HELIONDRIFT_ASSERT_H

#pragma once

#include <string_view>

namespace helion::assertion
{

    void handle_assert(const char* expr,
                       const char* file,
                       int line,
                       std::string_view message);

    void handle_verify(const char* expr,
                       const char* file,
                       int line,
                       std::string_view message);

} // namespace helion::assertion

#ifdef NDEBUG

#define HELION_ASSERT(expr) ((void)0)
#define HELION_ASSERT_MSG(expr, msg) ((void)0)

#else

#define HELION_ASSERT(expr) \
do { \
if (!(expr)) { \
helion::assertion::handle_assert(#expr, __FILE__, __LINE__, {}); \
} \
} while (0)

#define HELION_ASSERT_MSG(expr, msg) \
do { \
if (!(expr)) { \
helion::assertion::handle_assert(#expr, __FILE__, __LINE__, msg); \
} \
} while (0)

#endif

#define HELION_VERIFY(expr) \
((expr) ? true : \
(helion::assertion::handle_verify(#expr, __FILE__, __LINE__, {}), false))

#define HELION_VERIFY_MSG(expr, msg) \
((expr) ? true : \
(helion::assertion::handle_verify(#expr, __FILE__, __LINE__, msg), false))

class assert {

};



#endif //HELIONDRIFT_ASSERT_H
