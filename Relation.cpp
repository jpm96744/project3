//
// Created by jpm96 on 3/14/2022.
//

#include "Relation.h"

Relation::Relation() {

}

Relation Relation::Select(int index, string value) {
    Relation NewRelation, NewRelation1;
    NewRelation.SetName(name);
    NewRelation.SetScheme(TheScheme);
    NewRelation1.SetName(name);
    NewRelation1.SetScheme(TheScheme);
    NewRelation1.SetName(name);
    NewRelation1.SetScheme(TheScheme);

    for (auto i: DemTuples) {
        NewRelation1.AddTuple(i);
    }

    for (auto i: DemTuples) {
        if (i.at(index) == value) {
            NewRelation.AddTuple(i);
        }
    }

    return NewRelation;
}

Relation Relation::Select(int indexOne, int indexTwo) {
    Relation NewRelation, NewRelation1;
    NewRelation.SetName(name);
    NewRelation.SetScheme(TheScheme);
    NewRelation1.SetName(name);
    NewRelation1.SetScheme(TheScheme);

    for (auto i: DemTuples) {
        NewRelation1.AddTuple(i);
    }

    for (auto i: DemTuples) {
        if (i.at(indexOne) == i.at(indexTwo)) {
            NewRelation.AddTuple(i);
        }
    }
    return NewRelation;
}

Relation Relation::Project(vector<int> indices) {
    Relation NewRelation;
    NewRelation.SetName(name);
    for (auto i: DemTuples){
        Tuple tempTuple;
        for(unsigned j = 0; j < indices.size(); j++) {
            tempTuple.push_back(i.at(indices.at(j)));
        }
        NewRelation.AddTuple(tempTuple);
    }
    Scheme TempScheme;

    for (unsigned int i = 0; i < indices.size(); i++ ){
        TempScheme.pushBack(TheScheme.returnValueAt(indices.at(i)));
    }

    NewRelation.SetScheme(TempScheme);
    return NewRelation;
}

Relation Relation::Rename(vector<string> names) {
    Scheme newName;
    newName.getScheme(names);
    Relation NewRelation;
    NewRelation.SetName(name);
    NewRelation.SetScheme(newName);

    for (auto i : DemTuples) {
        NewRelation.AddTuple(i);
    }

    return NewRelation;
}

void Relation::AddTuple(Tuple tuples) {
    DemTuples.insert(tuples);
}

void Relation::SetScheme(Scheme DemSchemes) {
    TheScheme = DemSchemes;
}

void Relation::SetName(string DatName) {
    name = DatName;
}

Scheme Relation::GetScheme() {
    return TheScheme;
}

set<Tuple> Relation::GetTuple() {
    return DemTuples;
}

string Relation::ToString() {
    string rString;

    for (auto i : DemTuples) {
        if (TheScheme.returnSize() != 0) {
            cout << "  ";
        }
        for (unsigned int j = 0; j < TheScheme.returnSize(); j++) {
            cout << TheScheme.returnValueAt(j) + "=" + i.at(j);
            if (j < TheScheme.returnSize()-1) {
                cout << ", ";
            }
        }
        if (TheScheme.returnSize() != 0) {
            cout << "\n";
        }
    }
    return rString;
}
