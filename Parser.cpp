#include "Parser.h"

void Parser::parse()
{
    /*
    curToken = myLexer->nextToken();
    while(curToken.tCode != Token::ERROR){
        cout << curToken.lexeme << endl;
        curToken = myLexer->nextToken();
    }
    */
    curToken = myLexer->nextToken();
    statements();
}

bool Parser::statements()
{
    // Do statements things
    if(!checkError())
    {
        if(curToken.tCode != Token::END)
        {
            if(!statement())
            {
                return false;
            }
            if(curToken.tCode != Token::SEMICOL)
            {
                return false;
            }
            curToken = myLexer->nextToken();
            if(!statements())
            {
                return false;
            }
        }
    }

    return true;
}
bool Parser::statement()
{
    // Do statement things
    if(curToken.tCode == Token::ID)
    {
        curToken = myLexer->nextToken();

        if(curToken.tCode != Token::ASSIGN)
        {
            return false;
        }

        curToken = myLexer->nextToken();
        expr();
    }
    else if(curToken.tCode == Token::PRINT)
    {
        curToken = myLexer->nextToken();
        if(curToken.tCode != Token::ID)
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return true;
}
bool Parser::expr()
{

    return true;
}

bool Parser::term()
{
    return true;
}

bool Parser::factor()
{
    return true;
}

bool Parser::checkError()
{
    return (curToken.tCode == Token::ERROR);
}
