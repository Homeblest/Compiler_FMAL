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

    statements();
}

bool Parser::statements()
{
    // Do statements things
    if(!statement())
    {
        return false;
    }
    if(curToken.lexeme != ";")
    {
        return false;
    }
    curToken = myLexer->nextToken();

    if(!statements())
    {
        return false;
    }

    return true;
}
bool Parser::statement()
{
    // Do statement things
    return true;
}
