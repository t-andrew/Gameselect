#include "GameNode.h"

GameNode::GameNode(unsigned int uId) {
	this->uId = uId;
};

void GameNode::SetNext(GameNode *gameNode) {
    this->nextG = gameNode;
}

void GameNode::SetGame(Game g) {
    this->g = g;
}

Game GameNode::GetGame() {
    return this->g;
}

GameNode *GameNode::GetNext() {
    return this->nextG;
}

unsigned int GameNode::GetUID() {
	return this->uId;
}