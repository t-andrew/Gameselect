#include "GameNode.h"

GameNode::GameNode() {};

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