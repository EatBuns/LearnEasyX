#pragma once
#include "comm.h"

class Atlas
{
public:
	Atlas() = default;
	~Atlas() = default;

	//ͼƬ·����ͼƬ������ͼƬ��ʼ����
	void loadImage(LPCTSTR path, int num, int base_idx);
	IMAGE* getFrame(int idx);
	int getSize()const;
	void appendIMG(const IMAGE& img);
	void CClear();
	PVZ::SIZE getIMGSize() const;
private:
	std::vector<IMAGE> frame_lists;
};

