//
// Created by jpm96 on 12/7/2021.
//

#ifndef PROJECT1_STARTER_CODE_COMMA_H
#define PROJECT1_STARTER_CODE_COMMA_H

#include "Automaton.h"

using namespace std;

class CommaAutomaton : public Automaton{
public:
    CommaAutomaton() : Automaton(TokenType::COMMA) {}

    void S0(const string& input);
};


#endif //PROJECT1_STARTER_CODE_COMMA_H
