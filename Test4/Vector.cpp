#include "pch.h"
#include "Vector.h"

CVector::CVector(void)
{
	x = 0.0, y = 0.0, z = 1.0;
}

CVector::~CVector(void)
{
}

CVector::CVector(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

CVector::CVector(const CP3& p)
{
	x = p.x;
	y = p.y;
	z = p.z;
}

CVector::CVector(const CP3& p0, const CP3& p1)
{
	x = p1.x - p0.x;
	y = p1.y - p0.y;
	z = p1.z - p0.z;
}

double CVector::Magnitide(void)
{
	return sqrt(x * x + y * y + z * z);
}

CVector CVector::Normalize(void)
{
	CVector vector;
	double magnitude = sqrt(x * x + y * y + z * z);
	if (fabs(magnitude) < 1e-4) {
		magnitude = 1.0;
	}
	vector.x = x / magnitude;
	vector.y = y / magnitude;
	vector.z = z / magnitude;
	return vector;
}

CVector operator+(const CVector& v0, const CVector& v1)
{
	CVector vector;
	vector.x = v1.x + v0.x;
	vector.y = v1.y + v0.y;
	vector.z = v1.z + v0.z;
	return vector;
}

CVector operator-(const CVector& v0, const CVector& v1)
{
	CVector vector;
	vector.x = v1.x - v0.x;
	vector.y = v1.y - v0.y;
	vector.z = v1.z - v0.z;
	return vector;
}

CVector operator*(const CVector& v, double scalar)
{
	CVector vector;
	vector.x = v.x * scalar;
	vector.y = v.y * scalar;
	vector.z = v.z * scalar;
	return vector;
}

CVector operator*(double scalar, const CVector& v)
{
	CVector vector;
	vector.x = v.x * scalar;
	vector.y = v.y * scalar;
	vector.z = v.z * scalar;
	return vector;
}

CVector operator/(const CVector& v0, double scalar)
{
	CVector vector;
	vector.x = v0.x / scalar;
	vector.y = v0.y / scalar;
	vector.z = v0.z / scalar;
	return vector;
}

double DotProduct(const CVector& v0, const CVector& v1)
{
	return (v0.x * v1.x + v0.y * v1.y + v0.z * v1.z);
}

CVector CrossProduct(const CVector& v0, const CVector& v1)
{
	CVector vector;
	vector.x = v0.y * v1.z - v0.z * v1.y;
	vector.y = v0.z * v1.x - v0.x * v1.z;
	vector.z = v0.x * v1.y - v0.y * v1.x;
	return vector;
}
