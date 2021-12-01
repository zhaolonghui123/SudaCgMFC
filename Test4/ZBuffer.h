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
	//void FillTriangle(CDC* pDC);//填充三角形
	void GouraudShade(CDC* pDC);//光滑着色
	void DDA(CPoint2 PStart, CPoint2 PEnd, BOOL bFeature);//打边标记
	void InitialDepthBuffer(int nWidth, int nHeight, double zDepth);//初始化深度缓冲器
	CRGB LinearInterp(double t, double tStart, double tEnd, CRGB iStart, CRGB cEnd);//颜色线性插值
	void SortVertex(void);//顶点排序
public:
	CP3 P0, P1, P2;//三角形的浮点坐标
	CPoint3 point0, point1, point2;//三角形的整数顶点坐标
	CPoint2* SpanLeft; //跨度的起点数组标志
	CPoint2* SpanRight;//跨度的终点数组标志
	int nIndex;//记录扫描线条数
	double** zBuffer;//深度缓冲器
	int nWidth, nHeight;//缓冲区宽度与高度
};

