#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "AddAutomaton.h"
#include "CommaAutomaton.h"
#include "FactsAutomaton.h"
#include "LeftParenAutomaton.h"
#include "MultiAutomaton.h"
#include "PeriodAutomaton.h"
#include "QMarkAutomaton.h"
#include "QueriesAutomaton.h"
#include "RightParenthesesAutomaton.h"
#include "RulesAutomaton.h"
#include "SchemeAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include "UndefinedAutomaton.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new QMarkAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new RightParenthesesAutomaton());
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new MultiAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemeAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new UndefinedAutomaton());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    int lineNumber = 1;
    int maxRead;
    Automaton* maxAutomaton;
    int inputRead;
    Token* newToken;
    string tokenString = "";
    while (!input.empty()) {
        maxRead = 0;
        maxAutomaton = automata[0];

        // Here is the "Parallel" part of the algorithm

        while (isspace(input.at(0))) {
            if (input.substr(0,1) == "\n") {
                lineNumber = lineNumber + 1;
            }  //change for linux
            input.erase(0,1);
            if (input.empty()) {
                break;
            }
        }

        if (input.empty()) {
            break;
        }


        for (Automaton* fsa : automata) {
            inputRead = fsa->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = fsa;
            }
        }
            // Here is the "Max" part of the algorithm

            tokenString = input.substr(0, maxRead);
            input.erase(0, maxRead);

        if (maxRead > 0) {
            newToken = maxAutomaton->CreateToken(tokenString, lineNumber);
            lineNumber = lineNumber + maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        else {
            maxRead = 1;
            newToken = new Token(UNDEFINED, tokenString, lineNumber);
            tokens.push_back(newToken);
        }

    }

    // multi block undefined and need to remember length
    newToken = new Token(EOTF, "", lineNumber);
    tokens.push_back(newToken);
    savedTokens = tokens;
}

void Lexer::printTokens() {
    string newToken = "";
    int tokenTotal = tokens.size();

    while (!tokens.empty()) {
        newToken = tokens.front()->toString();
        tokens.erase(tokens.begin());
        cout << newToken << endl;
    }
    cout << "Total Tokens = " << tokenTotal << endl;
}

vector<Token *> Lexer::returnTokens() {
    return savedTokens;
}

