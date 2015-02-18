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

void Parser::statements()
{
    // Do statements things
    if(curToken.tCode != Token::END)
    {
        statement();
        if(curToken.tCode == Token::SEMICOL)
        {
            curToken = myLexer->nextToken();
            statements();
        }
        else
        {
            cout << "Syntax error! statements" << endl;
        }
    }
    curToken = myLexer->nextToken();
    return;
}
void Parser::statement()
{
    // Do statement things
    if(curToken.tCode == Token::ID)
    {
        curToken = myLexer->nextToken();

        if(curToken.tCode == Token::ASSIGN)
        {
            curToken = myLexer->nextToken();
            expr();
            curToken = myLexer->nextToken();
        }
        else
        {
            cout << "Syntax error! statement" << endl;
        }
    }
    else if(curToken.tCode == Token::PRINT)
    {
        curToken = myLexer->nextToken();
        if(curToken.tCode == Token::ID)
        {
            curToken = myLexer->nextToken();
        }
    }
    else
    {
        cout << "Syntax error! statement2" << endl;
    }
}
void Parser::expr()
{
    term();
    if(curToken.tCode == Token::PLUS){
        curToken = myLexer->nextToken();
        expr();
    }
    else if(curToken.tCode == Token::MINUS){
        curToken = myLexer->nextToken();
        expr();
    }
}

void Parser::term()
{
    factor();
    if(curToken.tCode == Token::MULT){
        curToken = myLexer->nextToken();
        term();
    }
}

void Parser::factor()
{
    if(curToken.tCode == Token::INT){
        curToken = myLexer->nextToken();
    }
    else if(curToken.tCode == Token::ID){
        curToken = myLexer->nextToken();
    }
    else if(curToken.tCode == Token::LPAREN){
        curToken = myLexer->nextToken();
        expr();
        if(curToken.tCode != Token::RPAREN){
            cout << "Syntax error! factor" << endl;
        }
    }
    else
    {
        cout << "Syntax error! factor2" << endl;
    }
}

bool Parser::checkError()
{
    return (curToken.tCode == Token::ERROR);
}
