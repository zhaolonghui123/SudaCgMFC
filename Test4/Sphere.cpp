#include "pch.h"
#include "Sphere.h"

CSphere::CSphere(void)
{
	nScalar = 200;
	Alpha = Beta = 0;
}

CSphere::~CSphere(void)
{
}

void CSphere::SetScale(int nScalar)
{
	this->nScalar = nScalar;
}

void CSphere::SetRotation(double Alpha, double Beta)
{
	this->Alpha = Alpha;
	this->Beta = Beta;
}

void CSphere::DrawFacet(CDC* pDC, CP3* P, CZBuffer* pZBuffer)
{
	CP3 ScreenPoint[4];
	for (int nPoint = 0; nPoint < 4; nPoint++) {
		ScreenPoint[nPoint] = projection.PerspectiveProjection(P[nPoint]);
		ScreenPoint[nPoint].c = P[nPoint].c;
	}
	line.MoveTo(pDC, ScreenPoint[0], RGB(0, 0, 0));
	line.LineTo(pDC, ScreenPoint[1], RGB(0, 0, 0));
	line.LineTo(pDC, ScreenPoint[2], RGB(0, 0, 0));
	line.LineTo(pDC, ScreenPoint[3], RGB(0, 0, 0));
	line.LineTo(pDC, ScreenPoint[0], RGB(0, 0, 0));
	pZBuffer->SetPoint(ScreenPoint[0], ScreenPoint[2], ScreenPoint[3]);
	pZBuffer->GouraudShade(pDC);
	pZBuffer->SetPoint(ScreenPoint[0], ScreenPoint[1], ScreenPoint[2]);//三角形
	pZBuffer->GouraudShade(pDC);
}

void CSphere::Draw(CDC* pDC, CZBuffer* pZBuffer)
{
	CP3 Point[4],temp;
	CP3 ViewPoint = projection.EyePoint;
	double SphereAlpha0, SphereAlpha1, SphereBeta0, SphereBeta1;
	int deltAlpha = 5, deltBeta = 5;
	for (int i = 0; i < 180; i += deltAlpha) {
		SphereAlpha0 = i * PI / 180;
		SphereAlpha1 = (i + deltAlpha) * PI / 180;
		for (int j = 0; j < 360; j += deltBeta) {
			SphereBeta0 = j * PI / 180;
			SphereBeta1 = (j + deltBeta) * PI / 180;
			Point[0].x = sin(SphereAlpha0) * sin(SphereBeta0);
			Point[0].y = cos(SphereAlpha0);
			Point[0].z = sin(SphereAlpha0) * cos(SphereBeta0);
			Point[0].c = CRGB(255, 0, 0);
			
			Point[1].x = sin(SphereAlpha0) * sin(SphereBeta1);
			Point[1].y = cos(SphereAlpha0);
			Point[1].z = sin(SphereAlpha0) * cos(SphereBeta1);
			Point[1].c = CRGB(0, 255, 0);

			Point[2].x = sin(SphereAlpha1) * sin(SphereBeta1);
			Point[2].y = cos(SphereAlpha1);
			Point[2].z = sin(SphereAlpha1) * cos(SphereBeta1);
			Point[2].c = CRGB(0, 0, 255);

			Point[3].x = sin(SphereAlpha1) * sin(SphereBeta0);
			Point[3].y = cos(SphereAlpha1);
			Point[3].z = sin(SphereAlpha1) * cos(SphereBeta0);
			Point[3].c = CRGB(150, 150, 150);

			transform.SetMatrix(Point, 4);
			transform.Scale(nScalar);
			transform.RotateX(Alpha);
			transform.RotateY(Beta);
			for (int i = 0; i < 4; i++) {
				quardrP[i] = Point[i];
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
			if (DotProduct(ViewVector, FacetNormal) >= 0)
			{
				DrawFacet(pDC, Point, pZBuffer);
			}
		}
	}
}
