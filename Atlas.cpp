#include "Atlas.h"

void Atlas::loadImage(LPCTSTR path, int num, int base_idx)
{
	frame_lists.clear();
	frame_lists.resize(num);

	for (int i = 0; i < num; i++)
	{
		wchar_t filepath[128];
		_stprintf_s(filepath, path, base_idx++);

		loadimage(&frame_lists[i], filepath);
	}
}

IMAGE* Atlas::getFrame(int idx)
{
	if(idx < 0 || idx > frame_lists.size() - 1)
	return nullptr;
	return &frame_lists[idx];
}

int Atlas::getSize() const
{
	return frame_lists.size();
}

void Atlas::appendIMG(const IMAGE& img)
{
	frame_lists.push_back(img);
}

void Atlas::CClear()
{
	frame_lists.clear();
}

PVZ::SIZE Atlas::getIMGSize() const
{
	PVZ::SIZE s;
	s.width = frame_lists[0].getwidth();
	s.height = frame_lists[0].getheight();
	return s;
}
