#include "main.h"

void pause();

int main(int argc, char *argv[]) {
    /*CPU cpu;
    CPU* cpuPtr = &cpu;
    CPU_initCPU(cpuPtr); */  

    if(SDL_Init(SDL_INIT_VIDEO) == -1){
        SDL_Log("Init SDL ERROR > %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    initScreen();

    initScreenWindow();

    updateScreen();
    
    

    pause();
   
    return 0;
}


void pause() 
{ 

    Uint8 next=1; 
 
    do 
    { 
        SDL_WaitEvent(&event); 

        switch(event.type) 
         { 
             case SDL_QUIT: 
                    next=0; 
                    break; 
             case SDL_KEYDOWN: 
                    next=0; 
                    break; 
             default: break; 
         } 
    }while(next==1); 

}