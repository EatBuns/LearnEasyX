#pragma once
#include <functional>


class mtimer
{
public:
	mtimer() = default;
	~mtimer() = default;
	void reset();
	void onUpdate(int delta);
	void setCallback(const std::function<void()>& cb);
	void setSignalShot(bool flag);
	void setInterval(int intv);

private:
	int passtime;			//经过时间
	int interval;			//间隔时间
	bool issignalshot = true;		//是否单次触发
	bool isPause;					//暂停
	bool isTrigger;					//是否触发
	std::function<void()> callback;
};

