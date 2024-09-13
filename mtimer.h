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
	int passtime;			//����ʱ��
	int interval;			//���ʱ��
	bool issignalshot = true;		//�Ƿ񵥴δ���
	bool isPause;					//��ͣ
	bool isTrigger;					//�Ƿ񴥷�
	std::function<void()> callback;
};

