#ifndef BLOCK_H
#define BLOCK_H

#include "../../Common/Common.h"

class Tile;
class TileHandler;

/////////////////////////////////////////////////
///@brief Class responsible for handling falling blocks collision, position and movement.
/////////////////////////////////////////////////
class Block {
public: 
    ~Block() = default;

/////////////////////////////////////////////////
///@brief Empty constructor for Object PongBlock to inherit.  
/////////////////////////////////////////////////
    Block();

/////////////////////////////////////////////////
///@brief Constructor that that instatiates the right TilePointers to use in a block.
///@param tilesIn A vector of tilepointer refrences used to .
///@param 
/////////////////////////////////////////////////
    Block(vector<Tile*> const& tilesIn, TileHandler* tileHandlerIn);

/////////////////////////////////////////////////
///@brief Vector variable containing tilepointers
/////////////////////////////////////////////////
    vector<Tile*> tiles;

/////////////////////////////////////////////////
///@brief Virtual boolean function that both Block.cc and PongBlock can define. Compares currentBlcoks position with the board bot coordinate and all the coordinates in TileHandlers tiles displayed on the board.
/////////////////////////////////////////////////
    virtual bool willLand() const;

/////////////////////////////////////////////////
///@brief Boolean Function to handle clipping between the currentBlock and allTiles in tileHandler by checking if their coordinates are the same. 
/////////////////////////////////////////////////
    bool hasOverlap(); 

/////////////////////////////////////////////////
///@brief Virtual function to handle the movement of the current falling block. Controll checks if it collides with either wall or tile and call the Tile objects move method.
///@param direction, A two char string that symbolise boardside, movedirection. leftboard , left key input = LL.
/////////////////////////////////////////////////
    virtual void move(string const& direction);

protected:

/////////////////////////////////////////////////
///@brief Virtual boolean function that controll checks if the players movement input will result in the tile moving into another tile by checking all the coordinates of tiles in TileHandler.
///@param moveInput, A two char string that symbolise boardside, movedirection. leftboard , left key input = LL.
/////////////////////////////////////////////////
    virtual bool willCollideWithTile(string const& moveInput) const;

/////////////////////////////////////////////////
///@brief Virtual boolean function that controll checks if the players movement input will result in the tile moving into a wall.
///@param moveInput, A two char string that symbolise boardside, movedirection. leftboard , left key input = LL.
/////////////////////////////////////////////////
    bool willCollideWithWall(string const& moveInput) const;

/////////////////////////////////////////////////
///@brief Protected pointer variable to TileHandler.
/////////////////////////////////////////////////
    TileHandler* tileHandler;
};


#endif