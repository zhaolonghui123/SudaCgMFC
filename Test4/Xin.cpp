#include "pch.h"
#include "Xin.h"

CXin::CXin(void)
{
	projection.InitialParameter();
}

CXin::~CXin(void)
{
}

void CXin::ReadPoint(void)
{
	P[0].x = -1, P[0].y = -1, P[0].z = 3; P[0].c = CRGB(0, 0, 0);
	P[1].x = 1, P[1].y = -1, P[1].z = 3; P[1].c = CRGB(1, 0, 0);
	P[2].x = 1, P[2].y = 1, P[2].z = 3; P[2].c = CRGB(1, 1, 0);
	P[3].x = -1, P[3].y = 1, P[3].z = 3; P[3].c = CRGB(0, 1, 0);
	
	P[4].x = -3, P[4].y = -1, P[4].z = 1; P[4].c = CRGB(0, 0, 0);
	P[5].x = -1, P[5].y = -3, P[5].z = 1; P[5].c = CRGB(0, 0, 0);
	P[6].x = 1, P[6].y = -3, P[6].z = 1; P[6].c = CRGB(1, 0, 0);
	P[7].x = 3, P[7].y = -1, P[7].z = 1; P[7].c = CRGB(1, 0, 0);
	P[8].x = 3, P[8].y = 1, P[8].z = 1; P[8].c = CRGB(1, 1, 0);
	P[9].x = 1, P[9].y = 3, P[9].z = 1; P[9].c = CRGB(1, 1, 0);
	P[10].x = -1, P[10].y = 3, P[10].z = 1; P[10].c = CRGB(0, 1, 0);
	P[11].x = -3, P[11].y = 1, P[11].z = 1; P[11].c = CRGB(0, 1, 0);

	P[12].x = -3, P[12].y = -1, P[12].z = -1; P[12].c = CRGB(0, 0, 1);
	P[13].x = -1, P[13].y = -3, P[13].z = -1; P[13].c = CRGB(0, 0, 1);
	P[14].x = 1, P[14].y = -3, P[14].z = -1; P[14].c = CRGB(1, 0, 1);
	P[15].x = 3, P[15].y = -1, P[15].z = -1; P[15].c = CRGB(1, 0, 1);
	P[16].x = 3, P[16].y = 1, P[16].z = -1; P[16].c = CRGB(1, 1, 1);
	P[17].x = 1, P[17].y = 3, P[17].z = -1; P[17].c = CRGB(1, 1, 1);
	P[18].x = -1, P[18].y = 3, P[18].z = -1; P[18].c = CRGB(0, 1, 1);
	P[19].x = -3, P[19].y = 1, P[19].z = -1; P[19].c = CRGB(0, 1, 1);

	P[20].x = -1, P[20].y = -1, P[20].z = -3; P[20].c = CRGB(0, 0, 1);
	P[21].x = 1, P[21].y = -1, P[21].z = -3; P[21].c = CRGB(1, 0, 1);
	P[22].x = 1, P[22].y = 1, P[22].z = -3; P[22].c = CRGB(1, 1, 1);
	P[23].x = -1, P[23].y = 1, P[23].z = -3; P[23].c = CRGB(0, 1, 1);
}

void CXin::ReadFacet(void)
{
	F[0].Index[0] = 0; F[0].Index[1] = 1; F[0].Index[2] = 2; F[0].Index[3] = 3;
	F[1].Index[0] = 5; F[1].Index[1] = 6; F[1].Index[2] = 1; F[1].Index[3] = 0;
	F[2].Index[0] = 1; F[2].Index[1] = 7; F[2].Index[2] = 8; F[2].Index[3] = 2;
	F[3].Index[0] = 2; F[3].Index[1] = 9; F[3].Index[2] = 10; F[3].Index[3] = 3;
	F[4].Index[0] = 3; F[4].Index[1] = 11; F[4].Index[2] = 4; F[4].Index[3] = 0;
	
	F[5].Index[0] = 4; F[5].Index[1] = 12; F[5].Index[2] = 13; F[5].Index[3] = 5;
	F[6].Index[0] = 5; F[6].Index[1] = 13; F[6].Index[2] = 14; F[6].Index[3] = 6;
	F[7].Index[0] = 6; F[7].Index[1] = 14; F[7].Index[2] = 15; F[7].Index[3] = 7;
	F[8].Index[0] = 7; F[8].Index[1] = 15; F[8].Index[2] = 16; F[8].Index[3] = 8;
	F[9].Index[0] = 8; F[9].Index[1] = 16; F[9].Index[2] = 17; F[9].Index[3] = 9;
	F[10].Index[0] = 9; F[10].Index[1] = 17; F[10].Index[2] = 18; F[10].Index[3] = 10;
	F[11].Index[0] = 10; F[11].Index[1] = 18; F[11].Index[2] = 19; F[11].Index[3] = 11;
	F[12].Index[0] = 11; F[12].Index[1] = 19; F[12].Index[2] = 12; F[12].Index[3] = 4;

	F[13].Index[0] = 23; F[13].Index[1] = 22; F[13].Index[2] = 21; F[13].Index[3] = 20;
	F[14].Index[3] = 20; F[14].Index[2] = 13; F[14].Index[1] = 14; F[14].Index[0] = 21;
	F[15].Index[3] = 21; F[15].Index[2] = 15; F[15].Index[1] = 16; F[15].Index[0] = 22;
	F[16].Index[3] = 22; F[16].Index[2] = 17; F[16].Index[1] = 18; F[16].Index[0] = 23;
	F[17].Index[3] = 23; F[17].Index[2] = 19; F[17].Index[1] = 12; F[17].Index[0] = 20;

	F[18].Index[0] = 4; F[18].Index[1] = 5; F[18].Index[2] = 0;
	F[19].Index[0] = 11; F[19].Index[1] = 3; F[19].Index[2] = 10;
	F[20].Index[0] = 1; F[20].Index[1] = 6; F[20].Index[2] = 7;
	F[21].Index[0] = 2; F[21].Index[1] = 8; F[21].Index[2] = 9;
	
	F[22].Index[2] = 12; F[22].Index[1] = 13; F[22].Index[0] = 20;
	F[23].Index[2] = 21; F[23].Index[1] = 14; F[23].Index[0] = 15;
	F[24].Index[2] = 22; F[24].Index[1] = 16; F[24].Index[0] = 17;
	F[25].Index[2] = 23; F[25].Index[1] = 18; F[25].Index[0] = 19;
}

CP3* CXin::GetVertexArrayName(void)
{
	return P;
}

void CXin::Draw(CDC* pDC)
{
	CP3 ScreenPoint[4], temp;
	CTriangle* pfill = new CTriangle;
	CP3 ViewPoint = projection.EyePoint;
	for (int nFacet = 0; nFacet < 18; nFacet++)
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
		CVector FacetNormal = (FacetNormalA + FacetNormalB);//面法向量
		FacetNormal = FacetNormal.Normalize();
		if (DotProduct(ViewVector, FacetNormal) >= 0) {
			for (int nPoint = 0; nPoint < 4; nPoint++)
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
			pfill->SetPoint(ScreenPoint[0], ScreenPoint[2], ScreenPoint[3]);
			pfill->GouraudShader(pDC);
			pfill->SetPoint(ScreenPoint[0], ScreenPoint[1], ScreenPoint[2]);
			pfill->GouraudShader(pDC);
		}
	}
	for (int nFacet = 18; nFacet < 26; nFacet++)
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

void CXin::Draw2(CDC* pDC, CZBuffer* pZBuffer)
{
	CP3 ScreenPoint[4], temp;
	for (int nFacet = 0; nFacet < 18; nFacet++)//面循环
	{
		for (int nPoint = 0; nPoint < 4; nPoint++)
		{
			ScreenPoint[nPoint] = projection.PerspectiveProjection(P[F[nFacet].Index[nPoint]]);
			ScreenPoint[nPoint].c = P[F[nFacet].Index[nPoint]].c;
		}
		pZBuffer->SetPoint(ScreenPoint[0], ScreenPoint[2], ScreenPoint[3]);
		pZBuffer->GouraudShade(pDC);
		pZBuffer->SetPoint(ScreenPoint[0], ScreenPoint[1], ScreenPoint[2]);//三角形
		pZBuffer->GouraudShade(pDC);
	}
	for (int nFacet = 18; nFacet < 26; nFacet++)//面循环
	{
		for (int nPoint = 0; nPoint < 3; nPoint++)
		{
			ScreenPoint[nPoint] = projection.PerspectiveProjection(P[F[nFacet].Index[nPoint]]);
			ScreenPoint[nPoint].c = P[F[nFacet].Index[nPoint]].c;
		}
		pZBuffer->SetPoint(ScreenPoint[0], ScreenPoint[1], ScreenPoint[2]);//三角形
		pZBuffer->GouraudShade(pDC);
	}
}


void CXin::Draw3(CDC* pDC)
{
	CP3 ScreenPoint[4], temp;
	CTriangle* pfill = new CTriangle;
	CP3 ViewPoint = projection.EyePoint;
	for (int nFacet = 0; nFacet < 18; nFacet++)
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
		CVector FacetNormal = (FacetNormalA + FacetNormalB);//面法向量
		FacetNormal = FacetNormal.Normalize();
		if (DotProduct(ViewVector, FacetNormal) >= 0) {
			for (int nPoint = 0; nPoint < 4; nPoint++)
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
			pfill->SetPoint(ScreenPoint[0], ScreenPoint[2], ScreenPoint[3]);
			pfill->GouraudShader(pDC);
			pfill->SetPoint(ScreenPoint[0], ScreenPoint[1], ScreenPoint[2]);
			pfill->GouraudShader(pDC);
		}
	}
	for (int nFacet = 18; nFacet < 26; nFacet++)
	{
		for (int j = 0; j < 3; j++) {
			quardrP[j] = P[F[nFacet].Index[j]];
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