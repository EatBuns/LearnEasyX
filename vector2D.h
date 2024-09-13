#pragma once
#include <cmath>

class vector2D
{
public:
	vector2D() = default;
	~vector2D() = default;
	vector2D(float x, float y):x(x), y(y){}

	//向量之和
	vector2D operator+(const vector2D& other) 
	{
		return vector2D(this->x + other.x, this->y + other.y);
	}

	vector2D operator-(const vector2D& other)
	{
		return vector2D(this->x - other.x, this->y - other.y);
	}

	vector2D operator*(const vector2D& other)
	{
		return vector2D(this->x * other.x, this->y * other.y);
	}

	vector2D operator*(float scalar)
	{
		return vector2D(this->x * scalar, this->y * scalar);
	}

	void operator+=(const vector2D& other)
	{
		this->x += other.x;
		this->y += other.y;
	}

	float length()
	{
		return sqrt(x * x + y * y);
	}
	vector2D Normalized()
	{
		float len = length();
		if (len == 0)	return vector2D(0, 0);
		return vector2D(x / len, y / len);
	}

	float x = 0, y = 0;
};

