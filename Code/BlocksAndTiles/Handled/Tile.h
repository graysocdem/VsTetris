#ifndef TILE_H
#define TILE_H

#include "../../Common/Common.h"

/////////////////////////////////////////////////
///@brief Class responsible for information in idividuall tiles.
/////////////////////////////////////////////////
class Tile : public sf::Drawable {
public:

/////////////////////////////////////////////////
///@brief Contstructor that defining texture, x and y coordinate and instatiates y and x position..
///@param 
/////////////////////////////////////////////////
  Tile(Texture texture, float x, float y);
  
/////////////////////////////////////////////////
///@brief Function for key inputs that handles movement and powerup usage.
///@param &leftTime, Variable that refrences leftBoard's clock a sf::clock that is used to control the time intervall between inputs.
///@param &rightTime, Variable that refrences to the adress of a sf::clock that is used to control the time intervall between inputs.
/////////////////////////////////////////////////
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;

/////////////////////////////////////////////////
///@brief Function that calls the addx() and addy() functions according to given direction string
///@param direction, A two char string that symbolise boardside,movedirection. leftboard , left key input = LL.
/////////////////////////////////////////////////
  void move(std::string const& direction);

/////////////////////////////////////////////////
///@brief Function that adds or subtracts the inparameter value to the position of the tile object aswell as update the sprite position with the sfml setPosition() function.
///@param x, A integer variable to define the diffrence in x value.
/////////////////////////////////////////////////
  void addX(int x);

/////////////////////////////////////////////////
///@brief Function that adds or subtracts the inparameter value to the position of the tile object aswell as update the sprite position with the sfml setPosition() function.
///@param x, A integer variable to define the diffrence in y value.
/////////////////////////////////////////////////
  void addY(int y);

/////////////////////////////////////////////////
///@brief Function to to set the tile objects x position to given inparameter value.
///@param x, Integer variable to change the x position to.
/////////////////////////////////////////////////
  void setX(int x);

/////////////////////////////////////////////////
///@brief Function to to set the tile objects y position to given inparameter value.
///@param x, Integer variable to change the y position to.
/////////////////////////////////////////////////
  void setY(int y);
  
/////////////////////////////////////////////////
///@brief Sfml float vector used to contain the x and y positon of the tile object.
/////////////////////////////////////////////////
  sf::Vector2f position; // X-position and Y-position

private:

/////////////////////////////////////////////////
/// @brief Variable storing a sfml drawable representation of a given texture.
/////////////////////////////////////////////////
  Texture texture;

/////////////////////////////////////////////////
///@brief Sfml variable responsible for storing graphics.
/////////////////////////////////////////////////
  Sprite sprite;

};

#endif