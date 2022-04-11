#include "write.h"
void fnWriteChar(int x, int y, const char* szCh, WORD color )
{
    //获得输出句柄；
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x * 2,y };
    SetConsoleCursorPosition(hOut, pos);
    SetConsoleTextAttribute(hOut, color);
    printf("%s", szCh);

}

void fnWriteNum(int x, int y, int nNum, WORD color)
{
    //获得输出句柄；
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x * 2,y };
    SetConsoleCursorPosition(hOut, pos);
    SetConsoleTextAttribute(hOut, color);
    printf("%d", nNum);
}