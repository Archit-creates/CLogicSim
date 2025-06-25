#include <stdio.h>
#include <string.h>
#include "parser.h"

int parse_circuit_file(const char* filename, Signal inputs[], int* num_inputs, Gate gates[], int* num_gates) {
    FILE* file = fopen(filename, "r");
    if (!file) return 0;

    char line[100], word[10];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "IN", 2) == 0) {
            char* token = strtok(line + 3, " \n");
            while (token) {
                strcpy(inputs[*num_inputs].name, token);
                inputs[*num_inputs].value = 0;
                (*num_inputs)++;
                token = strtok(NULL, " \n");
            }
        } else if (strstr(line, "GATES") || line[0] == '#') {
            continue;
        } else if (strncmp(line, "OUT", 3) == 0) {
            continue;  // Output handling later
        } else {
            char type[10], name[10], in1[10], in2[10];
            sscanf(line, "%s %s %s %s", type, name, in1, in2);
            Gate* g = &gates[*num_gates];
            strcpy(g->name, name);
            strcpy(g->in1, in1);
            strcpy(g->in2, in2);

            if (strcmp(type, "AND") == 0) g->type = AND;
            else if (strcmp(type, "OR") == 0) g->type = OR;
            else if (strcmp(type, "NOT") == 0) g->type = NOT;
            else if (strcmp(type, "XOR") == 0) g->type = XOR;
            else if (strcmp(type, "NAND") == 0) g->type = NAND;
            else if (strcmp(type, "NOR") == 0) g->type = NOR;
            else if (strcmp(type, "DFF") == 0) g->type = DFF;

            (*num_gates)++;
        }
    }

    fclose(file);
    return 1;
}
