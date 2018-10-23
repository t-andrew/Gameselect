#include<iostream>
#include<cstdlib>
#include<cstring>

#define MAX_GAMES 8

#define FAIL 0
#define SUCCESS 1
#define TRUE 1
#define FALSE 0

//#define _DEBUGMODE

using namespace std;

typedef short RESULT;
typedef short BOOLEAN;

class Game {
    private:
        char *name; //Name of the game
        char *path; //Path to executable file of the game


    public:

        Game(const char *path) {
            this->path = (char *) malloc(sizeof(char) * (strlen(path)+1));
			if(this->path == NULL) {
				cerr<<"Warning: Failed allocation"<<endl;
			}
            strcpy(this->path, path);
			
            //Set the name to the name of the executable
            char *lastSlash = strrchr(this->path, '/');
            if(lastSlash == NULL) {
                //No slash found. Maybe the path has backslashes
                lastSlash = strrchr(this->path, '\\');
                if(lastSlash == NULL) {
                    //No backslashes either. Just set the name to the path
                    this->name = (char *) malloc(sizeof(char) * (strlen(path)+2));
                    strcpy(this->name, this->path);
                } else {
                    lastSlash++; //No need to include the slash
                    this->name = (char *) malloc(sizeof(char) * (strlen(lastSlash)+2));
                    strcpy(this->name, lastSlash);
                }
            } else {
                lastSlash++; //No need to include the slash
                this->name = (char *) malloc(sizeof(char) * (strlen(lastSlash)+2));
                strcpy(this->name, lastSlash);
            }
        }

        Game(const char *path, const char *name) {
            this->path = (char *) malloc(sizeof(char) * (strlen(path)+1));
            this->name = (char *) malloc(sizeof(char) * (strlen(name)+1));
            strcpy(this->path, path);
            strcpy(this->name, name);
        }

        ~Game() {
			#ifdef _DEBUGMODE
				cout<<"Warning! Game Object destroyed."<<endl;
			#endif
        }

        char *GetPath(void) {
            return this->path;
        }
		
		char *GetName(void) {
			return this->name;
		}

        BOOLEAN IsEmpty(void) {
            if(!strcmp(this->path, "")) {return TRUE;}
            else return FALSE;
        }
};

class GameNode {
    private:
        Game g;
        GameNode *nextG;

    public:
        GameNode() : g("") {}

        void SetNext(GameNode *gameNode) {
            this->nextG = gameNode;
        }

        void SetGame(Game g) {
            this->g = g;
        }

        Game GetGame() {
            return this->g;
        }

        GameNode *GetNext() {
            return this->nextG;
        }
};

class GameList {
    private:
        //unsigned short maxGames;
        unsigned short currentCount;
        GameNode *currentGame;
        GameNode *firstGame; //Point to the first game
        GameNode *lastGame; //Keep track of the last game in the list too for now

    public:

        GameList(GameNode *firstGame) {
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
                cout<<"Gamelist created with "<<currentCount<<" games"<<endl;
            #endif

        }

        unsigned short GetCurrentCount() {
            return this->currentCount;
        }

        RESULT AddGame(Game game) {
            #ifdef _DEBUGMODE
                cout<<"Adding a game..."<<endl;
            #endif // _DEBUGMODE

            GameNode *newGame = new GameNode();
            newGame->SetGame(game);
			newGame->SetNext(NULL);
            this->lastGame->SetNext(newGame);
			this->lastGame = newGame;
			
			///this->currentGame = this->firstGame;
			
            this->currentCount++;
			
			#ifdef _DEBUGMODE
                cout<<"Game with path: "<<game.GetPath()<<" added."<<endl;
            #endif // _DEBUGMODE
			
            return SUCCESS;
        }

        GameNode *GetNode() {
            return this->currentGame;
        }

        void MoveNext() {
            if(this->currentGame->GetNext())
                this->currentGame = this->currentGame->GetNext();
        }
};

int main(int argc, char **argv) {

    Game g("asd/qwe");
    Game h("ty/cvbn");
	Game hh1("cvbbhgjkl");
    Game hh2("cvb/bh/gjkl2");
    Game hhh("zaxcx/yui");

    GameNode *gn1 = new GameNode();

    gn1->SetGame(g);
    gn1->SetNext(NULL);

    GameList n(gn1);
	n.AddGame(h);
	n.AddGame(hh1);
	n.AddGame(hh2);
	n.AddGame(hhh);

    cout<<n.GetNode()->GetGame().GetPath()<< " - " << n.GetNode()->GetGame().GetName()<<endl;
    n.MoveNext();
    cout<<n.GetNode()->GetGame().GetPath()<< " - " << n.GetNode()->GetGame().GetName()<<endl;
    n.MoveNext();
    cout<<n.GetNode()->GetGame().GetPath()<< " - " << n.GetNode()->GetGame().GetName()<<endl;
    n.MoveNext();
    cout<<n.GetNode()->GetGame().GetPath()<< " - " << n.GetNode()->GetGame().GetName()<<endl;
	n.MoveNext();
    cout<<n.GetNode()->GetGame().GetPath()<< " - " << n.GetNode()->GetGame().GetName()<<endl;
    return 0;
}
