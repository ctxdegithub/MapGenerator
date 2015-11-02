//
//  MapRender.cpp
//  
//
//  Created by MAC on 15/11/2.
//
//

#include "MapRender.h"

MapRender::MapRender() :
_squareSize(10)
{
    
}

bool MapRender::init() {
    if (!Node::init()) {
        return false;
    }
    
    _drawNode = DrawNode::create();
    addChild(_drawNode);
    
    return true;
}

void MapRender::renderMap(char **map, int width, int height) {
    _drawNode->clear();
    int x, y;
    Color4F color;
    float halfSquareSize = _squareSize * 0.5f;
    Vec2 points[4];
    Vec2 startPos = Vec2(-halfSquareSize * width, -halfSquareSize * height);
    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            points[0] = Vec2(startPos.x + (x - 0.5f) * _squareSize, startPos.y + (y - 0.5f) * _squareSize);
            points[1] = points[0] + Vec2(_squareSize, 0);
            points[2] = points[0] + Vec2(_squareSize, _squareSize);
            points[3] = points[0] + Vec2(0, _squareSize);
            color = map[x][y] == 1 ? Color4F::GRAY : Color4F::WHITE;
            _drawNode->drawPolygon(points, 4, color, 0, Color4F::BLACK);
        }
    }
}