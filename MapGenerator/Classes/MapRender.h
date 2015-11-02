//
//  MapRender.h
//  
//
//  Created by MAC on 15/11/2.
//
//

#ifndef ____MapRender__
#define ____MapRender__

#include "cocos2d.h"
USING_NS_CC;

class MapRender : public Node
{
public:
    MapRender();
    CREATE_FUNC(MapRender);
    bool init();
    void renderMap(char **map, int width, int height);
    
private:
    DrawNode* _drawNode;
    CC_SYNTHESIZE(float, _squareSize, SquareSize);
};

#endif /* defined(____MapRender__) */
