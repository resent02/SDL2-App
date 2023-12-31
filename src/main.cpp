#include "Screen.h"
#include <cmath>

struct vec3 {
    float x, y, z;
};

void rotate(vec3 &pont, float x = 1, float y = 1, float z = 1) {
    float rad = 0;
    
}

void line(Screen &screen, float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;

    float length = std::sqrt(dx * dx + dy * dy);
    float angle = std::atan2(dy, dx);
    for (float i = 0; i < length; i++) {
        screen.pixel(x1 + std::sin(angle) * i,
                     y1 + std::cos(angle) * i);
    }

}

int main(int argc, char *args[]) {
    Screen screen;
    for (int i = 0; i < 100; ++i) {
        screen.pixel(rand() % 680, rand() % 480);
    }
    line(screen, 100, 100, 200, 100);
    line(screen, 200, 100, 200, 0);
    while (true) {
        screen.show();
        screen.input();
    }
    return 0;
}
