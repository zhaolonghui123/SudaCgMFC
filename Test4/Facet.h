#pragma once
#include"Vector.h"
class CFacet
{
public:
	CFacet(void);
	virtual ~CFacet(void);
	void SetPtNumber(int Number);
	void SetFacetNormal(CP3 P0, CP3 P1, CP3 P2);
public:
	int Number;
	int Index[4];
	CVector fNormal;//面的法向量
};

