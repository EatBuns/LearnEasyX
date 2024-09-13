#include "physical_sim.h"

void physical_sim::calcFreeFall(float& x, float& y)
{
	vy += m_g;
	y += vy;
}
