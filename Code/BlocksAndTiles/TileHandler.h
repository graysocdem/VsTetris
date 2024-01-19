#ifndef TILEHANDLER_H
#define TILEHANDLER_H

#include "../Common/Common.h"

class Tile;
class BlockHandler;

/////////////////////////////////////////////////
///@brief Class responsible for storing, drawing and removing tiles.
/////////////////////////////////////////////////
class TileHandler : public sf::Drawable {
public: 
    ~TileHandler();

/////////////////////////////////////////////////
///@brief Constructor that instatiates a BlockHandler object with associated id and coordinate offset.
///@param id, Id number as integer
///@param xOffset, x pixel coordinate offset as integer.
///@param yOffset, y pixel coordinate offset as integer.
/////////////////////////////////////////////////
    TileHandler(const int id, const float xOffset, const float yOffset);

/////////////////////////////////////////////////
///@brief Function that calls the instatiated BlockHandler object functions update method.
/////////////////////////////////////////////////
    void update();
    
/////////////////////////////////////////////////
///@brief Function that calls the instatiated BlockHandler object functions userMove method.
///@param moveInput, A two char string that symbolise boardside,movedirection. leftboard , left key input = LL.
/////////////////////////////////////////////////
    void move(string moveInput);

/////////////////////////////////////////////////
///@brief Function for key inputs that handles movement and powerup usage.
///@param &leftTime, Variable that refrences leftBoard's clock a sf::clock that is used to control the time intervall between inputs.
///@param &rightTime, Variable that refrences to the adress of a sf::clock that is used to control the time intervall between inputs.
/////////////////////////////////////////////////
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    
/////////////////////////////////////////////////
///@brief Returns private vector variable that contains tile pointers.
/////////////////////////////////////////////////
    vector<Tile*> getTiles();

/////////////////////////////////////////////////
///@brief Inserts tile pointers into the private vector variable tiles.
///@param tile, tile pointer variable.
/////////////////////////////////////////////////
    void appendTile(Tile* tile);

/////////////////////////////////////////////////
///@brief Functions that handles the algorithm for clearing the board of tiles when full, also responsible for incrementing private variable pointCount with 1 for every row cleared.
/////////////////////////////////////////////////
    void clearRow();

/////////////////////////////////////////////////
///@brief returns private integer variable pointscleared.
/////////////////////////////////////////////////
    int getPointCount();

/////////////////////////////////////////////////
///@brief Sets private variable pointsCleared to given inparameter integer value.
///@param value, intgeger variable to set pointsCleared to.
/////////////////////////////////////////////////
    void setPointsCleared(int value);

/////////////////////////////////////////////////
///@brief retuns a pointer to BlockHandler object.
/////////////////////////////////////////////////
    BlockHandler* getBlockHandler() const;

protected:

/////////////////////////////////////////////////
///@brief Private pointer variable for BlockHandler.
/////////////////////////////////////////////////
    BlockHandler* blockHandler;

private:

/////////////////////////////////////////////////
///@brief Private Vector storing tile pointers.
/////////////////////////////////////////////////
    vector<Tile*> tiles;

/////////////////////////////////////////////////
///@brief Private integer value storing the id value.
/////////////////////////////////////////////////
    const int id;

/////////////////////////////////////////////////
///@brief Private integer value used for storing the amount of rows cleared.
/////////////////////////////////////////////////
    int pointsCleared;
};


#endif