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
    //覆盖蛇
    void fnClearSnake(int nmap[MapX][MapY]);
    //移动蛇
    int fnMoveSnake(int dir, int nmap[MapX][MapY]);
    // 画蛇
    void fnDrawSnake(int nmap[MapX][MapY]);
    void Game();
private:
    COORD g_snake[2][100];
    //蛇的方向和长度
    int g_nDir;
    int g_nlenth;
    int g_nDir1;
    int g_nlenth1;
    //存活判断
    int nlive1;
    int nlive2;
    //包了map和food对象
    CFood food;
    map map;

};

