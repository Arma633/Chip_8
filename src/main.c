#include "main.h"

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

    system("PAUSE");

    return 0;
}