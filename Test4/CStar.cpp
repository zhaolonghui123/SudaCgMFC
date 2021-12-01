#include "pch.h"
#include "CStar.h"
#define PI  3.14159

CStar::CStar(void)
{
	 r = 400;
}

CStar::~CStar(void)
{
    projection.InitialParameter();
}

void CStar::ReadPoint(void)
{
	const double nScale = sin(18 * PI / 180) / cos(36 * PI / 180);
	double r2 = nScale * r;//五角星内点圆半径
	double nAlpha = 72 * PI / 180;
	double nAlpha1 = PI / 2;
	double nAlpha2 = PI / 2 + 36 * PI / 180;//36
	double nHeight = 100;//五角星中心点距离
	for (int nPoint = 0; nPoint < 5; nPoint++)
	{
		P[2 * nPoint].x = r * cos(nPoint * nAlpha + nAlpha1);
		P[2 * nPoint].y = r * sin(nPoint * nAlpha + nAlpha1);
		P[2 * nPoint].z = 0;
		P[2 * nPoint].c = CRGB(1.0, 0.0, 0.0);
		P[2 * nPoint + 1].x = r2 * cos(nPoint * nAlpha + nAlpha2);
		P[2 * nPoint + 1].y = r2 * sin(nPoint * nAlpha + nAlpha2);
		P[2 * nPoint + 1].z = 0;
		P[2 * nPoint + 1].c = CRGB(1.0, 0.0, 0.0);
	}
	P[10].x = 0.0, P[10].y = 0.0, P[10].z = nHeight, P[10].c = CRGB(1.0, 1.0, 1.0);//前面中心点
	P[11].x = 0.0, P[11].y = 0.0, P[11].z = -nHeight, P[11].c = CRGB(1.0, 1.0, 1.0);//后面中心点
}

void CStar::ReadFacet(void)
{
	for (int nFacet = 0; nFacet < 10; nFacet++)
	{
		int Index = (nFacet + 1) % 10;
		F[nFacet].SetPtNumber(3);
		F[nFacet].Index[0] = nFacet;
		F[nFacet].Index[1] = Index;
		F[nFacet].Index[2] = 10;
	}
	for (int nFacet = 10; nFacet < 19; nFacet++)
	{
		int Index = (nFacet - 10 + 1) % 10;
		F[nFacet].SetPtNumber(3);
		F[nFacet].Index[0] = Index;
		F[nFacet].Index[1] = Index - 1;
		F[nFacet].Index[2] = 11;
	}
	F[19].SetPtNumber(3);
	F[19].Index[0] = 0;
	F[19].Index[1] = 9;
	F[19].Index[2] = 11;
}

CP3* CStar::GetVertexArrayName(void)
{
	return P;
}

void CStar::Draw(CDC* pDC)
{
	CP3 ScreenPoint[4], temp;
	CTriangle* pfill = new CTriangle;
	CP3 ViewPoint = projection.EyePoint;
	for (int nFacet = 0; nFacet < 20; nFacet++)
	{
		for (int i = 0; i < 3; i++) {
			quardrP[i] = P[F[nFacet].Index[i]];
		}
		CVector ViewVector(quardrP[0], ViewPoint);
		ViewVector = ViewVector.Normalize();
		CVector Vector01(quardrP[0], quardrP[1]);
		CVector Vector02(quardrP[0], quardrP[2]);
		CVector Vector03(quardrP[1], quardrP[2]);
		CVector FacetNormalA = CrossProduct(Vector01, Vector02);
		CVector FacetNormalB = CrossProduct(Vector02, Vector03);
		CVector FacetNormal = (FacetNormalA + FacetNormalB);//面法向量
		FacetNormal = FacetNormal.Normalize();
		if (DotProduct(ViewVector, FacetNormal) >= 0) {
			for (int nPoint = 0; nPoint < 3; nPoint++)
			{
				//ScreenPoint.x = P[F[nFacet].Index[nPoint]].x;
				//ScreenPoint.y = P[F[nFacet].Index[nPoint]].y;
				ScreenPoint[nPoint] = projection.OrthogonalProjection(P[F[nFacet].Index[nPoint]]);
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
			pfill->SetPoint(ScreenPoint[0], ScreenPoint[1], ScreenPoint[2]);
			pfill->GouraudShader(pDC);
		}
	}
	delete pfill;
}

void CStar::Draw2(CDC* pDC)
{
	CP3 ScreenPoint[4], temp;
	CTriangle* pfill = new CTriangle;
	CP3 ViewPoint = projection.EyePoint;
	for (int nFacet = 0; nFacet < 20; nFacet++)
	{
		for (int i = 0; i < 3; i++) {
			quardrP[i] = P[F[nFacet].Index[i]];
		}
		CVector ViewVector(quardrP[0], ViewPoint);
		ViewVector = ViewVector.Normalize();
		CVector Vector01(quardrP[0], quardrP[1]);
		CVector Vector02(quardrP[0], quardrP[2]);
		CVector Vector03(quardrP[1], quardrP[2]);
		CVector FacetNormalA = CrossProduct(Vector01, Vector02);
		CVector FacetNormalB = CrossProduct(Vector02, Vector03);
		CVector FacetNormal = (FacetNormalA + FacetNormalB);//面法向量
		FacetNormal = FacetNormal.Normalize();
		if (DotProduct(ViewVector, FacetNormal) >= 0) {
			for (int nPoint = 0; nPoint < 3; nPoint++)
			{
				//ScreenPoint.x = P[F[nFacet].Index[nPoint]].x;
				//ScreenPoint.y = P[F[nFacet].Index[nPoint]].y;
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
			pfill->SetPoint(ScreenPoint[0], ScreenPoint[1], ScreenPoint[2]);
			pfill->GouraudShader(pDC);
		}
	}
	delete pfill;
}
