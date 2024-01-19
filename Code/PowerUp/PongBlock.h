#ifndef PONGBLOCK_H
#define PONGBLOCK_H

#include "../Common/Common.h"
#include "PowerUp.h"
#include "../BlocksAndTiles/Handled/Block.h"

/////////////////////////////////////////////////
///@brief A PowerUp inheriting both from PowerUp and Block which represents a block bouncing diagonally across a board, colliding with both tileHandler's tiles and currentBlock.
/////////////////////////////////////////////////
class PongBlock : public PowerUp, public Block {
public:
    ~PongBlock() = default;

/////////////////////////////////////////////////
///@brief Pongblock's constructor.
///@param reciever A pointer to the board who will recieve the pongblock.
/////////////////////////////////////////////////
    PongBlock(Board* reciever);

/////////////////////////////////////////////////
///@brief Spawns a pongblock on a board.
///@param board A pointer to the board on which the pongblock is to be spawned.
/////////////////////////////////////////////////
    void apply(Board* board);

/////////////////////////////////////////////////
///@brief Handles pongblocks movement and collision handling.
///@param direction A string describing in which direction the ponblock is going.
/////////////////////////////////////////////////
    void move(std::string const& direction);

/////////////////////////////////////////////////
///@brief A string in the format "BD", where B is the board the pongblock is on (L or R) and D is the direction it's going (L or R). 
/////////////////////////////////////////////////
    std::string direction;

/////////////////////////////////////////////////
///@brief Checks if the pongBlock will land the next tick.
/////////////////////////////////////////////////
    bool willLand() const override;
    
private:

/////////////////////////////////////////////////
///@brief Handles the pongblocks collision with both tileHandler's and currentBlock's tiles.
/////////////////////////////////////////////////
    bool handleCollision(Tile* tile);

/////////////////////////////////////////////////
///@brief Switches the pongBlocks direction.
/////////////////////////////////////////////////
    void switchDirection();    

/////////////////////////////////////////////////
///@brief Checks if the pongblock can move down without colliding.
/////////////////////////////////////////////////
    bool canMoveDown(Tile* tile) const;

/////////////////////////////////////////////////
///@brief Checks if the pongblock can move down without colliding.
/////////////////////////////////////////////////
    bool canMoveSide(Tile* tile) const;

/////////////////////////////////////////////////
///@brief A pointer to the blockHandler controlling the pongblock.
/////////////////////////////////////////////////
    BlockHandler* blockHandler;

};

#endif
