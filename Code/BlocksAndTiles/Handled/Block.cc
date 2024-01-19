#include "Block.h"
#include "Tile.h"
#include "../TileHandler.h"


Block::Block() {}
// ========================================================================================================================================================//

// ========================================================================================================================================================//
Block::Block(vector<Tile*> const& tilesIn, TileHandler* tileHandlerIn) : tileHandler{tileHandlerIn}, tiles{tilesIn} {
}

// ========================================================================================================================================================//

void Block::move(string const& direction) {
    if (willCollideWithTile(direction) || willCollideWithWall(direction)) {return;}
    for (Tile* tile : tiles) {
        tile->move(direction);
    }
}

// ========================================================================================================================================================//


bool Block::willCollideWithWall(string const& direction) const {
    
    for (Tile* tile : tiles) {
        if ((direction == "LL" && tile->position.x == 154) || (direction == "LR" && tile->position.x == 424)) {
            return true;
        }
        if ((direction == "RL" && tile->position.x == 904) || (direction == "RR" && tile->position.x == 1174)) {
            return true;
        } 
    }
    return false;
}

// ========================================================================================================================================================//

bool Block::willLand() const {

    vector<Tile*> allTiles = tileHandler->getTiles();
    //Check if the block has landed on the lowest board coordinate.
    for (Tile* blockTile : tiles) {
        if (blockTile->position.y == 723) {
            return true;
        }
        //Check if the block has landed on another tile.
        for (Tile* boardTile : allTiles ) {
           if ((blockTile -> position.x == (boardTile->position.x)) && (blockTile -> position.y == (boardTile->position.y - 30))) {
            return true;
           }
        } 
    }
    return false;
}   

// ========================================================================================================================================================//

bool Block::hasOverlap() {
    //Gets allTiles
    vector<Tile*> tileHandlerTiles = tileHandler->getTiles();
    vector<Tile*> blockHandlerTiles = tiles;

    for (Tile* blockHandlerTile : blockHandlerTiles) {
        for (Tile* tileHandlerTile : tileHandlerTiles) {
            if ((blockHandlerTile -> position.y == tileHandlerTile -> position.y) && (blockHandlerTile -> position.x == tileHandlerTile -> position.x)){
                return true;
            }
        }
    }   
    return false;
}

//===============================================================================================================================

bool Block::willCollideWithTile(string const& moveInput) const {
    for (Tile* blockTile : tiles) {
        for (Tile* tileHandlerTile : tileHandler->getTiles()) {
            if (tileHandlerTile->position.x == (blockTile->position.x + 30) && (blockTile->position.y == tileHandlerTile->position.y) && (moveInput[1] == 'R')) {
                return true;
            }
            if (tileHandlerTile->position.x == (blockTile->position.x - 30) && (blockTile->position.y == tileHandlerTile->position.y) && (moveInput[1] == 'L')) {
                return true;
            }
        }
    }
    return false;
}
