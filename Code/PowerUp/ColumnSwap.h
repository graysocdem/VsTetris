#ifndef COLUMNSWAP_H
#define COLUMNSWAP_H

#include <vector>
#include "./TileMover.h"

/////////////////////////////////////////////////
///@brief Child class to powerup inheriting 
/////////////////////////////////////////////////
class ColumnSwap : public TileMover {
public:
    ~ColumnSwap() = default;
    
/////////////////////////////////////////////////
///@brief Applies the powerup on a board.
///@param board A pointer to the board on which the powerup is to be applied.
/////////////////////////////////////////////////
    void apply(Board* board) override; 

private:

/////////////////////////////////////////////////
///@brief Gets a vector with integers representing all columns with tiles on them.
///@param tileHandler A pointer to the tileHandler associated to the recieving board.
/////////////////////////////////////////////////
    std::vector<int> getColumnVector(TileHandler* tileHandler) const;

/////////////////////////////////////////////////
///@brief Gets two random columns from the column vector.
///@param columnVector A vector with integers representing all columns with tiles on them.
/////////////////////////////////////////////////
    pair<int, int> setRandom(std::vector<int> columnVector) const;

/////////////////////////////////////////////////
///@brief Swaps two columns.
///@param tileHandler A pointer to the tileHandler associated to the recieving board.
///@param columnsGrid The two columns that are to be swapped, in grid coordinates.
/////////////////////////////////////////////////
    void swap(TileHandler* tileHandler, pair<int, int> columnsGrid);
};

#endif
