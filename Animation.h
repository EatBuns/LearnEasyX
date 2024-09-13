#pragma once

#include "comm.h"
#include "Atlas.h"
#include <functional>

class Animation
{
public:
	Animation() = default;
	~Animation() = default;

	//设置图集
	void setAtlas(Atlas* atlas);
	//更新动画
	void onUpdate(int delta);
	//重置动画
	void reset();
	//循环播放
	void set_loop(bool flag);
	//设置间隔
	void setInterval(int intverval);
	//获取帧
	int getFrameIdx();
	//获取帧图片
	IMAGE* getFrame();
	//是否结束
	bool checkfinish();
	//绘制
	void onDraw(int x, int y);
	//设置回调
	void setCallback(std::function<void()> callback);
private:
	Atlas* m_atlas = nullptr;
	int interval = 0;	//帧间隔
	int timer = 0;		//定时器
	int idx = 0;		//帧索引
	bool is_loop = true;	//是否循环播放
	std::function<void()> Callback;
};