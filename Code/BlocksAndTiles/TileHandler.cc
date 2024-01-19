#include "TileHandler.h"
#include "Handled/Tile.h"
#include "BlockHandler.h"
  TileHandler::TileHandler(const int id, const float xOffset, const float yOffset) : id{id}, pointsCleared{0} {
    blockHandler = new BlockHandler(id, xOffset, yOffset, this);
  }

// ========================================================================================================================================================//

  TileHandler::~TileHandler() {
    delete blockHandler;
  }    

// ========================================================================================================================================================//

  void TileHandler::update() {
    blockHandler->update();
  }

// ========================================================================================================================================================//

 void TileHandler::move(string moveInput) {
    blockHandler -> userMove(moveInput);  
 }

// ========================================================================================================================================================//

  void TileHandler::draw(sf::RenderTarget &window, sf::RenderStates states) const {
      window.draw(*blockHandler);

      for (Tile* tile : tiles) {
        window.draw(*tile);
      }
  }

// ========================================================================================================================================================//

  vector<Tile*> TileHandler::getTiles() {
    return tiles;
  }

// ========================================================================================================================================================//

  void TileHandler::appendTile(Tile* tile) {
    tiles.push_back(tile);
  }

// ========================================================================================================================================================//

void TileHandler::clearRow() {
  
    std::map<int, vector<Tile*>> rowTileCount;

    if (tiles.size() == 0) { return; }

    for (Tile* tile : tiles) {
      int gridCoordY =  (tile->position.y - 153) / 30; //Convert between SFML pixel coordinate system and board grid 
      bool added{false};
      for (auto pair : rowTileCount) {
        if (gridCoordY == pair.first) {
          rowTileCount.at(gridCoordY).push_back(tile);
          added = true;
        }
      }
      if (added == false) {
        rowTileCount.insert({gridCoordY, vector<Tile*>{tile}});
      } 
     }

      for (int i = 19; i != (19 - (rowTileCount.size())); i--) {       
      vector<Tile*> &currentList = rowTileCount.at(i);

      if (currentList.size() == 10) {
        pointsCleared += 1;
        for (Tile* currentListTile : currentList) {
          for (Tile* &tileHandlerTile : tiles)
          {
            if (currentListTile == tileHandlerTile)
            {
              delete tileHandlerTile;
              tileHandlerTile = nullptr;              
            }
          }
        }

        auto it{std::remove_if(tiles.begin(), tiles.end(), [](Tile* ptr){ return (ptr == nullptr); })};
        tiles.erase(it, tiles.end());

        for (int j = i - 1; j != 19 - (rowTileCount.size()); j--) {
          for (Tile* tile : rowTileCount.at(j)) {
            tile->move("DD");
          }
          rowTileCount.at(j+1) = rowTileCount.at(j);
          rowTileCount.at(j) = {};
        }
      }
  }
  return;  


}
// ========================================================================================================================================================//


int TileHandler::getPointCount() {
  return pointsCleared;
}

// ========================================================================================================================================================//

void TileHandler::setPointsCleared(int value) {
  pointsCleared = value;
}

// ========================================================================================================================================================//

BlockHandler* TileHandler::getBlockHandler() const {
  return blockHandler; 
}

