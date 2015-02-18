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

        string word;
        for(unsigned int i = 0; i < temparr.size(); i++)
        {
            for(unsigned int j = 0; j < temparr[i].size(); j++)
            {
                if(temparr[i][j] == '(')
                {
                    lexArr.push_back("(");
                    temparr[i].erase(j,1);
                }
                else if(temparr[i][j] == ')')
                {
                    lexArr.push_back(")");
                    temparr[i].erase(j,1);
                }
                else if(isalpha(temparr[i][j]))
                {

                }
            }
            if(temparr[i].back() == ';'){
                temparr[i].erase(temparr[i].end() - 1);
                lexArr.push_back(temparr[i]);
                lexArr.push_back(";");
            }
            else
            {
                lexArr.push_back(temparr[i]);
            }

        }
    }
    counter = 0;

}

Token Lexer::nextToken()
{
    // Implement
    Token *nextToken = new Token();

    if(counter < lexArr.size())
    {
        // Get the string at index counter
        string word = lexArr[counter];
        // Check if first digit of word is a letter
        if(isalpha(word[0]))
        {
            if(word == "print")
            {
                nextToken->lexeme = word;
                nextToken->tCode = Token::PRINT;
            }
            else
            {
                nextToken->lexeme = word;
                nextToken->tCode = Token::ID;
            }
        }
        // Else check if first digit of word is a number
        else if(isdigit(word[0]))
        {
            nextToken->lexeme = word;
            nextToken->tCode = Token::INT;
        }
        else if(word == "+")
        {
            nextToken->lexeme = "+";
            nextToken->tCode = Token::PLUS;
        }
        else if (word == "-")
        {
            nextToken->lexeme = "-";
            nextToken->tCode = Token::MINUS;
        }
        else if(word == "*")
        {
            nextToken->lexeme = "*";
            nextToken->tCode = Token::MULT;
        }
        else if(word == "(")
        {
            nextToken->lexeme = "(";
            nextToken->tCode = Token::LPAREN;
        }
        else if(word == ")")
        {
            nextToken->lexeme = ")";
            nextToken->tCode = Token::RPAREN;
        }
        else if(word == "=")
        {
            nextToken->lexeme = "=";
            nextToken->tCode = Token::ASSIGN;
        }
        else if(word == ";")
        {
            nextToken->lexeme = ";";
            nextToken->tCode = Token::SEMICOL;
        }
        else
        {
            nextToken->tCode = Token::ERROR;
        }

        counter++;

        return *nextToken;

    }
    nextToken->tCode = Token::ERROR;
    return *nextToken;
}
