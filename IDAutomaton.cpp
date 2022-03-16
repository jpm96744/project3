//
// Created by jpm96 on 12/7/2021.
//

#include "IDAutomaton.h"
void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IDAutomaton::S1(const std::string& input) {
    if (input.substr(0, index) == "Schemes" || input.substr(0, index) == "Facts" ||
    input.substr(0, index) == "Rules" || input.substr(0, index) == "Queries") {
        if(isalpha(input[index]) && !isspace(input[index])) {
            inputRead++;
            index++;
            S1(input);
        }
        else {
            Serr();
        }
    }
    if (isalpha(input[index]) || isdigit(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
}