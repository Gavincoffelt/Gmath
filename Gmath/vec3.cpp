#include "vec3.h"

vec3::vec3()
{
	xpos = 0, ypos = 0, zpos = 0;
}

vec3::vec3(float x, float y,float z)
{
	xpos = x;
	ypos = y;
	zpos = z;
}

vec3 vec3::operator+(const vec3 & rhs) const
{
	vec3 vec;
	vec.xpos = xpos + rhs.xpos;
	vec.ypos = ypos + rhs.ypos;
	vec.zpos = zpos + rhs.zpos;
	return vec;
}

vec3 vec3::operator-(const vec3 & rhs) const
{
	vec3 vec;
	vec.xpos = xpos - rhs.xpos;
	vec.ypos = ypos - rhs.ypos;
	vec.zpos = zpos - rhs.zpos;
	return vec;
}

vec3 & vec3::operator+=(const vec3 & rhs)
{
	
	xpos += rhs.xpos;
	ypos += rhs.ypos;
	zpos += rhs.zpos;
	return *this;
}

vec3 & vec3::operator-=(const vec3 & rhs)
{
	
	xpos -= rhs.xpos;
	ypos -= rhs.ypos;
	zpos -= rhs.zpos;
	return *this;
}

bool vec3::operator==(const vec3 & rhs) const
{
	return ((xpos >= (rhs.xpos - FLT_EPSILON) && xpos <= (rhs.xpos + FLT_EPSILON)) &&
		(ypos >= (rhs.ypos - FLT_EPSILON) && ypos <= (rhs.ypos + FLT_EPSILON)) &&
		(zpos >= (rhs.zpos - FLT_EPSILON) && zpos <= (rhs.zpos + FLT_EPSILON)));
	
}

bool vec3::operator!=(const vec3 & rhs) const
{
	return !((xpos >= (rhs.xpos - FLT_EPSILON) && xpos <= (rhs.xpos + FLT_EPSILON)) &&
		(ypos >= (rhs.ypos - FLT_EPSILON) && ypos <= (rhs.ypos + FLT_EPSILON)) &&
		(zpos >= (rhs.zpos - FLT_EPSILON) && zpos <= (rhs.zpos + FLT_EPSILON)));
}

vec3 vec3::operator-() const
{
	vec3 vec;
	vec.xpos = -xpos;
	vec.ypos = -ypos;
	vec.zpos = -zpos;
	return vec;
}

float vec3::magnitude() const
{
	float magnitude = (xpos * xpos + ypos * ypos + zpos * zpos);

	sqrt(magnitude);

	return magnitude;
}

vec3 & vec3::normalize()
{
	float mag = magnitude();
	xpos /= mag;
	ypos /= mag;
	zpos /= mag;
	return *this;
}

vec3 vec3::getNormalized() const
{
	vec3 normal;
	float mag = normal.magnitude();
	std::cout << mag << std::endl;
	normal.xpos = xpos / mag;
	normal.ypos = ypos / mag;
	normal.zpos = zpos / mag;
	return normal;
}

vec3 & vec3::scale(const vec3 & rhs)
{

	xpos = xpos * rhs.xpos;
	ypos = ypos * rhs.ypos;
	zpos = zpos * rhs.zpos;
	return *this;
}

vec3 vec3::getScaled(const vec3 & rhs) const
{
	vec3 scaled{ xpos, ypos, zpos };
	scaled.xpos = scaled.xpos * rhs.xpos;
	scaled.ypos = scaled.ypos * rhs.ypos;
	scaled.zpos = scaled.zpos * rhs.zpos;
	return scaled;
}

vec3 vec3::operator*(const float rhs) const
{
	vec3 times;
	times.xpos = xpos * rhs;
	times.ypos = ypos * rhs;
	times.zpos = zpos * rhs;
	return times;
}

vec3 & vec3::operator*=(const float rhs)
{
	xpos *= rhs;
	ypos *= rhs;
	zpos *= rhs;
	return *this;
}

vec3 & vec3::operator/=(const float rhs)
{
	xpos /= rhs;
	ypos /= rhs;
	zpos /= rhs;
	return *this;
}


float vec3::dot(const vec3 & rhs) const
{
	return ((xpos * rhs.xpos) + (ypos * rhs.ypos)+ (zpos * rhs.zpos));
}

vec3 vec3::cross(const vec3 & rhs) const
{
	return vec3{ (ypos * rhs.zpos) - (zpos * rhs.ypos),
					(zpos * rhs.xpos) - (xpos * rhs.zpos),
					 (xpos * rhs.ypos) - (ypos * rhs.xpos) };
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	vec3 bob;
	bob.xpos = lhs * rhs.xpos;
	bob.ypos = lhs * rhs.ypos;
	bob.zpos = lhs * rhs.zpos;
	return bob;
}
