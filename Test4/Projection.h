#pragma once
#include"P3.h"
#include<math.h>
#define PI 3.141659265
class CProjection
{
public:
	CProjection(void);
	virtual ~CProjection(void);
	void SetEye(double R);
	void SetEye(double Phi, double Psi, double R, double d);
	void SetEye(double Phi, double Psi, double R);
	void SetEye(double Phi, double Psi);
	void InitialParameter(void);
	CP3 OrthogonalProjection(CP3 WorldPoint);
	CP3 ObliqueProjection(CP3 WorldPoint);
	CP3 PerspectiveProjection(CP3 WorldPoint);
public:
	CP3 EyePoint;
private:
	double k[8];
	double R, d, Phi, Psi;
};

