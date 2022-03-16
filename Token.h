#ifndef TOKEN_H
#define TOKEN_H
#include <string>

using namespace std;

enum TokenType {COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON,
    COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, UNDEFINED, EOTF};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    string tokenString;
    int lineNum;
    TokenType tokenType;

public:
    Token(TokenType type, std::string description, int line);
    string toString();
    string typeToString(TokenType type);
    string returnTokenString();
    int returnLineNum();
    TokenType returnTokenType();



    // TODO: add other needed methods
};

#endif // TOKEN_H

