#include<iostream>
#include "Game.h"
#include "GameNode.h"
#include "GameList.h"

#define MAX_GAMES 8


//#define _DEBUGMODE

using namespace std;

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
