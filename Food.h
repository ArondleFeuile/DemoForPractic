#pragma once
#include"Write.h"
class CFood
{
public:
    CFood();
    //�ı�ʳ������
    void SetFoodNum(int nNum);
    void fnCreatFood(int nMap[MapX][MapY]);
private:
    int nFoodExit;

};
