#include "Window.hpp"

bool Window::init()
{
  Debug::ShowLog("[Window] Initializing");

  createWindow();

  bool WindowSucceed = (bool) window;

  if (!WindowSucceed)
  {
    //TODO: Change SDL_Log for another function/definition
    SDL_Log("Unable to create window SDL: %s", SDL_GetError());
    SDL_Quit();
  }

  return WindowSucceed;
}


void Window::createWindow()
{
  Debug::ShowLog("[Window] Creating");

  Uint32 flags = fullscreen
    ? SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_FULLSCREEN
    : SDL_WINDOW_ALLOW_HIGHDPI;

  window = SDL_CreateWindow(
      windowTitle,
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      width, height,
      flags
  );
};

void Window::destroyWindow()
{
  Debug::ShowLog("[Window] Destroying");
  if (window) SDL_DestroyWindow(window);
  SDL_Quit();
}

void Window::updateWindow()
{
  Debug::ShowLog("[Window] Updating");
  //TODO
}
