//
// Created by jpm96 on 12/9/2021.
//

#include "Parameter.h"

#include <utility>
void Parameter::SetParam(string myToken) {
    parameter = std::move(myToken);
}

string Parameter::ToString() {
    return parameter;
}

string Parameter::returnParameter() {
    return parameter;
}

void Parameter::SetBool(bool trueOrFalse) {
    boolString = trueOrFalse;
}

bool Parameter::IsString() {
    return boolString;
}
