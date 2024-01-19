
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../Common/Common.h"

#include "../Board/Board.h"
#include "../Board/RightBoard.h"
#include "../Board/LeftBoard.h"

#include "../PowerUp/PowerUp.h"

#include "../PowerUp/SuperCharge.h"
#include "../PowerUp/ReduceSpeed.h"
#include "../PowerUp/PongBlock.h"
#include "../PowerUp/ColumnSwap.h"
#include "../PowerUp/RowSwap.h"

/////////////////////////////////////////////////
///@brief A class that is responsible for handling the gameloop and player inputs through the keyboard.
/////////////////////////////////////////////////
class GameState {
public:
    ~GameState() = default; 

/////////////////////////////////////////////////
///@brief Constructor that instantiates the LeftBoard and RightBoard classes. Is also responsible for loading in the texture file and setting the the background to given file.
/////////////////////////////////////////////////
    GameState();

/////////////////////////////////////////////////
///@brief Function that handles the gameloop of the program. 
/////////////////////////////////////////////////
    void run();

private:

/////////////////////////////////////////////////
///@brief Pointer to the instantiated LeftBoard class.
/////////////////////////////////////////////////
    LeftBoard* leftBoard;

/////////////////////////////////////////////////
///@brief Pointer to the instantiated RightBoard class.
/////////////////////////////////////////////////
    RightBoard* rightBoard;


/////////////////////////////////////////////////
///@brief Sfml variable responsible for storing graphics.
/////////////////////////////////////////////////
    Texture texture;

/////////////////////////////////////////////////
///@brief Sfml variable storing drawable representation of a given texture.
/////////////////////////////////////////////////
    Sprite background;

/////////////////////////////////////////////////
///@brief Function that draws drawable objects to the render target.
///@param &window, A reference to the SFML object window
///@param states Required parameter to properly use sf::Drawable
/////////////////////////////////////////////////
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;

/////////////////////////////////////////////////
///@brief Function for key inputs that handles movement and powerup usage.
///@param &leftTime, Variable that refrences leftBoard's clock a sf::clock that is used to control the time intervall between inputs.
///@param &rightTime, Variable that refrences to the adress of a sf::clock that is used to control the time intervall between inputs.
/////////////////////////////////////////////////
    void handleInput(sf::Clock &leftTime, sf::Clock &rightTime);

/////////////////////////////////////////////////
///@brief A function that calls apply() function within the PowerUp class family according to the value of the powerUpPoint integer of a board.  
///@param applier, A pointer to a board class that is meant to signify which board that is associated user of this function.
/////////////////////////////////////////////////
    void applyPowerUp(Board* applier);
};

#endif
