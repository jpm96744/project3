//
// Created by jpm96 on 12/7/2021.
//

#include "CommaAutomaton.h"

void CommaAutomaton::S0(const string& input) {
    if (input[index] == ',') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
