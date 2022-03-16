//
// Created by jpm96 on 12/7/2021.
//
#ifndef PROJECT1_STARTER_CODE_RIGHTPARENAUTOMATON_H
#define PROJECT1_STARTER_CODE_RIGHTPARENAUTOMATON_H

#include "Automaton.h"
class RightParenthesesAutomaton : public Automaton {
public:
    RightParenthesesAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_RIGHTPARENAUTOMATON_H
