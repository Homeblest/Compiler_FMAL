#ifndef PARSER_H
#define PARSER_H

#include "Lexer.h"

class Parser {
private:
    Lexer *myLexer;
    Token curToken;
    void statements();
    void statement();
    void expr();
    void term();
    void factor();
    bool checkError();
public:
    void parse();
    Parser(Lexer *inputLexer) {
        myLexer = inputLexer;
    };
};
#endif // PARSER_H
