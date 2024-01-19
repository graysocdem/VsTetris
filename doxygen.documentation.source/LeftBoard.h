#ifndef LEFTBOARD_H
#define LEFTBOARD_H

#include "../Common/Common.h"
#include "Board.h"

class LeftBoard : public Board {
public:
    ~LeftBoard() = default;
    LeftBoard(GameState* gameState);
};

#endif 