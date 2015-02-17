#include <iostream>

#include "Lexer.h"

Lexer::Lexer()
{
    while(getline(cin, input) && input != "end")
    {
        stringstream ss(input);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> temparr(begin, end);
        lexArr = temparr;
    }
}

Token Lexer::nextToken()
{
    // Implement
    Token *myToken = new Token();


    return *myToken;
}
