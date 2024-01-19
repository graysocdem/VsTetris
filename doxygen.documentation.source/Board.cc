#include "Board.h"

// ========================================================================================================================

Board::Board(int id, float x, float y, GameState* gameState,  int xOffset, int yOffset) : id{id}, position{x, y}, /*size{350, 700}*/ powerUpPoints{0}, xOffset{xOffset}, yOffset{yOffset}, tileHandler{new TileHandler(id, position.x, position.y)} {
    timeBetweenTicks = sf::milliseconds(125);
    texture.loadFromFile("../Textures/Board.png");
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

//==========================================================================================================================

Board::~Board() {
    delete tileHandler;
}

// ========================================================================================================================

int Board::getXOffset() const {
    return xOffset;
}

int Board::getYOffset() const {
    return yOffset;    
}
// ========================================================================================================================

void Board::draw(sf::RenderTarget &window, sf::RenderStates states) const
{ 
    window.draw(sprite);
    window.draw(*tileHandler);
}

// ========================================================================================================================

//Function that calls TileHandlers update function according to the boards Tickspeed

void Board::update(sf::Clock &clock) {
    
    if (clock.getElapsedTime() >= timeBetweenTicks) { 
        tileHandler->update();
        if (powerUpPoints < 4) {
        powerUpPoints += tileHandler->getPointCount();  
        }
        else if(powerUpPoints == 5) {
        std::cout << "Board.setPowerUpPoints: PowerUPPoints is maxed out." << std::endl;
        };
        tileHandler->setPointsCleared(0);
        clock.restart();
    }
}

// ========================================================================================================================

//Calls TileHandlers move input.

void Board::move(string moveInput) {
    tileHandler->move(moveInput); 
}

// ========================================================================================================================

//Gets the value of the private variable: PowerUpPoints.

    int Board::getPowerUpPoints(){
        return powerUpPoints; 
    }

// ========================================================================================================================
    
//

    void Board::setPowerUpPoints(int powerUpPointsNewValue ) {
        powerUpPoints = powerUpPointsNewValue;
    }
    
// ========================================================================================================================
   
//

        sf::Time& Board::getTimeBetweenTicksReference() {
        //sf::Time& timeBetweenTicksReference = timeBetweenTicks;
        return timeBetweenTicks;
    } 

// ========================================================================================================================
    
//
    
    BlockHandler* Board::getBlockHandler() const {
        return tileHandler->getBlockHandler();
    }
// ========================================================================================================================

    TileHandler* Board::getTileHandler() const {
        return tileHandler;
    }

// ========================================================================================================================

    int Board::getID() const {
        return id;
    }
