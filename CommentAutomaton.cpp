//
// Created by jpm96 on 12/8/2021.
//

#include "CommentAutomaton.h"
void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {

    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        inputRead++;
        index++;
        S3(input);
    }
}

void CommentAutomaton::S2(const std::string& input) {
    int inputSize = input.size();
    if (index > inputSize) {
        type = UNDEFINED;
    }
    else if (input[index] != '|') {
        if (input[index] == '\n') { //change for linux
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S5(input);
    }
}

void CommentAutomaton::S3(const std::string& input) {
    if (input[index] != '\n') { //change for linux
        inputRead++;
        index++;
        S3(input);
    }
    else if (input[index] == '\n') { //change for linux

    }
}

void CommentAutomaton::S5(const std::string& input) {
    if (input[index] != '#') {
        if (input[index] == '\n') { //change for linux
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
    else {
        inputRead++;
        index++;
    }
}

