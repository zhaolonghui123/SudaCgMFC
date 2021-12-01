#include "pch.h"
#include "Facet.h"

CFacet::CFacet(void)
{
	Number = 0;
	for (int i = 0; i < 4; i++) {
		Index[i] = 0;
	}
}

CFacet::~CFacet(void)
{
}

void CFacet::SetPtNumber(int Number)
{
	this->Number = Number;
}

void CFacet::SetFacetNormal(CP3 P0, CP3 P1, CP3 P2)
{
	CVector Vector01(P0, P1);// P0��P1���㹹�ɱ�����
	CVector Vector02(P0, P2);// P0��P2���㹹�ɱ�����
	fNormal = CrossProduct(Vector01, Vector02);
}


