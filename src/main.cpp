#include<iostream>
#include "GameList.h"

#define MAX_GAMES 8


//#define _DEBUGMODE

using namespace std;

int main(int argc, char **argv) {

    GameList n;
	n.AddGame("D:\\Games\\Duke Nukem Forever\\System\\DukeForever.exe");

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
