#include "pch.h"
#include "CLine.h"


CLine::CLine(void)
{
	
	c0 = RGB(0,0,0);
	c1 = RGB(0,0,0);
}

CLine::~CLine(void)
{
}

CLine::CLine(CP2 p0,CP2 p1, COLORREF c0, COLORREF c1)
{
	
	P0 = p0;
	P1 = p1;
	this->c0 = c0;
	this->c1 = c1;
}

void CLine::MoveTo(CDC* pDC, CP2 p0, COLORREF c0)
{
	P0 = p0;
}

void CLine::LineTo(CDC* pDC, CP2 p1, COLORREF c1)
{
	P1 = p1;
	double dx = abs(P1.x - P0.x);
	double dy = abs(P1.y - P0.y);
	BOOL bInterChange = FALSE;
	double e, signX, signY, temp;
	signX = (P1.x > P0.x) ? 1 : ((P1.x < P0.x) ? -1 : 0);
	signY = (P1.y > P0.y) ? 1 : ((P1.y < P0.y) ? -1 : 0);
	if (dy > dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		bInterChange = TRUE;
	}
	e = 0;
	CP2 p = P0;//从起点开始绘制直线
	for (int i = 1; i <= dx; i++)
	{
	
		if (bInterChange)//y为主位移方向
		{
			pDC->SetPixelV(p.x + signX, p.y, c1);
			pDC->SetPixelV(p.x, p.y, c0);
		}
		else//x为主位移方向
		{
			pDC->SetPixelV(p.x, p.y + signY,c1);
			pDC->SetPixelV(p.x, p.y, c0);
		}
		if (bInterChange)
			p.y += signY;
		else
			p.x += signX;
		e += (dy / dx);
		if (e >= 1.0)
		{
			if (bInterChange)
				p.x += signX;
			else
				p.y += signY;
			e--;
		}
	}
	P0 = p1;
}
