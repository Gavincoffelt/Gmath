#pragma once
#include <cmath>
#include <cfloat>
#include <iostream>
struct vec2 {
	float xpos; float ypos;
	vec2();
	vec2(float x, float y);

	vec2 operator+(const vec2 &rhs) const;
	vec2 operator-(const vec2 &rhs) const;

	vec2 &operator+=(const vec2 &rhs);
	vec2 &operator-=(const vec2 &rhs);

	bool operator==(const vec2 &rhs) const;
	bool operator!=(const vec2 &rhs) const;

	vec2 operator-() const;

	float magnitude() const;

	vec2 &normalize();
	vec2 getNormalized() const;

	vec2 &scale(const vec2 &rhs);
	vec2 getScaled(const vec2 &rhs) const;

	vec2 operator*(const float rhs) const;
	friend vec2 operator*(const float lhs, const vec2 &rhs);

	vec2 &operator*=(const float rhs);
	vec2 &operator/=(const float rhs);





};