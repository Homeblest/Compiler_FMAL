#include <iostream>

#include "Lexer.h"

Lexer::Lexer()
{
    string input;
    finalString = "";
    while(getline(cin, input) && input != "end")
    {
        for(unsigned int i = 0; i < input.length(); i++)
        {
            if(input[i] == ' ')
            {
                input.erase(i,1);
            }
        }
        finalString += input;
    }
}

Token Lexer::nextToken()
{
    if(finalString[0] == '(')
    {
        theToken.lexeme = "(";
        theToken.tCode = Token::LPAREN;
        finalString.erase(0,1);
    }
    else if(finalString[0] == ')')
    {
        theToken.lexeme = ")";
        theToken.tCode = Token::RPAREN;
        finalString.erase(0,1);
    }
    else if(finalString[0] == '+')
    {
        theToken.lexeme = "+";
        theToken.tCode = Token::PLUS;
        finalString.erase(0,1);
    }
    else if(finalString[0] == '-')
    {
        theToken.lexeme = "-";
        theToken.tCode = Token::MINUS;
        finalString.erase(0,1);
    }
    else if(finalString[0] == '*')
    {
        theToken.lexeme = "*";
        theToken.tCode = Token::MULT;
        finalString.erase(0,1);
    }
    else if(finalString[0] == '=')
    {
        theToken.lexeme = "=";
        theToken.tCode = Token::ASSIGN;
        finalString.erase(0,1);
    }
    else if(finalString[0] == ';')
    {
        theToken.lexeme = ";";
        theToken.tCode = Token::SEMICOL;
        finalString.erase(0,1);
    }
    else if(isdigit(finalString[0]))
    {
        string numb = "";
        int j = 0;
        while(isdigit(finalString[j]))
        {
            numb += finalString[j];
            j++;
        }
        theToken.lexeme = numb;
        theToken.tCode = Token::INT;
        finalString.erase(0,j);
    }
    else if(isalpha(finalString[0]))
    {
        if(finalString[0] == 'e')
        {
            if(finalString[1] == 'n')
            {
                if(finalString[2] == 'd')
                {
                    if(finalString.length() == 3)
                    {
                        theToken.lexeme = "end";
                        theToken.tCode = Token::END;
                        finalString.erase(0,3);
                        return theToken;
                    }
                }
            }
        }
        else if(finalString[0] == 'p')
        {
            if(finalString[1] == 'r')
            {
                if(finalString[2] == 'i')
                {
                    if(finalString[3] == 'n')
                    {
                        if(finalString[4] == 't')
                        {
                            theToken.lexeme = "print";
                            theToken.tCode = Token::PRINT;
                            finalString.erase(0,5);
                            return theToken;
                        }
                    }
                }
            }
        }
        int j = 0;
        string id = "";
        while(isalpha(finalString[j]))
        {
            id += finalString[j];
            j++;
        }
        theToken.lexeme = id;
        theToken.tCode = Token::ID;
        finalString.erase(0,id.length());
    }
    else
    {
        theToken.lexeme = "wow";
        theToken.tCode = Token::ERROR;
    }
    return theToken;
}
