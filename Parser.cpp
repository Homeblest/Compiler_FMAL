#include "Parser.h"


void Parser::parse()
{
    Token myToken = myLexer->nextToken();
    while(myToken.tCode != Token::ERROR)
    {
        cout << myToken.lexeme << endl;
        myToken = myLexer->nextToken();
    }
    if(myToken.tCode == Token::ERROR){
        cout << "error token recieved" << endl;
    }
}
