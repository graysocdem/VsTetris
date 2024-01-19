#include <iostream>
#include <random>

#include "RowSwap.h"
#include "TileMover.h"

#include "../BlocksAndTiles/TileHandler.h"
#include "../BlocksAndTiles/Handled/Tile.h"

// ========================================================================================================================================================//

void RowSwap::apply(Board* board) {

    TileHandler* tileHandler = board->getTileHandler();
    int lowest = getLowerBound(tileHandler);
    pair<int, int> rows = setRandom(lowest);
    swap(tileHandler, rows);
}

// ========================================================================================================================================================//

//Gets two non-empty tiles
std::pair<int, int> RowSwap::setRandom(int lowerBound) const {

    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distr(lowerBound, 19); 

    int r1 = distr(gen);
    int r2 = distr(gen);
    while (r1 == r2) {
        int newNum = distr(gen);
        r2 = newNum;
    }
    
    return {r1, r2};

}

// ========================================================================================================================================================//

//Fetches the lowerBound row
int RowSwap::getLowerBound(TileHandler* tileHandler) const {
    int lowestPixel{723};
    for (Tile* tile : tileHandler->getTiles()) {
        if (tile->position.y < lowestPixel) {
            lowestPixel = tile->position.y;
        }
    }
    int lowestGrid = (lowestPixel - 153) / 30; //conversion between SFML pixels and board grid

    return lowestGrid;
    
}

// ========================================================================================================================================================//

void RowSwap::swap(TileHandler* tileHandler, pair<int, int> rowsGrid) {
    pair<int, int> rowsPixel = {rowsGrid.first * 30 + 153, rowsGrid.second * 30 + 153};  //conversion from Board grid to SFML pixel

    for (Tile* tile : tileHandler->getTiles()) {
            if (tile->position.y == rowsPixel.first) {
            tile->setY(rowsPixel.second);
        }
        else if (tile->position.y == rowsPixel.second) {
            tile->setY(rowsPixel.first);
        }
    } 

}

// ========================================================================================================================================================//