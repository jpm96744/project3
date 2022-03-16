//
// Created by jpm96 on 12/7/2021.
//

#ifndef PROJECT1_STARTER_CODE_MULTIAUTOMATON_H
#define PROJECT1_STARTER_CODE_MULTIAUTOMATON_H

#include "Automaton.h"
class MultiAutomaton : public Automaton{
public:
    MultiAutomaton() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_MULTIAUTOMATON_H
