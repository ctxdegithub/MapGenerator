//
//  MapGenerator.h
//  
//
//  Created by MAC on 15/11/2.
//
//

#ifndef ____MapGenerator__
#define ____MapGenerator__

#include "cocos2d.h"
USING_NS_CC;

class MapGenerator : public Node
{
public:
    CREATE_FUNC(MapGenerator);
    MapGenerator();
    ~MapGenerator();
    bool init();
    void generateMap();
    inline bool isInMapRange(int x, int y) {
        return x >= 0 && x < _width && y >= 0 && y <= _height;
    }
    
private:
    void initMap();
    void destroyMap();
    void randomFillMap();   // 随机填充地图
    void smoothMap();       // 利用细胞自动机原理平滑地图
    int getSurroundingWallCount(int x, int y);  // 获取tile(x, y)周围wall的数量
    
private:
    CC_SYNTHESIZE(int, _width, Width);  // 地图的宽度
    CC_SYNTHESIZE(int, _height, Height);    // 地图的高度
    CC_SYNTHESIZE(int, _smoothCount, SmoothCount);  // 平滑次数
    CC_SYNTHESIZE(int, _randomWallPercent, RandomWallPercent);  // 随机障碍物占得百分比
    CC_SYNTHESIZE_READONLY(char**, _map, Map);  // 存储地图数据
};

#endif /* defined(____MapGenerator__) */
