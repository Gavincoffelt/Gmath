#pragma once
#include <cmath>
#include <cfloat>
#include <iostream>
struct vec4 {
	float xpos; float ypos; float zpos; float wpos;
	vec4();
	vec4(float x, float y, float z, float w);

	vec4 operator+(const vec4 &rhs) const;
	vec4 operator-(const vec4 &rhs) const;

	vec4 &operator+=(const vec4 &rhs);
	vec4 &operator-=(const vec4 &rhs);

	bool operator==(const vec4 &rhs) const;
	bool operator!=(const vec4 &rhs) const;

	vec4 operator-() const;

	float magnitude() const;

	vec4 &normalize();
	vec4 getNormalized() const;


	vec4 &scale(const vec4 &rhs);
	vec4 getScaled(const vec4 &rhs) const;

	vec4 operator*(const float rhs) const;
	friend vec4 operator*(const float lhs, const vec4 &rhs);

	vec4 &operator*=(const float rhs);
	vec4 &operator/=(const float rhs);
	float dot(const vec4 &rhs) const;
	vec4 cross(const vec4 &rhs) const;



};