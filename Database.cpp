//
// Created by jpm96 on 3/14/2022.
//

#include "Database.h"

void Database::AddRelation(string Name, Relation newRelation) {
    databases.insert({Name, newRelation});
}

void Database::AddTuplesToRelation(string Name, Tuple theTuple) {
    databases.at(Name).AddTuple(theTuple);
}

string Database::toString() {
    string myString;
    map<string, Relation> ptr;
    for (auto i: databases) {
        myString = i.first + ": \n" + i.second.ToString();
    }
    return myString;
}

Relation Database::GetRelation(string Name) {
    return databases.at(Name);
}
