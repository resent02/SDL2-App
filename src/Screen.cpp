#include "Screen.h"

Screen::Screen() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 1, 1);
}

void Screen::pixel(float x, float y) {
    auto *p = new SDL_FPoint;
    p->x = x;
    p->y = y;
    points.emplace_back(*p);
}

void Screen::show() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (auto &point: points) {
        SDL_RenderDrawPointF(renderer, point.x, point.y);
    }
    SDL_RenderPresent(renderer);
}

void Screen::input(){
    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT){
            SDL_Quit();
            exit(0);
        }
    }
}

void Screen::clearPoints(){
    points.clear();
};