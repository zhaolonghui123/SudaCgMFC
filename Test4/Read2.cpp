#include "pch.h"
#include "Read2.h"
using namespace std;
CRead2::CRead2(void)
{
	projection.InitialParameter();
}

CRead2::~CRead2(void)
{
}

void CRead2::ReadPoint(void)
{
	string name = "1.txt";
	int i_1 = 0;
	int i_2 = 0;
	ifstream ifs;
	ifs.open(name, ios::in);
	string buf;
	double x;
	while (getline(ifs, buf))
	{
		stringstream ss(buf);
		if (i_1 < 19231)
		{

			while (ss >> x)
			{//每一行包含不同个数的数字
				if (i_2 == 0) {
					P[i_1].x = x;
					i_2++;
				}
				else if (i_2 == 1) {
					P[i_1].y = x;
					i_2++;
				}
				else {
					P[i_1].z = x;
					i_2 = 0;
				}
			}
			if (i_1 % 3 == 0) {
				P[i_1].c = CRGB(255, 0, 0);
			}
			else if (i_1 % 3 == 1) {
				P[i_1].c = CRGB(0, 255, 0);
			}
			else {
				P[i_1].c = CRGB(0, 0, 255);
			}
			
			i_1++;
		}
		else
		{
			break;
		}
	}
	ifs.close();
}

void CRead2::ReadFacet(void)
{
	string name = "1.txt";
	int i_1 = 0;
	int i_2 = 0;
	ifstream ifs;
	ifs.open(name, ios::in);
	string buf;
	double x;
	double index;
	while (getline(ifs, buf))
	{
		stringstream ss(buf);
		if (i_1 >= 19231 && i_1 < 57619)
		{

			while (ss >> x)
			{//每一行包含不同个数的数字
				if (i_2 == 0)
				{
					index = x;
					i_2++;
				}
				else if (i_2 == 1)
				{
					F[i_1 - 19231].Index[0] = x;
					i_2++;
				}
				else if (i_2 == 2)
				{
					F[i_1 - 19231].Index[1] = x;
					i_2++;
				}
				else {
					F[i_1 - 19231].Index[2] = x;
					i_2 = 0;
				}
			}
			i_1++;
		}
		else if (i_1 < 19231) {
			i_1++;
		}
		else
		{
			break;
		}
	}
	ifs.close();
}

CP3* CRead2::GetVertexArrayName(void)
{
	return P;
}

void CRead2::Draw(CDC* pDC, CZBuffer* pZBuffer)
{
	CP3 ScreenPoint[4], temp;
	CP3 ViewPoint = projection.EyePoint;
	for (int nFacet = 0; nFacet < 38388; nFacet++)
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
	for (int nFacet = 0; nFacet < 38388; nFacet++)//面循环
	{
		for (int nPoint = 0; nPoint < 3; nPoint++)
			ScreenPoint[nPoint] = projection.PerspectiveProjection(P[F[nFacet].Index[nPoint]]);
		pZBuffer->SetPoint(ScreenPoint[0], ScreenPoint[1], ScreenPoint[2]);//三角形
		pZBuffer->GouraudShade(pDC);

	}
}

void CRead2::Draw2(CDC* pDC, CZBuffer* pZBuffer)
{
	CP3 ScreenPoint[4], temp;
	CP3 ViewPoint = projection.EyePoint;
	for (int nFacet = 0; nFacet < 38388; nFacet++)
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
		}
	}
	for (int nFacet = 0; nFacet < 38388; nFacet++)//面循环
	{
		for (int nPoint = 0; nPoint < 3; nPoint++)
			ScreenPoint[nPoint] = projection.PerspectiveProjection(P[F[nFacet].Index[nPoint]]);
		pZBuffer->SetPoint(ScreenPoint[0], ScreenPoint[1], ScreenPoint[2]);//三角形
		pZBuffer->GouraudShade(pDC);

	}
}
