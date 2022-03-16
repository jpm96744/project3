//
// Created by jpm96 on 12/9/2021.
//

#ifndef PROJECT1_STARTER_CODE_RULE_H
#define PROJECT1_STARTER_CODE_RULE_H

#include "Predicate.h"
class Rule {
private:
    Predicate* headPredicate;
    vector<Predicate*> bodyPredicates;
public:
    void SetHeadPredicate(Predicate* headPred);
    void SetRule(vector<Predicate*> bodyPred);
    string ToString();
};


#endif //PROJECT1_STARTER_CODE_RULE_H
