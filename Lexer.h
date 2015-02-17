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
    string input, final_string;
    vector<string> lexArr;
    unsigned int counter;

public:
    Lexer();
    Token nextToken();
};
#endif // LEXER_H
