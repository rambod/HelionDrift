//
// Created by Rambod ghashghaiabdi on 5.02.2026.
//

#include "renderer.h"
#include "log.h"

#include <raylib.h>

namespace helion
{

    renderer::renderer()
    {
        InitWindow(1280, 720, "Helion Drift");
        SetTargetFPS(60);

        LOG_INFO("Renderer initialized");
    }

    renderer::~renderer()
    {
        CloseWindow();
        LOG_INFO("Renderer shutdown");
    }

    void renderer::begin_frame()
    {
        BeginDrawing();
        ClearBackground(BLACK);
    }

    void renderer::end_frame()
    {
        EndDrawing();
    }

    bool renderer::should_close() const
    {
        return WindowShouldClose();
    }

} // namespace helion
