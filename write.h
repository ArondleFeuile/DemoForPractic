#pragma once
#include<windows.h>
#include <iostream>

#define �� 1
#define �� 2
#define �� 3
#define �� 4
#define MapX 50
#define MapY 40
#define �յ� 0
#define ʳ�� 1
#define �ϰ��� 2
#define �Լ� 3
//����
void fnWriteChar(int x, int y, const char* szCh, WORD color = 1 | 8);
void fnWriteNum(int x, int y, int nNum, WORD color);