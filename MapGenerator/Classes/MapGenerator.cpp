//
//  MapGenerator.cpp
//  
//
//  Created by MAC on 15/11/2.
//
//

#include "MapGenerator.h"

MapGenerator::MapGenerator() :
_width(50),
_height(50),
_smoothCount(5),
_randomWallPercent(50),
_map(nullptr)
{
    
}

MapGenerator::~MapGenerator() {
    destroyMap();
}

bool MapGenerator::init() {
    if (!Node::init()) {
        return false;
    }
    
    return true;
}

void MapGenerator::initMap() {
    _map = new char*[_width];
    for (int i = 0; i < _width; ++i) {
        _map[i] = new char[_height];
    }
}

void MapGenerator::destroyMap() {
    CC_SAFE_DELETE_ARRAY(_map);
}

void MapGenerator::generateMap() {
    destroyMap();
    initMap();
    
    randomFillMap();
    for (int i = 0; i < _smoothCount; ++i) {
        smoothMap();
    }
}

void MapGenerator::randomFillMap() {
    int x, y;
    for (y = 0; y < _height; ++y) {
        for (x = 0; x < _width; ++x) {
            if (random(0, 100) < _randomWallPercent) {
                _map[x][y] = 1;
            } else {
                _map[x][y] = 0;
            }
        }
    }
}

void MapGenerator::smoothMap() {
    int x, y;
    int wallCount;
    for (y = 0; y < _height; ++y) {
        for (x = 0; x < _width; ++x) {
            wallCount = getSurroundingWallCount(x, y);
            if (wallCount < 4) {
                _map[x][y] = 0;
            } else if (wallCount > 4) {
                _map[x][y] = 1;
            }
        }
    }
}

int MapGenerator::getSurroundingWallCount(int x, int y) {
    int nx, ny;
    int wallCount = 0;
    for (ny = y - 1; ny <= y + 1; ++ny) {
        for (nx = x - 1; nx <= x + 1; ++nx) {
            if (isInMapRange(nx, ny)) {
                if (nx != x || ny != y)
                    wallCount += _map[nx][ny];
            } else {
                ++wallCount;    // 超过边界就是wall
            }
        }
    }
    return wallCount;
}