#pragma once
#include"P3.h"
#define PI 3.14159265
#include<math.h>
class CTransform3
{
public:
	CTransform3(void);
	virtual ~CTransform3(void);
	void SetMatrix(CP3* P, int ptNumber);//���ö�ά��������
	void Identity(void);//��λ����
	void Translate(double tx, double ty, double tz);//ƽ��
	void Scale(double sx, double sy, double sz);//����
	void Scale(double sx, double sy, double sz, CP3 p);//����������ı����任
	void Scale(double s);//��������
	void Scale(double s,CP3 p);//��������
	void RotateX(double beta);//��X����ת
	void RotateY(double beta);//��Y����ת
	void RotateZ(double beta);//��Z����ת
	void RotateX(double beta, CP3 p);//������������ת
	void RotateY(double beta, CP3 p);//������������ת
	void RotateZ(double beta, CP3 p);//������������ת
	void ReflectX(void);
	void ReflectY(void);
	void ReflectZ(void);
	void ReflectXOY(void);
	void ReflectYOZ(void);
	void ReflectZOX(void);
	void ShearX(double b, double c);//����
	void ShearY(double d, double f);//����
	void ShearZ(double g, double h);//����
	void MultiplyMatrix(void);//����˷�
private:
	double M[4][4];
	CP3* P;
	int ptNumber;
};

