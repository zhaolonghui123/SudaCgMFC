#pragma once
#include"P3.h"
#include"Facet.h"
#include"P2.h"
#include"Projection.h"
#include"Vector.h"
#include"Triangle.h"
#include"CLine.h"
#include "ZBuffer.h"
#define ROUND(d) int(d+0.5)
class CStar
{
public:
	CStar(void);
	virtual ~CStar(void);
	void ReadPoint(void);
	void ReadFacet(void);
	CP3* GetVertexArrayName(void);
	void Draw(CDC* pDC);
	void Draw2(CDC* pDC);
public:
	CProjection projection;
	CLine line;
	int r;
private:
	CP3 P[12];
	CFacet F[20];
	CP3 quardrP[3];
};

