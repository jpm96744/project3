//
// Created by jpm96 on 3/14/2022.
//

#include "Interpreter.h"

void Interpreter::SetDatalog(DatalogProgram theInformation) {
    theDatalog = theInformation;
    SchemesToDatabase(theDatalog.returnSchemes());
    FactsToDatabase(theDatalog.returnFacts());
    RelationQueries(theDatalog.returnQueries());
}

void Interpreter::SchemesToDatabase(vector<Predicate*> Schemes) {
    for(unsigned int i = 0; i < Schemes.size(); i++) {
        string theName = Schemes.at(i)->returnID();
        Scheme theScheme;
        for (unsigned int j = 0; j < Schemes.at(i)->ReturnVector().size(); j++) {
            theScheme.pushBack(Schemes.at(i)->ReturnVector().at(j)->ToString());
        }
        Relation newRelation;
        newRelation.SetName(theName);
        newRelation.SetScheme(theScheme);
        theDatabase.AddRelation(theName, newRelation);
    }
}

void Interpreter::FactsToDatabase(vector<Predicate*> Facts) {
    for (unsigned int j = 0; j < Facts.size(); j++) {
        string theName;
        theName = Facts.at(j)->returnID();
        Tuple theTuple;
        for(unsigned int i = 0; i < Facts.at(j)->ReturnVector().size(); i++) {
            theTuple.push_back(Facts.at(j)->ReturnVector().at(i)->ToString());
        }
        theDatabase.AddTuplesToRelation(theName, theTuple);
    }
}

void Interpreter::RelationQueries(vector<Predicate*> Queries) {
    for (unsigned int i = 0; i < Queries.size(); i++) {
        string theName = Queries.at(i)->returnID();
        vector<int> theInts;
        vector<string> theStrings;
        Relation thisRelation = theDatabase.databases.at(theName);

        for (unsigned int j = 0; j < Queries.at(i)->ReturnVector().size(); j++) {
            Parameter* currentParameter = Queries.at(i)->ReturnVector().at(j);
            if (currentParameter->IsString() == true) {
                string yes = currentParameter->returnParameter();
                thisRelation = thisRelation.Select(j,yes);
            }
            else {
                bool duplicate = false;
                for (unsigned int k = 0; k < theStrings.size(); k++) {
                    if (theStrings.at(k) == currentParameter->returnParameter()) {
                        duplicate = true;
                        thisRelation = thisRelation.Select(j,k);
                    }
                }
                if(duplicate == false) {
                    theStrings.push_back(currentParameter->returnParameter());
                    theInts.push_back(j);
                }
            }
        }
        Relation newRelation;
        newRelation = thisRelation.Project(theInts);
        thisRelation = newRelation.Rename(theStrings);

        cout << Queries.at(i)->ToString() << "? ";
        if (thisRelation.DemTuples.size() == 0) {
            cout << "No\n";
        }
        else {
          cout << "Yes(" << thisRelation.DemTuples.size() <<")\n";
          thisRelation.ToString();
        }
    }
}

string Interpreter::ToString() {
    return theDatabase.toString();
}
