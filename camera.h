#pragma once
#include "vector2D.h"
#include <cmath>
#include <ctime>

class camera
{
public:
	camera()
	{
		srand(time(0));
	}

	~camera() = default;
	const vector2D& getPosition()const;
	void reset();
	void onUpdate(int delta);
	void setShakeParam(int strength, int dur);
	void Shake();
private:
	vector2D position;
	int m_strength = 0;
	int m_dur = 0;
};

