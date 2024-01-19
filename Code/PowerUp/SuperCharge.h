#ifndef SUPERCHARGE_H
#define SUPERCHARGE_H

#include "../Board/Board.h"
#include "../PowerUp/PowerUp.h"

/////////////////////////////////////////////////
///@brief Class with it's own apply function meant to increment a boards tickspeed.
/////////////////////////////////////////////////
class SuperCharge : public PowerUp {
public:
/////////////////////////////////////////////////
///@brief Class destructor.
/////////////////////////////////////////////////
    ~SuperCharge() = default;

/////////////////////////////////////////////////
///@brief Function that increment the tickspeed of a given board in the inparameter. Increments are made with 20 milliseconds.
///@param board, Board pointer variable. Used to specify which boards tickspeed to increment.
/////////////////////////////////////////////////
    void apply(Board* board) override; 

};

#endif
