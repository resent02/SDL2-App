#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>


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
    SDL_Window *win = SDL_CreateWindow("Title re", 0, 0, displayMode.w, displayMode.h, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
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

    SDL_Rect player_RECT;
    player_RECT.x = 0;   //Padding in Х
    player_RECT.y = 0;   //Padding in Y
    player_RECT.w = 333; //Width
    player_RECT.h = 227; //Height

    SDL_Rect background_RECT;
    background_RECT.x = 0;
    background_RECT.y = 0;
    background_RECT.w = displayMode.w;
    background_RECT.h = displayMode.h;

    const int player_WIGHT = 333;   //Width of img
    const int player_HEIGH = 227;   //Height of img
    double TESTtexture_SCALE = 1.0; //Coefficient

    SDL_Texture *player =  IMG_LoadTexture(ren,"..\\res\\player.png");

    return 0;
}
