#pragma once
#include "P2.h"
#include<math.h>
class CTransform2
{
public:
	CTransform2(void);
	virtual ~CTransform2(void);
	void SetMatrix(CP2* P, int ptNumber);//���ö�ά��������
	void Identity(void);//��λ����
	void Translate(double tx, double ty);//ƽ��
	void Scale(double sx, double sy);//����
	void Scale(double sx, double sy, CP2 p);//����������ı����任
	void Rotate(double beta);//��ת
	void Rotate(double beta, CP2 p);//������������ת
	void ReflectOrg(void);//����ԭ�㷴��
	void ReflectX(void);
	void ReflectY(void);
	void Shear(double b, double c);//����
	void MultiplyMatrix(void);//����˷�
private:
	double T[3][3];
	CP2* P;
	int ptNumber;
};

