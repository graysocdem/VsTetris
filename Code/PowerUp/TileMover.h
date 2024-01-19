#ifndef TILEMOVER_H
#define TILEMOVER_H

#include "../Common/Common.h"
#include "PowerUp.h"

/////////////////////////////////////////////////
///@brief Parent class responsible for randomising numbers
/////////////////////////////////////////////////
class TileMover : public PowerUp {
public:
    virtual ~TileMover() = default;

protected: 

/////////////////////////////////////////////////
///@brief Swaps two of something, either rows or columns.
/////////////////////////////////////////////////
    virtual void swap(TileHandler* tileHandler, pair<int, int>) = 0;

/////////////////////////////////////////////////
///@brief Pointer to TileHandler.
/////////////////////////////////////////////////
    TileHandler* tileHandler;

/////////////////////////////////////////////////
///@brief Virtual function to convert sfml pixel coordinates to the programs specified coordinates
///@param pixel the pixel coordinate which is to be converted to board grid
/////////////////////////////////////////////////
    virtual int toGrid(int pixel) const;

/////////////////////////////////////////////////
///@brief Virtual function to convert the programs specified coordinates to sfml pixel coordinates.
///@param grid the board grid coordinate which is to be converted to pixel
/////////////////////////////////////////////////
    virtual int toPixel(int grid) const;

};

#endif
