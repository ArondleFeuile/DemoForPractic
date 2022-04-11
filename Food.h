#pragma once
#include"Write.h"
class CFood
{
public:
    CFood();
    //改变食物数量
    void SetFoodNum(int nNum);
    void fnCreatFood(int nMap[MapX][MapY]);
private:
    int nFoodExit;

};
