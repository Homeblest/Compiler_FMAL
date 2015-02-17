#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

class Token {

public:
    enum TokenCode {
        ID, ASSIGN, SEMICOL, INT, PLUS, MINUS,
        MULT, LPAREN, RPAREN, PRINT, END, ERROR
    };
    // Constructors
    Token(){
        lexeme = "";
        tCode = ERROR;
    };

    Token(string lex, TokenCode code){
        lexeme = lex;
        tCode = code;
    };

    string lexeme;
    TokenCode tCode;
};
#endif // TOKEN_H
