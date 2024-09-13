#include "camera.h"

const vector2D& camera::getPosition() const
{
	return position;
}

void camera::reset()
{
	position.x = 0;
	position.y = 0;
}

void camera::onUpdate(int delta)
{
	/*vector2D v(-0.35, 0);
	position += v * (float)(delta);*/
	static int per = 0;
	per += delta;
	if(per < m_dur)
		Shake();
}

void camera::Shake()
{
	float y = sin(rand() % 360) * m_strength;
	float x = cos(rand() % 360) * m_strength;
	this->position.x = x;
	this->position.y = y;
}

void camera::setShakeParam(int strength, int dur)
{
	m_strength = strength;
	m_dur = dur;
}
