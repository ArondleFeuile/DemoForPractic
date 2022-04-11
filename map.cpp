#include "map.h"
void map::fnInitGame()
{
    for (int i = 0; i < MapX; i++)
    {
        for (int j = 0; j < MapY; j++)
        {
            if (i == 0 || j == 0 || i == MapX - 1 || j == MapY - 1)
            {
                g_Map[i][j] = 障碍物;
            }
            else
            {
                g_Map[i][j] = 空地;
            }
        }
    }
}

//画地图
void map::fnDrawMap()
{
    for (int i = 0; i < MapX; i++)
    {
        for (int j = 0; j < MapY; j++)
        {
            if (g_Map[i][j] == 障碍物)
            {
                fnWriteChar(i, j, "※", 7);
            }
            else if (g_Map[i][j] == 自己)
            {
                fnWriteChar(i, j, "■");
            }
            /*else if (g_Map[i][j] == 食物)
            {
                fnWriteChar(i, j, "★",6);
            }*/
        }
    }
}