#include "map.h"
void map::fnInitGame()
{
    for (int i = 0; i < MapX; i++)
    {
        for (int j = 0; j < MapY; j++)
        {
            if (i == 0 || j == 0 || i == MapX - 1 || j == MapY - 1)
            {
                g_Map[i][j] = �ϰ���;
            }
            else
            {
                g_Map[i][j] = �յ�;
            }
        }
    }
}

//����ͼ
void map::fnDrawMap()
{
    for (int i = 0; i < MapX; i++)
    {
        for (int j = 0; j < MapY; j++)
        {
            if (g_Map[i][j] == �ϰ���)
            {
                fnWriteChar(i, j, "��", 7);
            }
            else if (g_Map[i][j] == �Լ�)
            {
                fnWriteChar(i, j, "��");
            }
            /*else if (g_Map[i][j] == ʳ��)
            {
                fnWriteChar(i, j, "��",6);
            }*/
        }
    }
}