//
// Created by jpm96 on 12/7/2021.
//

#ifndef PROJECT1_STARTER_CODE_STRINGAUTOMATON_H
#define PROJECT1_STARTER_CODE_STRINGAUTOMATON_H

#include "Automaton.h"
class StringAutomaton : public Automaton{
private:
    void S1(const std::string& input);

public:
    StringAutomaton() : Automaton(TokenType::STRING) {}  // Call the base constructor

    void S0(const std::string& input);

};


#endif //PROJECT1_STARTER_CODE_STRINGAUTOMATON_H
