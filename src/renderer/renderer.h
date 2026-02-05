//
// Created by Rambod ghashghaiabdi on 5.02.2026.
//

#ifndef HELIONDRIFT_RENDERER_H
#define HELIONDRIFT_RENDERER_H



#pragma once

namespace helion
{

    class renderer
    {
    public:
        renderer();
        ~renderer();

        renderer(const renderer&) = delete;
        renderer& operator=(const renderer&) = delete;

        void begin_frame();
        void end_frame();

        bool should_close() const;
    };

} // namespace helion




#endif //HELIONDRIFT_RENDERER_H
