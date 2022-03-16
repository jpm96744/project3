//
// Created by jpm96 on 12/9/2021.
//

#ifndef PROJECT1_STARTER_CODE_PARSER_H
#define PROJECT1_STARTER_CODE_PARSER_H

#include "Token.h"
#include "DatalogProgram.h"
#include <iostream>
#include <vector>
using namespace std;

class Parser {
private:
    DatalogProgram datalogProgram;
    vector<Token*> tokens;
    vector<Parameter*> parameters;
    int increment = 0;
    Predicate* newPred;
    Predicate* headPred;
    vector<Predicate*> rulesList;
    void MatchTokens(TokenType tokenType);
    void SchemeParse();
    void SchemeListParse();
    void FactListParse();
    void RuleListParse();
    void QueryParse();
    void QueryListParse();
    void IDListParse();
    void StringListParse();
    void HeadPredicateParse();
    void PredicateParse();
    void PredicateListParse();
    void FactParse();
    void RuleParse();
    void ParameterParse();
    void ParameterListParse();
    void AddToParameterList(string description, bool stringTrueFalse);
    void SetNewPred(Predicate* newPred);
    Predicate* GetNewpred();
    void SetHeadPred(Predicate* newHeadPred);
    Predicate* GetHeadPred();

public:
    explicit Parser(vector<Token*> myTokens);
    void Run();
    DatalogProgram ReturnDatalog();

};


#endif //PROJECT1_STARTER_CODE_PARSER_H
