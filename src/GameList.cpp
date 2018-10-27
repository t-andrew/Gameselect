#include "GameList.h"


GameList::GameList() {
	this->firstGame = NULL;
	this->currentGame = NULL;
	this->lastGame = NULL;
	
	this->currentCount = 0;
	this->lastUID = 0;
}

/* DEPRECATED
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
*/

unsigned short GameList::GetCurrentCount() {
    return this->currentCount;
}

RESULT GameList::AddGame(Game game) {
    #ifdef _DEBUGMODE
        std::cout<<"Adding a game..."<<std::endl;
    #endif // _DEBUGMODE
	
	lastUID++;
	
	GameNode *newGame = new GameNode(lastUID);
    newGame->SetGame(game);
	newGame->SetNext(NULL);
	
	if(this->firstGame == NULL && this->currentCount == 0) {
		//There were no games in the game list
		//
		this->firstGame = newGame;
		this->currentGame = this->firstGame;
		this->lastGame = this->currentGame;
	}
	else
	{
		this->lastGame->SetNext(newGame);
		this->lastGame = newGame;
	}

    this->currentCount++;
	
	#ifdef _DEBUGMODE
        std::cout<<"Game with path: "<<game.GetPath()<<" added."<<std::endl;
    #endif // _DEBUGMODE
	
    return SUCCESS;
}

RESULT GameList::AddGame(const char *gamePath) {
	lastUID++;
	
	GameNode *newGame = new GameNode(lastUID);
	Game game(gamePath);
    newGame->SetGame(game);
	newGame->SetNext(NULL);
	
	if(this->firstGame == NULL && this->currentCount == 0) {
		//There were no games in the game list
		//
		this->firstGame = newGame;
		this->currentGame = this->firstGame;
		this->lastGame = this->currentGame;
	}
	else
	{
		this->lastGame->SetNext(newGame);
		this->lastGame = newGame;
	}

    this->currentCount++;
	
	return SUCCESS;
}

GameNode *GameList::GetNode() {
    return this->currentGame;
}

GameNode *GameList::GetNode(uid_size id) {
	if(id > this->currentCount) {
		throw "Out of bounds";
	}
	
	this->currentGame = this->firstGame;
	while(this->currentGame->GetUID() != id && this->currentGame->GetUID() < id) {
		this->MoveNext();	
	}
	
	if(this->currentGame->GetUID() == id) {
		return this->currentGame;
	}
	else
	{
		return NULL;
	}
}

unsigned int GameList::GetLastUID() {
	return this->lastUID;
}

void GameList::MoveNext() {
    if(this->currentGame->GetNext())
        this->currentGame = this->currentGame->GetNext();
}
