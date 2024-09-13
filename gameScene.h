#pragma once
#include "baseScene.h"
#include "SceneManager.h"

extern SceneManager* manager;

class GameScene : public BaseScene
{
public:
	GameScene() = default;
	~GameScene() = default;

	virtual void on_enter() {
		std::cout << "��Ϸ���� enter\n";
	}
	virtual void on_update(int delta) {
		std::cout << "��Ϸ���� update\n";
	}
	virtual void on_draw() {
		outtextxy(10, 10, L"��Ϸ����");
	}
	virtual void on_input(const ExMessage& msg) {
		if (msg.message == WM_KEYDOWN)
		{
			//manager->switchTO(SceneState::selectorScene);
		}
	}
	virtual void on_exit() {
		std::cout << "��Ϸ���� exit\n";
	}

private:

};
