#include "Food.h"
CFood::CFood():nFoodExit(0)
{

}
//�ı�ʳ������
void CFood::SetFoodNum(int nNum)
{
    nFoodExit = nNum;
}
//����ʳ��
void CFood::fnCreatFood(int nMap[MapX][MapY])
{
    int FoodX = rand() % (MapX - 2) + 1;
    int FoodY = rand() % (MapY - 2) + 1;
    if (nFoodExit == 0)
    {
        if (nMap[FoodX][FoodY] == �յ�)
        {
            nMap[FoodX][FoodY] = ʳ��;
            fnWriteChar(FoodX, FoodY, "��", 6);
            nFoodExit = 1;
            return;
        }
    }
}