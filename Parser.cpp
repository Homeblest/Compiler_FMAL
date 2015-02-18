#include "Parser.h"


void Parser::parse()
{

    // Just prints out the lexeme of the token
    // Stops if it runs into an error.
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
