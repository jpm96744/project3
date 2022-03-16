//
// Created by jpm96 on 3/14/2022.
//

#ifndef PROJECT1_STARTER_CODE_SCHEME_H
#define PROJECT1_STARTER_CODE_SCHEME_H
#include<iostream>
#include <vector>
#include <string>

using namespace std;
class Scheme {
private:
    vector<string> values;
public:
    unsigned int returnSize();
    void pushBack(string addString);
    void getScheme(vector<string> myVec);
    string returnValueAt(int i);
};


#endif //PROJECT1_STARTER_CODE_SCHEME_H
