#include "PongBlock.h"
#include "PowerUp.h"

#include "../Common/Common.h"
#include "../BlocksAndTiles/Handled/Block.h"
#include "../Board/Board.h"
#include "../BlocksAndTiles/Handled/Tile.h"
#include "../BlocksAndTiles/BlockHandler.h"

// ========================================================================================================================================================//

PongBlock::PongBlock(Board* reciever) {

    if (reciever->getID() == 1) {
        direction = "LR";
    }
    else {
        direction = "RR";
    }

    tileHandler = reciever->getTileHandler();
    blockHandler = reciever->getBlockHandler();
    sf::Texture tempTexture;
    tempTexture.loadFromFile("../Textures/Pink.png");
    tiles.push_back(new Tile(tempTexture, reciever->getXOffset(), reciever->getYOffset())); 

}
    
// ========================================================================================================================

void PongBlock::move(string const&) {

    bool moved{false};

    for (Tile* tile : blockHandler->getCurrentBlockTiles()) {
        if (handleCollision(tile)) {
            moved = true;
            break;
        }    
    }
    
    if (moved) {return;}

    for (Tile* tile : tileHandler->getTiles()) {
        if (handleCollision(tile)) {
            break;
        }    
    }
}  

// ========================================================================================================================

void PongBlock::apply(Board* board) {
    blockHandler = board->getBlockHandler();
    blockHandler->setPongBlock(this);
}

// ================================================================================================================================

void PongBlock::switchDirection() {
    if (direction == "LR") {
        direction = "LL";
    }
    else if (direction == "LL") {
        direction = "LR";
    }
    else if (direction == "RL") {
        direction = "RR";
    }
    else if (direction == "RR") {
        direction = "RL";
    }
}


// ================================================================================================================================

bool PongBlock::canMoveSide(Tile* tile) const { 

        if ((direction == "LL" && tiles[0]->position.x == 154))  {
            std::cout << (direction == "LL" && tiles[0]->position.x == 154) << std::endl;
            return false;
        }
        else if (direction == "LR" && tiles[0]->position.x == 424) {
            return false;
        }
        else if ((direction == "RL" && tiles[0]->position.x == 904) || (direction == "RR" && tiles[0]->position.x == 1174)) {
            return false;
        }
         if (((tiles[0]->position.x + 30 == tile->position.x)) && ((tiles[0]->position.y + 30 == tile->position.y) || (tiles[0]->position.y == tile->position.y))) {
        return false;
        }
        return true;
}


// ================================================================================================================================

bool PongBlock::canMoveDown(Tile* tile) const {

    int offset;
    if (direction[1] == 'R') {
        offset = 30;
    }
    else {
        offset = -30;
    }
  if (((tiles[0]->position.x + offset == tile->position.x)) && ((tiles[0]->position.y == tile->position.y + 30))) {
        return false;
    }
    return true;
}

// ================================================================================================================================

bool PongBlock::handleCollision(Tile* tile) {

    if (canMoveSide(tile)) {
        if (canMoveDown(tile)) {
            tiles[0]->move(direction);
            tiles[0]->move("DD");
            return true;
        }
    }
    switchDirection();
    if (canMoveSide(tile)) {
         if (canMoveDown(tile)) {
            tiles[0]->move(direction);
            tiles[0]->move("DD");
            return true;
        }
    }
    else {
        switchDirection();
    }

    switchDirection();
    tiles[0]->move(direction);
    return false;
}


// ================================================================================================================================


bool PongBlock::willLand() const  {
    //if it lands straight on the down move. (Board)
    if (tiles[0] -> position.y == 723) {
        return true;
    }


    //Checks if it would collide with currentBlock. Cannot use canMoveSide() as it is only used when currentBlock has already moved. Would generalize but cannot due to time constraints.
    int offset{};
    if(direction[1] == 'R') {
        offset = 30;
    }        
    else {
        offset = -30;
    }

    for (Tile* tile : blockHandler->getCurrentBlockTiles()) {
           if (((int)tiles[0]->position.x+offset == tile->position.x) && ((int)tiles[0]->position.y==tile->position.y)) {return false;}        
    }

    for (Tile* tile : tileHandler->getTiles()) {
           if ((tiles[0] -> position.x + offset == tile->position.x) && (tiles[0] -> position.y == tile->position.y)) {std::cout << "pongblock recognizes it is going to collide with tilehandler tiles" << std::endl; return false;}        
    }

    //if it lands straight on the down move. (Tile)
    for (Tile* boardTile : tileHandler->getTiles() ) {
           if ((tiles[0] -> position.x == boardTile->position.x) && (tiles[0] -> position.y + 30 == boardTile->position.y)) {
                return true;
           }
           else if ((direction[1] == 'R') && (tiles[0] -> position.x + 30 == (boardTile->position.x)) && (tiles[0] -> position.y + 30 == (boardTile->position.y))) {
                return true;
            }
            else if ((direction[1] == 'L') && (tiles[0] -> position.x - 30 == (boardTile->position.x)) && (tiles[0] -> position.y == (boardTile->position.y - 30))) {
                return true;
            }
        }
        return false;
}
    
// ========================================================================================================================================================//