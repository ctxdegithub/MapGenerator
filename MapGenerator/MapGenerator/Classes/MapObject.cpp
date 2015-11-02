//
//  MapObject.cpp
//  
//
//  Created by MAC on 15/11/2.
//
//

#include "MapObject.h"
#include "MapGenerator.h"
#include "MapRender.h"

bool MapObject::init() {
    if (!Node::init()) {
        return false;
    }
    
    _mapGenerator = MapGenerator::create();
    addChild(_mapGenerator);
    
    _mapRender = MapRender::create();
    addChild(_mapRender);
    
    return true;
}

void MapObject::generatorMap() {
    _mapGenerator->generateMap();
    _mapRender->renderMap(_mapGenerator->getMap(), _mapGenerator->getWidth(), _mapGenerator->getHeight());
}