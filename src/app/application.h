//
// Created by Rambod ghashghaiabdi on 4.02.2026.
//

#ifndef HELIONDRIFT_APPLICATION_H
#define HELIONDRIFT_APPLICATION_H
#include <cstdint>

namespace helion {

class application {
    public:
        application();
        ~application();

        application(const application &) = delete;
        application& operator=(const application &) = delete;

        void run();
    private:
        void tick();

        static constexpr std::uint32_t TICK_PER_SECOND = 60;
        static constexpr double FIXED_DT = 1.0 / TICK_PER_SECOND;

};

} // helion

#endif //HELIONDRIFT_APPLICATION_H
