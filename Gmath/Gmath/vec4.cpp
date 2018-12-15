#include "vec4.h"
vec4::vec4()
{
	xpos = 0, ypos = 0, zpos = 0, wpos = 0;
}

vec4::vec4(float x, float y, float z,float w)
{
	xpos = x;
	ypos = y;
	zpos = z;
	wpos = w;
}

vec4 vec4::operator+(const vec4 & rhs) const
{
	vec4 vec;
	vec.xpos = xpos + rhs.xpos;
	vec.ypos = ypos + rhs.ypos;
	vec.zpos = zpos + rhs.zpos;
	vec.wpos = wpos + rhs.wpos;

	return vec;
}

vec4 vec4::operator-(const vec4 & rhs) const
{
	vec4 vec;
	vec.xpos = xpos - rhs.xpos;
	vec.ypos = ypos - rhs.ypos;
	vec.zpos = zpos - rhs.zpos;
	vec.wpos = wpos - rhs.wpos;

	return vec;
}

vec4 & vec4::operator+=(const vec4 & rhs)
{

	xpos += rhs.xpos;
	ypos += rhs.ypos;
	zpos += rhs.zpos;
	wpos += rhs.wpos;

	return *this;
}

vec4 & vec4::operator-=(const vec4 & rhs)
{

	xpos -= rhs.xpos;
	ypos -= rhs.ypos;
	zpos -= rhs.zpos;
	wpos -= rhs.wpos;

	return *this;
}

bool vec4::operator==(const vec4 & rhs) const
{
	return ((xpos >= (rhs.xpos - FLT_EPSILON) && xpos <= (rhs.xpos + FLT_EPSILON)) &&
		  (ypos >= (rhs.ypos - FLT_EPSILON) && ypos <= (rhs.ypos + FLT_EPSILON)) &&
		 (zpos >= (rhs.zpos - FLT_EPSILON) && zpos <= (rhs.zpos + FLT_EPSILON)) &&
	    (wpos >= (rhs.wpos - FLT_EPSILON) && wpos <= (rhs.wpos + FLT_EPSILON)));

}

bool vec4::operator!=(const vec4 & rhs) const
{
	return !((xpos >= (rhs.xpos - FLT_EPSILON) && xpos <= (rhs.xpos + FLT_EPSILON)) &&
		   (ypos >= (rhs.ypos - FLT_EPSILON) && ypos <= (rhs.ypos + FLT_EPSILON)) &&
		  (zpos >= (rhs.zpos - FLT_EPSILON) && zpos <= (rhs.zpos + FLT_EPSILON)) &&
		 (wpos >= (rhs.wpos - FLT_EPSILON) && wpos <= (rhs.wpos + FLT_EPSILON)));
}

vec4 vec4::operator-() const
{
	vec4 vec;
	vec.xpos = -xpos;
	vec.ypos = -ypos;
	vec.zpos = -zpos;
	vec.wpos = -wpos;
	return vec;
}

float vec4::magnitude() const
{
	float magnitude = (xpos * xpos + ypos * ypos + zpos * zpos + wpos * wpos);

	sqrt(magnitude);

	return magnitude;
}

vec4 & vec4::normalize()
{
	float mag = magnitude();
	xpos /= mag;
	ypos /= mag;
	zpos /= mag;
	wpos /= mag;
	return *this;
}

vec4 vec4::getNormalized() const
{
	vec4 normal;
	float mag = normal.magnitude();
	std::cout << mag << std::endl;
	normal.xpos = xpos / mag;
	normal.ypos = ypos / mag;
	normal.zpos = zpos / mag;
	normal.wpos = wpos / mag;
	return normal;
}

vec4 & vec4::scale(const vec4 & rhs)
{

	xpos = xpos * rhs.xpos;
	ypos = ypos * rhs.ypos;
	zpos = zpos * rhs.zpos;
	wpos = wpos * rhs.wpos;
	return *this;
}

vec4 vec4::getScaled(const vec4 & rhs) const
{
	vec4 scaled{ xpos, ypos, zpos, wpos };
	scaled.xpos = scaled.xpos * rhs.xpos;
	scaled.ypos = scaled.ypos * rhs.ypos;
	scaled.zpos = scaled.zpos * rhs.zpos;
	scaled.wpos = scaled.wpos * rhs.wpos;
	return scaled;
}

vec4 vec4::operator*(const float rhs) const
{
	vec4 times;
	times.xpos = xpos * rhs;
	times.ypos = ypos * rhs;
	times.zpos = zpos * rhs;
	times.wpos = wpos * rhs;
	return times;
}

vec4 & vec4::operator*=(const float rhs)
{
	xpos *= rhs;
	ypos *= rhs;
	zpos *= rhs;
	wpos *= rhs;
	return *this;
}

vec4 & vec4::operator/=(const float rhs)
{
	xpos /= rhs;
	ypos /= rhs;
	zpos /= rhs;
	wpos /= rhs;
	return *this;
}

float vec4::dot(const vec4 & rhs) const
{
	
		return ((xpos * rhs.xpos) + (ypos * rhs.ypos) + (zpos * rhs.zpos) + (wpos * rhs.wpos));
	
}

vec4 vec4::cross(const vec4 & rhs) const
{
	return vec4{
				(ypos * rhs.zpos) - (zpos * rhs.ypos),
				  (zpos * rhs.xpos) - (xpos * rhs.zpos),
				   (xpos * rhs.ypos) - (ypos * rhs.xpos),0 };
}

vec4 operator*(const float lhs, const vec4 & rhs)
{
	vec4 bob;
	bob.xpos = lhs * rhs.xpos;
	bob.ypos = lhs * rhs.ypos;
	bob.zpos = lhs * rhs.zpos;
	bob.wpos = lhs * rhs.wpos;
	return bob;
}
