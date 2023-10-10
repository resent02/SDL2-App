#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>

class Window {
    SDL_Window *window = nullptr;
    SDL_Surface *screenSurface = nullptr;
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
public:
    
    Window() {
        //Initializing sdl video module
        if (SDL_Init(SDL_INIT_VIDEO)) {
            std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        } else {
            //Create window
            window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                      SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

            if (window == nullptr) {
                std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            }else{
                //Get window surface
                screenSurface = SDL_GetWindowSurface(window);
            };
        }
    }

    void loop() {

        //Fill the surface white
        SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

        //Update the surface
        SDL_UpdateWindowSurface(window);

        //Hack to get window to stay up
        SDL_Event e;
        bool quit = false;
        while (!quit) {
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) quit = true;
            }
        }
        SDL_DestroyWindow(window);

        SDL_Quit();

    }

    ~Window() = default;
};

int main(int argc, char *args[]) {
    Window window;
    window.loop();
    return 0;
}
