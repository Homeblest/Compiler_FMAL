#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

class Parser {
private:
    Lexer *myLexer;
    Token curToken;
public:
    Parser(Lexer *inputLexer) {
        myLexer = inputLexer;
    };
    void parse();
    bool statements();
    bool statement();
};
#endif // PARSER_H
