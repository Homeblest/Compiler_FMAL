#ifndef LEXER_H
#define LEXER_H

#include <string>
#include "Token.h"

class Lexer {

private:
    string input;

public:
    Token nextToken();
};
#endif // LEXER_H
