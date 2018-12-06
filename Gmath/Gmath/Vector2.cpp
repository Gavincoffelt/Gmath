#include "Vector2.h"

vec2::vec2()
{

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
	
}

bool vec2::operator!=(const vec2 & rhs) const
{
	
}

vec2 vec2::operator-() const
{
	return vec2();
}
