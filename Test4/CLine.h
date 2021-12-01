#include<math.h>
#include"P3.h"
#define COLOR(c) int(RGB(c.red * 255, c.green * 255, c.blue * 255))
#pragma once
class CLine
{
public:
	CLine(void);
	virtual~CLine(void);
	CLine(CP2 p0,CP2 p1, COLORREF c0, COLORREF c1);
	void MoveTo(CDC* pDC, CP2 p0, COLORREF c0);
	void LineTo(CDC* pDC, CP2 p1, COLORREF c1);
public:
	CP2 P0;//Æðµã
	CP2 P1;//ÖÕµã
	COLORREF c0;
	COLORREF c1;
};

