#pragma once
#include"P3.h"
#define PI 3.14159265
#include<math.h>
class CTransform3
{
public:
	CTransform3(void);
	virtual ~CTransform3(void);
	void SetMatrix(CP3* P, int ptNumber);//设置二维顶点数组
	void Identity(void);//单位矩阵
	void Translate(double tx, double ty, double tz);//平移
	void Scale(double sx, double sy, double sz);//放缩
	void Scale(double sx, double sy, double sz, CP3 p);//相对于任意点的比例变换
	void Scale(double s);//整体缩放
	void Scale(double s,CP3 p);//整体缩放
	void RotateX(double beta);//绕X轴旋转
	void RotateY(double beta);//绕Y轴旋转
	void RotateZ(double beta);//绕Z轴旋转
	void RotateX(double beta, CP3 p);//相对于任意点旋转
	void RotateY(double beta, CP3 p);//相对于任意点旋转
	void RotateZ(double beta, CP3 p);//相对于任意点旋转
	void ReflectX(void);
	void ReflectY(void);
	void ReflectZ(void);
	void ReflectXOY(void);
	void ReflectYOZ(void);
	void ReflectZOX(void);
	void ShearX(double b, double c);//错切
	void ShearY(double d, double f);//错切
	void ShearZ(double g, double h);//错切
	void MultiplyMatrix(void);//矩阵乘法
private:
	double M[4][4];
	CP3* P;
	int ptNumber;
};

