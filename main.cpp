#include <iostream>
#include <SDL.h>

int main(int argc, char *args[]) {
    // Init SDL module
    SDL_DisplayMode displayMode;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Getting info about screen
    if (SDL_GetDesktopDisplayMode(0, &displayMode) != 0) {
        std::cout << "GetDesktopDisplayMode Error:" << SDL_GetError();
        return 1;
    };

    //Creating window
    SDL_Window *win = SDL_CreateWindow("Title re", 0, 0, displayMode.w, displayMode.h, SDL_WINDOW_SHOWN);
    if (win == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    //Init renderer (renderer what will render our sprite)
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    return 0;
}
