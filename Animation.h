#pragma once

#include "comm.h"
#include "Atlas.h"
#include <functional>

class Animation
{
public:
	Animation() = default;
	~Animation() = default;

	//����ͼ��
	void setAtlas(Atlas* atlas);
	//���¶���
	void onUpdate(int delta);
	//���ö���
	void reset();
	//ѭ������
	void set_loop(bool flag);
	//���ü��
	void setInterval(int intverval);
	//��ȡ֡
	int getFrameIdx();
	//��ȡ֡ͼƬ
	IMAGE* getFrame();
	//�Ƿ����
	bool checkfinish();
	//����
	void onDraw(int x, int y);
	//���ûص�
	void setCallback(std::function<void()> callback);
private:
	Atlas* m_atlas = nullptr;
	int interval = 0;	//֡���
	int timer = 0;		//��ʱ��
	int idx = 0;		//֡����
	bool is_loop = true;	//�Ƿ�ѭ������
	std::function<void()> Callback;
};