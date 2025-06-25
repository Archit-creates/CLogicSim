#pragma once

#define MAX_GATES 100
#define MAX_SIGNALS 100

typedef struct {
    char name[10];
    int value;
} Signal;

typedef enum { AND, OR, NOT, XOR, NAND, NOR, DFF } GateType;

typedef struct {
    char name[10];
    GateType type;
    char in1[10];
    char in2[10];
    int output;
} Gate;

int parse_circuit_file(const char* filename, Signal inputs[], int* num_inputs, Gate gates[], int* num_gates);
