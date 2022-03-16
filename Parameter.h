//
// Created by jpm96 on 12/9/2021.
//

#ifndef PROJECT1_STARTER_CODE_PARAMETER_H
#define PROJECT1_STARTER_CODE_PARAMETER_H

#include <string>

using namespace std;

class Parameter {
private:
    string parameter;
    bool boolString;
public:
    void SetParam(string param);
    string ToString();
    string returnParameter();
    void SetBool(bool trueOrFalse);
    bool IsString();
};


#endif //PROJECT1_STARTER_CODE_PARAMETER_H
