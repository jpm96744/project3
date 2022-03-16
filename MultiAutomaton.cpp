//
// Created by jpm96 on 12/7/2021.
//

#include "MultiAutomaton.h"
void MultiAutomaton::S0(const std::string& input) {
    if (input[index] == '*') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}