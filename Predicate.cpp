//
// Created by jpm96 on 12/9/2021.
//

#include "Predicate.h"
void Predicate::SetID(string myID) {
    id = myID;
}

vector<Parameter *> Predicate::ReturnVector() {
    return parameters;
}

void Predicate::AddPredicate(Parameter* parameter) {
    parameters.push_back(parameter);
}

string Predicate::ToString() {
    string predString = id + "(";
    for (unsigned int i = 0; i < parameters.size(); i++) {

        if (i ==0 ){
            predString = predString + parameters[i]->ToString();
        }
        else {
            predString = predString + "," + parameters[i]->ToString();
        }
    }
    predString = predString + ")";
    return predString;
}

string Predicate::returnID() {
    return id;
}
