#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "RightBoard.h"

RightBoard::RightBoard(GameState* gameState) : Board(2, 750, 50, gameState, 904, 153) {
    tileHandler = new TileHandler(2, 904, 153);
}


