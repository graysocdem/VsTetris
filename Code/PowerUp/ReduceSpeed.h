#ifndef REDUCESPEED_H
#define REDUCESPEED_H

#include "PowerUp.h"
#include "../Board/Board.h"

/////////////////////////////////////////////////
///@brief Class with it's own apply function meant to decrement a boards tickspeed.
/////////////////////////////////////////////////
class ReduceSpeed : public PowerUp {
public:

/////////////////////////////////////////////////
///@brief Class destructor.
/////////////////////////////////////////////////
    ~ReduceSpeed() = default;

/////////////////////////////////////////////////
///@brief Function that decrements the tickspeed of a given board in the inparameter. Will not decrement a boards tickspeed further than 100 milliseconds.
///@param board, Board pointer variable. Used to specify which boards tickspeed to decrement.
/////////////////////////////////////////////////
    void apply(Board* board) override; 
};

#endif
