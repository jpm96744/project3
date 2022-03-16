//
// Created by jpm96 on 12/7/2021.
//

#include "StringAutomaton.h"
void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    int inputSize = input.size();

    if (index > inputSize){ //get help here
        type = UNDEFINED;
    }
    else if (input[index] != '\'') {
        if (input[index] == '\n') { //change for linux
            newLines++;
        }
        inputRead++;
        index++;

        S1(input);
    }
    else {
        if (input[index + 1] == '\'') {
            inputRead += 2;
            index += 2;
            S1(input);
        } else {
            inputRead++;
            index++;
        }
    }
}