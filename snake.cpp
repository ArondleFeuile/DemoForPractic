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
//����û����� 
int snake::fnWaitChar1()
{
    if (_kbhit())
    {
        char temp = _getch();
        if ((g_nDir == �� || g_nDir == ��) && (temp == 'w' || temp == 's'))
        {
            return 0;
        }
        if ((g_nDir == �� || g_nDir == ��) && (temp == 'a' || temp == 'd'))
        {
            return 0;
        }


        if ((g_nDir1 == �� || g_nDir1 == ��) && (temp == 'i' || temp == 'k'))
        {
            return 0;
        }
        if ((g_nDir1 == �� || g_nDir1 == ��) && (temp == 'j' || temp == 'l'))
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
        return g_nDir = ��;
        break;
    case 's':
        return g_nDir = ��;
        break;
    case 'a':
        return g_nDir = ��;
        break;
    case 'd':
        return g_nDir = ��;
        break;
    case 'i':
        return g_nDir1 = ��;
        break;
    case 'k':
        return g_nDir1 = ��;
        break;
    case 'j':
        return g_nDir1 = ��;
        break;
    case 'l':
        return g_nDir1 = ��;
        break;
    default:
        break;
    }
    return 1;
}
//������
void snake::fnClearSnake(int nmap[MapX][MapY])
{
    if (nlive1)
    {
        for (int i = 0; i < g_nlenth; i++)
        {
            fnWriteChar(g_snake[0][i].X, g_snake[0][i].Y, "  ");
            
        }
        nmap[g_snake[0][g_nlenth - 1].X][g_snake[0][g_nlenth - 1].Y] = �յ�;
    }
    if (nlive2)
    {
        for (int i = 0; i < g_nlenth1; i++)
        {
            fnWriteChar(g_snake[1][i].X, g_snake[1][i].Y, "  ");
        }
        nmap[g_snake[1][g_nlenth - 1].X][g_snake[1][g_nlenth - 1].Y] = �յ�;
    }
    
}
//�ƶ���
int snake::fnMoveSnake(int dir,int nmap[MapX][MapY])
{
    int tempX = g_snake[0][0].X;
    int tempY = g_snake[0][0].Y;
    int tempX1 = g_snake[1][0].X;
    int tempY1 = g_snake[1][0].Y;
     //��1���ж�
    switch (g_nDir)
    {
    case ��:
        tempY--;
        break;
    case ��:
        tempY++;
        break;
    case ��:
        tempX--;
        break;
    case ��:
        tempX++;
        break;
    }
    if (nmap[tempX][tempY] == �ϰ���)
    {
        return 0;
    }
    else if (nmap[tempX][tempY] == ʳ��)
    {
        g_nlenth++;
        nmap[tempX][tempY] = �յ�;
        food.SetFoodNum(0);
        
        fnWriteNum(56, 2, (g_nlenth-4)*10, 6);
    }
    else if (nmap[tempX][tempY] == �Լ�)
    {
        for (int i = 0; i < g_nlenth; i++)
        {
            fnWriteChar(g_snake[0][i].X, g_snake[0][i].Y, "  ");
            nmap[g_snake[0][i].X][g_snake[0][i].Y] = �յ�;
        }
        nlive1 = 0;
    }
    //��2���ж�
    switch (g_nDir1)
    {
    case ��:
        tempY1--;
        break;
    case ��:
        tempY1++;
        break;
    case ��:
        tempX1--;
        break;
    case ��:
        tempX1++;
        break;
    }

    if (nmap[tempX1][tempY1] == �ϰ���)
    {
        return 0;
    }

    else if (nmap[tempX1][tempY1] == ʳ��)
    {
        g_nlenth1++;
        nmap[tempX1][tempY1] = �յ�;
        food.SetFoodNum(0);
        
        fnWriteNum(56, 4, (g_nlenth1 - 4) * 10, 6);
    }

    else if (nmap[tempX1][tempY1] == �Լ�)
    {
        for (int i = 0; i < g_nlenth; i++)
        {
            fnWriteChar(g_snake[1][i].X, g_snake[1][i].Y, "  ");
            nmap[g_snake[1][i].X][g_snake[1][i].Y] = �յ�;
        }
        nlive2 = 0;
    }
    //��1�ı�����
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

    //��2
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
//����
void snake::fnDrawSnake(int nmap[MapX][MapY])
{
    if (nlive1)
    {
        for (int i = 0; i < g_nlenth; i++)
        {
            fnWriteChar(g_snake[0][i].X, g_snake[0][i].Y, "��", 6);
        }
        nmap[g_snake[0][0].X][g_snake[0][0].Y] = �Լ�;
    }

    //����2
    if (nlive2)
    {
        for (int i = 0; i < g_nlenth1; i++)
        {
            fnWriteChar(g_snake[1][i].X, g_snake[1][i].Y, "��", 5);
        }
        nmap[g_snake[1][0].X][g_snake[1][0].Y] = �Լ�;
    }    
}
//�������������һ�£������Ϸ���庯��
void snake::Game()
{
    //��ʼ��
    map.fnInitGame();
    map.fnDrawMap();
    fnWriteChar(50, 2, "���1 ����:");
    fnWriteChar(50, 4, "���2 ����:");
   
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

    //��Ϸ����������
    system("cls");
    fnWriteChar(0,0, "���������",6);
    printf("\n���1���֣�%d", (g_nlenth - 4) * 10);
    printf("\n���2���֣�%d",(g_nlenth1 - 4) * 10);
    if ((g_nlenth - 4) * 10 > (g_nlenth1 - 4) * 10)
    {
        printf("\n���1ʤ��������");
    }
    else if ((g_nlenth - 4) * 10 < (g_nlenth1 - 4) * 10)
    {
        printf("\n���2ʤ��������");
    }
    else 
    {
        printf("\n���ƽ�֣�����");
    }

    system("pause");
}