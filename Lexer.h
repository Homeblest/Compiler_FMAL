#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <iterator>

#include "Token.h"

class Lexer {

private:
    string finalString;
    Token theToken;

public:
    Lexer();
    Token nextToken();
};
#endif // LEXER_H
