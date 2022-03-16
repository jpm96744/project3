//
// Created by jpm96 on 12/9/2021.
//

#include "Rule.h"

void Rule::SetHeadPredicate(Predicate* headPred) {
    headPredicate = headPred;
}

void Rule::SetRule(vector<Predicate *> bodyPred) {
    for (auto & i : bodyPred) {
        bodyPredicates.push_back(i);
    }
}

string Rule::ToString() {
    string myRule;
    int bodyPredsSize = bodyPredicates.size();
    myRule = headPredicate->ToString() + " :- ";
    for (int i = 0; i < bodyPredsSize; i++) {
        if ( i == 0) {
            myRule = myRule + bodyPredicates[i]->ToString();
        }
        else {
            myRule = myRule + "," + bodyPredicates[i]->ToString();
        }
    }
    myRule += ".";
    return myRule;
}
