#include "BlockHandler.h"
#include <random>
#include <iostream>

#include "TileHandler.h"
#include "Handled/Block.h"
#include "Handled/Tile.h"
#include "BlockHandler.h"
#include "../PowerUp/PongBlock.h"

// ========================================================================================================================================================//
 
BlockHandler::BlockHandler(const int id, const int xOff, const int yOff, TileHandler* tileHandlerIn) : id{id}, xOffset{xOff}, tileHandler{tileHandlerIn}, yOffset{yOff}, tileSide{30}, pongBlock{nullptr} {
    loadBlocks();
    generateBlock();
}

// ========================================================================================================================================================//

BlockHandler::~BlockHandler() {
    for (Tile* tile : currentBlock->tiles) {
        delete tile;
    }
    delete currentBlock;
    delete pongBlock;
}

// ========================================================================================================================================================//


void BlockHandler::generateBlock() {

    vector<string> filePaths{
        "../Textures/Blue.png",
        "../Textures/Red.png",
        "../Textures/Green.png",
        "../Textures/MarineBlue.png",
        "../Textures/Purple.png",
        "../Textures/Yellow.png",
        "../Textures/Orange.png",
        "../Textures/Pink.png"
    };

    vector<Texture> textures{};

    for (string filePath : filePaths) {
        Texture texture;
        texture.loadFromFile(filePath);
        textures.push_back(texture);
    };

    std::random_device rd; // Take a random number from hardware.
    std::mt19937 gen(rd()); // The randomiser seed.
    std::uniform_int_distribution<> distr(0, blockMap.size()-1); // define the range.
    
    int num = distr(gen);
       
    vector<Tile*> tiles;

    for (pair<int,int> coordinate : blockMap.at(num)) {
        Tile* newTile = new Tile(textures[num], xOffset + ((coordinate.first + 4) * tileSide), yOffset + (coordinate.second * tileSide));
        tiles.push_back(newTile); 
    }                                                                                                                                        
    currentBlock = new Block(tiles, tileHandler);

    if (currentBlock->hasOverlap()) {
        hasLost(id);
    }
};

// ========================================================================================================================================================//

void BlockHandler::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    for (Tile* tile : currentBlock->tiles) {
        window.draw(*tile);
    }
     
    if (pongBlock) {
        for (Tile* tile : pongBlock->tiles) {
            window.draw(*tile);
        }
    }
}

// ========================================================================================================================================================//

void BlockHandler::update() {

    if(pongBlock) {
            for (Tile* tile : pongBlock->tiles) {
                std::cout << tile -> position.x << " " << tile->position.y << std::endl;
            }
        if (currentBlock->willLand()) {
            if (pongBlock->willLand())
            {
                transferBlocks(currentBlock);
                transferBlocks(pongBlock);
                deleteBlock(currentBlock);
                deleteBlock(pongBlock);
                pongBlock = nullptr;
                generateBlock();
                tileHandler->clearRow(); 
            } 
            else {
                pongBlock->move("DD");
                transferBlocks(currentBlock);
                deleteBlock(currentBlock);
                generateBlock();
                tileHandler->clearRow(); 
            }
        

        }
        else if (pongBlock->willLand()) {
            transferBlocks(pongBlock);
            pongBlock = nullptr;
            if (currentBlock->willLand()) {
                transferBlocks(currentBlock);
                deleteBlock(currentBlock);
                generateBlock();
                deleteBlock(pongBlock);
                 tileHandler->clearRow();
            }
            else {
                currentBlock->move("RD");
            }
        }
        else {
            currentBlock->move("DD");
            pongBlock->move("LD");
        }
    }
    //if there's no pongblock
    else {
        if (currentBlock->willLand()) {
            transferBlocks(currentBlock);
            deleteBlock(currentBlock);
            generateBlock();
            tileHandler->clearRow();
        }
        else {
            currentBlock->move("DD");
        }
    }
}

// ========================================================================================================================================================//

void BlockHandler::userMove(string const& direction) {
    currentBlock->move(direction);
}

// ========================================================================================================================================================//

void BlockHandler::hasLost(const int id) const{
    switch (id) {
        case (1):
        std::cout << "Player " << id << " has lost! Skill issue?" << std::endl;
        break;
        case (2):
        std::cout << "Player " << id << " has lost! Get Moled!" << std::endl;
        break;
    }

    sf::sleep(sf::milliseconds(1000));
    exit( 1 );
}
// ========================================================================================================================================================//

void BlockHandler::loadBlocks() {

    map<int, vector<pair<int, int>>> loadedBlockMap {};
    int count{0};
    // read text from textfile
    std::fstream blocksFile;
    blocksFile.open("../blocks.txt"); 
    string line{""};    
    
    
    // convert text to coordinates
    int y = 0;
    vector<pair<int, int>> rowVector{}; 
    while ( getline ( blocksFile, line )) {   

        //If line is not empty:
        if (line == "#") {
            loadedBlockMap.insert({count, rowVector});
            break;
        }
        
        else if (line.size() != 0) {
            int x = 0;
            for (char character : line) {
                if (character == '*') {
                    rowVector.push_back({x,y});
                }
                x += 1; // x increases nontheless if the text file contains space.
            } 

        y += 1;    
        }

        else {

            for (pair<int, int> par : rowVector) {
            }
            loadedBlockMap.insert({count, rowVector});
            rowVector = {};
            count += 1;
            y = 0;
        }

    }

    blocksFile.close(); 

    //std::cout << loadedBlockMap.size() << std::endl;
    blockMap = loadedBlockMap;
}

// ========================================================================================================================================================//


void BlockHandler::deleteBlock(Block* block) {

    PongBlock* ptr = dynamic_cast<PongBlock*>(block);

    if (ptr) {
        delete ptr;
    }
    else {
        delete block;
    }
} 

// ========================================================================================================================================================//


void BlockHandler::transferBlocks(Block* block) {
    for (Tile* tile : block->tiles) {
        tileHandler->appendTile(tile);
        tile = nullptr;
    }
}

// ========================================================================================================================================================//
            
 vector<Tile*> BlockHandler::getCurrentBlockTiles() {
    return currentBlock->tiles;
}

// ========================================================================================================================

void BlockHandler::setPongBlock(PongBlock* pongBlockIn) {
    pongBlock = pongBlockIn;
} 

