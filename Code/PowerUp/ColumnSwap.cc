#include <iostream>
#include <random>

#include "ColumnSwap.h"

#include "../BlocksAndTiles/TileHandler.h"
#include "../Board/Board.h"
#include "../BlocksAndTiles/Handled/Tile.h"

// ========================================================================================================================================================//

void ColumnSwap::apply(Board* board) {
    TileHandler* tileHandler = board->getTileHandler();

    std::vector<int> columnVector = getColumnVector(tileHandler);

    pair<int, int> columnsGrid = setRandom(columnVector); 

    swap(tileHandler, columnsGrid);
}

// ========================================================================================================================================================//

std::vector<int> ColumnSwap::getColumnVector(TileHandler* tileHandler) const  {
    vector<int> columnVector{};

    for (Tile* tile : tileHandler->getTiles()) {
        int currentX = tile->position.x;
        auto result = std::find(columnVector.begin(), columnVector.end(), currentX);
        if (result == columnVector.end()) { 
            columnVector.push_back(currentX);
        }
    }
    return columnVector;
}

// ========================================================================================================================================================//

pair<int, int> ColumnSwap::setRandom(std::vector<int> columnVector) const {

    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distr(0, columnVector.size()-1); 

    int r1{distr(gen)};
    int r2{distr(gen)};

    while (r1 == r2) {
        r2 = distr(gen);
    }
    return {columnVector[r1], columnVector[r2]};
}

// ========================================================================================================================================================//

void ColumnSwap::swap(TileHandler* tileHandler, pair<int, int> columns) {

    for (Tile* tile : tileHandler->getTiles()) {
            if (tile->position.x == columns.first) {
            tile->setX(columns.second);
        }
        else if (tile->position.x == columns.second) {
           tile->setX(columns.first);
        }
    } 
}

// ========================================================================================================================================================//

