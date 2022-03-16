//
// Created by jpm96 on 12/9/2021.
//

#ifndef PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
#define PROJECT1_STARTER_CODE_DATALOGPROGRAM_H


#include "Token.h"
#include "Parameter.h"
#include "Predicate.h"
#include "Rule.h"

#include <vector>
#include <set>
#include <sstream>
using namespace std;

class DatalogProgram {
private:
    vector<Predicate*> Schemes;
    vector<Predicate*> Facts;
    vector<Predicate*> Queries;
    vector<Rule*> Rules;
    set<string> Domain;
public:
    DatalogProgram();
    vector<Predicate*> returnSchemes();
    vector<Predicate*> returnFacts();
    vector<Predicate*> returnQueries();
    vector<Rule*> returnRules();
    void AddSchemes(Predicate* mySchemes);
    void AddFacts(Predicate* myFacts);
    void AddQueries(Predicate* myQueries);
    void AddRules(Rule* myRules);
    void AddDomain(string myDomain);
    string ToString();
};


#endif //PROJECT1_STARTER_CODE_DATALOGPROGRAM_H
