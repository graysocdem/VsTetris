#ifndef POWERUP_H
#define POWERUP_H

#include "../Board/Board.h"

class Board;

/////////////////////////////////////////////////
///@brief Parent class with solepurpose of containing a true virtual function that children classes have to overwrite. 
/////////////////////////////////////////////////
class PowerUp {
public:

/////////////////////////////////////////////////
///@brief The class's destructor.
/////////////////////////////////////////////////
    virtual ~PowerUp() = default;

/////////////////////////////////////////////////
///@brief True virtual function meant to overwritten.
///@param board The board on who the power-up will be applied.
/////////////////////////////////////////////////
    virtual void apply(Board* board) = 0;

};

#endif