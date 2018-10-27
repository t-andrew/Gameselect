#ifndef _CLASS_GAME
#define _CLASS_GAME


#include <iostream>
#include <cstdlib>
#include <cstring>

#include "typedefs.h"

class Game {
    private:
        char *name; //Name of the game
        char *path; //Path to executable file of the game

    public:
		Game();
        Game(const char *);
        Game(const char *, const char *);
        ~Game();
		
		//Getters
        char *GetPath(void);
		char *GetName(void);

        BOOLEAN IsEmpty(void);
};

#endif //_CLASS_GAME