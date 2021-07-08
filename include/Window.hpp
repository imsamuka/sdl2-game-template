#pragma once

#include <SDL2/SDL.h>
#include "Debug.hpp"

const static int defaultWidth = 256 * 3;
const static int defaultHeight =  224 * 3;
const static bool defaultFullscreen =  224 * 3;

const static char* windowTitle = "LittleGame";

struct Window
{
  ~Window(){ destroyWindow(); }

  int width = defaultWidth;
  int height = defaultHeight;
  bool fullscreen = defaultFullscreen;

  bool init();
  void updateWindow();

private:
  void createWindow();
  void destroyWindow();

  SDL_Window* window;
};
