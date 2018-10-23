#ifndef _CLASS_GAMENODE
#define _CLASS_GAMENODE

#include "Game.h"

class GameNode {
    private:
        Game g;
        GameNode *nextG;

    public:
        GameNode();
	
		//Setters
        void SetNext(GameNode *gameNode);
        void SetGame(Game g);

		//Getters
        Game GetGame();
        GameNode *GetNext();
};

#endif //_CLASS_GAMENODE