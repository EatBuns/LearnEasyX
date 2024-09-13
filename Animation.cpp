#include "Animation.h"

void Animation::setAtlas(Atlas* atlas)
{
	reset();
	m_atlas = atlas;
}

void Animation::onUpdate(int delta)
{
	timer += delta;
	if (timer >= interval)
	{
		timer = 0;
		idx++;
		if (idx > m_atlas->getSize() - 1)
		{
			idx = is_loop ? 0 : m_atlas->getSize() - 1;
		}
	}
}

void Animation::reset()
{
	idx = 0;
	timer = 0;
}

void Animation::set_loop(bool flag)
{
	is_loop = flag;
}

void Animation::setInterval(int intverval)
{
	this->interval = intverval;
}

int Animation::getFrameIdx()
{
	return idx;
}

IMAGE* Animation::getFrame()
{
	return m_atlas->getFrame(idx);
}

bool Animation::checkfinish()
{
	if(is_loop) return false;
	return (idx == m_atlas->getSize() - 1);
}

void Animation::onDraw(int x, int y)
{
	putimage_alpha(x, y, m_atlas->getFrame(idx));
}

void Animation::setCallback(std::function<void()> callback)
{
	Callback = callback;
}
