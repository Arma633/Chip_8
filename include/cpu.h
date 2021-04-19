#define LMEMORY 4096
#define NREG 16
#define MEMBEG 512


typedef struct {
    uint8_t CPU_memory[LMEMORY]; // Main memory of 4096 bytes
    uint8_t CPU_reg[16]; // The 16 register of the chip8 CPU, from V0 to VF
    uint16_t CPU_regI;
    uint16_t CPU_jump[16]; // Stack related vars -> used to store the old values of the pc (16 level)
    uint16_t CPU_pc; // Stack related vars -> the PC, used to jump to another memory address
    uint8_t CPU_pcCounter; // Stack related vars -> the counter of the CPU_jump
    uint8_t CPU_refSystem; // 60hz = 1/60 sec = 16ms
    uint8_t CPU_refSound; // 60hz = 1/60 sec = 16ms
} CPU;


void CPU_initCPU(CPU* cpu);
void CPU_deductRef(CPU* cpu);