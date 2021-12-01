#include "pch.h"
#include "ZBuffer.h"
#define ROUND(d) int(d + 0.5)

CZBuffer::CZBuffer(void)
{
}


CZBuffer::~CZBuffer(void)
{
	for (int i = 0; i < nWidth; i++)
	{
		delete[] zBuffer[i];
		zBuffer[i] = NULL;
	}
	if (zBuffer != NULL)
	{
		delete zBuffer;
		zBuffer = NULL;
	}
}

void CZBuffer::SetPoint(CP3 P0, CP3 P1, CP3 P2)
{
	this->P0 = P0;
	this->P1 = P1;
	this->P2 = P2;
	point0.x = ROUND(P0.x);
	point0.y = ROUND(P0.y);
	point0.z = P0.z;
	point0.c = P0.c;
	point1.x = ROUND(P1.x);
	point1.y = ROUND(P1.y);
	point1.z = P1.z;
	point1.c = P1.c;
	point2.x = ROUND(P2.x);
	point2.y = ROUND(P2.y);
	point2.z = P2.z;
	point2.c = P2.c;
}



void CZBuffer::GouraudShade(CDC* pDC)
{
	SortVertex();//point0��Ϊy������С�ĵ�,point1��Ϊy�������ĵ�,point2���y����λ�ڶ���֮�䡣���yֵ��ͬ��ȡx��С�ĵ�
	//���������θ��ǵ�ɨ��������
	int nTotalScanLine = point1.y - point0.y + 1;
	//����span��������յ�����
	SpanLeft = new CPoint2[nTotalScanLine];//�����������
	SpanRight = new CPoint2[nTotalScanLine];//����ұ�����

	//�ж���������P0P1�ߵ�λ�ù�ϵ��0-1-2Ϊ����ϵ
	int nDeltz = (point1.x - point0.x) * (point2.y - point1.y) - (point1.y - point0.y) * (point2.x - point1.x);//��ʸ�������z����
	if (nDeltz > 0)//������λ��P0P1�ߵ����
	{
		nIndex = 0;
		DDA(point0, point2, TRUE);
		DDA(point2, point1, TRUE);
		nIndex = 0;
		DDA(point0, point1, FALSE);
	}
	else//������λ��P0P1�ߵ��Ҳ�
	{
		nIndex = 0;
		DDA(point0, point1, TRUE);
		nIndex = 0;
		DDA(point0, point2, FALSE);
		DDA(point2, point1, FALSE);
	}
	double	CurrentDepth = 0.0;//��ǰɨ���ߵ����
	CVector Vector01(P0, P1), Vector02(P0, P2);
	CVector fNormal = CrossProduct(Vector01, Vector02);
	double A = fNormal.x, B = fNormal.y, C = fNormal.z;//ƽ�淽��Ax+By+Cz��D=0��ϵ��
	double D = -A * point0.x - B * point0.y - C * point0.z;//��ǰɨ��������x��������Ȳ���
	if (fabs(C) < 1e-4)
		C = 1.0;
	double DepthStep = -A / C;//��Ȳ���
	for (int y = point0.y; y < point1.y; y++)//�±��Ͽ�
	{
		int n = y - point0.y;
		BOOL bInFlag = FALSE;//���������Ա�־����ʼֵΪ�ٱ�ʾ�������ⲿ
		for (int x = SpanLeft[n].x; x < SpanRight[n].x; x++)//����ҿ�
		{
			if (bInFlag == FALSE)
			{
				CurrentDepth = -(A * x + B * y + D) / C;//z=-(Ax+By+D)/C
				bInFlag = TRUE;
				x -= 1;
			}
			else
			{
				CRGB clr = LinearInterp(x, SpanLeft[n].x, SpanRight[n].x, SpanLeft[n].c, SpanRight[n].c);
				if (CurrentDepth <= zBuffer[x + nWidth / 2][y + nHeight / 2])//�����ǰ����������С��֡��������ԭ����������)
				{
					zBuffer[x + nWidth / 2][y + nHeight / 2] = CurrentDepth;//ʹ�õ�ǰ���������ȸ�����Ȼ�����
					pDC->SetPixelV(x, y, RGB(clr.red * 255, clr.green * 255, clr.blue * 255));
				}
				CurrentDepth += DepthStep;
			}
		}
	}
	if (SpanLeft)
	{
		delete[]SpanLeft;
		SpanLeft = NULL;
	}
	if (SpanRight)
	{
		delete[]SpanRight;
		SpanRight = NULL;
	}
}

void CZBuffer::DDA(CPoint2 PStart, CPoint2 PEnd, BOOL bFeature)
{
	int dx = PEnd.x - PStart.x;
	int dy = PEnd.y - PStart.y;
	double m = double(dx) / dy;
	double x = PStart.x;
	for (int y = PStart.y; y < PEnd.y; y++)
	{
		CRGB crColor = LinearInterp(y, PStart.y, PEnd.y, PStart.c, PEnd.c);
		if (bFeature)
			SpanLeft[nIndex++] = CPoint2(ROUND(x), y, crColor);
		else
			SpanRight[nIndex++] = CPoint2(ROUND(x), y, crColor);
		x += m;
	}
}

CRGB CZBuffer::LinearInterp(double t, double tStart, double tEnd, CRGB iStart, CRGB cEnd)//��ɫ���Բ�ֵ
{
	CRGB color;
	color = (t - tEnd) / (tStart - tEnd) * iStart + (t - tStart) / (tEnd - tStart) * cEnd;
	return color;
}

void CZBuffer::SortVertex()
{
	CPoint3 p[3];
	p[0] = point0;
	p[1] = point1;
	p[2] = point2;
	for (int i = 0; i < 2; ++i)
	{
		int k = i;
		for (int j = i + 1; j < 3; ++j)
		{
			if (p[k].y > p[j].y)
				k = j;
			if (p[k].y == p[j].y)
				if (p[k].x > p[j].x)
					k = j;
		}
		if (k != i)
		{
			CPoint3 pTemp = p[i];
			p[i] = p[k];
			p[k] = pTemp;
		}
	}
	point0 = p[0];
	point1 = p[2];
	point2 = p[1];
}

void CZBuffer::InitialDepthBuffer(int nWidth, int nHeight, double zDepth)//��ʼ����Ȼ���
{
	this->nWidth = nWidth, this->nHeight = nHeight;
	zBuffer = new double* [nWidth];
	for (int i = 0; i < nWidth; i++)
		zBuffer[i] = new double[nHeight];
	for (int i = 0; i < nWidth; i++)//��ʼ����Ȼ���
		for (int j = 0; j < nHeight; j++)
			zBuffer[i][j] = zDepth;
}