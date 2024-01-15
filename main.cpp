#include <iostream>
#include "inc/lgfx_sim_sdl.hpp"

#define LGFX_USE_V1

LGFX Device;

__attribute__((weak))
int user_func(bool* running)
{
  Device.init();
  do
  {
    Device.clearDisplay(0xFFFFFF);
  } while (*running);
  return 0;
}



int main(int, char**)
{
    
    return lgfx::Panel_sdl::main(user_func);
    
}
