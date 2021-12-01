#include "pch.h"
#include "Fence.h"
#define ROUND(d) int(d+0.5)

CFence::CFence(void)
{
}

CFence::~CFence(void)
{
}

void CFence::ReadPoint(void)
{
	P[0] = CP2(1, 1);
	P[1] = CP2(-1, -1);
	P[2] = CP2(1, -1);

}

void CFence::Draw(CDC* pDC)
{
	CPen NewPen(PS_SOLID, 3, RGB(0, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&NewPen);
	pDC->MoveTo(ROUND(P[0].x), ROUND(P[0].y));
	pDC->LineTo(ROUND(P[1].x), ROUND(P[1].y));
	pDC->LineTo(ROUND(P[2].x), ROUND(P[2].y));
	pDC->LineTo(ROUND(P[0].x), ROUND(P[0].y));
	pDC->SelectObject(pOldPen);
}
