#include<iostream>
#include "GameList.h"
#include "WinApp.h"

#define MAX_GAMES 8


//#define _DEBUGMODE

using namespace std;

int main(int argc, char **argv) {

    GameList n;
	WinApp wap;
	try {
		n.AddGame("C:\\Setup.exe");
		wap.Start(n.GetNode(1)->GetGame());
		cout<<n.GetNode(1)->GetGame().GetPath()<< " - " << n.GetNode(1)->GetGame().GetName()<<endl;
	}
	catch(const char* msg) {
		cerr<<msg<<endl;
	}
	
    
    return 0;
}
