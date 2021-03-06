#pragma once
#include "vec3.h"
#include "Vector2.h"
struct mat3
{
	union
	{
		struct
		{
			vec3 xAxis;
			vec3 yAxis;
			vec3 zAxis;
		};
		vec3 axis[3];
		struct
		{
			float m1, m2, m3,
				m4, m5, m6,
				m7, m8, m9;
		};
		struct
		{
			float m[9];
		};
		struct
		{
			float mm[3][3];
		};
	};

	mat3();
	mat3(float *ptr);
	mat3(float m1, float m2, float m3,
		float m4, float m5, float m6,
		float m7, float m8, float m9);

	static mat3 identity();
	static mat3 translation(float x, float y);
	static mat3 translation(const vec2 &vec);
	static mat3 rotation(float rot);
	static mat3 scale(float xScale, float yScale);
    static mat3 scale(const vec2 &vec);
	// rebuild the matrix
	void set(float m1, float m2, float m3,
		float m4, float m5, float m6,
		float m7, float m8, float m9);

	// rebuild the matrix - expects pointer to array of 9 floats
	void set(float *ptr);

	void transpose();
	mat3 getTranspose() const;

	operator float *();
	operator const float *() const;

	vec3 &operator[](const int index);
	const vec3 &operator[](const int index) const;

	mat3  operator*(const mat3 &rhs) const;
	mat3 &operator*=(const mat3 &rhs);

	// transforms a 4D vector by performing 4x4 x 4x1 matrix multiplication
	vec3 operator*(const vec3 &rhs) const;
	// convenience function for transforming a 2D vector
	vec2 operator*(const vec2 &rhs) const;

	bool operator==(const mat3 &rhs) const;
	bool operator!=(const mat3 &rhs) const;
};