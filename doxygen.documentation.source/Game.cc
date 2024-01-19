#include "Game.h"

// ========================================================================================================================================================//

void Game::load() {
    gameState = new GameState();
    gameState->run();
    delete gameState;

}

// ========================================================================================================================================================//

Game::~Game() {
    delete gameState;
}

// ========================================================================================================================================================//