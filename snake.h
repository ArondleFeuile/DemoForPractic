#pragma once
#include<conio.h>
#include "write.h"
#include"Food.h"
#include"map.h"

class snake
{
public:
    snake();
    int fnGetPlayerInfo1(int Ope);
    int fnWaitChar1();
    //������
    void fnClearSnake(int nmap[MapX][MapY]);
    //�ƶ���
    int fnMoveSnake(int dir, int nmap[MapX][MapY]);
    // ����
    void fnDrawSnake(int nmap[MapX][MapY]);
    void Game();
private:
    COORD g_snake[2][100];
    //�ߵķ���ͳ���
    int g_nDir;
    int g_nlenth;
    int g_nDir1;
    int g_nlenth1;
    //����ж�
    int nlive1;
    int nlive2;
    //����map��food����
    CFood food;
    map map;

};

