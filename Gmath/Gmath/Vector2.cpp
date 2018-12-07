#include "Vector2.h"

vec2::vec2()
{
	x = 2;
	y = 2;
}

vec2::vec2(float x, float y)
{
	this->x = x;
	this->y = y;
}

vec2 vec2::operator+(const vec2 & rhs) const
{
	vec2 vec;
	vec.x = x + rhs.x;
	vec.y = y + rhs.y;

	return vec;
}

vec2 vec2::operator-(const vec2 & rhs) const
{
	vec2 vec;
	vec.x = x - rhs.x;
	vec.y = y - rhs.y;

	return vec;
}

vec2 & vec2::operator+=(const vec2 & rhs)
{
	x += rhs.x;
	y += rhs.y;

	return *this;
}

vec2 & vec2::operator-=(const vec2 & rhs)
{

	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

bool vec2::operator==(const vec2 & rhs) const
{
	if ((x >= (rhs.x - FLT_EPSILON) && x <= (rhs.x + FLT_EPSILON)) &&
		(y >= (rhs.y - FLT_EPSILON) && y <= (rhs.y + FLT_EPSILON))) {
		return true;
	}
	return false;
}

bool vec2::operator!=(const vec2 & rhs) const
{
	if ((x >= (rhs.x - FLT_EPSILON) && x <= (rhs.x + FLT_EPSILON)) &&
		(y >= (rhs.y - FLT_EPSILON) && y <= (rhs.y + FLT_EPSILON))) {
		return false;
	}
	return true;

}

vec2 vec2::operator-() const
{
	vec2 vec;
	vec.x = -x;
	vec.y = -y;
	return vec;
}

float vec2::magnitude() const
{
	float magnitude = (x * x + y * y);
	
	sqrt(magnitude);

	return magnitude;
}

vec2 & vec2::normalize()
{
	
	
}

vec2 vec2::getNormalized() const
{	
	vec2 normal;
	float mag = normal.magnitude();
	std::cout << mag << std::endl;
	normal.x = x / mag;
	normal.y = y / mag;
	return normal;
}
//
//vec2 & vec2::scale(const vec2 & rhs)
//{
//	
//}
//
//vec2 vec2::getScaled(const vec2 & rhs) const
//{
//	
//}
//
//vec2 vec2::operator*(const float rhs) const
//{
//	
//}
//
//vec2 & vec2::operator*=(const float rhs)
//{
//	
//}
//
//vec2 & vec2::operator/=(const float rhs)
//{
//	
//}
//
//vec2 operator*(const float lhs, const vec2 & rhs)
//{
//	
//}
