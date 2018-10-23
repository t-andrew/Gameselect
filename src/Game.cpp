#include "Game.h"

Game::Game(const char *path) {
    this->path = (char *) malloc(sizeof(char) * (strlen(path)+1));
	if(this->path == NULL) {
		std::cerr<<"Warning: Failed allocation"<<std::endl;
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

Game::Game(const char *path, const char *name) {
    this->path = (char *) malloc(sizeof(char) * (strlen(path)+1));
    this->name = (char *) malloc(sizeof(char) * (strlen(name)+1));
    strcpy(this->path, path);
    strcpy(this->name, name);
}

Game::~Game() {
	#ifdef _DEBUGMODE
		std::cout<<"Warning! Game Object destroyed."<<std::endl;
	#endif
}

char *Game::GetPath(void) {
    return this->path;
}

char *Game::GetName(void) {
	return this->name;
}

BOOLEAN Game::IsEmpty(void) {
    if(!strcmp(this->path, "")) {return TRUE;}
    else return FALSE;
}
