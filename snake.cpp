#include "snake.h"
snake::snake()
{
    g_snake[0][0].X = 10;
    g_snake[0][0].Y = 10;
    g_snake[0][1].X = 10;
    g_snake[0][1].Y = 9;
    g_snake[0][2].X = 10;
    g_snake[0][2].Y = 8;
    g_snake[0][3].X = 10;
    g_snake[0][3].Y = 7;
    g_nDir = 2;
    g_nlenth = 4;
    nlive1=1;
   
    g_snake[1][0].X = 15;
    g_snake[1][0].Y = 10;
    g_snake[1][1].X = 15;
    g_snake[1][1].Y = 9;
    g_snake[1][2].X = 15;
    g_snake[1][2].Y = 8;
    g_snake[1][3].X = 15;
    g_snake[1][3].Y = 7; 
    g_nDir1 = 2;
    g_nlenth1 = 4;
    nlive2=1;
}
//获得用户输入 
int snake::fnWaitChar1()
{
    if (_kbhit())
    {
        char temp = _getch();
        if ((g_nDir == 上 || g_nDir == 下) && (temp == 'w' || temp == 's'))
        {
            return 0;
        }
        if ((g_nDir == 左 || g_nDir == 右) && (temp == 'a' || temp == 'd'))
        {
            return 0;
        }


        if ((g_nDir1 == 上 || g_nDir1 == 下) && (temp == 'i' || temp == 'k'))
        {
            return 0;
        }
        if ((g_nDir1 == 左 || g_nDir1 == 右) && (temp == 'j' || temp == 'l'))
        {
            return 0;
        }
        else return temp;

        
    }
}
int snake::fnGetPlayerInfo1(int Ope)
{
    switch (Ope)
    {
    case 'w':
        return g_nDir = 上;
        break;
    case 's':
        return g_nDir = 下;
        break;
    case 'a':
        return g_nDir = 左;
        break;
    case 'd':
        return g_nDir = 右;
        break;
    case 'i':
        return g_nDir1 = 上;
        break;
    case 'k':
        return g_nDir1 = 下;
        break;
    case 'j':
        return g_nDir1 = 左;
        break;
    case 'l':
        return g_nDir1 = 右;
        break;
    default:
        break;
    }
    return 1;
}
//覆盖蛇
void snake::fnClearSnake(int nmap[MapX][MapY])
{
    if (nlive1)
    {
        for (int i = 0; i < g_nlenth; i++)
        {
            fnWriteChar(g_snake[0][i].X, g_snake[0][i].Y, "  ");
            
        }
        nmap[g_snake[0][g_nlenth - 1].X][g_snake[0][g_nlenth - 1].Y] = 空地;
    }
    if (nlive2)
    {
        for (int i = 0; i < g_nlenth1; i++)
        {
            fnWriteChar(g_snake[1][i].X, g_snake[1][i].Y, "  ");
        }
        nmap[g_snake[1][g_nlenth - 1].X][g_snake[1][g_nlenth - 1].Y] = 空地;
    }
    
}
//移动蛇
int snake::fnMoveSnake(int dir,int nmap[MapX][MapY])
{
    int tempX = g_snake[0][0].X;
    int tempY = g_snake[0][0].Y;
    int tempX1 = g_snake[1][0].X;
    int tempY1 = g_snake[1][0].Y;
     //蛇1的判断
    switch (g_nDir)
    {
    case 上:
        tempY--;
        break;
    case 下:
        tempY++;
        break;
    case 左:
        tempX--;
        break;
    case 右:
        tempX++;
        break;
    }
    if (nmap[tempX][tempY] == 障碍物)
    {
        return 0;
    }
    else if (nmap[tempX][tempY] == 食物)
    {
        g_nlenth++;
        nmap[tempX][tempY] = 空地;
        food.SetFoodNum(0);
        
        fnWriteNum(56, 2, (g_nlenth-4)*10, 6);
    }
    else if (nmap[tempX][tempY] == 自己)
    {
        for (int i = 0; i < g_nlenth; i++)
        {
            fnWriteChar(g_snake[0][i].X, g_snake[0][i].Y, "  ");
            nmap[g_snake[0][i].X][g_snake[0][i].Y] = 空地;
        }
        nlive1 = 0;
    }
    //蛇2的判断
    switch (g_nDir1)
    {
    case 上:
        tempY1--;
        break;
    case 下:
        tempY1++;
        break;
    case 左:
        tempX1--;
        break;
    case 右:
        tempX1++;
        break;
    }

    if (nmap[tempX1][tempY1] == 障碍物)
    {
        return 0;
    }

    else if (nmap[tempX1][tempY1] == 食物)
    {
        g_nlenth1++;
        nmap[tempX1][tempY1] = 空地;
        food.SetFoodNum(0);
        
        fnWriteNum(56, 4, (g_nlenth1 - 4) * 10, 6);
    }

    else if (nmap[tempX1][tempY1] == 自己)
    {
        for (int i = 0; i < g_nlenth; i++)
        {
            fnWriteChar(g_snake[1][i].X, g_snake[1][i].Y, "  ");
            nmap[g_snake[1][i].X][g_snake[1][i].Y] = 空地;
        }
        nlive2 = 0;
    }
    //蛇1改变坐标
    if (nlive1)
    {
        for (int i = g_nlenth - 1; i >= 0; i--)
        {
            g_snake[0][i + 1].X = g_snake[0][i].X;
            g_snake[0][i + 1].Y = g_snake[0][i].Y;
        }
        g_snake[0][0].X = tempX;
        g_snake[0][0].Y = tempY;
    }

    //蛇2
    if (nlive2)
    {
        for (int i = g_nlenth1 - 1; i >= 0; i--)
        {
            g_snake[1][i + 1].X = g_snake[1][i].X;
            g_snake[1][i + 1].Y = g_snake[1][i].Y;
        }
        g_snake[1][0].X = tempX1;
        g_snake[1][0].Y = tempY1;
    }
    
}
//画蛇
void snake::fnDrawSnake(int nmap[MapX][MapY])
{
    if (nlive1)
    {
        for (int i = 0; i < g_nlenth; i++)
        {
            fnWriteChar(g_snake[0][i].X, g_snake[0][i].Y, "■", 6);
        }
        nmap[g_snake[0][0].X][g_snake[0][0].Y] = 自己;
    }

    //画蛇2
    if (nlive2)
    {
        for (int i = 0; i < g_nlenth1; i++)
        {
            fnWriteChar(g_snake[1][i].X, g_snake[1][i].Y, "■", 5);
        }
        nmap[g_snake[1][0].X][g_snake[1][0].Y] = 自己;
    }    
}
//最后把上面的整合一下，获得游戏主体函数
void snake::Game()
{
    //初始化
    map.fnInitGame();
    map.fnDrawMap();
    fnWriteChar(50, 2, "玩家1 积分:");
    fnWriteChar(50, 4, "玩家2 积分:");
   
    while (nlive1==1||nlive2==1)
    {

        fnClearSnake(map.g_Map);
        int op1 = fnWaitChar1();
        int dir1 = fnGetPlayerInfo1(op1);
        fnMoveSnake(dir1, map.g_Map);
        fnDrawSnake(map.g_Map);
        Sleep(100);
        food.fnCreatFood(map.g_Map);
    }

    //游戏结束输出结果
    system("cls");
    fnWriteChar(0,0, "比赛结果：",6);
    printf("\n玩家1积分：%d", (g_nlenth - 4) * 10);
    printf("\n玩家2积分：%d",(g_nlenth1 - 4) * 10);
    if ((g_nlenth - 4) * 10 > (g_nlenth1 - 4) * 10)
    {
        printf("\n玩家1胜利！！！");
    }
    else if ((g_nlenth - 4) * 10 < (g_nlenth1 - 4) * 10)
    {
        printf("\n玩家2胜利！！！");
    }
    else 
    {
        printf("\n打成平手！！！");
    }

    system("pause");
}