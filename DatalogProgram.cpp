//
// Created by jpm96 on 12/9/2021.
//

#include "DatalogProgram.h"
DatalogProgram::DatalogProgram() = default;

vector<Predicate *> DatalogProgram::returnSchemes() {
    return Schemes;
}

vector<Predicate *> DatalogProgram::returnFacts() {
    return Facts;
}

vector<Predicate *> DatalogProgram::returnQueries() {
    return Queries;
}

vector<Rule *> DatalogProgram::returnRules() {
    return Rules;
}

void DatalogProgram::AddSchemes(Predicate* myScheme) {
    Schemes.push_back(myScheme);
}

void DatalogProgram::AddFacts(Predicate* myFact) {
    Facts.push_back(myFact);
}

void DatalogProgram::AddQueries(Predicate* myQuery) {
    Queries.push_back(myQuery);
}

void DatalogProgram::AddRules(Rule* myRule) {
    Rules.push_back(myRule);
}

void DatalogProgram::AddDomain(string myDomain) {
    Domain.insert(myDomain);
}

string DatalogProgram::ToString() {
    stringstream ss;
    unsigned int schemesSize = Schemes.size();
    unsigned int factsSize = Facts.size();
    unsigned int rulesSize = Rules.size();
    unsigned int queriesSize = Queries.size();
    unsigned int domainSize = Domain.size();

    ss << "Success!\nSchemes(" << schemesSize << "):\n";
    for (auto & Scheme : Schemes) {
        ss<< "  " << Scheme->ToString() << "\n";
    }
    ss << "Facts(" << factsSize << "):\n";
    for (auto & Fact : Facts) {
        ss<< "  " << Fact->ToString() << ".\n";
    }
    ss << "Rules(" << rulesSize << "):\n";
    for (auto & Rule : Rules) {
        ss<< "  " << Rule->ToString() << "\n";
    }
    ss << "Queries(" << queriesSize << "):\n";
    for (auto & Query : Queries) {
        ss<< "  " << Query->ToString() << "?\n";
    }
    ss << "Domain(" << domainSize << "):\n";
    set<string>::iterator it;
    for (it = Domain.begin(); it != Domain.end(); it++) {
        ss << "  " << *it << "\n";
    }

    string datalogStructure = ss.str();
    return datalogStructure;
}

