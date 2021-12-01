#pragma once
#include<fstream>
#include<string>
#include <sstream>
#include"P3.h"
#include"Facet.h"
#include"P2.h"
#include"Projection.h"
#include"Vector.h"
#include"Triangle.h"
#include"CLine.h"
#include "ZBuffer.h"
#define ROUND(d) int(d+0.5)
class CRead2
{
public:
	CRead2(void);
	virtual ~CRead2(void);
	void ReadPoint(void);
	void ReadFacet(void);
	CP3* GetVertexArrayName(void);
	void Draw(CDC* pDC, CZBuffer* pZBuffer);
	void Draw2(CDC* pDC, CZBuffer* pZBuffer);
public:
	CProjection projection;
private:
	CP3 P[19231];
	CFacet F[38388];
	CP3 quardrP[4];
	CLine line;
};
