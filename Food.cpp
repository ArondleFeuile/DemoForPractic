#include "Food.h"
CFood::CFood():nFoodExit(0)
{

}
//改变食物数量
void CFood::SetFoodNum(int nNum)
{
    nFoodExit = nNum;
}
//生成食物
void CFood::fnCreatFood(int nMap[MapX][MapY])
{
    int FoodX = rand() % (MapX - 2) + 1;
    int FoodY = rand() % (MapY - 2) + 1;
    if (nFoodExit == 0)
    {
        if (nMap[FoodX][FoodY] == 空地)
        {
            nMap[FoodX][FoodY] = 食物;
            fnWriteChar(FoodX, FoodY, "★", 6);
            nFoodExit = 1;
            return;
        }
    }
}