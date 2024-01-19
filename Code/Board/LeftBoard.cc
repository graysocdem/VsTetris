#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "LeftBoard.h"
#include "Board.h"

LeftBoard::LeftBoard(GameState* gameState) : Board(1, 0, 50, gameState, 154, 153)  {
    tileHandler = new TileHandler(1, 154, 153);
}


