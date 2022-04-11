#pragma once
#include<windows.h>
#include <iostream>

#define 上 1
#define 下 2
#define 左 3
#define 右 4
#define MapX 50
#define MapY 40
#define 空地 0
#define 食物 1
#define 障碍物 2
#define 自己 3
//画笔
void fnWriteChar(int x, int y, const char* szCh, WORD color = 1 | 8);
void fnWriteNum(int x, int y, int nNum, WORD color);