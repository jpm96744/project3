//
// Created by jpm96 on 3/14/2022.
//

#ifndef PROJECT1_STARTER_CODE_RELATION_H
#define PROJECT1_STARTER_CODE_RELATION_H
#include "Scheme.h"
#include "Tuple.h"
#include <set>


class Relation {
private:
    string name;
    Scheme TheScheme;
public:
    Relation();
    Relation Select(int index, string value);
    Relation Select(int indexOne, int indexTwo);
    Relation Project(vector<int> indices);
    Relation Rename(vector<string> names);
    void AddTuple(Tuple tuples);
    void SetScheme(Scheme DemSchemes);
    void SetName(string DatName);
    Scheme GetScheme();
    set<Tuple> GetTuple();
    string ToString();
    set<Tuple> DemTuples;
};


#endif //PROJECT1_STARTER_CODE_RELATION_H
