#pragma once
#include"P3.h"
#include<math.h>
class CVector
{
public:
	CVector(void);
	virtual ~CVector(void);
	CVector(double x, double y, double z);
	CVector(const CP3& p);
	CVector(const CP3& p0,const CP3& p1);
	double Magnitide(void);//计算向量的模
	CVector Normalize(void);//归一化向量
	friend CVector operator + (const CVector& v0, const CVector& v1);
	friend CVector operator - (const CVector& v0, const CVector& v1);
	friend CVector operator * (const CVector& v, double scalar);
	friend CVector operator * (double scalar, const CVector& v);
	friend CVector operator / (const CVector& v0, double scalar);
	friend double DotProduct(const CVector& v0, const CVector& v1);//点积
	friend CVector CrossProduct (const CVector& v0, const CVector& v1);//叉积
public:
	double x, y, z;
};

