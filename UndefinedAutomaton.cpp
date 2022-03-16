//
// Created by jpm96 on 12/8/2021.
//

#include "UndefinedAutomaton.h"
void UndefinedAutomaton::S0(const std::string& input) {
    if (!isalpha(input[index]) && !isdigit(input[index])) {
        inputRead++;
        index++;
    }
    else if (isdigit(input[index])) {
        inputRead++;
        index++;
    }
    else {
        Serr();
    }
}