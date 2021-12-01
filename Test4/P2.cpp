#include "pch.h"
#include "P2.h"

CP2::CP2(void)
{
	x = 0.0;
	y = 0.0;
	w = 1.0;
	c = CRGB(0, 0, 0);
}

CP2::~CP2(void)
{
}

CP2::CP2(double x, double y)
{
	this->x = x;
	this->y = y;
	this->w = 1.0;
	c = CRGB(0, 0, 0);
}

CP2::CP2(double x, double y, CRGB c)
{
	this->x = x;
	this->y = y;
	this->c = c;
}

CP2 operator+(const CP2& p0, const CP2& p1)
{
	CP2 temp;
	temp.x = p0.x + p1.x;
	temp.y = p0.y + p1.y;
	temp.w = p0.w + p1.w;
	return temp;
}

CP2 operator-(const CP2& p0, const CP2& p1)
{
	CP2 temp;
	temp.x = p0.x - p1.x;
	temp.y = p0.y - p1.y;
	temp.w = p0.w - p1.w;
	return temp;
}

CP2 operator*(const CP2& p, double scalar)
{
	CP2 temp;
	temp.x = p.x * scalar;
	temp.y = p.y * scalar;
	temp.w = p.w * scalar;
	return temp;
}

CP2 operator*(double scalar, const CP2& p)
{
	CP2 temp;
	temp.x = scalar * p.x;
	temp.y = scalar * p.y;
	temp.w = scalar * p.w;
	return temp;
}

CP2 operator/(const CP2& p, double scalar)
{
	CP2 temp;
	temp.x = p.x / scalar;
	temp.y = p.y / scalar;
	temp.w = p.w / scalar;
	return temp;
}

CP2 operator+=(CP2& p0, CP2& p1)
{
	CP2 temp;
	temp.x = p0.x + p1.x;
	temp.y = p0.y + p1.y;
	temp.w = p0.w + p1.w;
	return temp;
}

CP2 operator-=(CP2& p0, CP2& p1)
{
	CP2 temp;
	temp.x = p0.x - p1.x;
	temp.y = p0.y - p1.y;
	temp.w = p0.w - p1.w;
	return temp;
	return CP2();
}

CP2 operator*=(CP2& p0, double scalar)
{
	CP2 temp;
	temp.x = p0.x * scalar;
	temp.y = p0.y * scalar;
	temp.w = p0.w * scalar;
	return temp;
}

CP2 operator/=(CP2& p0, double scalar)
{
	CP2 temp;
	temp.x = p0.x / scalar;
	temp.y = p0.y / scalar;
	temp.w = p0.w / scalar;
	return temp;
}
