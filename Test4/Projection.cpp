#include "pch.h"
#include "Projection.h"

CProjection::CProjection(void)
{
	R = 1200, d = 800;
	Phi = 90.0, Psi = 0.0;
	InitialParameter();
}

CProjection::~CProjection(void)
{
}

void CProjection::SetEye(double R)
{
	EyePoint.z = R;
}

void CProjection::SetEye(double Phi, double Psi, double R, double d)
{
	this->Phi = Phi;
	this->Psi = Psi;
	this->R = R;
	this->d = d;
}

void CProjection::SetEye(double Phi, double Psi, double R)
{
	this->Phi = Phi;
	this->Psi = Psi;
	this->R = R;
}

void CProjection::SetEye(double Phi, double Psi)
{
	this->Phi = Phi;
	this->Psi = Psi;
}

void CProjection::InitialParameter(void)
{
	k[0] = sin(PI * Phi / 180);
	k[1] = cos(PI * Phi / 180);
	k[2] = sin(PI * Psi / 180);
	k[3] = cos(PI * Psi / 180);
	k[4] = k[0] * k[2];
	k[5] = k[0] * k[3];
	k[6] = k[1] * k[2];
	k[7] = k[1] * k[3];
	EyePoint.x = k[4] * R;
	EyePoint.y = k[1] * R;
	EyePoint.z = k[5] * R;

}

CP3 CProjection::OrthogonalProjection(CP3 WorldPoint)
{
	CP3 ScreenPoint;//屏幕坐标系三维点
	ScreenPoint.x = WorldPoint.x;
	ScreenPoint.y = WorldPoint.y;
	ScreenPoint.z = -WorldPoint.z;
	ScreenPoint.c = WorldPoint.c;
	return ScreenPoint;
}

CP3 CProjection::ObliqueProjection(CP3 WorldPoint)
{
	CP3 ScreenPoint;
	double Cota = 0.5;
	double Beta = PI / 4;
	ScreenPoint.x = WorldPoint.x - WorldPoint.z * Cota * cos(Beta);
	ScreenPoint.y = WorldPoint.y - WorldPoint.z * Cota * cos(Beta);
	ScreenPoint.z = WorldPoint.y - WorldPoint.z * Cota * cos(Beta);
	ScreenPoint.c = WorldPoint.c;
	return ScreenPoint;
}

CP3 CProjection::PerspectiveProjection(CP3 WorldPoint)
{
	CP3 ViewPoint;//观察坐标系三维点
	ViewPoint.x = k[3] * WorldPoint.x - k[2] * WorldPoint.z;
	ViewPoint.y = -k[6] * WorldPoint.x + k[0] * WorldPoint.y - k[7] * WorldPoint.z;
	ViewPoint.z = -k[4] * WorldPoint.x - k[1] * WorldPoint.y - k[5] * WorldPoint.z + R;
	ViewPoint.c = WorldPoint.c;
	CP3 ScreenPoint;//屏幕坐标系三维点
	ScreenPoint.x = d * ViewPoint.x / ViewPoint.z;
	ScreenPoint.y = d * ViewPoint.y / ViewPoint.z;
	ScreenPoint.z = (ViewPoint.z - d) * d / ViewPoint.z;//Bouknight公式;
	ScreenPoint.c = ViewPoint.c;
	return ScreenPoint;
}
