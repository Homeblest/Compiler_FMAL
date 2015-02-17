#include <iostream>
#include <sstream>

#include "Lexer.h"

Token Lexer::nextToken()
{
    // Implement
    Token *myToken = new Token();

    string input;
    stringstream myStream;

    while(getline(cin, input) && input != "end")
    {
        // Read line and process
        for(unsigned int i = 0; i < input.length(); i++)
        {
            if(isalpha(input[i]))
            {
                // Input is a word, process that word
                while(isalpha(input[i]))
                {
                    myStream << input[i];
                    i++;
                }
                string word = myStream.str();
                // One word is now in myStream
                // Do stuff with that word.
                if(word == "print")
                {
                    myToken->lexeme = "print";
                    myToken->tCode = Token::PRINT;
                }
                else {
                    myToken->lexeme = word;
                    myToken->tCode = Token::ID;
                }
                myStream.str(string());
            }
            else if(isdigit(input[i]))
            {
                // Input is a number, process that number
                while(isdigit(input[i]))
                {
                    myStream << input[i];
                    i++;
                }

                string number = myStream.str();

                myToken->lexeme = number;
                myToken->tCode = Token::INT;

                myStream.str(string());
            }
            else if(input[i] == '+') {
                myToken->lexeme = "+";
                myToken->tCode = Token::PLUS;
            }
            else if (input[i] == '-')
            {
                myToken->lexeme = "-";
                myToken->tCode = Token::MINUS;
            }
            else if(input[i] == '*')
            {
                myToken->lexeme = "*";
                myToken->tCode = Token::MULT;
            }
            else if(input[i] == '(')
            {
                myToken->lexeme = "(";
                myToken->tCode = Token::LPAREN;
            }
            else if(input[i] == ')')
            {
                myToken->lexeme = ")";
                myToken->tCode = Token::RPAREN;
            }
            else if(input[i] == '=')
            {
                myToken->lexeme = "=";
                myToken->tCode = Token::ASSIGN;
            }
            else if(input[i] == ';')
            {
                myToken->lexeme = ";";
                myToken->tCode = Token::SEMICOL;
            }
            else
            {
                myToken->lexeme = "";
                myToken->tCode = Token::ERROR;
            }
        }
    }
    return *myToken;
}
