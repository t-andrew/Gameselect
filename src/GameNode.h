#ifndef _CLASS_GAMENODE
#define _CLASS_GAMENODE

#include "Game.h"

class GameNode {
    private:
        Game g;
        GameNode *nextG;
		uid_size uId; //Assigned by GameList object. Unique id of node in the list.

    public:
		GameNode(unsigned int);
		
		//Setters
        void SetNext(GameNode *gameNode);
        void SetGame(Game g);

		//Getters
        Game GetGame();
        GameNode *GetNext();
		uid_size GetUID();
};

#endif //_CLASS_GAMENODE