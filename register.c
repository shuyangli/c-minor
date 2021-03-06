#include "register.h"
#include <stdio.h>      // fprintf
#include <stdlib.h>     // exit

// we'll keep track of allocation status of all 16 registers
int register_allocation_table[16] = {
    //  rax rbx rcx rdx rsi rdi rsp rbp
        1,  0,  1,  1,  1,  1,  1,  1,
    //  r8  r9  r10 r11 r12 r13 r14 r15
        1,  1,  0,  0,  0,  0,  0,  0
};

const char *register_name(int r) {
    static const char *register_name_table[16] = {
        "%rax", "%rbx", "%rcx", "%rdx",
        "%rsi", "%rdi", "%rsp", "%rbp",
        "%r8",  "%r9",  "%r10", "%r11",
        "%r12", "%r13", "%r14", "%r15"
    };

    if (r >= 0 && r < 16) {
        return register_name_table[r];
    } else {
        fprintf(stderr, "cminor: unknown register %d passed into register_name\n", r);
        exit(1);
    }
}

const char *param_register_name(int i) {
    static const char *param_register_name_table[6] = {
        "%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"
    };
    if (i >= 0 && i < 6) {
        return param_register_name_table[i];
    } else {
        fprintf(stderr, "cminor: unknown parameter number %d\n", i);
        exit(1);
    }
}

int register_alloc() {
    static int scratch_registers_idx[7] = {
        1, 10, 11, 12, 13, 14, 15
    };

    int i;
    for (i = 0; i < 7; ++i) {
        if (register_allocation_table[scratch_registers_idx[i]] == 0) {
            register_allocation_table[scratch_registers_idx[i]] = 1;
            return scratch_registers_idx[i];
        }
    }

    printf("error: no free register available\n");
    exit(1);
}

void register_free(int r) {
    register_allocation_table[r] = 0;
}
