#ifndef BOARD_H
#define BOARD_H
#include "../Common/Common.h"
#include "../BlocksAndTiles/TileHandler.h"

class PowerUp;
class GameState;

/////////////////////////////////////////////////
///@brief Parent class responsible for handling player data, position and drawing itself.
/////////////////////////////////////////////////
class Board : public sf::Drawable
{
public:
    virtual ~Board();
/////////////////////////////////////////////////
///@brief Constructor that instatiates it's own TileHandler class and defines it's id, powerUpPoints, x position, y position aswell as x,y coordinate offsets.
///@param id, A integer used for storing player number.
///@param x, A float that signifies the boards it's x coordinate.
///@param y, A float that signifies the boards it's y coordinate. 
///@param gameState, A pointer variable to the GameState class.
///@param xOffset, A variable that stores the x offset pixel coordinate for the board.
///@param yOffset, A variable that stores the x offset pixel coordinate for the board.
/////////////////////////////////////////////////
    Board(int id, float x, float y, GameState* gameState, int xOffset, int yOffset);

/////////////////////////////////////////////////
///@brief Destructor for virtual class Board
/////////////////////////////////////////////////

/////////////////////////////////////////////////
///@brief Function that calls instatiated TileHandler update function. 
///@param &clock, variable that is used to determine the the time intervall inbetween ticks, stored as the adress of a sf::clocks,
/////////////////////////////////////////////////
    void update(sf::Clock &clock);

/////////////////////////////////////////////////
///@brief Function that calls TileHandlers move function.
///@param moveInput, A two char string that symbolise boardside,movedirection. leftboard , left key input = LL.
/////////////////////////////////////////////////
    void move(string moveInput);

/////////////////////////////////////////////////
///@brief Function that returns the boards private variable powerUpPoints.
/////////////////////////////////////////////////
    int getPowerUpPoints();

/////////////////////////////////////////////////
///@brief Function that sets private variable powerUpPoints to given value in parameter
///@param powerUpPointsNewValue Integer value that powerUpPoints is set to. 
/////////////////////////////////////////////////
    void setPowerUpPoints(int powerUpPointsNewValue);   

/////////////////////////////////////////////////
///@brief Function that returns the value of private variable timeBetweenTicks.
/////////////////////////////////////////////////
    sf::Time& getTimeBetweenTicksReference();
 
 /////////////////////////////////////////////////
///@brief Function that calls TileHandlers getBlockHandlerFunction() to return a pointer of BlockHandler.
/////////////////////////////////////////////////
    BlockHandler* getBlockHandler() const;

/////////////////////////////////////////////////
///@brief Function that returns a pointer to instatiated TileHandler.
/////////////////////////////////////////////////
    TileHandler* getTileHandler() const;
    
/////////////////////////////////////////////////
///@brief returns value of protected variable xOffset.
/////////////////////////////////////////////////
    int getXOffset() const;

/////////////////////////////////////////////////
///@brief returns value of private variable yOffset.
/////////////////////////////////////////////////
    int getYOffset() const;

/////////////////////////////////////////////////
///@brief Returns value of protected variable id.
/////////////////////////////////////////////////
    int getID() const;

protected:

/////////////////////////////////////////////////
///@brief Variable that stores the xOffset as a integer.
/////////////////////////////////////////////////
    const int xOffset;

/////////////////////////////////////////////////
////@brief Variable that stores the yOffset as a integer.
/////////////////////////////////////////////////
    const int yOffset;

/////////////////////////////////////////////////
////@brief Variable that stores the powerUpPoints as a integer.
/////////////////////////////////////////////////
    int powerUpPoints;

/////////////////////////////////////////////////
///@brief Variable that stores the powerUpPoints as  
/////////////////////////////////////////////////
    const int id;

/////////////////////////////////////////////////
///@brief Pointer variable to the instatiated GameState object.
/////////////////////////////////////////////////
    GameState* gameState;

/////////////////////////////////////////////////
///@brief Pointer variable to the instatiated GameHandler object.
/////////////////////////////////////////////////
    TileHandler* tileHandler; 

/////////////////////////////////////////////////
///@brief Represent's the board's tickspeed. 
/////////////////////////////////////////////////
    sf::Time timeBetweenTicks;

/////////////////////////////////////////////////
///@brief Variable that stores two floats in a sfml vector. 
/////////////////////////////////////////////////
    const sf::Vector2f position; // X-position and Y-position
    /*const sf::Vector2i size;*/

/////////////////////////////////////////////////
///@brief Sfml variable responsible for storing graphics.
/////////////////////////////////////////////////
    Sprite sprite; 

/////////////////////////////////////////////////
/// @brief Variable storing a sfml drawable representation of a given texture.
/////////////////////////////////////////////////
    Texture texture;
    
/////////////////////////////////////////////////
///@brief Virtual function that draws drawable objects to the render target.
///@param &window, A reference to the SFML object window
///@param states Required parameter to properly use sf::Drawable
/////////////////////////////////////////////////
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};
#endif
