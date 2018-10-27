#ifndef _CLASS_GAMELIST
#define _CLASS_GAMELIST

#include <iostream>

#include "Game.h"
#include "GameNode.h"
#include "typedefs.h"

class GameList {
    private:
        unsigned short currentCount;
        GameNode *currentGame;
        GameNode *firstGame; //Point to the first game
        GameNode *lastGame; //Keep track of the last game in the list too for now
		uid_size lastUID;

    public:
		GameList();
        GameList(GameNode *firstGame);

        unsigned short GetCurrentCount();

        RESULT AddGame(Game game);
		RESULT AddGame(const char *gamePath);

        GameNode *GetNode();
		GameNode *GetNode(uid_size);
		uid_size GetLastUID();
        void MoveNext();
};

#endif //_CLASS_GAMELIST