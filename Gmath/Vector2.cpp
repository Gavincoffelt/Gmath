#include "Vector2.h"

vec2::vec2()
{
	xpos = 0;
	ypos = 0;
}

vec2::vec2(float x, float y)
{
	this->xpos = x;
	this->ypos = y;
}

vec2 vec2::operator+(const vec2 & rhs) const
{
	vec2 vec;
	vec.xpos = xpos + rhs.xpos;
	vec.ypos = ypos + rhs.ypos;

	return vec;
}

vec2 vec2::operator-(const vec2 & rhs) const
{
	vec2 vec;
	vec.xpos = xpos + rhs.xpos;
	vec.ypos = ypos + rhs.ypos;


	return vec;
}

vec2 & vec2::operator+=(const vec2 & rhs)
{
	xpos += rhs.xpos;
	ypos += rhs.ypos;

	return *this;
}

vec2 & vec2::operator-=(const vec2 & rhs)
{

	xpos -= rhs.xpos;
	ypos -= rhs.ypos;

	return *this;
}

bool vec2::operator==(const vec2 & rhs) const
{
	return ((xpos >= (rhs.xpos - FLT_EPSILON) && xpos <= (rhs.xpos + FLT_EPSILON)) &&
		(ypos >= (rhs.ypos - FLT_EPSILON) && ypos <= (rhs.ypos + FLT_EPSILON)));
	
}

bool vec2::operator!=(const vec2 & rhs) const
{
	return !((xpos >= (rhs.xpos - FLT_EPSILON) && xpos <= (rhs.xpos + FLT_EPSILON)) &&
		(ypos >= (rhs.ypos - FLT_EPSILON) && ypos <= (rhs.ypos + FLT_EPSILON)));
	

}

vec2 vec2::operator-() const
{
	vec2 vec;
	vec.xpos = -xpos;
	vec.ypos = -ypos;
	return vec;
}

float vec2::magnitude() const
{
	float magnitude = (xpos * xpos + ypos * ypos);
	
	sqrt(magnitude);

	return magnitude;
}

float vec2::dot(const vec2 & rhs) const
{
	return ((xpos * rhs.xpos) + (ypos * rhs.ypos));
}

vec2 & vec2::normalize()
{
	float mag = magnitude();
	xpos /= mag;
	ypos /= mag;
	return *this;
}

vec2 vec2::getNormalized() const
{	
	vec2 normal;
	float mag = normal.magnitude();
	std::cout << mag << std::endl;
	normal.xpos = xpos / mag;
	normal.ypos = ypos / mag;
	return normal;
}

vec2 & vec2::scale(const vec2 & rhs)
{
	xpos = xpos * rhs.xpos;
	ypos = ypos * rhs.ypos;
	return *this;
}

vec2 vec2::getScaled(const vec2 & rhs) const
{
	vec2 scaled{ xpos, ypos };
	scaled.xpos = scaled.xpos * rhs.xpos;
	scaled.ypos = scaled.ypos * rhs.ypos;
	return scaled;
}

vec2 vec2::operator*(const float rhs) const
{
	vec2 times;
	times.xpos = xpos * rhs;
	times.ypos = ypos * rhs;
	return times;
}

vec2 & vec2::operator*=(const float rhs)
{
	xpos *= rhs;
	ypos *= rhs;
	return *this;
}

vec2 & vec2::operator/=(const float rhs)
{
	
	 xpos /= rhs;
	 ypos /= rhs;
	 return *this;
}

vec2 operator*(const float lhs, const vec2 & rhs)
{
	vec2 bob;
	bob.xpos = lhs * rhs.xpos;
	bob.ypos = lhs * rhs.ypos;
	return bob;
}
