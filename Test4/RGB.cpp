#include "pch.h"
#include "RGB.h"

CRGB::CRGB(void)
{
	red = 1.0;
	green = 1.0;
	blue = 1.0;
}
CRGB::CRGB(double red, double green, double blue)//���ع��캯��
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

CRGB::~CRGB(void)
{
}

CRGB operator +(const CRGB& c1, const CRGB& c2)//"+"���������
{
	CRGB color;
	color.red = c1.red + c2.red;
	color.green = c1.green + c2.green;
	color.blue = c1.blue + c2.blue;
	return color;
}

CRGB operator -(const CRGB& c1, const CRGB& c2)//"-"���������
{
	CRGB color;
	color.red = c1.red - c2.red;
	color.green = c1.green - c2.green;
	color.blue = c1.blue - c2.blue;
	return color;
}

CRGB operator *(const CRGB& c1, const CRGB& c2)//"*"���������
{
	CRGB color;
	color.red = c1.red * c2.red;
	color.green = c1.green * c2.green;
	color.blue = c1.blue * c2.blue;
	return color;
}

CRGB operator *(const CRGB& c1, double scalar)//"*"���������
{
	CRGB color;
	color.red = scalar * c1.red;
	color.green = scalar * c1.green;
	color.blue = scalar * c1.blue;
	return color;
}

CRGB operator *(double scalar, const CRGB& c1)//"*"���������
{
	CRGB color;
	color.red = scalar * c1.red;
	color.green = scalar * c1.green;
	color.blue = scalar * c1.blue;
	return color;
}

CRGB operator /(const CRGB& c1, double scalar)//"/"���������
{
	CRGB color;
	color.red = c1.red / scalar;
	color.green = c1.green / scalar;
	color.blue = c1.blue / scalar;
	return color;
}

CRGB operator +=(CRGB& c1, CRGB& c2)//"+="���������
{
	c1.red += c2.red;
	c1.green += c2.green;
	c1.blue += c2.blue;
	return c1;
}

CRGB operator -=(CRGB& c1, CRGB& c2)//"-="���������
{
	c1.red -= c2.red;
	c1.green -= c2.green;
	c1.blue -= c2.blue;
	return c1;
}

CRGB operator *=(CRGB& c1, CRGB& c2)//"*="���������
{
	c1.red *= c2.red;
	c1.green *= c2.green;
	c1.blue *= c2.blue;
	return c1;
}

CRGB operator /=(CRGB& c1, double scalar)//"/="���������
{
	if (fabs(scalar) < 1e-4)
		scalar = 1.0;
	c1.red /= scalar;
	c1.green /= scalar;
	c1.blue /= scalar;
	return c1;
}

void CRGB::Normalize()//��һ��
{
	red = (red < 0.0) ? 0.0 : ((red > 1.0) ? 1.0 : red);
	green = (green < 0.0) ? 0.0 : ((green > 1.0) ? 1.0 : green);
	blue = (blue < 0.0) ? 0.0 : ((blue > 1.0) ? 1.0 : blue);
}