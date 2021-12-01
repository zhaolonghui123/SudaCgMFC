#pragma once
#include "CLine.h"
#include"Facet.h"
#include"P3.h"
#include"Point3.h"
#include"Projection.h"
#include"Triangle.h"
#include"Transform3.h"
#include"Vector.h"
#include"ZBuffer.h"
#define ROUND(d) int(d+0.5)
class CSphere
{
public:
	CSphere(void);
	virtual~CSphere(void);
	void SetScale(int nScalar);
	void SetRotation(double Alpha, double Beta);
	void DrawFacet(CDC* pDC, CP3* P, CZBuffer* pZBuffer);
	void Draw(CDC* pDC, CZBuffer* pZBuffer);
public:
	CProjection projection;
	CP3 quardrP[4];
	CLine line;
	int nScalar;
	double Alpha, Beta;
	CTransform3 transform;
};

