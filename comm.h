#pragma once

#include <graphics.h>
#include <iostream>
#include <vector>

#pragma comment(lib, "MSIMG32.LIB")

enum SceneState {
	mainScene,
	gameScene,
	selectorScene
};

enum DIRECTION
{
	NONE,
	W,
	A,
	S,
	D,
	UP
};


inline void putimage_alpha(int x, int y, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255,  AC_SRC_ALPHA });
}

static void filpIMG(IMAGE* src, IMAGE* dst)
{
	//ÏÈresize
	int width = src->getwidth();
	int height = src->getheight();
	Resize(dst, width, height);

	DWORD *srcbuf = GetImageBuffer(src);
	DWORD* dstbuf = GetImageBuffer(dst);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int idx_src = i * width + j;
			int idx_dst = i * width + (width - j - 1);
			dstbuf[idx_dst] = srcbuf[idx_src];
		}
	}
}

namespace PVZ {
	typedef struct SIZE
	{
		int width;
		int height;
	}SIZE;

	typedef struct POINT
	{
		float x = 0;
		float y = 0;
	}POINT;
}