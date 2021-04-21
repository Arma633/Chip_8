#include <SDL.h>
#define BLACK 0
#define WHITE 1
#define LENGTH 64 
#define WIDTH 32
#define SPIXEL 2
#define SCREEN_WIDTH WIDTH * SPIXEL
#define SCREEN_LENGTH LENGTH * SPIXEL

typedef struct{
    SDL_Rect position;
    uint8_t color;
}PIXEL;

SDL_Window* screenWindow ;
SDL_Renderer* screenRenderer;
PIXEL screen[LENGTH][WIDTH];
SDL_Event event;

void initScreen();
void initScreenWindow();
void drawPixel(PIXEL pixel);
void resetScreen();
void updateScreen();



