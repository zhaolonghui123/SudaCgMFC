#pragma once
#include"Point3.h"
#include "P3.h"
#include "Vector.h"

class CZBuffer
{
public:
	CZBuffer(void);
	virtual ~CZBuffer(void);
	void SetPoint(CP3 P0, CP3 P1, CP3 P2);
	//void FillTriangle(CDC* pDC);//���������
	void GouraudShade(CDC* pDC);//�⻬��ɫ
	void DDA(CPoint2 PStart, CPoint2 PEnd, BOOL bFeature);//��߱��
	void InitialDepthBuffer(int nWidth, int nHeight, double zDepth);//��ʼ����Ȼ�����
	CRGB LinearInterp(double t, double tStart, double tEnd, CRGB iStart, CRGB cEnd);//��ɫ���Բ�ֵ
	void SortVertex(void);//��������
public:
	CP3 P0, P1, P2;//�����εĸ�������
	CPoint3 point0, point1, point2;//�����ε�������������
	CPoint2* SpanLeft; //��ȵ���������־
	CPoint2* SpanRight;//��ȵ��յ������־
	int nIndex;//��¼ɨ��������
	double** zBuffer;//��Ȼ�����
	int nWidth, nHeight;//�����������߶�
};

