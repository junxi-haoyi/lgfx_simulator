#pragma once

#include "../LovyanGFX/src/lgfx/v1/platforms/device.hpp"
#include "../LovyanGFX/src/lgfx/v1/platforms/common.hpp"
#include "../LovyanGFX/src/lgfx/v1/lgfx_filesystem_support.hpp"
#include "../LovyanGFX/src/lgfx/v1/LGFXBase.hpp"
#include "../LovyanGFX/src/lgfx/v1/LGFX_Sprite.hpp"
#include "../LovyanGFX/src/lgfx/v1/LGFX_Button.hpp"
#include "../LovyanGFX/src/lgfx/v1/Light.hpp"

// #include "../LovyanGFX/src/lgfx/v1_autodetect/common.hpp"
#include "../LovyanGFX/src/lgfx/v1/platforms/sdl/Panel_sdl.hpp"

#include <SDL2/SDL.h>






namespace lgfx
{
    inline namespace v1
    {
        class LGFX : public LGFX_Device
        {
            lgfx::Panel_sdl _panel_instance;

            bool init_impl(bool use_reset, bool use_clear)
            {
                return LGFX_Device::init_impl(false, use_clear);
            }

            public:
            LGFX(int width = 320, int height = 240, uint_fast8_t scaling_x = 0, uint_fast8_t scaling_y = 0)
            {
                auto cfg = _panel_instance.config();
                cfg.memory_width = width;
                cfg.panel_width = width;
                cfg.memory_height = height;
                cfg.panel_height = height;
                _panel_instance.config(cfg);
                if(scaling_x == 0) { scaling_x = 1; }
                if(scaling_y == 0) { scaling_y = scaling_x; }
                _panel_instance.setScaling(scaling_x, scaling_y);
                setPanel(&_panel_instance);
                _board = board_t::board_SDL;
            }
        };
    }
}


using LGFX = lgfx::LGFX;




