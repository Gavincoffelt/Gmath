#include "transform2d.h"

transform2d::transform2d()
{
}

void transform2d::translate(const vec2 & offset)
{
	localPos.xpos += offset.xpos;
	localPos.ypos += offset.ypos;
}

void transform2d::rotate(const float angle)
{
	localRot += angle;
}

void transform2d::lookAt(const transform2d & target)
{

}

vec2 transform2d::forward() const
{
	return vec2();
}

void transform2d::setForward(const vec2 & newFwd)
{

}

mat3 transform2d::getTRSMatrix() const
{
	return mat3();
}
