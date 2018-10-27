#include "Game.h"

char *Game::GetFilename(void) {
	
	//Search for the last slash
	char *lastSlash = strrchr(this->path, '/');
	if(lastSlash == NULL) {
		//No slash found. Maybe the path has backslashes
		lastSlash = strrchr(this->path, '\\');
		if(lastSlash == NULL) {
			//No backslashes either. This should not be possible since the path
			//is a valid absolute path.
			return NULL;
		}
	}
	
	lastSlash++; //No need to include the slash
	return lastSlash;
	
}


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
		if(this->IsPathValid(path) == FALSE) {
			throw "Path is invalid or inaccessible";
		}
		strcpy(this->path, path);
		
		char *name = this->GetFilename();
		this->name = (char *) malloc(sizeof(char) * (strlen(name)+1));
		strcpy(this->name, name);
		
	}
}

Game::Game(const char *path, const char *name) {
	
    this->path = (char *) malloc(sizeof(char) * (strlen(path)+1));
    this->name = (char *) malloc(sizeof(char) * (strlen(name)+1));
	
	if(this->path != NULL && this->name != NULL) {
		if(this->IsPathValid(path) == FALSE) {
			throw "Path is invalid or inaccessible";
		}
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

BOOLEAN Game::IsPathValid(const char *path) {
	FILE *fp;
	
	fp = fopen(path, "r");
	if(fp == NULL)
		return FALSE;
	
	//Path is valid
	fclose(fp);
	return TRUE;
}	

