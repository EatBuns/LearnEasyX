#pragma once
#include "baseScene.h"
#include "SceneManager.h"
#include "camera.h"
#include "mtimer.h"
#include "Animation.h"
#include "player.h"

extern SceneManager* manager;
extern Atlas peashooter_idle_right;
extern IMAGE menu_background;
extern IMAGE gravestone;

class MenuSecne : public BaseScene
{
public:
	MenuSecne() = default;
	~MenuSecne() = default;

	void on_enter() {
		p.on_enter();
	}

	void on_update(int delta) {
		m_camera.onUpdate(delta);
		p.on_update(delta);
	}

	virtual void on_draw() {
		//putimage_alpha(0, 0, &menu_background);
		p.on_draw(m_camera, 0, 0);
	}

	virtual void on_input(const ExMessage& msg) {
		p.on_input(msg);
	}

	virtual void on_exit() {
		//std::cout << "Ö÷²Ëµ¥ exit\n";
	}

private:
	Animation peashooter_idle_right_animation;
	camera m_camera;
	Player p;
};