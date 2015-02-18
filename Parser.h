#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

class Parser {
private:
    Lexer *myLexer;
    Token curToken;
    bool statements();
    bool statement();
    bool expr();
    bool term();
    bool factor();
    bool checkError();
public:
    void parse();
    Parser(Lexer *inputLexer) {
        myLexer = inputLexer;
    };
};
#endif // PARSER_H
