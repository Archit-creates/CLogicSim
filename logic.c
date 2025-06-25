#include <stdio.h>
#include <string.h>
#include "logic.h"
#include "dff.h"
int get_signal_value(const char* name, Signal inputs[], int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(inputs[i].name, name) == 0) return inputs[i].value;
    }
    return 0;
}

int eval_gate(GateType type, int a, int b) {
    switch (type) {
        case AND: return a & b;
        case OR:  return a | b;
        case NOT: return !a;
        case XOR: return a ^ b;
        case NAND:return !(a & b);
        case NOR: return !(a | b);
        default:  return 0;
    }
}

void generate_truth_table(Signal inputs[], int num_inputs, Gate gates[], int num_gates) {
    int rows = 1 << num_inputs;

    for (int g = 0; g < num_gates; g++) {
    Gate* gate = &gates[g];
    int in1 = get_signal_value(gate->in1, inputs, num_inputs);
    int in2 = get_signal_value(gate->in2, inputs, num_inputs);

    if (gate->type == DFF) {
        gate->output = eval_dff(gate, inputs, num_inputs, gates, num_gates);
    } else {
        gate->output = eval_gate(gate->type, in1, in2);
    }

    printf("%s=%d ", gate->name, gate->output);
}

}
