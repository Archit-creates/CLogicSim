#include <string.h>
#include "dff.h"
#include "parser.h"

int last_clk_state = 0;

int is_rising_edge(int current_clk) {
    int result = (last_clk_state == 0 && current_clk == 1);
    last_clk_state = current_clk;
    return result;
}

int eval_dff(Gate* gate, Signal inputs[], int num_inputs, Gate gates[], int num_gates) {
    // Get D and CLK values
    int d = get_signal_value(gate->in1, inputs, num_inputs);
    int clk = get_signal_value(gate->in2, inputs, num_inputs);

    // Rising edge logic
    if (is_rising_edge(clk)) {
        return d;  // On rising edge, latch D to Q
    }
    return gate->output;  // Else hold previous state
}
