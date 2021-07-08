#include "Game.hpp"

bool Game::init(){
  Debug::ShowLog("[Game] Initializing");

  // Try to initialize SDL Video and Audio
  bool SLDSucceed = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == 0;
  if (!SLDSucceed) SDL_Log("Unable to initialize SDL: %s", SDL_GetError());

  // Only initialize window, if SLD succeed
  return SLDSucceed && window.init();
}

void Game::run()
{
  Debug::ShowLog("[Game] Running");

  isRunning = true;
  lastTime = SDL_GetTicks();

  while (isRunning)
  {
    // Get the deltaTime
    Uint32 time = SDL_GetTicks();
    DeltaTime dt = (time - lastTime) / 1000;
    lastTime = time;

    handleEvents();
    update(dt);
    render();

    isRunning = false;
  }
};


void Game::handleEvents()
{
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT)
    {
        isRunning = false;
        return;
    }

    //TODO: handleEvents Scene

    switch (event.type) {
      case SDL_KEYUP:
        switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_E:
                break;
            default:
                break;
        }
        break;
      default:
        break;
    }
  }
};

void Game::update(DeltaTime dt)
{
  //TODO: Check if scene finished -> call scene callback
  //TODO: Update Scene
};

void Game::render()
{
  //TODO: Render Scene
};