#include <stdio.h>
#include "parser.h"
#include "logic.h"

int main() {
    Signal inputs[MAX_SIGNALS];
    Gate gates[MAX_GATES];
    int num_inputs = 0, num_gates = 0;

    if (!parse_circuit_file("circuit.txt", inputs, &num_inputs, gates, &num_gates)) {
        printf("Failed to parse circuit file.\n");
        return 1;
    }

    printf("\n=== TRUTH TABLE ===\n");
    generate_truth_table(inputs, num_inputs, gates, num_gates);

    return 0;
}
