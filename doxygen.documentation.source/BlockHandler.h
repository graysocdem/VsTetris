#ifndef BLOCKHANDLER_H
#define BLOCKHANDLER_H

#include <fstream>
#include <iomanip>
#include <sstream>
#include "../Common/Common.h"

class Block;
class TileHandler;
class Board;
class Tile;
class PongBlock;
/////////////////////////////////////////////////
///@brief Class responsible for handling a board's blocks' generation, deletion and drawing. 
/////////////////////////////////////////////////

class BlockHandler : public sf::Drawable {
public: 
    ~BlockHandler();

//////////////////////////////////////////////////
///@brief Blockhandler's constructor, called by Board.
///@param id Blockhandler's ID, used for identifying the board i.e in the Game Over-message.
///@param xOff The x-offset in pixels, represents the gap between the screen border and the Board border.
///@param yOff The y-offset in pixels, represents the gap between the top screen border and the Board's top.
///@param TileHandlerIn The tilehandler associated to this blockhandler.
/////////////////////////////////////////////////
    BlockHandler(const int id, const int xOff, const int yOff, TileHandler* tileHandlerIn);
//////////////////////////////////////////////////
///@brief Generates a new, random block and places it around the middle of the board.
/////////////////////////////////////////////////
    void generateBlock();
/////////////////////////////////////////////////
///@brief Loads block blueprients from a text file.
/////////////////////////////////////////////////
    void loadBlocks();
/////////////////////////////////////////////////
///@brief Handles user move inputs
///@param direction A two-character string in the format "BD" where B is the board ((L)eft or (R)ight) and D is which direction ((L)eft, (R)ight or (D)own). 
/////////////////////////////////////////////////
    void userMove(string const& direction);
/////////////////////////////////////////////////
///@brief Function for key inputs that handles movement and powerup usage.
///@param &leftTime, Variable that refrences leftBoard's clock a sf::clock that is used to control the time intervall between inputs.
///@param &rightTime, Variable that refrences to the adress of a sf::clock that is used to control the time intervall between inputs.
/////////////////////////////////////////////////
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
/////////////////////////////////////////////////
///@brief Represents a tick. Calls the appropriate move functions depending on the board-state, and also generates and destroys entities as needed.
/////////////////////////////////////////////////
    void update();
/////////////////////////////////////////////////
///@brief Transfers all tile pointers in a block to tilehandler's tiles list.
///@param block A pointer to the block whose tiles are to be transfered.
/////////////////////////////////////////////////
    void transferBlocks(Block* block);
/////////////////////////////////////////////////
///@brief Deletes a block. Note that it does not call delete on the pointers. 
///@param block A pointer to the block which is to be deleted.
/////////////////////////////////////////////////
    void deleteBlock(Block* block);
/////////////////////////////////////////////////
///@brief Fetches currentBlock's tiles list.
/////////////////////////////////////////////////
    vector<Tile*> getCurrentBlockTiles();
/////////////////////////////////////////////////
///@brief Sets the pongBlock member pointer to the adress of the newly created pongblock.
///@param pongBlock A pointer to the pongblock which is to be set in blockhandler.
/////////////////////////////////////////////////
    void setPongBlock(PongBlock* pongBlock);
/////////////////////////////////////////////////
///@brief Ends the game and prints a win/loss message to the terminal.
///@param id The id of the board (player) who lost.
/////////////////////////////////////////////////
    void hasLost(int id) const;
private:    

/////////////////////////////////////////////////
///@brief A pointer to the current block.
/////////////////////////////////////////////////
    Block* currentBlock;
/////////////////////////////////////////////////
///@brief A pointer to the current pongblock. Value is set to nullptr if there is none on the board.
/////////////////////////////////////////////////
    PongBlock* pongBlock;
/////////////////////////////////////////////////
///@brief A pointer to the blockahandaler's tilehandler.
/////////////////////////////////////////////////
    TileHandler* tileHandler;

/////////////////////////////////////////////////
///@brief A container for the block blueprints. Consists of vectors of coordinates associated to an ID.
/////////////////////////////////////////////////
    map<int, vector<pair<int, int>>> blockMap; 

/////////////////////////////////////////////////
///@brief Variable that stores the xOffset as a integer.
/////////////////////////////////////////////////
    const int xOffset;

/////////////////////////////////////////////////
///@brief Variable that stores the yOffset as a integer.
/////////////////////////////////////////////////
    const int yOffset;

/////////////////////////////////////////////////
///@brief The length of a tile's side.
/////////////////////////////////////////////////
    const int tileSide;
    
/////////////////////////////////////////////////
///@brief The ID of the board associated to the blockhandler.
/////////////////////////////////////////////////
    const int id;
    


};

#endif