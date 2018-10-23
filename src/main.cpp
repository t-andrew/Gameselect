#include<iostream>
#include<cstdlib>
#include<cstring>

#define MAX_GAMES 8

#define FAIL 0
#define SUCCESS 1
#define TRUE 1
#define FALSE 0

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
            strcpy(this->path, path);

            //Set the name to the name of the executable
            char *lastSlash = strrchr(this->path, '/');
            if(lastSlash == NULL) {
                //No slash found. Maybe the path has backslashes
                lastSlash = strrchr(this->path, '\\');
                if(lastSlash == NULL) {
                    //No backslashes either. Just set the name to the path
                    this->name = (char *) malloc(sizeof(char) * (strlen(path)+1));
                    strcpy(this->name, this->path);
                } else {
                    lastSlash++; //No need to include the slash
                    this->name = (char *) malloc(sizeof(char) * (strlen(lastSlash)+1));
                    strcpy(this->name, lastSlash);
                }
            } else {
                lastSlash++; //No need to include the slash
                this->name = (char *) malloc(sizeof(char) * (strlen(lastSlash)+1));
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
            free(this->name);
            free(this->path);
        }

        char *GetPath(void) {
            return this->path;
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
            countGames++; //Count the last game aswell
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

            GameNode *newGame;
            newGame->SetGame(game);
            lastGame->SetNext(newGame);
            newGame->SetNext(NULL);

            this->currentCount++;
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
    Game hh("cvbbhgjkl");
    Game hhh("zaxcx/yui");

    GameNode *gn1, *gn2, *gn3, *gn4;

    gn1= new GameNode();
    gn2= new GameNode();
    gn3= new GameNode();
    gn4= new GameNode();

    gn1->SetGame(g);
    gn1->SetNext(gn2);
    gn2->SetGame(h);
    gn2->SetNext(gn3);
    gn3->SetGame(hh);
    gn3->SetNext(gn4);
    gn4->SetGame(hhh);
    gn4->SetNext(NULL);

    GameList n(gn1);

    cout<<n.GetNode()->GetGame().GetPath()<<endl;
    n.MoveNext();
    cout<<n.GetNode()->GetGame().GetPath()<<endl;
    n.MoveNext();
    cout<<n.GetNode()->GetGame().GetPath()<<endl;
    n.MoveNext();
    cout<<n.GetNode()->GetGame().GetPath()<<endl;

    return 0;
}
