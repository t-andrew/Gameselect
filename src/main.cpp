#include<iostream>
#include "GameList.h"

#define MAX_GAMES 8


//#define _DEBUGMODE

using namespace std;

int main(int argc, char **argv) {

    GameList n;
	try {
		n.AddGame("D:\\Games\\Duke Nukem Forever\\System\\DukeForever.exe");
		n.AddGame("D:\\Games\\Duke Nukem Forever\\System\\Launcher.exe");
		n.AddGame("D:\\Games\\Duke Nukem Forever\\Redist\\DCO\\Setup.exe");
		
		cout<<n.GetNode(4)->GetGame().GetPath()<< " - " << n.GetNode(2)->GetGame().GetName()<<endl;

	}
	catch(const char* msg) {
		cerr<<msg<<endl;
	}
	
    
    return 0;
}
