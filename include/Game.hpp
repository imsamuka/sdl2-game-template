#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "DeltaTime.hpp"
#include "Window.hpp"
#include "Debug.hpp"


class Game {

public:

  ~Game()
  {
    Debug::ShowLog("[Game] Destroying");
  }

  bool init();
  void run();
  [[nodiscard]] bool running() const { return isRunning; };

private:

  void handleEvents() ;
  void update(DeltaTime dt);
  void render();

  bool isRunning;
  Uint32 lastTime;
  Window window;
  SDL_Event event;
};