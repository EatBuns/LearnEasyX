#pragma once

class physical_sim
{
public:
	void calcFreeFall(float& x, float& y);
	void setHspeed(float xspeed);
	void setVspeed(float yspeed);
	void setG(float g);
	void setF(float f);
private:
	float m_f = 0.9;
	float m_g = 0.98;
	float vx = 0;
	float vy = 0;
};

