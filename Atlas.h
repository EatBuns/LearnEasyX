#pragma once
#include "comm.h"

class Atlas
{
public:
	Atlas() = default;
	~Atlas() = default;

	//图片路径，图片数量，图片起始索引
	void loadImage(LPCTSTR path, int num, int base_idx);
	IMAGE* getFrame(int idx);
	int getSize()const;
	void appendIMG(const IMAGE& img);
	void CClear();
	PVZ::SIZE getIMGSize() const;
private:
	std::vector<IMAGE> frame_lists;
};

