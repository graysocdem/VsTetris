#ifndef ROWSWAP_H
#define ROWSWAP_H

#include "TileMover.h"

/////////////////////////////////////////////////
///@brief Child class to Tilemover responsible for swapping tile rows.
/////////////////////////////////////////////////
class RowSwap : public TileMover {
public:    
    ~RowSwap() = default;
/////////////////////////////////////////////////
///@brief Applies the RowSwap powerup on a board.
///@param board The board whose rows will be swapped.
/////////////////////////////////////////////////
    void apply(Board* board);

private:

/////////////////////////////////////////////////
///@brief Gets the lowest (visually highest) row with tiles on it.
///@param tileHandler The tilehandler associated to the board whose rows are to be swapped.
/////////////////////////////////////////////////
    int getLowerBound(TileHandler* tileHandler) const;

/////////////////////////////////////////////////
///@brief Gets two random rows.
///@param lowest The lowest (visually highest) row with tiles on it.
/////////////////////////////////////////////////
    std::pair<int, int> setRandom(int lowest) const;

/////////////////////////////////////////////////
///@brief Swaps all tiles between two rows.
///@param tileHandler The tilehandler associated to the bord whose rows are to be switched.
///@param rowGrid The rows that are to be switched in grid coordinates. 
/////////////////////////////////////////////////
    void swap(TileHandler* tileHandler, pair<int, int> rowGrid) override;
};

#endif
