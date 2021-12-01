#pragma once
class CRGB
{
public:
	CRGB(void);
	CRGB(double red, double green, double blue);
	~CRGB(void);
	friend CRGB operator+(const CRGB& c1, const CRGB& c2);//���������
	friend CRGB operator-(const CRGB& c1, const CRGB& c2);
	friend CRGB operator*(const CRGB& c1, const CRGB& c2);
	friend CRGB operator*(const CRGB& c1, double scalar);
	friend CRGB operator*(double scalar, const CRGB& c);
	friend CRGB operator/(const CRGB& c1, double scalar);
	friend CRGB operator+=(CRGB& c1, CRGB& c2);
	friend CRGB operator-=(CRGB& c1, CRGB& c2);
	friend CRGB operator*=(CRGB& c1, CRGB& c2);
	friend CRGB operator/=(CRGB& c1, double scalar);
	void   Normalize();	//��ɫ������һ����[0,1]����
public:
	double red;//��ɫ����
	double green;//��ɫ����
	double blue;//��ɫ����
};


