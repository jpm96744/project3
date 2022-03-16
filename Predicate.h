//
// Created by jpm96 on 12/9/2021.
//

#ifndef PROJECT1_STARTER_CODE_PREDICATE_H
#define PROJECT1_STARTER_CODE_PREDICATE_H

#include "Parameter.h"
#include <vector>
using namespace std;
class Predicate {
private:
    vector<Parameter*> parameters;
    string id;
public:
    void SetID(string myID);
    vector<Parameter*> ReturnVector();
    void AddPredicate(Parameter* parameter);
    string ToString();
    string returnID();
};


#endif //PROJECT1_STARTER_CODE_PREDICATE_H
