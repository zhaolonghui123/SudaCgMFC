#include "pch.h"
#include "Cube.h"
#define ROUND(d) int(d+0.5)

CCube::CCube(void)
{
	projection.InitialParameter();
}

CCube::~CCube(void)
{
}

void CCube::ReadPoint(void)
{
	P[0].x = 0, P[0].y = 0, P[0].z = 0; P[0].c = CRGB(0, 0, 0);
	P[1].x = 1, P[1].y = 0, P[1].z = 0; P[1].c = CRGB(1, 0, 0);
	P[2].x = 1, P[2].y = 1, P[2].z = 0; P[2].c = CRGB(1, 1, 0);
	P[3].x = 0, P[3].y = 1, P[3].z = 0; P[3].c = CRGB(0, 1, 0);
	P[4].x = 0, P[4].y = 0, P[4].z = 1; P[4].c = CRGB(0, 0, 1);
	P[5].x = 1, P[5].y = 0, P[5].z = 1; P[5].c = CRGB(1, 0, 1);
	P[6].x = 1, P[6].y = 1, P[6].z = 1; P[6].c = CRGB(1, 1, 1);
	P[7].x = 0, P[7].y = 1, P[7].z = 1; P[7].c = CRGB(0, 1, 1);
}

void CCube::ReadFacet(void)
{
	F[0].Index[0] = 4; F[0].Index[1] = 5; F[0].Index[2] = 6; F[0].Index[3] = 7; 
	F[1].Index[0] = 0; F[1].Index[1] = 3; F[1].Index[2] = 2; F[1].Index[3] = 1; 
	F[2].Index[0] = 0; F[2].Index[1] = 4; F[2].Index[2] = 7; F[2].Index[3] = 3; 
	F[3].Index[0] = 1; F[3].Index[1] = 2; F[3].Index[2] = 6; F[3].Index[3] = 5; 
	F[4].Index[0] = 2; F[4].Index[1] = 3; F[4].Index[2] = 7; F[4].Index[3] = 6; 
	F[5].Index[0] = 0; F[5].Index[1] = 1; F[5].Index[2] = 5; F[5].Index[3] = 4; 
}

CP3* CCube::GetVertexArrayName(void)
{
	return P;
}

void CCube::Draw(CDC* pDC, CZBuffer* pZBuffer)
{
	CP3 ScreenPoint[4], temp;
	CP3 ViewPoint = projection.EyePoint;
	for (int nFacet = 0; nFacet < 6; nFacet++)//??ѭ??
	{
		for (int nPoint = 0; nPoint < 4; nPoint++)
		{
			ScreenPoint[nPoint] = projection.OrthogonalProjection(P[F[nFacet].Index[nPoint]]);
			ScreenPoint[nPoint].c = P[F[nFacet].Index[nPoint]].c;
		}
		pZBuffer->SetPoint(ScreenPoint[0], ScreenPoint[2], ScreenPoint[3]);
		pZBuffer->GouraudShade(pDC);
		pZBuffer->SetPoint(ScreenPoint[0], ScreenPoint[1], ScreenPoint[2]);//??????
		pZBuffer->GouraudShade(pDC);
	}
	for (int nFacet = 0; nFacet < 6; nFacet++)
	{
		for (int i = 0; i < 4; i++) {
			quardrP[i] = P[F[nFacet].Index[i]];
		}
		CVector ViewVector(quardrP[0], ViewPoint);
		ViewVector = ViewVector.Normalize();
		CVector Vector01(quardrP[0], quardrP[1]);
		CVector Vector02(quardrP[0], quardrP[2]);
		CVector Vector03(quardrP[0], quardrP[3]);
		CVector FacetNormalA = CrossProduct(Vector01, Vector02);
		CVector FacetNormalB = CrossProduct(Vector02, Vector03);
		CVector FacetNormal = (FacetNormalA + FacetNormalB);//?淨????
		FacetNormal = FacetNormal.Normalize();
		if (DotProduct(ViewVector, FacetNormal) >= 0) {
			for (int nPoint = 0; nPoint < 4; nPoint++)
			{
				ScreenPoint[nPoint] = projection.OrthogonalProjection(P[F[nFacet].Index[nPoint]]);
				ScreenPoint[nPoint].c=P[F[nFacet].Index[nPoint]].c;

				if (0 == nPoint)
				{
					line.MoveTo(pDC,ScreenPoint[nPoint], RGB(0, 0, 0));
					temp = ScreenPoint[nPoint];
				}
				else
				{
					line.LineTo(pDC, ScreenPoint[nPoint], RGB(0, 0, 0));
				}
			}
			line.LineTo(pDC, temp, RGB(0, 0, 0));
		}
	}
}



void CCube::Draw2(CDC* pDC, CZBuffer* pZBuffer)
{
	CP3 ScreenPoint[4], temp;
	CP3 ViewPoint = projection.EyePoint;
	for (int nFacet = 0; nFacet < 6; nFacet++)//??ѭ??
	{
		for (int nPoint = 0; nPoint < 4; nPoint++)
		{
			ScreenPoint[nPoint] = projection.PerspectiveProjection(P[F[nFacet].Index[nPoint]]);
			ScreenPoint[nPoint].c = P[F[nFacet].Index[nPoint]].c;
		}
		pZBuffer->SetPoint(ScreenPoint[0], ScreenPoint[2], ScreenPoint[3]);
		pZBuffer->GouraudShade(pDC);
		pZBuffer->SetPoint(ScreenPoint[0], ScreenPoint[1], ScreenPoint[2]);//??????
		pZBuffer->GouraudShade(pDC);
	}
	for (int nFacet = 0; nFacet < 6; nFacet++)
	{

		for (int i = 0; i < 4; i++) {
			quardrP[i] = P[F[nFacet].Index[i]];
		}
		CVector ViewVector(quardrP[0], ViewPoint);
		ViewVector = ViewVector.Normalize();
		CVector Vector01(quardrP[0], quardrP[1]);
		CVector Vector02(quardrP[0], quardrP[2]);
		CVector Vector03(quardrP[0], quardrP[3]);
		CVector FacetNormalA = CrossProduct(Vector01, Vector02);
		CVector FacetNormalB = CrossProduct(Vector02, Vector03);
		CVector FacetNormal = (FacetNormalA + FacetNormalB);//?淨????
		FacetNormal = FacetNormal.Normalize();
		if (DotProduct(ViewVector, FacetNormal) >= 0) {
			for (int nPoint = 0; nPoint < 4; nPoint++)
			{
				ScreenPoint[nPoint] = projection.PerspectiveProjection(P[F[nFacet].Index[nPoint]]);
				ScreenPoint[nPoint].c = P[F[nFacet].Index[nPoint]].c;

				if (0 == nPoint)
				{
					line.MoveTo(pDC, ScreenPoint[nPoint], RGB(0, 0, 0));
					temp = ScreenPoint[nPoint];
				}
				else
				{
					line.LineTo(pDC, ScreenPoint[nPoint], RGB(0, 0, 0));
				}
			}
			line.LineTo(pDC, temp, RGB(0, 0, 0));
		}
	}
}


