//
//  MapObject.h
//  
//
//  Created by MAC on 15/11/2.
//
//

#ifndef ____MapObject__
#define ____MapObject__

#include "cocos2d.h"
USING_NS_CC;

class MapGenerator;
class MapRender;
class MapObject : public Node
{
public:
    CREATE_FUNC(MapObject);
    bool init();
    void generatorMap();
    
private:
    MapGenerator* _mapGenerator;
    MapRender* _mapRender;
};

#endif /* defined(____MapObject__) */
