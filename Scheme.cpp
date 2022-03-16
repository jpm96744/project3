//
// Created by jpm96 on 3/14/2022.
//

#include "Scheme.h"

unsigned int Scheme::returnSize() {
    return values.size();
}

void Scheme::pushBack(string addString) {
    values.push_back(addString);
}

void Scheme::getScheme(vector<string> myVec) {
    values = myVec;
}

string Scheme::returnValueAt(int i) {
    return values.at(i);
}
