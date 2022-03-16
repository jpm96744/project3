//
// Created by jpm96 on 3/14/2022.
//

#ifndef PROJECT1_STARTER_CODE_DATABASE_H
#define PROJECT1_STARTER_CODE_DATABASE_H
#include <map>
#include "Relation.h"

class Database {
public:
    map<string, Relation> databases;
    void AddRelation(string Name, Relation newRelation);
    void AddTuplesToRelation(string Name, Tuple theTuple);
    string toString();
    Relation GetRelation(string Name);
};


#endif //PROJECT1_STARTER_CODE_DATABASE_H
