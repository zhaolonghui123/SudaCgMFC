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
class CRead1
{
public:
	CRead1(void);
	virtual ~CRead1(void);
	void ReadPoint(void);
	void ReadFacet(void);
	CP3* GetVertexArrayName(void);
	void Draw(CDC* pDC);
	void Draw2(CDC* pDC);
public:
	CProjection projection;
private:
	CP3 P[6527];
	CFacet F[12948];
	CP3 quardrP[4];
	CLine line;
};


