#pragma once
#include"P3.h"
#include"Facet.h"
#include"P2.h"
#include"Projection.h"
#include"Vector.h"
#include"Triangle.h"
#include"CLine.h"
#define ROUND(d) int(d+0.5)
class CCube
{
public:
	CCube(void);
	virtual ~CCube(void);
	void ReadPoint(void);
	void ReadFacet(void);
	CP3* GetVertexArrayName(void);
	void Draw(CDC* pDC);
	void Draw2(CDC* pDC);
	void Draw3(CDC* pDC);
public:
	CProjection projection;
private:
	CP3 P[8];
	CFacet F[6];
	CP3 quardrP[4];
	CLine line;
	CP2 ObliqueProjection(CP3 WorldPoint);
	//CP2 PerspectiveProjection(CP3 WorldPoint);
};

