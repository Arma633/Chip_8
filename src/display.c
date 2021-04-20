#include "main.h"

void initScreen(){
    for(int i = 0; i<LENGTH;i++){
        for (int j = 0; j < WIDTH; j++){
         screen[i][j].position.x = i*SPIXEL;
         screen[i][j].position.y = j*SPIXEL;
         screen[i][j].color = BLACK; // Default color is black

        if(i%(j+1)==0) 
              screen[i][j].color=BLACK; 
            else 
              screen[i][j].color=WHITE; 

        }   
    }


}

void initScreenWindow(){
    screenWindow = NULL;
    screenRenderer = NULL;

    screenWindow = SDL_CreateWindow("Chip8 Emulator", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1220, 720,0);
    if (screenWindow == NULL){
        SDL_Log("screenWindow creation ERROR > %s\n",SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    screenRenderer = SDL_CreateRenderer(screenWindow,-1,SDL_RENDERER_ACCELERATED);
    if(screenRenderer == NULL){
        SDL_Log("screenRenderer creation ERROR > %s\n",SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    colorBlitter = SDL_CreateTexture(screenRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET | SDL_TEXTUREACCESS_STREAMING,WIDTH,LENGTH);
}

void drawPixel(PIXEL pixel){
    if(pixel.color == BLACK){
        SDL_SetRenderTarget(screenRenderer,colorBlitter);
        SDL_SetRenderDrawColor(screenRenderer,0,0,0,SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(screenRenderer,&(pixel.position));
        SDL_SetRenderTarget(screenRenderer,NULL);
       // SDL_RenderCopy(screenRenderer,colorBlitter,NULL,&(pixel.position));

    }

    if(pixel.color == WHITE){
        SDL_SetRenderTarget(screenRenderer,colorBlitter);
        SDL_SetRenderDrawColor(screenRenderer,255,255,255,SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(screenRenderer,&(pixel.position));
        SDL_SetRenderTarget(screenRenderer,NULL);
        //SDL_RenderCopy(screenRenderer,colorBlitter,NULL,&(pixel.position));
        
    }


}

void resetScreen(){
    for(int i = 0; i<LENGTH;i++){
        for(int j = 0; j<WIDTH;j++){
            screen[i][i].color = BLACK;
        }
    }
    for(int i = 0; i<LENGTH;i++){
        for(int j = 0; j<WIDTH;j++){
            drawPixel(screen[i][j]);
        }
    }
}

void updateScreen(){
     for(int i = 0; i<LENGTH;i++){
        for(int j = 0; j<WIDTH;j++){
            drawPixel(screen[i][j]);
        }
    }
    SDL_RenderPresent(screenRenderer);
    
}




    


