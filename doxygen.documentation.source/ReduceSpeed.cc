#include "ReduceSpeed.h"

//==========================================================================================================================

void ReduceSpeed::apply(Board* board) {

    //The Time to to decrease the current tickvalue
    sf::Time timeToDecreaseCurrentTimeBetweenTicks = sf:: milliseconds(100);
    //Get the boards tick time 
    sf::Time& currentTimeBetweenTicks = board->getTimeBetweenTicksReference();
    //set a newTickTime
    if (currentTimeBetweenTicks > sf::milliseconds(100)) {
    currentTimeBetweenTicks = (currentTimeBetweenTicks + timeToDecreaseCurrentTimeBetweenTicks);
    }
}

//==========================================================================================================================