#pragma once
#ifndef TYPEHEADER
#define TYPEHEADER
struct Vector3
{
	float x;
	float y;
	float z;
	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Vector3(float x_, float y_, float z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}
};

#endif