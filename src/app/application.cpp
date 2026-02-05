//
// Created by Rambod ghashghaiabdi on 4.02.2026.
//

#include "application.h"
#include "log.h"
#include "profiler.h"
#include "renderer.h"
#include <chrono>
#include <thread>

namespace helion {

     application::application(){
LOG_INFO("Application started");
}
     application::~application(){
LOG_INFO("Application stopped");
}
    void application::run()
     {
         helion::renderer renderer;

         using clock = std::chrono::steady_clock;
         LOG_INFO("Application starting main loop");
         auto previousTime = clock::now();
         double accumulator = 0.0;

         constexpr double MAX_FRAME_TIME = 0.25; // avoid spiral of death
         bool running = true;
         std::uint64_t tickCount = 0;
         while (running)
         {
             const auto currentTime = clock::now();
             const std::chrono::duration<double> frameTime = currentTime - previousTime;

             previousTime = currentTime;

             double deltaTime = frameTime.count();
             if (deltaTime > MAX_FRAME_TIME)
             {
                 deltaTime = MAX_FRAME_TIME;
             }
             accumulator += deltaTime;
             while (accumulator >= FIXED_DT)
             {
                 {
                     HELION_PROFILE_SCOPE("SimulationTick");
                     tick();
                 }
                 accumulator -= FIXED_DT;
                 ++tickCount;
                 if (tickCount >= 300)
                 {
                     running = false;
                 }
             }
             //sleep a bit to avoid burning CPU
             std::this_thread::sleep_for(std::chrono::milliseconds(1));
             renderer.begin_frame();
             // nothing drawn yet
             renderer.end_frame();
         }
         LOG_INFO("Application main loop exited");

     }
    void application::tick()
     {
         // Stub simulation update
         LOG_TRACE("Simulate tick");
     }
} // helion