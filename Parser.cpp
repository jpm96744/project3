//
// Created by jpm96 on 12/9/2021.
//

#include "Parser.h"

Parser::Parser(vector<Token *> myTokens) {
    tokens = myTokens;
}


void Parser::Run() {
    int tokensSize = tokens.size();
    for (int i = 0; i < tokensSize; i++) {
        if (tokens[i]->returnTokenType() == COMMENT) {
            tokens.erase(tokens.begin() + i);
            i--;
        }
    }
    MatchTokens(SCHEMES);
    MatchTokens(COLON);

    SchemeParse();
    SchemeListParse();

    MatchTokens(FACTS);
    MatchTokens(COLON);

    FactListParse();

    MatchTokens(RULES);
    MatchTokens(COLON);

    RuleListParse();

    MatchTokens(QUERIES);
    MatchTokens(COLON);

    QueryParse();
    QueryListParse();

    //cout << datalogProgram.ToString() << endl;

}

void Parser::MatchTokens(TokenType tokenType) {
    if(tokens[increment]->returnTokenType() == tokenType) {
        increment++;
    }
    else {
        throw (tokens[increment]);
    }
}

void Parser::SchemeListParse() {
    if (tokens[increment]->returnTokenType() != FACTS) {
        SchemeParse();
        SchemeListParse();
    }
}

void Parser::FactListParse() {
    if(tokens[increment]->returnTokenType() != RULES) {
        FactParse();
        int vectorSize;
        vector<Predicate*> factGrab = datalogProgram.returnFacts();
        for (auto & Fact : factGrab) {
            vector<Parameter*> stringGrab = Fact->ReturnVector();
            vectorSize = stringGrab.size();
            for (int i = 0; i < vectorSize; i++) {
                datalogProgram.AddDomain(stringGrab[i]->ToString());
            }
        }
        FactListParse();
    }
}

void Parser::RuleListParse() {
    if(tokens[increment]->returnTokenType() != QUERIES) {
        RuleParse();
        RuleListParse();
    }
}

void Parser::QueryListParse() {
    if(tokens[increment]->returnTokenType() != EOTF) {
        QueryParse();
        QueryListParse();
    }
}

void Parser::SchemeParse() {
    Predicate *newScheme = new Predicate();
    MatchTokens(ID);
    newScheme->SetID(tokens[increment - 1]->returnTokenString());
    MatchTokens(LEFT_PAREN);
    MatchTokens(ID);
    //added arg
    AddToParameterList(tokens[increment - 1]->returnTokenString(), false);

    IDListParse();

    MatchTokens(RIGHT_PAREN);
    int parameterSize = parameters.size();
    for (int i = 0; i < parameterSize; i++) {
        newScheme->AddPredicate(parameters[i]);
    }
    datalogProgram.AddSchemes(newScheme);
    parameters.clear();
}

void Parser::FactParse() {
    Predicate *newFact = new Predicate();
    MatchTokens(ID);
    newFact->SetID(tokens[increment - 1]->returnTokenString());
    MatchTokens(LEFT_PAREN);
    MatchTokens(STRING);
    //added arg
    AddToParameterList(tokens[increment - 1]->returnTokenString(), true);
    datalogProgram.AddDomain(tokens[increment-1]->returnTokenString());

    StringListParse();

    MatchTokens(RIGHT_PAREN);
    MatchTokens(PERIOD);
    int parameterSize = parameters.size();
    for (int i = 0; i < parameterSize; i++) {
        newFact->AddPredicate(parameters[i]);
    }
    datalogProgram.AddFacts(newFact);
    parameters.clear();
}

void Parser::RuleParse() {
    Rule* newRule = new Rule();

    HeadPredicateParse();
    newRule->SetHeadPredicate(GetHeadPred());
    MatchTokens(COLON_DASH);

    PredicateParse();
    PredicateListParse();

    MatchTokens(PERIOD);
    newRule->SetRule(rulesList);
    datalogProgram.AddRules(newRule);
    parameters.clear();
    rulesList.clear();
}

void Parser::QueryParse() {
    PredicateParse();

    MatchTokens(Q_MARK);
    datalogProgram.AddQueries(GetNewpred());
}

void Parser::HeadPredicateParse() {
    Predicate* headPredicate = new Predicate();

    MatchTokens(ID);
    headPredicate->SetID(tokens[increment - 1]->returnTokenString());
    MatchTokens(LEFT_PAREN);
    MatchTokens(ID);
    //added arg
    AddToParameterList(tokens[increment-1]->returnTokenString(), false);

    IDListParse();

    MatchTokens(RIGHT_PAREN);

    for (auto & parameter : parameters) {
        headPredicate->AddPredicate(parameter);
    }
    SetHeadPred(headPredicate);
    parameters.clear();
}

void Parser::PredicateParse() {
    Predicate* newPredicate = new Predicate();

    MatchTokens(ID);
    newPredicate->SetID(tokens[increment - 1]->returnTokenString());
    MatchTokens(LEFT_PAREN);

    ParameterParse();

    ParameterListParse();

    MatchTokens(RIGHT_PAREN);

    for (auto & parameter : parameters) {
        newPredicate->AddPredicate(parameter);
    }
    parameters.clear();
    SetNewPred(newPredicate);
    rulesList.push_back(newPredicate);
}

void Parser::PredicateListParse() {
    if(tokens[increment]->returnTokenType() != PERIOD) {
        MatchTokens(COMMA);
        PredicateParse();
        PredicateListParse();
    }
}

void Parser::ParameterListParse() {
    if(tokens[increment]->returnTokenType() != RIGHT_PAREN) {
        MatchTokens(COMMA);
        ParameterParse();
        ParameterListParse();
    }
}

void Parser::StringListParse() {
    if(tokens[increment]->returnTokenType() != RIGHT_PAREN) {
        MatchTokens(COMMA);
        MatchTokens(STRING);
        //added arg
        AddToParameterList(tokens[increment-1]->returnTokenString(), true);
        StringListParse();
    }
}

void Parser::IDListParse() {
    if(tokens[increment]->returnTokenType() != RIGHT_PAREN) {
        MatchTokens(COMMA);
        MatchTokens(ID);
        //added arg
        AddToParameterList(tokens[increment - 1]->returnTokenString(), false);
        IDListParse();
    }
}

void Parser::ParameterParse() {
    Parameter* newParameter = new Parameter();
    if(tokens[increment]->returnTokenType() == STRING) {
        MatchTokens(STRING);
        newParameter->SetParam(tokens[increment-1]->returnTokenString());
        //added
        newParameter->SetBool(true);
    } else if (tokens[increment]->returnTokenType() == ID) {
        MatchTokens(ID);
        newParameter->SetParam(tokens[increment-1]->returnTokenString());
        //added
        newParameter->SetBool(false);
    } else {
        throw (tokens[increment-1]);
    }
    //added arg
    AddToParameterList(newParameter->ToString(), newParameter->IsString());
}

//added bool
void Parser::AddToParameterList(string description, bool stringTrueFalse) {
    Parameter *myParameter = new Parameter();
    myParameter->SetParam(description);
    //added
    myParameter->SetBool(stringTrueFalse);
    parameters.push_back(myParameter);
}

void Parser::SetNewPred(Predicate* myPred) {
    newPred = myPred;
}

Predicate *Parser::GetNewpred() {
    return newPred;
}

void Parser::SetHeadPred(Predicate* newHeadPred) {
    headPred = newHeadPred;
}

Predicate* Parser::GetHeadPred() {
    return headPred;
}

DatalogProgram Parser::ReturnDatalog() {
    return datalogProgram;
}


