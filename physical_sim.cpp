#include "physical_sim.h"

void physical_sim::calcFreeFall(float& x, float& y)
{
	vy += m_g;
	y += vy;
}

void physical_sim::setHspeed(float xspeed)
{
	vx = xspeed;
}

void physical_sim::setVspeed(float yspeed)
{
	vy = yspeed;
}

void physical_sim::setG(float g)
{
	m_g = g;
}

void physical_sim::setF(float f)
{
	m_f = f;
}
