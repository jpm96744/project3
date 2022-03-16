//
// Created by jpm96 on 3/14/2022.
//

#ifndef PROJECT1_STARTER_CODE_INTERPRETER_H
#define PROJECT1_STARTER_CODE_INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"

using namespace std;
class Interpreter {
private:
    Database theDatabase;
    DatalogProgram theDatalog;
public:
    void SetDatalog(DatalogProgram theInformation);
    void SchemesToDatabase(vector<Predicate*> Schemes);
    void FactsToDatabase(vector<Predicate*> Facts);
    void RelationQueries(vector<Predicate*> Queries);
    string ToString();
};


#endif //PROJECT1_STARTER_CODE_INTERPRETER_H
