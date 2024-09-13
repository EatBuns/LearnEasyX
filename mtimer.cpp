#include "mtimer.h"

void mtimer::reset()
{
	passtime = 0;
	isTrigger = false;
}

void mtimer::onUpdate(int delta)
{
	passtime += delta;
	if (passtime >= this->interval)
	{
		if ( (!isTrigger || !issignalshot) && callback)
			callback();
		passtime = 0;
		isTrigger = true;
	}
}

void mtimer::setCallback(const std::function<void()>& cb)
{
	callback = cb;
}

void mtimer::setSignalShot(bool flag)
{
	issignalshot = flag;
}

void mtimer::setInterval(int intv)
{
	this->interval = intv;
}
