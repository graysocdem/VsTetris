#include "GameState.h"

//================================================================================================================================

//GameState constructor
GameState::GameState() : leftBoard{new LeftBoard(this)}, rightBoard{new RightBoard(this)} {
   texture.loadFromFile("../Textures/Background.png");
   background.setTexture(texture);
}

//================================================================================================================================

void GameState::run()
{
    sf::Clock leftUpdateClock;
    sf::Clock rightUpdateClock;

    sf::Clock leftInputTime;
    sf::Clock rightInputTime;

    const size_t width = 1366;
    const size_t height = 769;

    sf::RenderWindow window{sf::VideoMode{width, height}, "Tetris"};
    window.setVerticalSyncEnabled(true);
   
    sf::Event event;
    bool quit{false};
    while (!quit)
    {
        window.clear();
	    window.draw(background);
	    window.draw(*leftBoard);
        window.draw(*rightBoard);
        window.display();

    while (window.pollEvent(event)) {
        switch (event.type)
        {
        case sf::Event::Closed:
            quit = true;
            break;
        default:
            break;
        }
    }
        handleInput(leftInputTime, rightInputTime);
        
        leftBoard->update(leftUpdateClock);
        rightBoard->update(rightUpdateClock);
    }
}

//================================================================================================================================

void GameState::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
  window.draw(background);
}

//================================================================================================================================

void GameState::handleInput(sf::Clock &leftTime, sf::Clock &rightTime) {

    if (leftTime.getElapsedTime().asMilliseconds() >= 25) {
        leftTime.restart();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {leftBoard->move("LL"); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {leftBoard->move("LR"); }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {applyPowerUp(leftBoard); }

    }
    if (rightTime.getElapsedTime().asMilliseconds() >= 25) { 
        rightTime.restart();
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {rightBoard->move("RL"); }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {rightBoard->move("RR"); }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {applyPowerUp(rightBoard), std::cout << "1.1 GameState.HandleInput() : input" << std::endl; }
    }
}

//================================================================================================================================

void GameState::applyPowerUp(Board* applier) {
    
    Board* reciever;

    if (applier == leftBoard) {
        reciever = rightBoard;
    }
    else if (applier == rightBoard){
        reciever = leftBoard;
    }
    
    int PUP = applier->getPowerUpPoints();
    
    if (PUP == 3) {
        std::cout << "1.1 GameState.ApplyPowerUp(IncreaseSpeed): PuP Value:" << PUP << std::endl;
        PowerUp* powerUp = new SuperCharge();
        powerUp->apply(reciever);
        applier->setPowerUpPoints(0);
        delete powerUp;
     
        return;
    } 
    else if (PUP == 2) {
        std::cout << "1.2 GameState.ApplyPowerUp(ReduceSpeed): PuP Value:" << PUP << std::endl;
        PowerUp* powerUp = new ReduceSpeed();
        powerUp->apply(applier);
        applier->setPowerUpPoints(0);
        std::cout << applier->getPowerUpPoints() << std::endl;
        delete powerUp;
        return;
    }
    else if (PUP == 5) {
        std::cout << "1.1 GameState.ApplyPowerUp(PongBlock): PuP Value:" << PUP << std::endl;
        PowerUp* powerUp = new PongBlock(reciever);
        powerUp->apply(reciever);
        applier->setPowerUpPoints(0);
        return;
    }      
    else if (PUP == 1) {
        std::cout << "1.1 GameState.ApplyPowerUp(ColumnSwap): PuP Value:" << PUP << std::endl;
        PowerUp* powerUp = new ColumnSwap();
        powerUp->apply(reciever);
        delete powerUp;
        return;
    }
    else if (PUP == 4) {
        std::cout << "1.1 GameState.ApplyPowerUp(RowSwap): PuP Value:" << PUP << std::endl;
        PowerUp* powerUp = new RowSwap();
        powerUp->apply(reciever);
        applier->setPowerUpPoints(0);
        std::cout << "1.1 PongBlock.ApplyPowerUp(PongBlock): " << std::endl;
        delete powerUp;
        return;
    }
}

// ==============================================================================================================================
