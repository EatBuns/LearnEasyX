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
		std::cout << "ѡ�񳡾� enter\n";
	}

	void on_update() {
		std::cout << "ѡ�񳡾� update\n";
	}
	virtual void on_draw() {
		outtextxy(10, 10, L"ѡ�񳡾���ͼ");
	}
	virtual void on_input(const ExMessage& msg) {
		if (msg.message == WM_KEYDOWN)
		{
			//manager->switchTO(SceneState::mainScene);
		}
	}
	virtual void on_exit() {
		std::cout << "ѡ�񳡾� exit\n";
	}

private:

};