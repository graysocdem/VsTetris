#include "SuperCharge.h"
//==========================================================================================================================

void SuperCharge::apply(Board* board) {
    //The Time to to decrease the current tickvalue
    sf::Time timeToDecreaseCurrentTimeBetweenTicks = sf:: milliseconds(20);
    //Get the boards tick time 
    sf::Time& currentTimeBetweenTicks = board->getTimeBetweenTicksReference();
    //set a newTickTime
    currentTimeBetweenTicks = (currentTimeBetweenTicks - timeToDecreaseCurrentTimeBetweenTicks);
}

//==========================================================================================================================