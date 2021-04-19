// void CPU_initCPU(CPU cpu);
// void CPU_deductRef(CPU cpu);

#include "main.h"

void CPU_initCPU(CPU* cpu) {
    
    for(int i = 0; i<LMEMORY; i++){
        cpu->CPU_memory[i] = 0;
    }
    for(int i = 0; i<NREG;i++){
        cpu->CPU_reg[i] = 0;
        cpu->CPU_jump[i] = 0;
    }
    cpu->CPU_regI = 0;
    cpu->CPU_pc = MEMBEG;
    cpu->CPU_pcCounter = 0;
    cpu->CPU_refSystem = 0;
    cpu->CPU_refSound = 0;
}

void CPU_deductRef(CPU* cpu){
    if (cpu->CPU_refSystem > 0) {
        cpu->CPU_refSystem--;
    }
    
    if (cpu->CPU_refSound > 0) {
        cpu->CPU_refSound--;
    }
}