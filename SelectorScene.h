#pragma once
#include "baseScene.h"

#pragma once
#include "baseScene.h"
#include "SceneManager.h"

extern SceneManager* manager;

class SelectorScene : public BaseScene
{
public:
	SelectorScene() = default;
	~SelectorScene() = default;

	void on_enter() {
		initgraph(500, 500);
		std::cout << "选择场景 enter\n";
	}

	void on_update() {
		std::cout << "选择场景 update\n";
	}
	virtual void on_draw() {
		outtextxy(10, 10, L"选择场景绘图");
	}
	virtual void on_input(const ExMessage& msg) {
		if (msg.message == WM_KEYDOWN)
		{
			//manager->switchTO(SceneState::mainScene);
		}
	}
	virtual void on_exit() {
		std::cout << "选择场景 exit\n";
	}

private:

};