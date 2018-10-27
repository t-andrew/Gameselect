#include "Game.h"

Game::Game() {
	this->path = NULL;
	this->name = NULL;
}

Game::Game(const char *path) {
    this->path = (char *) malloc(sizeof(char) * (strlen(path)+1));
	if(this->path == NULL) {
		std::cerr<<"Warning: Failed allocation"<<std::endl;
		this->name = NULL;
	} else {
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
}

Game::Game(const char *path, const char *name) {
	
    this->path = (char *) malloc(sizeof(char) * (strlen(path)+1));
    this->name = (char *) malloc(sizeof(char) * (strlen(name)+1));
	
	if(this->path != NULL && this->name != NULL) {
		strcpy(this->path, path);
		strcpy(this->name, name);
	} else {
		this->path = NULL;
		this->name = NULL;
	}
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
    if(this->path==NULL) {return TRUE;}
    else return FALSE;
}



