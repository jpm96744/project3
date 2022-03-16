//
// Created by jpm96 on 12/7/2021.
//

#ifndef PROJECT1_STARTER_CODE_QMARKAUTOMATON_H
#define PROJECT1_STARTER_CODE_QMARKAUTOMATON_H

#include "Automaton.h"

class QMarkAutomaton : public Automaton {
public:
    QMarkAutomaton() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //PROJECT1_STARTER_CODE_QMARKAUTOMATON_H
