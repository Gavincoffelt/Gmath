#include "mat3.h"

mat3::mat3()
{

}

mat3::mat3(float * ptr)
{
	for (int i = 0; i < 9; i++) {
		m[i] = ptr[i];
	}
}

mat3::mat3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
{
	m[0] = m1;
	m[1] = m2;
	m[2] = m3;
	m[3] = m4;
	m[4] = m5;
	m[5] = m6;
	m[6] = m7;
	m[7] = m8;
	m[8] = m9;
}

mat3 mat3::identity()
{
	return mat3(1,0,0,
				0,1,0,
				0,0,1);
}

mat3 mat3::translation(float x, float y)
{
	mat3 t;
	
	t.mm[2][0] = x;
	t.mm[2][1] = y;
	return t;
}

mat3 mat3::translation(const vec2 & vec)
{
	mat3 t;

	t.mm[2][0] = vec.xpos;
	t.mm[2][1] = vec.ypos;
	return t;
}

mat3 mat3::rotation(float rot)
{
	mat3 r;
	r.mm[0][0] = cos(rot);
	r.mm[0][1] = sin(rot);
	r.mm[1][0] = -sin(rot);
	r.mm[1][1] = cos(rot);
	return r;

}

mat3 mat3::scale(float xScale, float yScale)
{
	mat3 scaled;
	scaled.m1 = xScale;
	scaled.m5 = yScale;
	return scaled;
	
}

mat3 mat3::scale(const vec2 & vec)
{
	mat3 scaled;
	scaled.m1 = vec.xpos;
	scaled.m5 = vec.ypos;
	return scaled;
}

void mat3::set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
{
	m[0] = m1;
	m[1] = m2;
	m[2] = m3;
	m[3] = m4;
	m[4] = m5;
	m[5] = m6;
	m[6] = m7;
	m[7] = m8;
	m[8] = m9;
}

void mat3::set(float * ptr)
{
	for (int i = 0; i < 9; i++) {
		m[i] = ptr[i];
	}
}

void mat3::transpose()
{
	mat3 result = getTranspose();

	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			mm[c][r] = result.mm[r][c];
		}
	}
}

mat3 mat3::getTranspose() const
{
	mat3 result;
	
	for (int i = 0; i < 3; i++) {
		for (int e = 0; e < 3; e++) {
			result.mm[i][e] = mm[e][i];

		}

	}
	return result;
}

mat3::operator float*()
{
	return &m1;
}

mat3::operator const float*() const
{
	return &m1;
}

vec3 & mat3::operator[](const int index)
{
	return axis[index];

}

const vec3 & mat3::operator[](const int index) const
{
	return axis[index];

}

mat3 mat3::operator*(const mat3 & rhs) const
{
	mat3 result;
	
	for (int i = 0; i < 3; i++) {
		for (int e = 0; e < 3; e++) {
			result.mm[e][i] = mm[0][i] * rhs.mm[e][0] +
					   		  mm[1][i] * rhs.mm[e][1] +
							  mm[2][i] * rhs.mm[e][2];
			 
		}

	}


	return *this;
}

mat3 & mat3::operator*=(const mat3 & rhs)
{
	mat3 result;

	for (int i = 0; i < 3; i++) {
		for (int e = 0; e < 3; e++) {
			result.mm[e][i] = mm[0][i] * rhs.mm[e][0] +
				mm[1][i] * rhs.mm[e][1] +
				mm[2][i] * rhs.mm[e][2];

		}

	}


	return *this;

}

vec3 mat3::operator*(const vec3 & rhs) const
{
	vec3 result;
	 
	result.xpos = mm[0][0] * rhs.xpos + mm[1][0] * rhs.ypos +
				  mm[2][0] * rhs.zpos;

	result.ypos = mm[0][1] * rhs.xpos + mm[1][1] * rhs.ypos +
	      	      mm[2][1] * rhs.zpos;

	result.zpos = mm[0][2] * rhs.xpos + mm[1][2] * rhs.ypos +
		          mm[2][2] * rhs.zpos;
	return result;
}

vec2 mat3::operator*(const vec2 & rhs) const
{

	vec2 result;

	    result.xpos = mm[0][0] * rhs.xpos + mm[1][0] * rhs.ypos;


		result.ypos = mm[0][1] * rhs.xpos + mm[1][1] * rhs.ypos;
		return result;
}

bool mat3::operator==(const mat3 & rhs) const
{
	for (int i = 0; i < 3; i++) {
		for (int e = 0; e < 3; e++) {
			if (mm[i][e] != rhs.mm[i][e]) {
				return false;
			}
		}
	}
	return true;
}

bool mat3::operator!=(const mat3 & rhs) const
{
	for (int i = 0; i < 3; i++) {
		for (int e = 0; e < 3; e++) {
			if (mm[i][e] == rhs.mm[i][e]) {
				return false;
			}
		}
	}
	return true;
}
