#include <SDL.h>
#define BLACK 0
#define WHITE 1
#define LENGTH 32 
#define WIDTH 64
#define SPIXEL 8
#define SCREEN_WIDTH WIDTH * SPIXEL
#define SCREEN_LENGTH LENGTH * SPIXEL

typedef struct{
    SDL_Rect position;
    uint8_t color;
}PIXEL;

SDL_Window* screenWindow ;
SDL_Renderer* screenRenderer;
SDL_Texture* colorBlitter;
PIXEL screen[LENGTH][WIDTH];

void initScreen();
void initScreenWindow();
void drawPixel(PIXEL pixel);
void resetScreen();
void updateScreen();



