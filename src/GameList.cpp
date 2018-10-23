#include "GameList.h"

GameList::GameList(GameNode *firstGame) {
    this->firstGame = firstGame;
    int countGames = 1;

    this->currentGame = this->firstGame;
    while(this->currentGame->GetNext() != NULL) {
        this->currentGame = this->currentGame->GetNext();
        countGames++;
    }
    this->lastGame = this->currentGame;
    this->currentGame = this->firstGame;

    this->currentCount = countGames;
    #ifdef _DEBUGMODE
        std::cout<<"Gamelist created with "<<currentCount<<" games"<<std::endl;
    #endif

}

unsigned short GameList::GetCurrentCount() {
    return this->currentCount;
}

RESULT GameList::AddGame(Game game) {
    #ifdef _DEBUGMODE
        std::cout<<"Adding a game..."<<std::endl;
    #endif // _DEBUGMODE

    GameNode *newGame = new GameNode();
    newGame->SetGame(game);
	newGame->SetNext(NULL);
    this->lastGame->SetNext(newGame);
	this->lastGame = newGame;

    this->currentCount++;
	
	#ifdef _DEBUGMODE
        std::cout<<"Game with path: "<<game.GetPath()<<" added."<<std::endl;
    #endif // _DEBUGMODE
	
    return SUCCESS;
}

GameNode *GameList::GetNode() {
    return this->currentGame;
}

void GameList::MoveNext() {
    if(this->currentGame->GetNext())
        this->currentGame = this->currentGame->GetNext();
}
