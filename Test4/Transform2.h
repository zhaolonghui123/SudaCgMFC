#pragma once
#include "P2.h"
#include<math.h>
class CTransform2
{
public:
	CTransform2(void);
	virtual ~CTransform2(void);
	void SetMatrix(CP2* P, int ptNumber);//设置二维顶点数组
	void Identity(void);//单位矩阵
	void Translate(double tx, double ty);//平移
	void Scale(double sx, double sy);//放缩
	void Scale(double sx, double sy, CP2 p);//相对于任意点的比例变换
	void Rotate(double beta);//旋转
	void Rotate(double beta, CP2 p);//相对于任意点旋转
	void ReflectOrg(void);//关于原点反射
	void ReflectX(void);
	void ReflectY(void);
	void Shear(double b, double c);//错切
	void MultiplyMatrix(void);//矩阵乘法
private:
	double T[3][3];
	CP2* P;
	int ptNumber;
};

